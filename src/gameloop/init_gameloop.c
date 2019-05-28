/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_gameloop
*/

#include <time.h>
#include <stdlib.h>
#include "rpg.h"
#include "gameloop.h"
#include "loader.h"
#include "main_menu.h"

int init_gameloop(window_t *w, gameloop_data_t *d, resource_t *r, char *name)
{
    sfVector2i perso = {0, 0};

    srand(time(NULL));
    (void)w;
    if (get_character(w, r, &perso) == ERROR)
        return (ERROR);
    d->name = name;
    d->map.obj.perso = ini_perso(r->perso.hum_3a.texture, perso.x, perso.y);
    if (load_map(r, ".map/map_spawn/", &(d->map)) == ERROR)
        return (ERROR);
    if (load_hud(&d->hud, name) == ERROR)
        return (ERROR);
    sfSprite_setTextureRect(d->hud.profil, (sfIntRect){
        perso.x * 46 + (perso.y * 184), 0, 46, 48});
    d->anim_clock = sfClock_create();
    d->resource = r;
    init_item(d);
    load_particule(d, r);
    if (ini_inventory(d) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
