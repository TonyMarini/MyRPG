/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include "music.h"

static const int SUCCESS = 0;
static const int ERROR = 84;
static const int TRUE = 1;
static const int FALSE = 0;
static const int SCALE = 5;
static const int TILE_SIZE = 16;
static const int TILE_SCALE = SCALE * TILE_SIZE;
//file where key setting are store
static const char KEY_FILE[20] = ".key_setting";
//file where window size and sound setting are store
static const char OPTION_FILE[20] = ".option";
//folder where all map are store
static const char MAP_FOLDER[20] = ".map/";
//number of item
static const int NB_ITEM = 13;

//Custom types
typedef struct my_texture_s {
    sfTexture *texture;
    int w;
    int h;
} my_texture_t;

typedef struct stat_s {
    int ammo;
    int ad;
    int life;
    int max_life;
    int xp;
    int max_xp;
} stat_t;

typedef struct perso_s {
    int x;
    int y;
    sfSprite *sprite;
    char direction;
    sfIntRect rect;
    stat_t stat;
    int mission;
} perso_t;

typedef struct button_s {
    sfSprite *sprite;
    sfText *text;
    sfIntRect rect;
} button_t;

typedef struct checkbox_s {
    sfSprite *box;
    sfText *text;
    sfIntRect rect;
    int status;
} checkbox_t;

typedef struct slider_s {
    sfSprite *bg;
    sfSprite *lvl_indi;
    sfSprite *slider;
    int value;
    sfVector2f pos;
    int slider_w;
    sfVector2f min_pos;
} slider_t;

typedef struct window_s {
    sfRenderWindow *win;
    int w;
    int h;
    float scale;
    sfView *view;
} window_t;

typedef struct ui_texture_s {
    my_texture_t button;
    my_texture_t title;
    my_texture_t button2;
    my_texture_t selector;
    my_texture_t checkbox;
    my_texture_t sound_bar;
    my_texture_t sound_lvl_indi;
    my_texture_t sound_slider;
    my_texture_t button3;
    my_texture_t bg_option;
    my_texture_t spell;
    my_texture_t spell_bar;
    my_texture_t bg_menu;
    my_texture_t inventory;
    my_texture_t zombie_life;
    my_texture_t dialogue;
    my_texture_t bg_item;
    my_texture_t info_key;
    my_texture_t bg_info_item;
    my_texture_t bg_menu_image;
    my_texture_t bg_option_image;
    my_texture_t life;
    my_texture_t game_over;
    my_texture_t how_to_play;
    my_texture_t bg_stat;
    my_texture_t bg_inventory;
    my_texture_t fr_inventory;
    my_texture_t end_screen;
} ui_texture_t;

typedef struct perso_texture_s {
    my_texture_t civ_a;
    my_texture_t civ_b;
    my_texture_t hum_1a;
    my_texture_t hum_1b;
    my_texture_t hum_3a;
    my_texture_t zomb_1a;
    my_texture_t zomb_1b;
    my_texture_t zomb_1c;
    my_texture_t dead_zomb_1a;
    my_texture_t dead_zomb_1b;
    my_texture_t dead_zomb_1c;
} perso_texture_t;

typedef struct item_texture_s {
    my_texture_t item1;
    my_texture_t item2;
    my_texture_t item3;
} item_texture_t;

typedef struct resource_s {
    sfTexture **map_texture;
    ui_texture_t ui_texture;
    sfFont *font;
    perso_texture_t perso;
    my_texture_t particule;
    my_texture_t blood_particule;
    my_texture_t steam_particule;
    my_texture_t health_particule;
    item_texture_t item;
    sfText *space;
    music_data_t music_data;
    my_texture_t mouse_cursor;
    sfSprite *cursor;
} resource_t;

typedef struct game_key_s {
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode action;
    sfKeyCode inventory;
    sfKeyCode spell1;
    sfKeyCode spell2;
    sfKeyCode spell3;
    sfKeyCode spell4;
    sfKeyCode spell5;
    sfKeyCode spell6;
} game_key_t;

typedef struct option_s {
    game_key_t key;
    int select_size;
    int window_w;
    int window_h;
    int fullscreen;
    int sound_mute;
    int sound_lvl;
    int music_mute;
    int music_lvl;
} option_t;

int rpg(void);
int check_env(int argc, char **argv, char **envp);
int gameloop(window_t *window,
        resource_t *texture, option_t *option, char *name);
void load_music_option(music_data_t *music_data, option_t *option);
void display_cursor(window_t *win, sfSprite *cursor);

#endif /* !RPG_H_ */
