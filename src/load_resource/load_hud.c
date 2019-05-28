/*
** EPITECH PROJECT, 2019
** Rpg
** File description:
** Load the HUD
*/

#include "gameloop.h"

static const char *PROFIL = "resource/ui/profile.png";
static const char *BOX = "resource/ui/box.png";
static const char *LIFE = "resource/ui/life.png";
static const char *EXP = "resource/ui/exp.png";
static const char *FONT = "resource/font/VCR.ttf";

static int create_sprite(hud_t *hud)
{
    sfTexture *profil = sfTexture_createFromFile(PROFIL, NULL);
    sfTexture *box = sfTexture_createFromFile(BOX, NULL);
    sfTexture *life = sfTexture_createFromFile(LIFE, NULL);
    sfTexture *exp = sfTexture_createFromFile(EXP, NULL);

    if (!profil || !box || !life || !exp)
        return (ERROR);
    hud->profil = sfSprite_create();
    hud->box = sfSprite_create();
    hud->life = sfSprite_create();
    hud->exp = sfSprite_create();
    if (!hud->profil || !hud->box || !hud->life || !hud->exp)
        return (ERROR);
    sfSprite_setTexture(hud->profil, profil, sfFalse);
    sfSprite_setTexture(hud->box, box, sfFalse);
    sfSprite_setTexture(hud->life, life, sfFalse);
    sfSprite_setTexture(hud->exp, exp, sfFalse);
    return (SUCCESS);
}

static void set_hud_sprite(hud_t *hud)
{
    sfSprite_setScale(hud->profil, ini_vector(2.25, 2.25));
    sfSprite_setScale(hud->box, ini_vector(2.25, 2.25));
    sfSprite_setScale(hud->life, ini_vector(225, 2.25));
    sfSprite_setScale(hud->exp, ini_vector(0, 2.25));
    sfSprite_setPosition(hud->profil, ini_vector(41, 38));
    sfSprite_setPosition(hud->box, ini_vector(20, 20));
    sfSprite_setPosition(hud->life, ini_vector(173, 31));
    sfSprite_setPosition(hud->exp, ini_vector(173, 76));
}

static int create_set_text(hud_t *hud, char *name)
{
    sfFont *font = sfFont_createFromFile(FONT);

    hud->name = sfText_create();
    if (!hud->name || !font)
        return (ERROR);
    sfText_setString(hud->name, name);
    sfText_setFont(hud->name, font);
    sfText_setCharacterSize(hud->name, 25);
    sfText_setPosition(hud->name, ini_vector(275, 138));
    set_origin_text(hud->name);
    return (SUCCESS);
}

int load_hud(hud_t *hud, char *name)
{
    if (create_sprite(hud) == ERROR)
        return (ERROR);
    set_hud_sprite(hud);
    if (create_set_text(hud, name) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
