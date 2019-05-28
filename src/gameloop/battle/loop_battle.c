/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_battle
*/

#include "gameloop.h"

//  Function for the zomby's turn
static void zomby_turn(gameloop_data_t *data, window_t *win)
{
    sfVector2f pos = sfSprite_getPosition(data->map.obj.perso.sprite);

    (void)win;
    data->map.obj.perso.stat.life -=
        data->map.obj.zombie[data->battle.zombie].stat.ad;
    sfMusic_play(data->resource->music_data.music[Z_ATK].music);
    remove_life(data);
    sfClock_restart(data->battle.anim_clock);
    data->battle.anim = 1;
    pos.x += TILE_SCALE / 2;
    pos.y += TILE_SCALE;
    setpos_blood_particule(data, pos);
    data->battle.blood_particule = 1;
}

static void play_turn(gameloop_data_t *data, int *turn, window_t *win)
{
    if (*turn == 1) {
        if (time_to_second(data->battle.anim_clock) >= TURN_TIME
            && data->battle.anim == 1) {
            data->battle.anim = 0;
            *turn = 2;
            data->battle.blood_particule = 0;
        }
    } else if (*turn == 2) {
        if (data->battle.anim == 0)
            zomby_turn(data, win);
        else if (time_to_second(data->battle.anim_clock) >= TURN_TIME
            && data->battle.anim == 1) {
            data->battle.anim = 0;
            *turn = 1;
            data->battle.blood_particule = 0;
        }
    }
}

void loop_battle(gameloop_data_t *data, window_t *win, int *status)
{
    int turn = 1;

    while (data->map.obj.perso.stat.life > 0
        && data->map.obj.zombie[data->battle.zombie].stat.life > 0) {
        display_battle(win, data);
        if (handle_evt(win, data, turn, status) == -1)
            return;
        play_turn(data, &turn, win);
        for (int i = 0; i < 6; i++)
            button_is_over(*win, &data->battle.spell_button[i]);
        if (data->battle.blood_particule == 1)
            move_blood_particule(data->blood_particule, 50);
        if (data->battle.health_particule == 1)
            move_blood_particule(data->health_particule, 30);
    }
    if (data->map.obj.zombie[data->battle.zombie].stat.life <= 0) {
        data->resource->music_data.music[Z_DYING].play = true;
        to_dead_zombie(&(data->map.obj.zombie[data->battle.zombie]));
        xp(data);
    }
    data->battle.status_battle = -1;
}