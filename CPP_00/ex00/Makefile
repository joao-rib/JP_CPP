NAME = megaphone
MAIN = megaphone.cpp
CPP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -fr

all: $(NAME)

$(NAME): $(SRC)
	@$(CPP) $(FLAGS) $(MAIN) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
