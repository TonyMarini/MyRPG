/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Refresh the music
*/

#include "gameloop.h"
#include "music.h"

static void refresh_loop(music_data_t *music_data, music_t *music)
{
    sfSoundStatus status = sfMusic_getStatus(music->music);

    if (status == sfStopped && music->play == true)
        sfMusic_play(music->music);
    if (status == sfPlaying && music->play == false)
        sfMusic_stop(music->music);
    if (music_data->is_modification == false)
        return;
    sfMusic_setVolume(music->music, music_data->music_lvl);
    if (music_data->music_mute == true)
        sfMusic_setVolume(music->music, 0);
}

static void refresh_sound(music_data_t *music_data, music_t *music)
{
    if (music->play == true) {
        sfMusic_play(music->music);
        music->play = false;
    }
    if (music_data->is_modification == false)
        return;
    sfMusic_setVolume(music->music, music_data->sound_lvl);
    if (music_data->sound_mute == true)
        sfMusic_setVolume(music->music, 0);
}

void refresh_music(music_data_t *music_data)
{
    for (int i = 0 ; i < NB_MUSIC ; i++) {
        if (music_data->music[i].loop == true)
            refresh_loop(music_data, &music_data->music[i]);
        else
            refresh_sound(music_data, &music_data->music[i]);
    }
    if (music_data->is_modification == true)
        music_data->is_modification = false;
}
