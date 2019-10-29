NAME = fillit
FLAG = gcc -Wall -Wextra -Werror $<
SRC = convert.c \
		enter.c \
		main.c \
		map.c \
		setup.c \
		transfer.c \
		validate.c \
		freemem.c

HEADER = header.h

all: $(NAME)

$(NAME):
	@make -C ./libft re
	@$(FLAG) $(SRC) -I $(HEADER) -L. libft/libft.a -o $(NAME)

clean:
	@make -C ./libft clean

fclean:
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean