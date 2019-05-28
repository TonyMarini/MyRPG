/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Load the music
*/

#include <stdlib.h>
#include "gameloop.h"
#include "music.h"

static const char *CITY_C = "./resource/music/city_ambiant.ogg";
static const char *MUSIC_C = "./resource/music/music.ogg";
static const char *ZOMBIE1_C = "./resource/music/zombie1.ogg";
static const char *ZOMBIE2_C = "./resource/music/zombie2.ogg";
static const char *ZOMBIE3_C = "./resource/music/zombie3.ogg";
static const char *Z_ATK_C = "./resource/music/zombie_atk.ogg";
static const char *Z_DYING_C = "./resource/music/zombie_dying.ogg";
static const char *Z_HIT_C = "./resource/music/zombie_hit.ogg";
static const char *GAME_O = "./resource/music/game_over.ogg";
static const char *LV_UP = "./resource/music/level_up.ogg"; 
static const char *HEALING = "./resource/music/heal.ogg";

static void init_music1(music_data_t *music_data)
{
    music_data->music[0].music = sfMusic_createFromFile(MUSIC_C);
    music_data->music[0].loop = true;
    sfMusic_setLoop(music_data->music[0].music, sfTrue);
    music_data->music[1].music = sfMusic_createFromFile(CITY_C);
    music_data->music[1].loop = true;
    sfMusic_setLoop(music_data->music[1].music, sfTrue);
    music_data->music[2].music = sfMusic_createFromFile(ZOMBIE1_C);
    music_data->music[2].loop = true;
    sfMusic_setLoop(music_data->music[2].music, sfTrue);
}

static void init_music2(music_data_t *music_data)
{
    music_data->music[3].music = sfMusic_createFromFile(Z_ATK_C);
    music_data->music[4].music = sfMusic_createFromFile(Z_HIT_C);
    music_data->music[5].music = sfMusic_createFromFile(Z_DYING_C);
    music_data->music[6].music = sfMusic_createFromFile(ZOMBIE2_C);
    music_data->music[6].loop = true;
    sfMusic_setLoop(music_data->music[6].music, sfTrue);
    music_data->music[7].music = sfMusic_createFromFile(ZOMBIE3_C);
    music_data->music[7].loop = true;
    music_data->music[8].music = sfMusic_createFromFile(GAME_O);
    music_data->music[9].music = sfMusic_createFromFile(LV_UP);
    music_data->music[10].music = sfMusic_createFromFile(HEALING);
    sfMusic_setLoop(music_data->music[7].music, sfTrue);
}

static void init_music(music_data_t *music_data)
{
    for (int i = 0 ; i < NB_MUSIC ; i++) {
        music_data->music[i].play = false;
        music_data->music[i].loop = false;
    }
    init_music1(music_data);
    init_music2(music_data);
}

int load_music(music_data_t *music_data)
{
    music_data->is_modification = true;
    music_data->sound_mute = false;
    music_data->sound_lvl = 80;
    music_data->music_mute = false;
    music_data->music_lvl = 80;
    music_data->music = malloc(sizeof(music_data_t) * NB_MUSIC);
    if (!music_data->music)
        return (ERROR);
    init_music(music_data);
    return (SUCCESS);
}
