#pragma once
#include <string>
#include <vector>

class Product
{
public:
    // constructors
    Product() = default;
    Product(std::string name, std::string brand, double price, double marketPrice, double cost)
        : name(name), brand(brand), price(price), marketPrice(marketPrice), cost(cost){};
    static std::vector<Product> products;

    // getters
    std::string getName() const { return name; };
    std::string getBrand() const { return brand; };
    double getPrice() const { return price; };
    double getMarketPrice() const { return marketPrice; };
    double getCost() const { return cost; };

    // setters
    void setPrice(double price) { this->price = price; };
    void setMarketPrice(double marketPrice) { this->marketPrice = marketPrice; };

private:
    std::string name;
    std::string brand;
    double price;
    double marketPrice;
    double cost;
};