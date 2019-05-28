/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Launch the zombie ambiant song
*/

#include "gameloop.h"
#include "rpg.h"

#include <stdio.h>

void launch_zombie_ambiant(music_data_t *music_data, obj_t obj)
{
    int nb_zombie_alive = 0;

    music_data->music[ZOMBIE1].play = false;
    music_data->music[ZOMBIE2].play = false;
    music_data->music[ZOMBIE3].play = false;
    for (int i = 0 ; i < obj.nb_zombie ; i++)
        if (obj.zombie[i].alive == 1)
            nb_zombie_alive++;
    if (nb_zombie_alive == 1)
        music_data->music[ZOMBIE1].play = true;
    if (nb_zombie_alive == 2)
        music_data->music[ZOMBIE2].play = true;
    if (nb_zombie_alive >= 3)
        music_data->music[ZOMBIE3].play = true;
}
