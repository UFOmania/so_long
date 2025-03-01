CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
AR = ar rcs
RM = rm -f

LIBFT = _libft/libft.a
GNL = _gnl/gnl.a

SRC_PATH = src
SRCB_PATH = bonus/src

SRC = 	$(SRC_PATH)/so_long.c\
		$(SRC_PATH)/map.c\
		$(SRC_PATH)/map_utils.c\
		$(SRC_PATH)/update.c\
		$(SRC_PATH)/sprite.c\
		$(SRC_PATH)/move.c\
		$(SRC_PATH)/clear.c\

SRCB = 	$(SRCB_PATH)/so_long_bonus.c\
		$(SRCB_PATH)/map.c\
		$(SRCB_PATH)/map_utils.c\
		$(SRCB_PATH)/update.c\
		$(SRCB_PATH)/sprite.c\
		$(SRCB_PATH)/sprite_utils.c\
		$(SRCB_PATH)/move.c\
		$(SRCB_PATH)/clear.c\
		$(SRCB_PATH)/enemy.c\
		
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

NAME = so_long
NAMEB = so_long_bonus

all: libft gnl $(NAME)

bonus: libft gnl $(NAMEB)

libft:
	make -C _libft/

gnl:
	make -C _gnl/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(GNL) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAMEB):  $(OBJB)
	$(CC) $(CFLAGS) $(GNL) $(LIBFT) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAMEB) 

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c includes/so_long.h includes/map.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCB_PATH)/%.o: $(SRCB_PATH)/%.c bonus/includes/so_long_bonus.h bonus/includes/map.h  bonus/includes/sprite.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	make clean -C _libft
	make clean -C _gnl
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(NAMEB)

re: fclean all

.PHONY: libft gnl clean
