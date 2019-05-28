/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_map_texture
*/

#include <stdlib.h>
#include "rpg.h"

static const char *TILE_A = "resource/map_resource/A_Exterior-Floor.png";
static const char *TILE_B = "resource/map_resource/B_Exterior-Floor-Wall.png";
static const char *TILE_C = "resource/map_resource/C_Exterior-Wall.png";
static const char *TILE_D = "resource/map_resource/D_Exterior-Wall.png";
static const char *TILE_E = "resource/map_resource/E_Exterior-Roof-Window.png";
static const char *TILE_F = "resource/map_resource/F_Exterior-Floor-Window.png";
static const char *TILE_G = "resource/map_resource/G_Exterior-Window-Door.png";
static const char *TILE_H = "resource/map_resource/H_Exterior-Floor-Nature.png";
static const char *TILE_I = "resource/map_resource/I_Exterior-Extra.png";
static const char *TILE_J = "resource/map_resource/J_Exterior-Extra.png";
static const char *TILE_K = "resource/map_resource/K_Exterior-Nature.png";
static const char *TILE_L = "resource/map_resource/L_Water.png";
static const char *TILE_M = "resource/map_resource/M_Interior-Floor-Wall.png";
static const char *TILE_N = "resource/map_resource/N_Interior-Wall.png";
static const char *TILE_O = "resource/map_resource/O_Interior-Wall.png";
static const char *TILE_P = "resource/map_resource/P_Interior-Wall.png";
static const char *TILE_Q = "resource/map_resource/Q_Interior-Extras.png";
static const char *TILE_R = "resource/map_resource/R_Interior-Extra.png";
static const char *TILE_S = "resource/map_resource/S_Interior-Extra.png";
static const char *TILE_T = "resource/map_resource/T_Interior-Extra.png";
static const char *TILE_U = "resource/map_resource/U_Interior-Extra.png";
static const char *TILE_V = "resource/map_resource/V_Exterior-Floor-Winter.png";
static const char *TILE_W = "resource/map_resource/W_Exterior-Floor-Winter.png";
static const char *TILE_X = "resource/map_resource/X_Winter-Extra.png";

static int fill_tiles_a_to_j(sfTexture ***tiles)
{
    (*tiles)[0] = sfTexture_createFromFile(TILE_A, NULL);
    (*tiles)[1] = sfTexture_createFromFile(TILE_B, NULL);
    (*tiles)[2] = sfTexture_createFromFile(TILE_C, NULL);
    (*tiles)[3] = sfTexture_createFromFile(TILE_D, NULL);
    (*tiles)[4] = sfTexture_createFromFile(TILE_E, NULL);
    (*tiles)[5] = sfTexture_createFromFile(TILE_F, NULL);
    (*tiles)[6] = sfTexture_createFromFile(TILE_G, NULL);
    (*tiles)[7] = sfTexture_createFromFile(TILE_H, NULL);
    (*tiles)[8] = sfTexture_createFromFile(TILE_I, NULL);
    (*tiles)[9] = sfTexture_createFromFile(TILE_J, NULL);
    return (SUCCESS);
}

static int fill_tiles_k_to_t(sfTexture ***tiles)
{
    (*tiles)[10] = sfTexture_createFromFile(TILE_K, NULL);
    (*tiles)[11] = sfTexture_createFromFile(TILE_L, NULL);
    (*tiles)[12] = sfTexture_createFromFile(TILE_M, NULL);
    (*tiles)[13] = sfTexture_createFromFile(TILE_N, NULL);
    (*tiles)[14] = sfTexture_createFromFile(TILE_O, NULL);
    (*tiles)[15] = sfTexture_createFromFile(TILE_P, NULL);
    (*tiles)[16] = sfTexture_createFromFile(TILE_Q, NULL);
    (*tiles)[17] = sfTexture_createFromFile(TILE_R, NULL);
    (*tiles)[18] = sfTexture_createFromFile(TILE_S, NULL);
    (*tiles)[19] = sfTexture_createFromFile(TILE_T, NULL);
    return (SUCCESS);
}

static int fill_tiles_u_to_w(sfTexture ***tiles)
{
    (*tiles)[20] = sfTexture_createFromFile(TILE_U, NULL);
    (*tiles)[21] = sfTexture_createFromFile(TILE_V, NULL);
    (*tiles)[22] = sfTexture_createFromFile(TILE_W, NULL);
    (*tiles)[23] = sfTexture_createFromFile(TILE_X, NULL);
    return (SUCCESS);
}

int load_map_texture(sfTexture ***tiles)
{
    if ((*tiles = malloc(sizeof(*tiles) * 25)) == NULL)
        return (ERROR);
    fill_tiles_a_to_j(tiles);
    fill_tiles_k_to_t(tiles);
    fill_tiles_u_to_w(tiles);
    (*tiles)[24] = NULL;
    return (SUCCESS);
}
