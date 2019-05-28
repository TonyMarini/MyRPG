/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_ev
*/

#include "rpg.h"
#include "tool.h"
#include <unistd.h>

int check_env(int argc, char **argv, char **envp)
{
    (void)argv;
    if (argc != 1)
        return (ERROR);
    if (!envp)
        return (ERROR);
    for (int i = 0; envp[i] != NULL; i++)
        if (my_strcomp_env("DISPLAY", envp[i]) == 1)
            return (SUCCESS);
    write(2, "Check if DISPLAY exist in your env!\n", 36);
    return (ERROR);
}