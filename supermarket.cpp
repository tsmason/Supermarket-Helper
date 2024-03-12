#include <ncurses.h>
#include "fixture/fixture.h"
#include "menu/menu.h"

int main()
{
    // initialize ncurses
    WINDOW *win = initscr();
    int day = 1;

    Fixture::initializePrototypes();

    // bool to keep the game running
    bool running = true;
    std::vector<std::string> options = {"Start day", "Products", "Fixtures", "Exit"};
    // main game loop
    while (running)
    {
        // show the day then print a blank line
        mvprintw(0, 0, "Day %d", day);
        printw("\n");

        int selection = Menu::numberChoiceMenu(options);

        // if the user selects 4, exit the game
        if (selection == 4)
        {
            running = false;
        }

        clear();
    }

    // end ncurses
    endwin();
}
