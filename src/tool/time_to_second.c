/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** time_to_second
*/

#include "rpg.h"

float time_to_second(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    return (time.microseconds / 1000000.0);
}
