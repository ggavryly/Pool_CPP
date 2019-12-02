NAME	= convert

SRC		= main.cpp LiteralConversion.cpp

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created convert"

clean:
	/bin/rm -f *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned convert"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned convert"

re: fclean all

.PHONY: clean fclean re all test