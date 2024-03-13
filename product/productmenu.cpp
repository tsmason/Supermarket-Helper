#include "productmenu.h"

#include <vector>
#include <string>
#include <ncurses.h>

#include "productcreator.h"
#include "../menu/menu.h"

void ProductMenu::displayProductMenu()
{
    while (true)
    {
        clear();
        printw("Product Menu\n\n");
        std::vector<std::string> options = {"Add product", "List Products", "Exit"};

        int selection = Menu::numberChoiceMenu(options);

        switch (selection)
        {
        case 1:
            ProductCreator::createProduct();
            break;
        case 2:
            // TODO: show Products List for editing, deleting, or viewing
            break;
        case 3:
            return;

        default:
            // output a message saying something's wrong
            printw("Something's wrong, hit default in product menu\n");
            break;
        }
    }
}

void ProductMenu::displayProductInformation(Product product)
{
    // clear the screen
    clear();

    // display the product information
    printw("Product Information\n");
    printw("Name: %s\n", product.getName().c_str());
    printw("Brand: %s\n", product.getBrand().c_str());
    printw("Price: %.2f\n", product.getPrice());
    printw("Market Price: %.2f\n", product.getMarketPrice());
    printw("Cost: %.2f\n", product.getCost());
}
