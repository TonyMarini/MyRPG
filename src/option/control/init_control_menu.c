/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_control_menu
*/

#include <stdio.h>
#include "option.h"
#include "tool.h"

static button_t create_control_b(sfVector2f pos, resource_t *r, sfKeyCode key)
{
    sfFont *font = r->font;
    ui_texture_t ui = r->ui_texture;
    button_t my_button = create_button(ui.button3, KEY_NAME[key], font, 30);

    change_button_pos(&my_button, pos);
    return (my_button);
}

static sfText *create_control_t(sfVector2f pos_txt, resource_t *res, int i)
{
    sfText *my_text = sfText_create();

    sfText_setCharacterSize(my_text, 30);
    sfText_setString(my_text, CONTROL_NAME[i]);
    sfText_setFont(my_text, res->font);
    set_origin_text(my_text);
    sfText_setPosition(my_text, pos_txt);
    return (my_text);
}

static void init_navig_button(control_menu_t *menu, resource_t *r, window_t w)
{
    sfFont *font = r->font;
    sfVector2f pos = {w.w / 2 - 200, 900};
    ui_texture_t ui = r->ui_texture;

    menu->back_button = create_button(ui.button, "Back", font, 30);
    change_button_pos(&(menu->back_button), pos);
    pos = ini_vector(w.w / 2 + 200, 900);
    menu->save_button = create_button(ui.button, "Save", font, 30);
    change_button_pos(&(menu->save_button), pos);
    pos = ini_vector(w.w / 2, 840);
}

int init_control_m(control_menu_t *d, window_t w, resource_t *r, option_t op)
{
    sfVector2f pos_txt = {w.w / 2 - 300, 200};
    sfVector2f pos_button = {w.w / 2 - 150, 200};

    from_key_to_array(op.key, d->key_code);
    for (int i = 0 ; i < NB_CONTROL ; i++) {
        if (i == NB_CONTROL / 2) {
            pos_txt = ini_vector(w.w / 2 + 150, 200);
            pos_button = ini_vector(w.w / 2 + 300, 200);
        }
        d->label[i] = create_control_t(pos_txt, r, i);
        d->button[i] = create_control_b(pos_button, r, d->key_code[i]);
        pos_button.y += 100;
        pos_txt.y += 100;
    }
    init_navig_button(d, r, w);
    d->wait_event = -1;
    return (SUCCESS);
}