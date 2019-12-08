.PHONY: all, obj, clean, fclean, re
CC = clang++

NAME = ft_retro

FLAGS = -Wall -Wextra -Werror

I_DIR = ./inc

S_DIR = ./src

O_DIR = obj

EXTENSIONS = $(addprefix $(I_DIR)/,$(EXT))

EXT = Cartridge.hpp \
      DeepSpace.hpp \
      EnemyBullet.hpp \
      EnemyShip.hpp \
      Object.hpp \
      PlayerShip.hpp \
      GameEntity.hpp

HEADERS =-I$(I_DIR)

SOURCES =   main.cpp \
            Cartridge.cpp \
            DeepSpace.cpp \
            EnemyBullet.cpp \
            EnemyShip.cpp \
            Object.cpp \
            PlayerShip.cpp \
            GameEntity.cpp

SRCS = $(addprefix $(S_DIR)/,$(SOURCES))

OBJS = $(addprefix $(O_DIR)/,$(SOURCES:.cpp=.o))

all: obj $(NAME)

$(NAME): $(OBJS) $(EXTENSIONS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(HEADERS) -lncurses

obj:
	mkdir -p obj

$(O_DIR)/%.o: $(S_DIR)/%.cpp $(DEPS) $(EXTENSIONS)
		$(CC) -c -o $@ $< $(FLAGS) $(HEADERS)

clean:
		rm -f $(OBJS)
		rm -rf $(O_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
