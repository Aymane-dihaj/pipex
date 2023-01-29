NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC = pipex.c utils.c process.c

OBJ = $(SRC:.c=.o)

.SILENT:

all: libfta $(NAME)
	echo "\x1b[42mThe program was built successfully\033[0m"

libfta:
	$(MAKE) -C libft

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -L./libft -lft -o $(NAME)

clean:
	rm -rf $(OBJ)
	echo "\x1b[41mObject files are cleaned.\033[0m\n"

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)
	echo "\x1b[41mExecutable file cleaned.\033[0m"

re: fclean all