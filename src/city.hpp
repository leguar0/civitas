#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include "building.hpp"
#include "buildingManager.hpp"
#include "resourceManager.hpp"

class City
{
private:
    BuildingManager buildingManager_;
    ResourceManager resourceManager_;
public:
    City();
    ~City() = default;

    const std::vector<Building>& getBuildings() const;
    Building* getBuilding(const int index);
    
    bool addBuilding(BuildingType type);
    bool removeBuilding(const int id);
};

#endif
