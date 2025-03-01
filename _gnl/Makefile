CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRC = 	get_next_line.c get_next_line_utils.c

		
OBJ = $(SRC:.c=.o)

NAME= gnl.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	$(RM) $(OBJ) $(NAME)

re: clean all