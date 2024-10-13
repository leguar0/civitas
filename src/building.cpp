#include "building.hpp"

int Building::nextId = 0;

Building::Building(BuildingType type)
    : id_(nextId++)
    , type_(type)
{
}

int Building::getId() const
{
    return id_;
}
