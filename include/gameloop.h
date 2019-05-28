/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** gameloop
*/

#ifndef GAMELOOP_H_
#define GAMELOOP_H_

#include <stdio.h>
#include "rpg.h"
#include "tool.h"

static const float TURN_TIME = 0.5;

typedef struct map_sprite_s {
    sfSprite *sprite;
} map_sprite_t;

//Use is_fighting to know which zombie is in battle
typedef struct zombie_s {
    sfSprite *sprite;
    sfSprite *life_bar;
    sfSprite *live;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f move;
    sfVector2i pos;
    int is_fighting;
    float dificulty;
    int scale;
    int skin_x;
    int skin_y;
    char *direction;
    int index;
    int alive;
    stat_t stat;
    sfTexture *dead_texture;
} zombie_t;

typedef struct pnj_s {
    sfSprite *sprite;
    sfSprite *dial_box;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2i pos_tab;
    sfText *text_start;
    sfText *text_end;
    int mission;
    int item_req;
    int item_reward;
} pnj_t;

//type 0: Avatar
//type 1: Pnj
//type 2: Zombie
typedef struct interaction_s {
    int type;
    char map_spawn;
    char *link_map;
    char link_dir;
} interaction_t;

typedef struct loot_s {
    sfVector2f pos;
    sfVector2f pos_item;
    sfVector2i pos_tab;
    int status;
    int nb_bullet;
    int nb_item;
    sfClock *clock;
    sfSprite *cadre;
    sfSprite *cadre_obj;
    sfIntRect rect_cadre;
} loot_t;

typedef struct obj_s {
    perso_t perso;
    zombie_t *zombie;
    pnj_t *pnj;
    loot_t *loot;
    int nb_zombie;
    int nb_pnj;
    int nb_loot;
    interaction_t **obj_map;
    int is_outdoor;
} obj_t;

typedef struct map_data_s {
    map_sprite_t **layer0;
    map_sprite_t **layer1;
    map_sprite_t **layer2;
    map_sprite_t **layer3;
    map_sprite_t **layer4;
    map_sprite_t **layer5;
    obj_t obj;
    int w;
    int h;
} map_data_t;

typedef struct hud_s {
    sfSprite *profil;
    sfSprite *box;
    sfSprite *life;
    sfSprite *exp;
    sfText *name;
} hud_t;

typedef struct in_game_menu_s {
    button_t resume_button;
    button_t option_button;
    button_t quit_button;
    sfSprite *bg;
} in_game_menu_t;

typedef struct stat_text_s {
    sfText *title;
    sfText *act;
    sfText *max;
} stat_text_t;

typedef struct battle_s {
    int status_battle;
    int zombie;
    char dir;
    sfSprite *spell_sprite;
    button_t spell_button[6];
    sfSprite *content_sprite[6];
    int anim;
    sfClock *anim_clock;
    int blood_particule;
    int health_particule;
} battle_t;

typedef struct inventory_s {
    sfSprite *cadre;
    sfSprite *life_icon;
    sfSprite *xp_icon;
    sfSprite *ammo_icon;
    sfSprite *cadre_inven;
    sfSprite *inventory_sprite[9];
    button_t bg_inventory[9];
    sfFont *font;
    stat_text_t life;
    stat_text_t xp;
    stat_text_t ammo;
    stat_text_t level;
    int inventory_content[9];
    int spell_content[6];
    int drag_item;
    sfSprite *drag_sprite;
    sfSprite *item_stat;
    int display_info;
    char *description;
    sfText *txt_descript;
    sfText *item_name;
    sfSprite *bg_inv;
    sfSprite *fr_inv;
    sfText *name;
    int nb_level;
} inventory_t;

typedef struct particule_s {
    sfVector2f speed;
    sfColor color;
    sfSprite *sprite;
    int distance;
} particule_t;

typedef struct item_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int damage;
    int heal;
    char *obj_name;
} item_t;

typedef struct get_player_s {
    sfSprite *background;
    button_t next;
    button_t prev;
    button_t back;
    button_t start;
    sfSprite *perso;
    int pos_x;
    int pos_y;
} get_player_t;

typedef struct gameloop_data_s {
    map_data_t map;
    item_t item[13];
    hud_t hud;
    sfClock *anim_clock;
    battle_t battle;
    resource_t *resource;
    option_t *option;
    inventory_t inventory;
    particule_t *player_particule;
    particule_t *blood_particule;
    particule_t *ash_particule;
    particule_t *health_particule;
    char *name;
} gameloop_data_t;

