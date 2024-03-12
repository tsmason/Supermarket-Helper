#include "fixture.h"

std::unordered_map<Fixture::FixtureType, Fixture> Fixture::prototypes;
std::vector<Fixture> Fixture::fixtures;

void Fixture::initializePrototypes()
{
    prototypes[FixtureType::Freezer] = Fixture(FixtureType::Freezer, 2);
    prototypes[FixtureType::Fridge] = Fixture(FixtureType::Fridge, 10);
    prototypes[FixtureType::Shelf] = Fixture(FixtureType::Shelf, 8);
}
