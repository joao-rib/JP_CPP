NAME = megaphone
SRC = megaphone.cpp
CPP = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
COMPILER = $(CPP) $(CFLAGS)
RM = rm -f

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiled chief"
	$(COMPILER) $^ -o $@

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
