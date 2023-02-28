NAME = fdf
FILES = *c *.h
ARGS = -Wall -Wextra -Werror

$(NAME): $(FILES)
	gcc -c $(FILES)
	gcc *.o -o $(NAME)

all:
	make $(NAME)

clean:
	rm -rf *.o
	rm -rf *.gch

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

n:
	clear
	norminette -R CheckForbiddenSourceHeader