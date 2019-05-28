/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** tool
*/

#ifndef TOOL_H_
#define TOOL_H_

#include "rpg.h"

//Basic lib function
int mstrlen(char *str);
int mputchar(char c);
int mputstr(char *str);
int my_strcomp_env(char const *str, char const *str_comp);
int mputerror(char *str);
char *mstrcat(char const *str1, char const *str2);
int fputstr(const char *str, int fd);
void fputnbr(int nb, int fd);
char *my_strcpy(char *str);
int mgetnbr(char *nb);
char **str_to_word_array(char *str);


//Initialisator
sfIntRect ini_rect(int x, int y, int width, int height);
sfVector2f ini_vector(float fact_x, float fact_y);
sfVector2i ini_vectori(int x, int  y);
sfColor ini_color(int r, int g, int b, int a);
sfRectangleShape *ini_rectangle(int width, int height);
perso_t ini_perso(sfTexture *texture, int x, int y);
char **marg(char *str);
void set_origin_text(sfText *text);
/*
Create a sprite with the texture given as arguement
change pos and scale of the sprite with the arg
and if c == 1 the sprite is center
*/
sfSprite *set_sprite(my_texture_t texture, sfVector2f pos, float scale, int c);

//Convertor
float time_to_second(sfClock *clock);
char *mitoa(int nbr);

//Rect
void scale_rect(sfFloatRect *rect, float scale);
void move_rect(sfIntRect *rect, int offset, int max_value);

//Button tools
/*
Create a new button
*/
button_t create_button(my_texture_t bg, const char *str, sfFont *font, int f);
/*
Change pos of the button
*/
void change_button_pos(button_t *button, sfVector2f pos);
void display_button(sfRenderWindow *win, button_t button);
/*
Change the scale of the button if the button is over with the mouse and play
the sound givent as arg
*/
int button_is_over(window_t win, button_t *button);
void free_button(button_t button);
/*
Change button default scale and max scale when it over by mouse
*/
int button_is_click(window_t win, button_t *button, sfVector2i pos);

/*
Create a checkbox
*/
checkbox_t create_chbox(my_texture_t bg, char *str, sfFont *f, sfVector2f p);
void display_checkbox(sfRenderWindow *win, checkbox_t box);
void checkbox_is_over(window_t win, checkbox_t *box);
void checkbox_update(checkbox_t *box, int new_value);
int checkbox_is_click(window_t win, checkbox_t*box, sfVector2i pos);

//slider
slider_t create_slider(ui_texture_t t, sfVector2f pos, int value);
void display_slider(sfRenderWindow *win, slider_t slider);
void move_slider(window_t win, slider_t *slider);
void change_button_txt(button_t *button, const char *str);

/*
Convert game_key_t to an array of key code
*/
int from_key_to_array(game_key_t key, sfKeyCode *array);
/*
Convert an array of key code into game_key_t struct
*/
int from_array_to_key(game_key_t *key, sfKeyCode *array);

//Make percent
int make_percent(unsigned int actual, unsigned int total);
int reverse_percent(unsigned int percent, unsigned int total);

#endif /* !TOOL_H_ */
