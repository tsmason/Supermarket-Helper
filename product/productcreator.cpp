#include <ncurses.h>
#include <limits>
#include <string>

#include "productcreator.h"
#include "../menu/menu.h"

Product ProductCreator::createProduct()
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
    return product;
}

bool ProductCreator::confirmCreation()
{
    // clear the screen
    clear();

    // ask the user if they want to create a product
    return Menu::yesNoMenu("Would you like to create a product?");
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
    printw("\n");
    printw("Enter the product cost: ");
    refresh();

    // read the user input into a string using ncurses into a variable named costString
    // and verify the user entered a valid positive double
    // if so assign to cost and break the loop
    // if not, print an error message and ask the user to enter a valid positive double
    double cost;
    while (true)
    {
        char costArray[256];
        getstr(costArray);
        std::string costString = costArray;

        try
        {
            cost = std::stod(costString);
            if (cost > 0)
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

    // ask the user for the product's market price
    // and read the user input into a double
    // and verify the user entered a valid positive double
    printw("\n");
    printw("Enter the product market price: ");
    refresh();
    double marketPrice;
    while (true)
    {
        char marketPriceArray[256];
        getstr(marketPriceArray);
        std::string marketPriceString = marketPriceArray;

        try
        {
            marketPrice = std::stod(marketPriceString);
            if (cost > 0)
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

    // calculate the price with profit margin
    double price = cost / (1 - INITIAL_PROFIT_MARGIN);

    // return a new product with the gathered information
    return Product(name, brand, price, marketPrice, cost);
}

bool ProductCreator::confirmProductInformation(Product product)
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

    // insert a blank line and ask the user to confirm the product information
    return Menu::yesNoMenu("Is this information correct?");
}
