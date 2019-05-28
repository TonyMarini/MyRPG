/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** laod_setting
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rpg.h"
#include "tool.h"

static char **load_file(const char *filename, int max_size)
{
    char **temp = NULL;
    char *line = NULL;
    size_t len = 0;
    FILE *fd = fopen(filename, "r");

    if (fd == NULL)
        return (NULL);
    temp = malloc(sizeof(char *) * (max_size + 1));
    if (temp == NULL)
        return (NULL);
    temp[max_size] = NULL;
    for (int i = 0 ; i < max_size && getline(&line, &len, fd) != -1 ; i++)
        temp[i] = my_strcpy(line);
    free(line);
    fclose(fd);
    return (temp);
}

static int get_array_size(char **array)
{
    int size = 0;

    for ( ; array[size] ; size++);
    return (size);
}

static int get_value(int index, char **array)
{
    char **temp = str_to_word_array(array[index]);
    int nb = 0;

    if (get_array_size(temp) < 2)
        return (-1);
    nb = mgetnbr(temp[1]);
    for (int i = 0 ; temp[i] ; i++)
        free(temp[i]);
    free(temp);
    return (nb);
}

int load_option_from_file(option_t *option)
{
    char **file = NULL;

    file = load_file(OPTION_FILE, 6);
    if (file == NULL)
        return (ERROR);
    option->sound_lvl = get_value(0, file);
    option->sound_mute = get_value(1, file);
    option->music_lvl = get_value(2, file);
    option->music_mute = get_value(3, file);
    option->select_size = get_value(4, file);
    option->fullscreen = get_value(5, file);
    for (int i = 0 ; file[i] ; i++)
        free(file[i]);
    free(file);
    return (SUCCESS);
}

int load_key_from_file(option_t *option)
{
    char **file = NULL;

    file = load_file(KEY_FILE, 12);
    if (file == NULL)
        return (ERROR);
    option->key.left = get_value(0, file);
    option->key.right = get_value(1, file);
    option->key.up = get_value(2, file);
    option->key.down = get_value(3, file);
    option->key.action = get_value(4, file);
    option->key.inventory = get_value(5, file);
    option->key.spell1 = get_value(6, file);
    option->key.spell2 = get_value(7, file);
    option->key.spell3 = get_value(8, file);
    option->key.spell4 = get_value(9, file);
    option->key.spell5 = get_value(10, file);
    option->key.spell6 = get_value(11, file);
    for (int i = 0 ; file[i] ; i++)
        free(file[i]);
    free(file);
    return (SUCCESS);
}