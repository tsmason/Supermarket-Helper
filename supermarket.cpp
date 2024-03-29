#include <ncurses.h>

#include "fixture/fixturemenu.h"
#include "product/productmenu.h"
#include "menu/menu.h"

int main()
{
    // initialize ncurses
    WINDOW *win = initscr();
    int day = 1;

    Fixture::initializePrototypes();
    // deserialize fixtures
    Fixture::deserialize_fixtures();
    Product::deserialize_products();

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
        switch (selection)
        {
        case 1:
            // TODO: start day
            break;
        case 2:
            // show product menu
            ProductMenu::displayProductMenu();
            break;
        case 3:
            // show fixture menu
            FixtureMenu::displayFixtureMenu();
            break;
        case 4:
            running = false;
            break;
        default:
            // output a message saying something's wrong
            printw("Something's wrong, hit default in main menu\n");
            break;
        }

        clear();
    }

    // end ncurses
    endwin();
    // save fixtures
    Product::save_products();
    Fixture::save_fixtures();
}
