/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Music struct initialization
*/

#ifndef MUSIC_H_
#define MUSIC_H_

static const int NB_MUSIC = 11;

typedef enum mbool_e {
    false = 0,
    true = 1
} mbool;

typedef enum music_index_e {
    MUSIC = 0,
    CITY,
    ZOMBIE1,
    Z_ATK,
    Z_HIT,
    Z_DYING,
    ZOMBIE2,
    ZOMBIE3,
    GAME_OVER,
    LVL_UP,
    HEAL
} music_index;

typedef struct music_s {
    sfMusic *music;
    mbool play;
    mbool loop;
} music_t;

typedef struct music_data_s {
    music_t *music;
    mbool is_modification;
    mbool sound_mute;
    float sound_lvl;
    mbool music_mute;
    float music_lvl;
} music_data_t;

//Music function
int load_music(music_data_t *music_data);
void refresh_music(music_data_t *music_data);
void free_music(music_data_t *music_data);

#endif /* MUSIC_H_ */
