#include "building.hpp"

Building::Building(BuildingType type)
    : type_(type)
    , people_(0)
{
}

void Building::addPeople(int people)
{
    people_ += people;
}

void Building::removePeople(int people)
{
    people_ -= people;
}

int Building::getPeople() const
{
    return people_;
}