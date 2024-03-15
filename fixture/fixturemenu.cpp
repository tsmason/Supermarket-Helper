#include "fixturemenu.h"

#include <ncurses.h>
#include <vector>
#include <string>

#include "fixture.h"
#include "../menu/menu.h"

void FixtureMenu::displayFixtureMenu()
{
    while (true)
    {
        clear();
        printw("Product Menu\n\n");
        std::vector<std::string> options = {"Add fixture", "View Fixture Capacities", "Exit"};

        int selection = Menu::numberChoiceMenu(options);

        switch (selection)
        {
        case 1:
        {
            std::vector<std::string> fixtureOptions = {"Freezer", "Fridge", "Shelf"};
            int fixtureSelection = Menu::numberChoiceMenu(fixtureOptions);

            switch (fixtureSelection)
            {
            case 1:
                Fixture::createFixture(Fixture::FixtureType::Freezer);
                break;
            case 2:
                Fixture::createFixture(Fixture::FixtureType::Fridge);
                break;
            case 3:
                Fixture::createFixture(Fixture::FixtureType::Shelf);
                break;
            default:
                printw("Something's wrong, hit default in fixture create menu\n");
            }
            break;
        }
        case 2:
            displayFixtureInformation();
            break;
        case 3:
            return;

        default:
            // output a message saying something's wrong
            printw("Something's wrong, hit default in fixture menu\n");
            break;
        }
    }
}
void FixtureMenu::displayFixtureInformation()
{
    while (true)
    {
        clear();
        printw("Fixture Counts\n\n");

        // print the total capacity of each fixture type
        printw("Freezer: %d\n", Fixture::getFixtureCapacity(Fixture::FixtureType::Freezer));
        printw("Fridge: %d\n", Fixture::getFixtureCapacity(Fixture::FixtureType::Fridge));
        printw("Shelf: %d\n", Fixture::getFixtureCapacity(Fixture::FixtureType::Shelf));

        printw("\nPress any key to return\n");
        refresh();

        // wait for a keypress then return
        getch();
        return;
    }
};