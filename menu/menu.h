#pragma once

#include <vector>
#include <string>

class Menu
{
public:
    static int numberChoiceMenu(std::vector<std::string> options);
    static bool boolPrompt(std::string prompt);
    static double positiveDoublePrompt(std::string prompt);
    static int positiveIntPrompt(std::string prompt);
};