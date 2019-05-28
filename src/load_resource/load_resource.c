/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_texture
*/

#include "rpg.h"
#include "loader.h"

static int load_mouse(resource_t *resource)
{
    if (load_img(&resource->mouse_cursor, "resource/ui/cursor.png",
            12, 17) == ERROR)
        return (ERROR);
    resource->cursor = sfSprite_create();
    sfSprite_setTexture(resource->cursor, resource->mouse_cursor.texture,
            sfTrue);
    return (SUCCESS);
}

int load_img(my_texture_t *texture, const char *path, int w, int h)
{
    texture->texture = sfTexture_createFromFile(path, NULL);
    if (texture->texture == NULL)
        return (84);
    texture->w = w;
    texture->h = h;
    return (0);
}

int load_fisrt_part(resource_t *resource)
{
    if (load_map_texture(&(resource->map_texture)) == ERROR)
        return (ERROR);
    if (load_ui_texture(&resource->ui_texture) == ERROR)
        return (ERROR);
    resource->font = sfFont_createFromFile("resource/font/VCR.ttf");
    if (resource->font == NULL)
        return (ERROR);
    if (load_perso(&resource->perso) == ERROR)
        return (ERROR);
    if (load_img(&resource->particule, "resource/particule.png", 5, 5) == 84)
        return (ERROR);
    if (load_img(&resource->blood_particule, "resource/blood_particule.png",
        5, 5) == 84)
        return (ERROR);
    if (load_img(&resource->steam_particule,
            "resource/steam_particule.png", 5, 5) == 84)
        return (ERROR);
    if (load_item(&resource->item) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int load_resource(window_t win, resource_t *resource)
{
    (void)win;
    if (load_fisrt_part(resource) == ERROR)
        return (ERROR);
    if (load_mouse(resource) == ERROR)
        return (ERROR);
    if (load_img(&resource->health_particule, "resource/health_particule.png",
        15, 15) == ERROR)
        return (ERROR);
    return (SUCCESS);
}