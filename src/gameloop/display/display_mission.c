/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_mission
*/

#include "gameloop.h"

static void check_in_spell_bar(gameloop_data_t *data, int *i)
{
    for (int j = 0; j < 6; j++)
        if (data->inventory.spell_content[j] != -1 &&
            data->inventory.spell_content[j] ==
            data->map.obj.pnj[*i].item_req) {
            data->map.obj.perso.mission += data->map.obj.pnj[*i].mission;
            data->inventory.spell_content[j] =
                    data->map.obj.pnj[*i].item_reward;
        }
}

static void check_mission(gameloop_data_t *data, int *i)
{
    if ((data->map.obj.perso.mission %
        (data->map.obj.pnj[*i].mission * 10))
        / data->map.obj.pnj[*i].mission == 1)
    return;
    for (int j = 0; j < 9; j++)
        if (data->inventory.inventory_content[j] != -1 &&
            data->inventory.inventory_content[j] ==
            data->map.obj.pnj[*i].item_req) {
            data->map.obj.perso.mission += data->map.obj.pnj[*i].mission;
            data->inventory.inventory_content[j] =
                    data->map.obj.pnj[*i].item_reward;
            return;
        }
    check_in_spell_bar(data, i);
}

static void select_dialogue(window_t *win, gameloop_data_t *data, int *i)
{
    check_mission(data, i);
    sfRenderWindow_drawSprite(win->win,
                data->map.obj.pnj[*i].dial_box, NULL);
    if ((data->map.obj.perso.mission % (data->map.obj.pnj[*i].mission * 10))
        / data->map.obj.pnj[*i].mission == 1)
        sfRenderWindow_drawText(win->win,
                data->map.obj.pnj[*i].text_end, NULL);
    else {
        sfRenderWindow_drawText(win->win,
                data->map.obj.pnj[*i].text_start, NULL);
    }
}

void display_mission(window_t *win, gameloop_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->map.obj.perso.sprite);
    int space_x = 0;
    int space_y = 0;
    int pos_x = pos.x / TILE_SCALE;
    int pos_y = (pos.y + TILE_SCALE) / TILE_SCALE;

    for (int i = 0; i < data->map.obj.nb_pnj; i++) {
        space_x = pos_x - data->map.obj.pnj[i].pos_tab.x;
        space_y = pos_y - data->map.obj.pnj[i].pos_tab.y;
        if (space_x > -2 && space_x < 2 && space_y > -2 && space_y < 2)
            select_dialogue(win, data, &i);
    }
}
