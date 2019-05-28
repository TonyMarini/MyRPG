/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_option
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "option.h"
#include "tool.h"

static void save_sound(option_t option, int fd)
{
    fputstr("SOUND_VOL:", fd);
    fputnbr(option.sound_lvl, fd);
    fputstr("\nSOUND_MUTE:", fd);
    fputnbr(option.sound_mute, fd);
    fputstr("\nMUSIC_VOL:", fd);
    fputnbr(option.music_lvl, fd);
    fputstr("\nMUSIC_MUTE:", fd);
    fputnbr(option.music_mute, fd);
}

static int save_struct(option_menu_t data)
{
    int fd = open(OPTION_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
        return (ERROR);
    save_sound(*data.option, fd);
    fputstr("\nWINDOW_SIZE:", fd);
    fputnbr(data.option->select_size, fd);
    fputstr("\nFULL_SCREEN:", fd);
    fputnbr(data.option->fullscreen, fd);
    close(fd);
    return (SUCCESS);
}

int save_option(option_menu_t *data)
{
    if (save_struct(*data) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int restore_option(window_t *win, option_menu_t *data)
{
    option_t temp = data->save_option;

    change_window_size(win, data->option, temp.select_size, temp.fullscreen);
    data->save_option.key = data->option->key;
    *(data->option) = data->save_option;
    load_music_option(data->music, &data->save_option);
    return (SUCCESS);
}
