#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include "building.hpp"

class City
{
private:
    std::vector<Building> buildings_;
    int people_;
    float money_;
public:
    City();
    ~City() = default;

    std::vector<Building>& getBuildings();

    bool addBuilding(Building building);
};

#endif
