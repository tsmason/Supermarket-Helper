#include <ncurses.h>
#include <limits>
#include <string>

#include "productcreator.h"
#include "productmenu.h"
#include "../menu/menu.h"

void ProductCreator::createProduct()
{
    Product product;
    bool creatingProduct = true;

    while (creatingProduct)
    {
        // gather the product information
        product = gatherProductInformation();
        creatingProduct = !confirmProductInformation(product);
    }

    // return the product
    Product::products.push_back(product);
}

bool ProductCreator::confirmCreation()
{
    // clear the screen
    clear();

    // ask the user if they want to create a product
    return Menu::boolPrompt("Would you like to create a product?");
}

Product ProductCreator::gatherProductInformation()
{
    // clear the screen
    clear();

    // ask the user for the product name
    // and read the user input into a string
    printw("Enter the product name: ");
    refresh();
    char nameArray[256];
    getstr(nameArray);
    std::string name = nameArray;

    // ask the user for the product brand
    // and read the line into a string
    printw("\n");
    printw("Enter the product brand: ");
    refresh();
    char brandArray[256];
    getstr(brandArray);
    std::string brand = brandArray;

    // ask the user for the product cost
    double cost = Menu::positiveDoublePrompt("Enter the product cost: ");
    // ask the user for the product's market price
    double marketPrice = Menu::positiveDoublePrompt("Enter the product market price: ");
    // calculate the price with profit margin
    double price = cost / (1 - INITIAL_PROFIT_MARGIN);

    // return a new product with the gathered information
    return Product(name, brand, price, marketPrice, cost);
}

bool ProductCreator::confirmProductInformation(Product product)
{
    ProductMenu::displayProductInformation(product);
    return Menu::boolPrompt("Is this information correct?");
}
