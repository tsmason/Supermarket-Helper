#pragma once

#include <vector>
#include <string>

class Menu
{
public:
    static int numberChoiceMenu(std::vector<std::string> options);
    static bool yesNoMenu(std::string prompt);
};