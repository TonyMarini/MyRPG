/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main
*/

#include "rpg.h"

int main(int argc, char **argv, char **envp)
{
    if (check_env(argc, argv, envp) == SUCCESS)
        return (rpg());
    else
        return (ERROR);
}