/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Free the musics
*/

#include "rpg.h"

void free_music(music_data_t *music_data)
{
    for (int i = 0 ; i < NB_MUSIC ; i++)
        sfMusic_destroy(music_data->music[i].music);
}
