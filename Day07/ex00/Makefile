NAME	= whatever

SRC		= whatever.cpp

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created whatever"

clean:
	/bin/rm -f *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned whatever"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned whatever"

re: fclean all

.PHONY: clean fclean re all test