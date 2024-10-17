#include "city.hpp"

City::City(std::shared_ptr<IBuildingManager> buildingManager, 
           std::shared_ptr<IResourceManager> resourceManager)
    : buildingManager_(std::move(buildingManager)),
      resourceManager_(std::move(resourceManager))
{}

const std::vector<std::unique_ptr<Building>>& City::getBuildings() const
{
    return buildingManager_->getBuildings();
}

Building* City::getBuilding(const int index)
{
    return buildingManager_->getBuilding(index);
}

int City::getPeople() const
{
    return resourceManager_->getPeople();
}

double City::getMoney() const
{
    return resourceManager_->getMoney();
}

bool City::addBuilding(std::unique_ptr<Building> building)
{
    double cost = 0.5;
    if (resourceManager_->removeMoney(cost)) {
        buildingManager_->addBuilding(std::move(building));
        return true;    
    }

    return false;
}

bool City::removeBuilding(const int id)
{
    return buildingManager_->removeBuilding(id);
}