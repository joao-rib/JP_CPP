#pragma once

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl();
    ~Harl();
    void complain(std::string level);
};

#endif
