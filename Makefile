##
## EPITECH PROJECT, 2019
## CPool_d01
## File description:
## exo00
##

SRC		=	src/main.cpp	\
			src/error.cpp	\
			src/Arcade.cpp	\
			src/Loader.cpp	\




LIBSRC_SFML	=	lib/lib_SFML/sfml.cpp \
				src/Arcade.cpp	\
				src/Loader.cpp	\

LIBOBJ_SFML	=	sfml.o Arcade.o Loader.o
LIB_SFML	=	lib_arcade_SFML.so
SFMLFLAGS	=   -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -lm -g3#-lc_graph_prog 


LIBSRC_ALLEGRO	=	lib//lib_ALLEGRO/allegro.cpp \
					src/Arcade.cpp	\
					src/Loader.cpp	\


LIBOBJ_ALLEGRO	=	allegro.o Arcade.o  Loader.o
LIB_ALLEGRO		=	lib_arcade_ALLEGRO.so
ALLEGROFLAGS	=   -g3 `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`


LIBSRC_NCURSE	=	lib/lib_NCURSE/ncurse.cpp \
					src/Arcade.cpp	\
					src/Loader.cpp	\
					
LIBOBJ_NCURSE	=	ncurse.o Arcade.o Loader.o
LIB_NCURSE		=	lib_arcade_NCURSE.so
NCURSEFLAGS		=   -lm -lncurses



LIBSRC_NIBBLER	=	games/lib_NIBBLER/nibbler.cpp \
					src/Arcade.cpp	\
					src/Loader.cpp	\

LIBOBJ_NIBBLER	=	nibbler.o Arcade.o Loader.o
LIB_NIBBLER		=	lib_arcade_nibbler.so



LIBSRC_SOLARFOX	=	games/lib_SOLARFOX/solarfox.cpp \
					src/Arcade.cpp	\
					src/Loader.cpp	\

LIBOBJ_SOLARFOX	=	solarfox.o Arcade.o Loader.o
LIB_SOLARFOX	=	lib_arcade_solarfox.so



$(LIB_SFML):
		$(CC) -c $(LIBSRC_SFML) -fpic $(SFMLFLAGS)
		$(CC) -shared -o $(LIB_SFML) $(LIBOBJ_SFML) $(SFMLFLAGS)
		mv $(LIB_SFML) ./lib


$(LIB_ALLEGRO):
		$(CC) -c $(LIBSRC_ALLEGRO) -fpic $(ALLEGROFLAGS)
		$(CC) -shared -o $(LIB_ALLEGRO) $(LIBOBJ_ALLEGRO) $(ALLEGROFLAGS)
		mv $(LIB_ALLEGRO) ./lib


$(LIB_NCURSE):
		$(CC) -c $(LIBSRC_NCURSE) -fpic  $(NCURSEFLAGS)
		$(CC) -shared -o $(LIB_NCURSE) $(LIBOBJ_NCURSE) $(NCURSEFLAGS)
		mv $(LIB_NCURSE) ./lib


$(LIB_NIBBLER):
		$(CC) -c $(LIBSRC_NIBBLER) -fpic 
		$(CC) -shared -o $(LIB_NIBBLER) $(LIBOBJ_NIBBLER)
		mv $(LIB_NIBBLER) ./games

$(LIB_SOLARFOX):
		$(CC) -c $(LIBSRC_SOLARFOX) -fpic 
		$(CC) -shared -o $(LIB_SOLARFOX) $(LIBOBJ_SOLARFOX)
		mv $(LIB_SOLARFOX) ./games

CC		=	g++
CFLAGS  =	-ldl -Wall -Wextra -Werror -std=c++14 -I -g3
NAME	=	arcade

$(NAME):
		$(CC) $(SRC) -o $(NAME) $(CFLAGS)  $(ALLEGROFLAGS)


core:	$(NAME) 

games:  $(LIB_NIBBLER) $(LIB_SOLARFOX)

graphicals: $(LIB_SFML) $(LIB_ALLEGRO) $(LIB_NCURSE)


all:		core games graphicals

clean:
		rm -f $(LIBOBJ_SFML)
		rm -f $(LIBOBJ_NCURSE)
		rm -f $(LIBOBJ_ALLEGRO)
		rm -f $(LIBOBJ_NIBBLER)
		rm -f $(LIBOBJ_SOLARFOX)

fclean:	 clean
		rm -f ./games/lib_arcade_nibbler.so
		rm -f $(NAME)
		rm -f ./lib/$(LIB_SFML)
		rm -f ./lib/$(LIB_NCURSE)
		rm -f ./lib/$(LIB_ALLEGRO)
		rm -f ./games/$(LIB_NIBBLER)
		rm -f ./games/$(LIB_SOLARFOX)

re:		fclean all
