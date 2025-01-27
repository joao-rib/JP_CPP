#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    std::cout << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB Jim("Jim");
        Jim.attack();
        Jim.setWeapon(club);
        Jim.attack();
        club.setType("some other type of club");
        Jim.attack();
    }

    return(0);
}
