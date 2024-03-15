#include "product.h"

std::vector<Product> Product::products;

void Product::save_products()
{
    std::ofstream ofs("products.dat");
    boost::archive::text_oarchive oa(ofs);
    for (const auto &product : products)
    {
        oa << product;
    }
}

void Product::load_products()
{
    std::ifstream ifs("products.dat");
    boost::archive::text_iarchive ia(ifs);
    products.clear();
    while (true)
    {
        try
        {
            Product product;
            ia >> product;
            products.push_back(product);
        }
        catch (boost::archive::archive_exception &e)
        {
            break;
        }
    }
}

void Product::deserialize_products()
{
    std::ifstream file("products.dat");
    if (file.good())
    {
        file.close();
        Product::load_products();
    }
}
