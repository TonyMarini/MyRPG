/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_item
*/

#include "rpg.h"
#include "loader.h"

static const char *ITEM1 = "resource/item/HC_PowerUps1.png";
static const char *ITEM2 = "resource/item/HC_PowerUps2.png";
static const char *ITEM3 = "resource/item/HC_PowerUps3.png";

int load_item(item_texture_t *item)
{
    if (load_img(&item->item1, ITEM1, 384, 448) == ERROR)
        return (ERROR);
    if (load_img(&item->item2, ITEM2, 384, 448) == ERROR)
        return (ERROR);
    if (load_img(&item->item3, ITEM3, 384, 488) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
