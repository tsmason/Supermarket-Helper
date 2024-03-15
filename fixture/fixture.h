#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Fixture
{
public:
    enum FixtureType
    {
        Freezer,
        Fridge,
        Shelf
    };

    Fixture() = default;

    FixtureType getType() const { return type; };
    int getCapacity() const { return capacity; };

    static std::unordered_map<FixtureType, Fixture> prototypes;
    static std::vector<Fixture> fixtures;
    static int getFixtureCapacity(FixtureType type);

    static void createFixture(FixtureType type) { fixtures.push_back(prototypes[type]); };
    static void initializePrototypes();
    static int calculateTotalSlots();

    // serialization
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & type;
        ar & capacity;
    };

    static void save_fixtures();
    static void load_fixtures();
    static void deserialize_fixtures();

private:
    Fixture(FixtureType type, int capacity) : type(type), capacity(capacity){};
    FixtureType type;
    int capacity;
};
