#pragma once
#include "product.h"

class ProductCreator
{
public:
    static Product createProduct();
    static bool confirmCreation();

private:
    static constexpr double INITIAL_PROFIT_MARGIN = 0.3;

    ProductCreator(){}; // private constructor, utility class only
    static Product gatherProductInformation();
    static bool confirmProductInformation(Product product);
};