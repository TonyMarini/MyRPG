/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_ui
*/

#include "rpg.h"
#include "loader.h"

static const char *IMG_SOUND_BAR = "resource/ui/sound_bar.png";
static const char *IMG_SOUND_LVL = "resource/ui/sound_lvl_indicator.png";
static const char *IMG_SOUND_SLIDER = "resource/ui/sound_slider.png";
static const char *IMG_BG_OPTION = "resource/ui/bg_option.png";
static const char *IMG_SPELL_BAR = "resource/ui/spell_bar.png";
static const char *IMG_INVENTORY = "resource/ui/inventory.png";
static const char *IMG_INFO_BOX = "resource/ui/info_box.png";
static const char *IMG_BG_MENU = "resource/ui/bg_menu_image.png";
static const char *IMG_OPTION = "resource/ui/bg_option_image.png";
static const char *IMG_LIFE_ZOMBY = "resource/ui/zombie_bar.png";
static const char *IMG_GAME_OVER = "resource/ui/game_over.png";
static const char *IMG_FR_INV = "resource/ui/front_inventory.png";
static const char *IMG_BG_INV = "resource/ui/bg_inventory.png";
static const char *IMG_LIFE = "resource/ui/life.png";
static const char *IMG_BG_STAT = "resource/ui/bg_stats.png";
static const char *IMG_BUTTON3 = "resource/ui/button3.png";
static const char *IMG_END_GAME = "resource/ui/end_game.png";

static int load_ui_texture3(ui_texture_t *ui)
{
    if (load_img(&ui->bg_info_item, IMG_INFO_BOX, 192, 128) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_menu_image, IMG_BG_MENU, 1920, 1080) == ERROR)
        return (ERROR);
    if (load_img(&ui->zombie_life, IMG_LIFE_ZOMBY, 16, 24) == ERROR)
        return (ERROR);
    if (load_img(&ui->life, IMG_LIFE, 16, 24) == ERROR)
        return (ERROR);
    if (load_img(&ui->game_over, IMG_GAME_OVER, 1920, 1080) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_stat, IMG_BG_STAT, 336, 336) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_inventory, IMG_BG_INV, 898, 491) == ERROR)
        return (ERROR);
    if (load_img(&ui->fr_inventory, IMG_FR_INV, 513, 128) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_option_image, IMG_OPTION, 1920, 1080) == ERROR)
        return (ERROR);
    if (load_img(&ui->end_screen, IMG_END_GAME, 1920, 1080) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int load_ui_texture2(ui_texture_t *ui)
{
    if (load_img(&ui->sound_lvl_indi, IMG_SOUND_LVL, 16, 24) == ERROR)
        return (ERROR);
    if (load_img(&ui->sound_slider, IMG_SOUND_SLIDER, 16, 32) == ERROR)
        return (ERROR);
    if (load_img(&ui->button3, IMG_BUTTON3, 144, 51) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_option, IMG_BG_OPTION, 144, 51) == ERROR)
        return (ERROR);
    if (load_img(&ui->spell, "resource/ui/spell.png", 102, 102) == ERROR)
        return (ERROR);
    if (load_img(&ui->spell_bar, IMG_SPELL_BAR, 660, 120) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_menu, "resource/ui/bg_menu.png", 320, 384) == ERROR)
        return (ERROR);
    if (load_img(&ui->inventory, IMG_INVENTORY, 336, 336) == ERROR)
        return (ERROR);
    if (load_ui_texture3(ui) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int load_ui_texture(ui_texture_t *ui)
{
    if (load_img(&ui->button, "resource/ui/button.png", 244, 56) == ERROR)
        return (ERROR);
    if (load_img(&ui->title, "resource/ui/title.png", 812, 426) == ERROR)
        return (ERROR);
    if (load_img(&ui->button2, "resource/ui/button2.png", 240, 52) == ERROR)
        return (ERROR);
    if (load_img(&ui->selector, "resource/ui/selector.png", 28, 28) == ERROR)
        return (ERROR);
    if (load_img(&ui->checkbox, "resource/ui/checkbox.png", 28, 28) == ERROR)
        return (ERROR);
    if (load_img(&ui->dialogue, "resource/ui/dialogue.png", 376, 128) == ERROR)
        return (ERROR);
    if (load_img(&ui->sound_bar, IMG_SOUND_BAR, 196, 40) == ERROR)
        return (ERROR);
    if (load_img(&ui->bg_item, "resource/ui/bg_item.png", 80, 109) == ERROR)
        return (ERROR);
    if (load_img(&ui->info_key, "resource/ui/info_key.png", 66, 44) == ERROR)
        return (ERROR);
    return (load_ui_texture2(ui));
}
