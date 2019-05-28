/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Center the text
*/

#include "rpg.h"

void set_origin_text(sfText *text)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos;

    pos.y = rect.height / 2;
    pos.x = rect.width / 2;
    sfText_setOrigin(text, pos);
}
