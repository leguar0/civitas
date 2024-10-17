#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include <memory>
#include "building.hpp"
#include "buildingManager.hpp"
#include "resourceManager.hpp"

class City
{
    std::shared_ptr<IBuildingManager> buildingManager_;
    std::shared_ptr<IResourceManager> resourceManager_;
public:
    City(std::shared_ptr<IBuildingManager> buildManager,
         std::shared_ptr<IResourceManager> resourceManager);
    ~City() = default;

    const std::vector<std::unique_ptr<Building>>& getBuildings() const;
    Building* getBuilding(const int index);
    int getPeople() const;
    double getMoney() const;
    bool addBuilding(std::unique_ptr<Building> building);
    bool removeBuilding(const int id);
};

#endif
