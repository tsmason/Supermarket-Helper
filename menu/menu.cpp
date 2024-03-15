#include <ncurses.h>
#include "menu.h"

int Menu::numberChoiceMenu(std::vector<std::string> options)
{
    // print a new line
    printw("\n");
    int numberOfChoices = 0;
    int choice = 0;
    // ask the user to choose an option
    printw("Choose an option:\n\n");

    // iterate through the set
    for (std::string option : options)
    {
        numberOfChoices++;
        // print the option
        printw("%d. %s\n", numberOfChoices, option.c_str());
    }
    printw("\n");
    printw("Selection: ");
    refresh();

    // get the user input and ensure it's a number 1-numberOfChoices
    while (true)
    {
        char choiceArray[256];
        getstr(choiceArray);
        std::string choiceString = choiceArray;

        try
        {
            choice = std::stoi(choiceString);
            if (choice > 0 && choice <= numberOfChoices)
            {
                break;
            }
            else
            {
                printw("\n");
                printw("Invalid input. Please enter a number 1-%d: ", numberOfChoices);
                refresh();
            }
        }
        catch (std::invalid_argument &e)
        {
            printw("\n");
            printw("Invalid input. Please enter a number 1-%d: ", numberOfChoices);
            refresh();
        }
    }

    return choice;
}

bool Menu::boolPrompt(std::string prompt)
{
    printw("\n");
    // ask the user the prompt
    printw("%s\n", prompt.c_str());
    // then ask the user Y or N
    printw("Y/N: ");
    refresh();

    // ensure input is either Y, y, N, or n
    while (true)
    {
        char choiceArray[256];
        getstr(choiceArray);
        std::string choiceString = choiceArray;

        if (choiceString == "Y" || choiceString == "y")
        {
            return true;
        }
        else if (choiceString == "N" || choiceString == "n")
        {
            return false;
        }
        else
        {
            printw("\n");
            printw("Invalid input. Please enter Y or N: ");
            refresh();
        }
    }
}

double Menu::positiveDoublePrompt(std::string prompt)
{
    printw("\n");
    // print the prompt
    printw("%s", prompt.c_str());
    refresh();

    double amount;
    while (true)
    {
        char amountArray[256];
        getstr(amountArray);
        std::string amountString = amountArray;

        try
        {
            amount = std::stod(amountString);
            if (amount > 0)
            {
                break;
            }
            else
            {
                printw("\n");
                printw("Invalid input. Please enter a positive number: ");
                refresh();
            }
        }
        catch (const std::invalid_argument &e)
        {
            printw("\n");
            printw("Invalid input. Please enter a positive number: ");
            refresh();
        }
    }

    return amount;
}

int Menu::positiveIntPrompt(std::string prompt)
{
    printw("\n");
    // print the prompt
    printw("%s", prompt.c_str());
    // refresh the screen
    refresh();

    int amount;

    // ensure the amount is a positive integer
    while (true)
    {
        char amountArray[256];
        getstr(amountArray);
        std::string amountString = amountArray;

        try
        {
            amount = std::stoi(amountString);
            if (amount > 0)
            {
                break;
            }
            else
            {
                printw("\n");
                printw("Invalid input. Please enter a positive number: ");
                refresh();
            }
        }
        catch (const std::invalid_argument &e)
        {
            printw("\n");
            printw("Invalid input. Please enter a positive number: ");
            refresh();
        }
    }

    return amount;
}
