/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Load the music from option_t
*/

#include "rpg.h"

static int modif_mute(music_data_t *music_data, option_t *option)
{
    int modif = 0;

    if (option->sound_mute == 1 && music_data->sound_mute == false) {
        music_data->sound_mute = true;
        modif++;
    }
    if (option->sound_mute == 0 && music_data->sound_mute == true) {
        music_data->sound_mute = false;
        modif++;
    }
    if (option->music_mute == 1  && music_data->music_mute == false) {
        music_data->music_mute = true;
        modif++;
    }
    if (option->music_mute == 0 && music_data->music_mute == true) {
        music_data->music_mute = false;
        modif++;
    }
    return (modif);
}

static int modif_lvl(music_data_t *music_data, option_t *option)
{
    int modif = 0;

    if (music_data->music_lvl != option->music_lvl) {
        music_data->music_lvl = option->music_lvl;
        modif++;
    }
    if (music_data->sound_lvl != option->sound_lvl) {
        music_data->sound_lvl = option->sound_lvl;
        modif++;
    }
    return (modif);
}

void load_music_option(music_data_t *music_data, option_t *option)
{
    int modif = 0;

    modif += modif_mute(music_data, option);
    modif += modif_lvl(music_data, option);
    if (modif > 0)
        music_data->is_modification = true;
}
