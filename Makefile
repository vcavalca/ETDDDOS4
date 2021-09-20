NAME = App

CC = clang
CFLAGS = -c -Wall -Werror -Wextra

SRCS = srcs/ft_main.c srcs/ft_mysql_conection.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -o $(NAME) `mysql_config --cflags --libs`
		@echo "Successfully compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf $(OBJ)
	@echo "$(OBJ) was erased!"

fclean: clean
		@rm -rf $(NAME)
		@echo "$(NAME) was erased!"

re: fclean all