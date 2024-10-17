#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include <memory>
#include <QObject>
#include <QTimer>
#include "building.hpp"
#include "buildingManager.hpp"
#include "resourceManager.hpp"

class City
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int people READ getPeople NOTIFY populationChanged);
    Q_PROPERTY(double money READ getMoney NOTIFY moneyChanged);

private:
    std::shared_ptr<IBuildingManager> buildingManager_;
    std::shared_ptr<IResourceManager> resourceManager_;
    QTimer* timer_;
public:
    City(std::shared_ptr<IBuildingManager> buildManager,
         std::shared_ptr<IResourceManager> resourceManager);
    ~City() = default;

    const std::vector<std::unique_ptr<Building>>& getBuildings() const;
    Building* getBuilding(const int index);
    int getPeople() const;
    double getMoney() const;
    Q_INVOKABLE bool addBuilding(Building* building);
    Q_INVOKABLE bool removeBuilding(const int id);

    void updateResources();
signals:
    void populationChanged();
    void moneyChanged();
};

#endif
