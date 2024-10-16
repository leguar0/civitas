#include "city.hpp"

#include <iostream>
#include <QDebug>

City::City(std::shared_ptr<IBuildingManager> buildingManager,
           std::shared_ptr<IResourceManager> resourceManager)
    : buildingManager_(std::move(buildingManager)),
      resourceManager_(std::move(resourceManager)),
      timer_(new QTimer(this))
{
    connect(timer_, &QTimer::timeout, this, &City::updateResources);
    timer_->start(3000);
}

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

bool City::addBuilding(Building* building)
{
    auto buildingPtr = std::unique_ptr<Building>(building);

    double cost = 0.5;
    if (resourceManager_->removeMoney(cost)) {
        buildingManager_->addBuilding(std::move(buildingPtr));
        return true;    
    }

    return false;
}

bool City::removeBuilding(const int id)
{
    return buildingManager_->removeBuilding(id);
}

void City::updateResources()
{
    resourceManager_->increaseMoney();
    resourceManager_->increasePopulation();

    emit populationChanged();
    emit moneyChanged();
}