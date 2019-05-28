/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main_menu
*/

#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "rpg.h"
#include "gameloop.h"

typedef struct start_menu_s {
    button_t play_button;
    button_t how_play_button;
    button_t option_button;
    button_t quit_button;
    resource_t *resource;
    option_t *option;
    sfSprite *title;
    sfSprite *bg;
    sfSprite *bg_image;
    sfSprite *how_to_play;
} start_menu_t;

int start_menu(window_t *win, resource_t *texture, option_t *option);

//Event
int start_menu_event(window_t *win, start_menu_t *menu_data);

//in_game_menu
int in_game_menu_event(window_t *w, gameloop_data_t *data, in_game_menu_t *m);
int in_game_menu(window_t *win, gameloop_data_t *data);

//inventory
int inventory_event(window_t *win, gameloop_data_t *data);
stat_text_t load_statistic_text_inventory(sfVector2f pos,
        char *str, sfVector2i act_max, sfFont *font);
int inventory(window_t *win, gameloop_data_t *data);
void init_icon_inventory(gameloop_data_t *data);
int ini_inventory(gameloop_data_t *data);
int load_inventory_content(gameloop_data_t *game_data);
int init_item_inv(gameloop_data_t *data);
void display_inventory(window_t *win, gameloop_data_t *data);
int start_drag_item(sfMouseButtonEvent m, window_t *w, gameloop_data_t *data);
int move_drag_item(sfMouseMoveEvent mouse, gameloop_data_t *data);
int end_drag_item(sfMouseButtonEvent m, window_t *w, gameloop_data_t *data);
int init_inventory2(gameloop_data_t *data);
void update_info_item(window_t *win, gameloop_data_t *data, int index, int t);
void move_steam_particle(particule_t *particule);
void init_pos_and_distance_particule(particule_t *particule,
        sfVector2f pos, int distance);
int inv_use_item(gameloop_data_t *data, int i, int t);
void ini_particule_menu(particule_t **particule,
        particule_t **a_particule, resource_t *texture);

//How to play
int init_how_to_play(start_menu_t *data, resource_t *texture, window_t win);
int how_to_play(window_t *win, start_menu_t *data);

//enter_name
int enter_name(window_t *win, char *name, start_menu_t *menu);
int enter_name_event(window_t *win, int *i, char *name);
int destroy_enter_name_element(sfText *name,
        sfText *enter_name, sfSprite *sprite, sfSprite *backg);

#endif /* !MAIN_MENU_H_ */
