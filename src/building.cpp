#include "building.hpp"

int Building::nextId = -1;

Building::Building()
    : id_(nextId++)
{
}

void Building::upgrade()
{
}

void Building::demolish()
{
}

int Building::getId() const
{
    return id_;
}

void House::build()
{
}

void Mine::build()
{
}

double Mine::generateMoney()
{
    return 0.0;
}

void PoliceStation::build()
{
}

double PoliceStation::generateMoney()
{
    return 0.0;
}

void Hospital::build()
{
}

double Hospital::generateMoney()
{
    return 0.0;
}
