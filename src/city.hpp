#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include "building.hpp"

class City
{
private:
    std::vector<Building> buildings_;
public:
    City();
    ~City() = default;

    bool addBuilding(Building building);
};

#endif
