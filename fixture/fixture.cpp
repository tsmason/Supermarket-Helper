#include "fixture.h"

std::unordered_map<Fixture::FixtureType, Fixture> Fixture::prototypes;
std::vector<Fixture> Fixture::fixtures;

int Fixture::getFixtureCapacity(FixtureType type)
{
    // count the total number of fixtures matching the type
    int capacity = 0;
    for (auto fixture : fixtures)
    {
        if (fixture.getType() == type)
        {
            capacity += fixture.getCapacity();
        }
    }
    return capacity;
}

void Fixture::initializePrototypes()
{
    prototypes[FixtureType::Freezer] = Fixture(FixtureType::Freezer, 2);
    prototypes[FixtureType::Fridge] = Fixture(FixtureType::Fridge, 10);
    prototypes[FixtureType::Shelf] = Fixture(FixtureType::Shelf, 8);
}

int Fixture::calculateTotalSlots()
{
    int totalSlots = 0;
    for (auto fixture : fixtures)
    {
        totalSlots += fixture.getCapacity();
    }
    return totalSlots;
}

void Fixture::save_fixtures()
{
    std::ofstream ofs("fixtures.dat");
    boost::archive::text_oarchive oa(ofs);
    for (const auto &fixture : fixtures)
    {
        oa << fixture;
    }
}

void Fixture::load_fixtures()
{
    std::ifstream ifs("fixtures.dat");
    boost::archive::text_iarchive ia(ifs);
    fixtures.clear();
    while (true)
    {
        try
        {
            Fixture fixture;
            ia >> fixture;
            fixtures.push_back(fixture);
        }
        catch (boost::archive::archive_exception &e)
        {
            break;
        }
    }
}

void Fixture::deserialize_fixtures()
{
    // check if file exists
    std::ifstream file("fixtures.dat");
    if (file.good())
    {
        file.close();
        Fixture::load_fixtures();
    }
}
