/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loader
*/

#include <stdio.h>
#include "gameloop.h"

#ifndef LOADER_H_
#define LOADER_H_

#include "rpg.h"

//Main func for texture loading
int load_resource(window_t win, resource_t *texture);

//Sub to load an img and set width and height
int load_img(my_texture_t *texture, const char *path, int w, int h);

//Subfunction for texture loading
int load_map_texture(sfTexture ***tiles);
int load_ui_texture(ui_texture_t *ui);
int load_perso(perso_texture_t *perso);

//load_obj
int get_size_malloc_obj(FILE *fd);
int select_loader(int select, FILE *fd, obj_t *obj, resource_t *resource);
int load_obj(obj_t *obj, char *path, resource_t *resource);

//load_zombie
void initialize_zombie(FILE *fd, int *i,
        perso_texture_t *perso, zombie_t *zombie);
void initialize_zombie_two(char **info, int *i, zombie_t *zombie);
sfTexture *select_texture_zombie(char *str, perso_texture_t *perso);
int load_zombie(FILE *fd, obj_t *obj, resource_t *resource);
void initialize_zombie_life(resource_t *resource, zombie_t *zombie, int *i);

//load map link
int load_link(FILE *fd, obj_t *objet);

//load_pnj
int load_pnj(FILE *fd, obj_t *obj, resource_t *resource);

//load_hud
int load_hud(hud_t *hud, char *name);

//load_item
int load_item(item_texture_t *item);

//load_loot
int load_loot(FILE *fd, obj_t *obj, resource_t *resource);
void load_random_stuff(map_data_t *map);

#endif /* !LOADER_H_ */
