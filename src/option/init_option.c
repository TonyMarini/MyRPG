/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_option
*/

#include <stdio.h>
#include "option.h"
#include "tool.h"

static void init_size_button(option_menu_t *menu, resource_t *r, window_t win)
{
    ui_texture_t ui = r->ui_texture;
    sfIntRect rect = ini_rect(0, 0, ui.selector.w, ui.selector.h);
    sfVector2f pos = {win.w / 2 - 200, 500};
    sfVector2f center =  ini_vector(rect.width / 2, rect.height / 2);
    char nam[6][15] = {"2560x1440", "1920x1080", "1366x768",
    "1280x720", "960x540", "640x360"};

    for (int i = 0 ; i < 6 ; i++, pos.y += 100) {
        menu->size_button[i] = create_button(ui.button2, nam[i], r->font, 25);
        change_button_pos(&menu->size_button[i], pos);
        sfText_setCharacterSize(menu->size_button[i].text, 30);
        menu->selector[i] = set_sprite(ui.selector, pos, 1, 1);
        sfSprite_setTextureRect(menu->selector[i], rect);
        sfSprite_setOrigin(menu->selector[i], center);
        sfSprite_setPosition(menu->selector[i], ini_vector(pos.x - 94, pos.y));
        i == 2 ? pos = ini_vector(win.w / 2 + 200, 400) : pos;
    }
    rect = ini_rect(0, ui.selector.h, ui.selector.w, ui.selector.h);
    sfSprite_setTextureRect(menu->selector[menu->option->select_size], rect);
}

static void init_sound_slide(option_menu_t *menu, resource_t *r, window_t win)
{
    sfFont *font = r->font;
    ui_texture_t ui = r->ui_texture;
    sfVector2f pos = {win.w / 2 - 200, 350};
    option_t *option = menu->option;
    int temp = option->sound_lvl / 10;

    menu->sound_slider = create_slider(r->ui_texture, pos, temp);
    pos.y += 35;
    menu->mute_sound = create_chbox(ui.checkbox, "Mute sound", font, pos);
    checkbox_update(&(menu->mute_sound), option->sound_mute);
    pos = ini_vector(win.w / 2 + 200, 350);
    temp = option->music_lvl / 10;
    menu->music_slider = create_slider(r->ui_texture, pos, temp);
    pos.y += 35;
    menu->mute_music = create_chbox(ui.checkbox, "Mute music", font, pos);
    checkbox_update(&(menu->mute_music), option->music_mute);
}

static void init_info(window_t win, option_menu_t *menu, resource_t *resource)
{
    ui_texture_t ui = resource->ui_texture;
    sfVector2f pos = {win.w / 2, win.h / 2};

    menu->bg_sprite = set_sprite(ui.bg_option, pos, 1, 1);
    pos = ini_vector(win.w / 2 + 200, 300);
    menu->text_music = sfText_create();
    sfText_setCharacterSize(menu->text_music, 30);
    sfText_setString(menu->text_music, "Music");
    sfText_setFont(menu->text_music, resource->font);
    set_origin_text(menu->text_music);
    sfText_setPosition(menu->text_music, pos);
    pos = ini_vector(win.w / 2 - 200, 300);
    menu->text_sound = sfText_create();
    sfText_setCharacterSize(menu->text_sound, 30);
    sfText_setString(menu->text_sound, "Sound");
    sfText_setFont(menu->text_sound, resource->font);
    set_origin_text(menu->text_sound);
    sfText_setPosition(menu->text_sound, pos);
}

int init_option(option_menu_t *menu, resource_t *resource, window_t win)
{
    ui_texture_t ui = resource->ui_texture;
    sfVector2f pos = {win.w / 2 - 200, 900};
    sfFont *font = resource->font;

    menu->mouse_press = 0;
    menu->back_button = create_button(ui.button, "Back", font, 30);
    change_button_pos(&(menu->back_button), pos);
    pos = ini_vector(win.w / 2 + 200, 900);
    menu->save_button = create_button(ui.button, "Save", font, 30);
    change_button_pos(&(menu->save_button), pos);
    pos = ini_vector(win.w / 2, 840);
    menu->control_button = create_button(ui.button, "Control", font, 30);
    change_button_pos(&(menu->control_button), pos);
    pos = ini_vector(win.w / 2, 750);
    menu->fscreen_box = create_chbox(ui.checkbox, "Fullscreen", font, pos);
    checkbox_update(&(menu->fscreen_box), menu->option->fullscreen);
    init_size_button(menu, resource, win);
    init_sound_slide(menu, resource, win);
    init_info(win, menu, resource);
    return (SUCCESS);
}