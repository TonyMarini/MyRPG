/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_strcmp
*/

int my_strcomp_env(char const *str, char const *str_comp)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] != str_comp[i])
            return (-1);
    return (1);
}