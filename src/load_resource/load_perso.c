/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_perso
*/

#include "rpg.h"
#include "loader.h"

static const char *CIVA = "resource/character_sprite/PHC_CiviliansA.png";
static const char *CIVB = "resource/character_sprite/PHC_CiviliansB.png";
static const char *HUM1A = "resource/character_sprite/HC_Humans1A.png";
static const char *HUM1B = "resource/character_sprite/HC_Humans1B.png";
static const char *HUM3A = "resource/character_sprite/HC_Humans3A.png";
static const char *ZOM1A = "resource/character_sprite/HC_Zombies1A.png";
static const char *ZOM1B = "resource/character_sprite/HC_Zombies1B.png";
static const char *ZOM1C = "resource/character_sprite/HC_Zombies1C.png";
static const char *DEADA = "resource/character_sprite/HC_Humans1_Dead1.png";
static const char *DEADB = "resource/character_sprite/HC_Humans1_Dead2.png";
static const char *DEADC = "resource/character_sprite/HC_Humans2_Dead1.png";

static int load_sprite_pack1(perso_texture_t *perso)
{
    if (load_img(&perso->hum_1a, HUM1A, 192, 256) == ERROR)
        return (ERROR);
    if (load_img(&perso->hum_1b, HUM1B, 192, 256) == ERROR)
        return (ERROR);
    if (load_img(&perso->zomb_1a, ZOM1A, 240, 256) == ERROR)
        return (ERROR);
    if (load_img(&perso->zomb_1b, ZOM1B, 240, 256) == ERROR)
        return (ERROR);
    if (load_img(&perso->zomb_1c, ZOM1C, 240, 256) == ERROR)
        return (ERROR);
    if (load_img(&perso->dead_zomb_1a, DEADA, 384, 128) == ERROR)
        return (ERROR);
    if (load_img(&perso->dead_zomb_1b, DEADB, 384, 128) == ERROR)
        return (ERROR);
    if (load_img(&perso->dead_zomb_1c, DEADC, 384, 128) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

static int load_sprite_pack3(perso_texture_t *perso)
{
    if (load_img(&perso->hum_3a, HUM3A, 192, 256) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int load_perso(perso_texture_t *perso)
{
    if (load_img(&perso->civ_a, CIVA, 192, 256) == ERROR)
        return (ERROR);
    if (load_img(&perso->civ_b, CIVB, 192, 256) == ERROR)
        return (ERROR);
    if (load_sprite_pack1(perso) == ERROR)
        return (ERROR);
    if (load_sprite_pack3(perso) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
