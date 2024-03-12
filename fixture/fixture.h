#pragma once
#include <vector>
#include <unordered_map>
#include <string>

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

    Fixture createFixture(FixtureType type) { return prototypes[type]; };
    static void initializePrototypes();

private:
    Fixture(FixtureType type, int capacity) : type(type), capacity(capacity){};
    FixtureType type;
    int capacity;
};
