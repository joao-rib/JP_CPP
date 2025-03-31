NAME = DiamondTrap
CPP = c++
FLAGS = -Wall -Werror -Wextra -Wno-shadow -std=c++98 
MAIN = main.cpp
SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
RM = rm -fr

all: $(NAME)

$(NAME):
	@$(CPP) $(FLAGS) $(SRC) $(MAIN) -o $(NAME)

clean:
	@$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
