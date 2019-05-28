/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** save_key
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "option.h"
#include "tool.h"

static int save_key_in_file(control_menu_t *menu)
{
    int fd = open(KEY_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (void)menu;
    if (fd < 0) {
        mputerror("Error: key file can't be open\n");
        return (ERROR);
    }
    for (int i = 0 ; i < NB_CONTROL ; i++) {
        fputstr(CONTROL_NAME[i], fd);
        fputstr(":", fd);
        fputnbr(menu->key_code[i], fd);
        fputstr("\n", fd);
    }
    mputstr("New key save!\n");
    close(fd);
    return (SUCCESS);
}

int save_key(control_menu_t *menu)
{
    if (save_key_in_file(menu) == ERROR)
        return (ERROR);
    from_array_to_key(&menu->option->key, menu->key_code);
    return (SUCCESS);
}