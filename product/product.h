#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>

#include "../fixture/fixture.h"

class Product
{
public:
    // constructors
    Product() = default;
    Product(std::string name, std::string brand, double price, double marketPrice, double cost, int caseSize, int amountPerSlot, Fixture::FixtureType fixtureType)
        : name(name), brand(brand), price(price), marketPrice(marketPrice), cost(cost), caseSize(caseSize), amountPerSlot(amountPerSlot), fixtureType(fixtureType){};
    static std::vector<Product> products;

    // getters
    std::string getName() const { return name; };
    std::string getBrand() const { return brand; };
    double getPrice() const { return price; };
    double getMarketPrice() const { return marketPrice; };
    double getCost() const { return cost; };
    int getAmountPerSlot() const { return amountPerSlot; };
    int getShelfCapacity() const { return shelfCapacity; };
    Fixture::FixtureType getFixtureType() const { return fixtureType; };
    int getCaseSize() const { return caseSize; };

    // setters
    void setCost(double cost) { this->cost = cost; };
    void setPrice(double price) { this->price = price; };
    void setMarketPrice(double marketPrice) { this->marketPrice = marketPrice; };
    void setShelfCapacity(int shelfCapacity) { this->shelfCapacity = shelfCapacity; };

    // serialization
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & name;
        ar & brand;
        ar & price;
        ar & marketPrice;
        ar & cost;
        ar & caseSize;
        ar & amountPerSlot;
        ar & numberOfShelves;
        ar & fixtureType;
        ar & shelfCapacity;
        ar & onHand;
        ar & maxSales;
        ar & sales;
    };

    static void save_products();
    static void load_products();
    static void deserialize_products();

private:
    std::string name;
    std::string brand;
    double price;
    double marketPrice;
    double cost;
    int caseSize;
    int amountPerSlot;
    int numberOfShelves = 0;
    Fixture::FixtureType fixtureType;
    int shelfCapacity = 0;
    int onHand = 0;
    int maxSales = 0;

    // day, sales
    std::map<int, double> sales;
};