/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** sound_button_event
*/

#include <stdio.h>
#include "option.h"
#include "tool.h"

int sound_button_event(window_t *win, option_menu_t *d, sfVector2i pos, int s)
{
    move_slider(*win, &(d->sound_slider));
    d->option->sound_lvl = d->sound_slider.value * 10;
    move_slider(*win, &(d->music_slider));
    d->option->music_lvl = d->music_slider.value * 10;
    if (checkbox_is_click(*win, &(d->mute_sound), pos) && s == 1) {
        checkbox_update(&(d->mute_sound), !d->mute_sound.status);
        d->option->sound_mute = !d->option->sound_mute;
    }
    if (checkbox_is_click(*win, &(d->mute_music), pos) && s == 1) {
        checkbox_update(&(d->mute_music), !d->mute_music.status);
        d->option->music_mute = !d->option->music_mute;
    }
    return (SUCCESS);
}
