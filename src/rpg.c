/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** rpg
*/

#include "rpg.h"
#include "music.h"
#include "init.h"
#include "loader.h"
#include "main_menu.h"
#include "tool.h"

int rpg(void)
{
    window_t win;
    resource_t texture;
    option_t option;

    if ((init_window(&win, 1920, 1080, 1)) == ERROR)
        return (ERROR);
    if (init_game_setting(&option, &win) == ERROR)
        return (ERROR);
    if (load_resource(win, &texture) == ERROR) {
        mputerror("Error : some resource can't be load\n");
        sfRenderWindow_close(win.win);
        return (ERROR);
    }
    if (load_music(&texture.music_data) == ERROR)
        return (ERROR);
    refresh_music(&texture.music_data);
    sfRenderWindow_setMouseCursorVisible(win.win, sfFalse);
    if (start_menu(&win, &texture, &option) == ERROR)
        return (ERROR);
    free_music(&texture.music_data);
    return (0);
}
