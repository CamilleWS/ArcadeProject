//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//

#include "../include/main.hpp"

void print_usage()
{
    std::cerr << "USAGE: ./arcade lib" << std::endl;
    std::cerr << "\tlib\t\tThe name of the library with which you want to start the program." << std::endl;
    std::cerr << "\tUsage example:\t\"./arcade ./lib/lib_arcade_[LIBRARY_NAME].so\"" << std::endl;
}

int verif_ac(int ac)
{
    if (ac != 2) {
        print_usage();
        return 84;
    }
    return 0;
}

int verif_av(char **av)
{
    (void)av;
    return 0;
}

int error(int ac, char **av)
{
    if (verif_ac(ac) == 84)
        return 84;
    if (verif_av(av) == 84)
        return 84;
    return 0;
}
