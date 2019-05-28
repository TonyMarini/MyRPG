/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** gameloop
*/

#include <stdio.h>
#include "rpg.h"
#include "gameloop.h"
#include "tool.h"
#include "main_menu.h"
#include "music.h"

void launch_zombie_ambiant(music_data_t *music_data, obj_t obj);

static int loop2(window_t *win,gameloop_data_t *game_data)
{
    load_interaction(&game_data->map.obj);
    is_battle(&game_data->battle, &game_data->map.obj);
    move_zombie(game_data->map.obj.nb_zombie, game_data->map.obj.zombie);
    move_particule(game_data);
    launch_zombie_ambiant(&game_data->resource->music_data, game_data->map.obj);
    refresh_music(&game_data->resource->music_data);
    for (int i = 0 ; i < game_data->map.obj.nb_zombie ; i++) {
        if (game_data->map.obj.zombie[i].scale == 2 &&
            game_data->map.obj.zombie[i].alive == FALSE) {
            end_screen(win ,game_data);
            return (ERROR);
        }
    }
    return (SUCCESS);
}

static int loop(window_t *win, gameloop_data_t *game_data, option_t *option)
{
    perso_t *perso = &game_data->map.obj.perso;

    if (display(win, game_data) == ERROR)
        return (ERROR);
    if (move_perso(option->key, perso, &game_data->map) == ERROR)
        return (ERROR);
    if (anim_gameloop(game_data) == ERROR)
        return (ERROR);
    if (manage_event(win, game_data) == ERROR)
        return (ERROR);
    if (game_data->battle.status_battle == TRUE)
        if (battle(game_data, win) == ERROR)
            return (ERROR);
    if (perso->stat.life <= 0)
        return (game_over(win, game_data));
    change_map(win, perso, game_data);
    return (loop2(win, game_data));
}

int gameloop(window_t *window,
        resource_t *texture, option_t *option, char *name)
{
    gameloop_data_t game_data;

    game_data.option = option;
    game_data.resource = texture;
    if (init_gameloop(window, &game_data, texture, name) == ERROR)
        return (ERROR);
    if (init_sprite_battle(&game_data, window) == ERROR)
        return (ERROR);
    game_data.option = option;
    game_data.resource = texture;
    texture->music_data.music[MUSIC].play = false;
    texture->music_data.music[CITY].play = true;
    while (sfRenderWindow_isOpen(window->win))
        if (loop(window, &game_data, option) == ERROR)
            return (ERROR);
    return (0);
}
