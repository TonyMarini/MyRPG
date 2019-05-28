##
## EPITECH PROJECT, 2018
## MUL_my_rpg_2018 | Makefile
## File description:
## Makefile
##

SRC	=	src/main.c						\
		src/rpg.c						\
		src/check_env.c						\
		src/cursor.c						\
		src/init/init_window.c 					\
		src/init/init_setting.c					\
		src/init/load_setting.c					\
		src/main_menu/start_menu/start_menu.c			\
		src/main_menu/start_menu/start_menu_event.c		\
		src/main_menu/start_menu/steam_particule.c		\
		src/main_menu/start_menu/how_to_play.c			\
		src/main_menu/start_menu/enter_name.c			\
		src/main_menu/start_menu/event_enter_name.c		\
		src/main_menu/menu_in_game/menu_in_game.c		\
		src/main_menu/menu_in_game/menu_in_game_event.c		\
		src/main_menu/inventory/inventory.c			\
		src/main_menu/inventory/inventory_event.c		\
		src/main_menu/inventory/init_inventory.c		\
		src/main_menu/inventory/init_item_inv.c			\
		src/main_menu/inventory/display_inventory.c		\
		src/main_menu/inventory/drag_item.c			\
		src/main_menu/inventory/init_inventory2.c		\
		src/main_menu/inventory/item_info.c			\
		src/main_menu/inventory/use_item.c			\
		src/music/load_music.c					\
		src/music/refresh_music.c				\
		src/music/free_music.c					\
		src/music/load_music_option.c				\
		src/music/launch_zombie_ambiant.c			\
		src/load_resource/load_resource.c			\
		src/load_resource/load_map_texture.c			\
		src/load_resource/load_hud.c				\
		src/load_resource/load_ui.c				\
		src/load_resource/load_perso.c				\
		src/load_resource/load_item.c				\
		src/gameloop/gameloop.c					\
		src/gameloop/init_sprite_battle.c			\
		src/gameloop/gameloop_event.c				\
		src/gameloop/load_interaction.c				\
		src/gameloop/is_battle.c				\
		src/gameloop/particule.c				\
		src/gameloop/ash_particule.c				\
		src/gameloop/map/load_map.c				\
		src/gameloop/map/load_layer.c				\
		src/gameloop/map/change_map.c				\
		src/gameloop/map/map_transition.c			\
		src/gameloop/map/move_map.c				\
		src/gameloop/init_gameloop.c				\
		src/gameloop/display/display.c				\
		src/gameloop/display/display_avatar.c			\
		src/gameloop/display/display_map.c			\
		src/gameloop/display/display_hud.c			\
		src/gameloop/display/display_zombie.c			\
		src/gameloop/display/display_mission.c			\
		src/gameloop/display/display_particule.c		\
		src/gameloop/event/move_perso.c				\
		src/gameloop/anim/anim.c				\
		src/gameloop/anim/anim_perso.c				\
		src/gameloop/anim/anim_zombie.c				\
		src/gameloop/anim/anim_loot.c				\
		src/gameloop/battle/battle.c				\
		src/gameloop/battle/spell_bar.c				\
		src/gameloop/battle/action_battle.c			\
		src/gameloop/battle/spawn_battle.c			\
		src/gameloop/battle/dead_zombie.c			\
		src/gameloop/battle/life.c				\
		src/gameloop/battle/life_zombie.c			\
		src/gameloop/battle/xp.c				\
		src/gameloop/battle/battle_event.c			\
		src/gameloop/battle/loop_battle.c			\
		src/gameloop/init_item.c				\
		src/gameloop/load_obj.c					\
		src/gameloop/load_obj2.c				\
		src/gameloop/load_loot.c				\
		src/gameloop/load_zombie.c				\
		src/gameloop/load_life_zombie.c				\
		src/gameloop/load_pnj.c					\
		src/gameloop/load_link.c				\
		src/gameloop/move_zombie.c				\
		src/gameloop/percent.c					\
		src/gameloop/loot/check_loot.c				\
		src/gameloop/blood_particule.c				\
		src/gameloop/game_over.c				\
		src/gameloop/end_screen.c				\
		src/gameloop/get_character/get_character.c		\
		src/gameloop/get_character/display_get_char.c		\
		src/gameloop/get_character/get_char_event.c		\
		src/gameloop/get_character/init_get_char.c		\
		src/option/option_menu.c				\
		src/option/option_menu_event.c				\
		src/option/init_option.c				\
		src/option/change_window_size.c				\
		src/option/size_button_event.c				\
		src/option/sound_button_event.c				\
		src/option/save_option.c				\
		src/option/control/control_menu.c			\
		src/option/control/init_control_menu.c			\
		src/option/control/control_event.c			\
		src/option/control/change_key_event.c			\
		src/option/control/keymap_event.c			\
		src/option/control/save_key.c				\
		src/tool/ini_color.c					\
		src/tool/ini_rectangle.c				\
		src/tool/ini_rect.c					\
		src/tool/ini_vector.c					\
		src/tool/mstrlen.c					\
		src/tool/mputstr.c					\
		src/tool/time_to_second.c				\
		src/tool/mitoa.c					\
		src/tool/mstrcat.c					\
		src/tool/set_origin_text.c				\
		src/tool/my_strcmp.c					\
		src/tool/button.c					\
		src/tool/button2.c					\
		src/tool/scale_rect.c					\
		src/tool/ini_perso.c					\
		src/tool/move_rect.c					\
		src/tool/marg.c						\
		src/tool/create_sprite.c				\
		src/tool/checkbox.c					\
		src/tool/slider.c					\
		src/tool/convert_key.c					\
		src/tool/mputnbr.c					\
		src/tool/str_to_word_array.c				\
		src/tool/my_strcpy.c					\
		src/tool/mgetnbr.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS = -I./include

CFLAGS	=	-lm -g -Wextra -Wall -Werror

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -lm -o $(NAME) $(CFLAGS) $(CSFML) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
