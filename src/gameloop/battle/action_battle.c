/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** action_battle
*/

#include "main_menu.h"
#include "gameloop.h"

static void player_attack(gameloop_data_t *data, int i)
{
    sfVector2f pos = sfSprite_getPosition(
            data->map.obj.zombie[data->battle.zombie].sprite);

    data->map.obj.zombie[data->battle.zombie].stat.life -=
            data->item[data->inventory.spell_content[i]].damage;
    if (data->inventory.spell_content[i] == 8
        || data->inventory.spell_content[i] == 9)
        data->map.obj.perso.stat.ammo -= 1;
    remove_life_zombie(&data->map.obj.zombie[data->battle.zombie]);
    sfMusic_play(data->resource->music_data.music[Z_HIT].music);
    pos.x += TILE_SCALE / 2;
    pos.y += TILE_SCALE;
    setpos_blood_particule(data, pos);
    data->battle.blood_particule = 1;
}

static void player_heal(gameloop_data_t *data, int i)
{
    sfVector2f pos = sfSprite_getPosition(data->map.obj.perso.sprite);

    data->map.obj.perso.stat.life +=
            data->item[data->inventory.spell_content[i]].heal;
    if (data->map.obj.perso.stat.life > data->map.obj.perso.stat.max_life)
        data->map.obj.perso.stat.life = data->map.obj.perso.stat.max_life;
    add_life(data);
    sfMusic_play(data->resource->music_data.music[HEAL].music);
    data->inventory.spell_content[i] = -1;
    pos.x += TILE_SCALE / 2;
    pos.y += TILE_SCALE;
    setpos_health_particule(data, pos);
    data->battle.health_particule = 1;
}

static int action_press(gameloop_data_t *data, window_t *win, int i)
{
    (void)win;
    if (data->inventory.spell_content[i] == -1)
        return (ERROR);
    if (data->map.obj.perso.stat.ammo <= 0 &&
        (data->inventory.spell_content[i] == 8
        || data->inventory.spell_content[i] == 9))
        return (ERROR);
    sfClock_restart(data->battle.anim_clock);
    data->battle.anim = 1;
    if (data->item[data->inventory.spell_content[i]].heal == -1)
        player_attack(data, i);
    else
        player_heal(data, i);
    return (SUCCESS);
}

int key_press_battle(sfKeyEvent key, window_t *win, gameloop_data_t *d, int *s)
{
    if (key.code == d->option->key.spell1)
        return (action_press(d, win, 0));
    if (key.code == d->option->key.spell2)
        return (action_press(d, win, 1));
    if (key.code == d->option->key.spell3)
        return (action_press(d, win, 2));
    if (key.code == d->option->key.spell4)
        return (action_press(d, win, 3));
    if (key.code == d->option->key.spell5)
        return (action_press(d, win, 4));
    if (key.code == d->option->key.spell6)
        return (action_press(d, win, 5));
    if (key.code == sfKeyEscape)
        if (in_game_menu(win, d) == ERROR) {
            *s = 1;
            return (-1);
        }
    return (ERROR);
}

int click_spell_attack(sfMouseButtonEvent m, window_t *w, gameloop_data_t *d)
{
    sfVector2i pos = ini_vectori(m.x, m.y);
    int status = -1;

    for (int i = 0; i < 6; i++) {
        if (button_is_click(*w, &d->battle.spell_button[i], pos)) {
            status = action_press(d, w, i);
        }
        if (status == SUCCESS)
            return (SUCCESS);
    }
    return (ERROR);
}