//Init
int init_gameloop(window_t *w, gameloop_data_t *d, resource_t *r, char *name);
int init_sprite_battle(gameloop_data_t *data, window_t *win);
void init_item(gameloop_data_t *data);

//Event
int move_perso(game_key_t key, perso_t *perso, map_data_t *map);

//Display
int display(window_t *win, gameloop_data_t *game_data);
int display_no_clear(window_t *win, gameloop_data_t *game_data);
void display_avatar(window_t win, obj_t *obj);
int display_map_layer(window_t *win, map_sprite_t **map, int w, int h);
void display_obj(window_t win, obj_t *obj);
void display_hud(window_t *win, hud_t hud);
void display_particule(window_t *win, gameloop_data_t *particule);
int display_battle(window_t *win, gameloop_data_t *data);
void display_spell(window_t *win, gameloop_data_t *data);
void display_loot(window_t *win, gameloop_data_t *data);
void display_mission(window_t *win, gameloop_data_t *data);
void display_ash_particule(window_t *win, gameloop_data_t *data);
void display_blood_particule(window_t *win, gameloop_data_t *data);

//Map
map_sprite_t **load_layer(char *path, sfTexture **texture, int *w, int *h);
int load_map(resource_t *resource, char *map_path, map_data_t *map_data);
int change_map(window_t *w, perso_t *perso, gameloop_data_t *data);
int map_transition(window_t *w, map_data_t *old, map_data_t *n, sfVector2f d);
void move_map_layer(map_sprite_t **map, int w, int h, sfVector2f pos);

//Anim
int anim_perso(perso_t *perso);
int anim_gameloop(gameloop_data_t *data);
void move_rect_zombie(zombie_t *zombie);
void move_rect_zombie_two(zombie_t *zombie);
void anim_loot(gameloop_data_t *data);

//Move
void move_zombie(int nb_zombie, zombie_t *zombie);

//Battle
int battle(gameloop_data_t *data, window_t *win);
void is_battle(battle_t *battle, obj_t *obj);
int key_press_battle(sfKeyEvent key, window_t *win, gameloop_data_t *d,
    int *status);
int click_spell_attack(sfMouseButtonEvent m, window_t *w, gameloop_data_t *d);
void spawn_zombie(char dir, zombie_t *zombie);
void spawn_battle_player(char dir, perso_t *perso);
void to_dead_zombie(zombie_t *zombie);
void remove_life(gameloop_data_t *data);
void remove_life_zombie(zombie_t *zombie);
void add_life(gameloop_data_t *data);
void xp(gameloop_data_t *data);
int handle_evt(window_t *win, gameloop_data_t *data, int turn, int *status);
void loop_battle(gameloop_data_t *data, window_t *win, int *status);

//Event
int manage_event(window_t *window, gameloop_data_t *game_data);
void get_loot(gameloop_data_t *data);

//Particule
void move_particule(gameloop_data_t *data);
void setpos_blood_particule(gameloop_data_t *data, sfVector2f pos);
void move_blood_particule(particule_t *particule, int nb);
void load_particule(gameloop_data_t *data, resource_t *resource);
int init_particule(particule_t **my_particule, my_texture_t texture, int nb);
void hide_particule(particule_t *particule);
void move_ash_particle(particule_t *particule);
void init_rand_pos_and_distance_particule(particule_t *particule, int distance);
void setpos_health_particule(gameloop_data_t *data, sfVector2f pos);
void display_health_particule(window_t *win, gameloop_data_t *data);

//Interaction
void load_interaction(obj_t *obj);

//Spell bar
int update_spell_bar(gameloop_data_t *data, window_t *win);

//Game Over
int game_over(window_t *win, gameloop_data_t *data);

int is_outdoor(obj_t *obj, FILE *fd);

//Character chose
void display_get_character(window_t *win, get_player_t *data, resource_t *res);
int get_character(window_t *win, resource_t *resource, sfVector2i *perso);
int get_char_event(window_t *window, get_player_t *game_data);
int init_get_character(resource_t *r, get_player_t *data, sfVector2i p);

//End screen
void end_screen(window_t *win, gameloop_data_t *data);

#endif /* !GAMELOOP_H_ */
