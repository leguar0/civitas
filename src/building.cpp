#include "building.hpp"

int Building::nextId = -1;

Building::Building()
    : id_(nextId++)
{
}

void Building::upgrade()
{
    ++level;
}

int Building::getId() const
{
    return id_;
}

int Building::getLevel() const
{
    return level;
}

double Mine::generateMoney()
{
    return 0.5*getLevel();
}

double PoliceStation::generateMoney()
{
    return 0.25*getLevel();
}

double Hospital::generateMoney()
{
    return 0.1*getLevel();
}
