#ifndef BUILDING_MANAGER_HPP
#define BUILDING_MANAGER_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include "building.hpp"

class IBuildingManager
{
public:
    virtual ~IBuildingManager() = default;
    virtual const std::vector<std::unique_ptr<Building>>& getBuildings() const = 0;
    virtual Building* getBuilding(const int index) = 0;
    virtual void addBuilding(std::unique_ptr<Building> building) = 0;
    virtual bool removeBuilding(const int id) = 0;
};

class BuildingManager 
    : public IBuildingManager
{
private:
    std::vector<std::unique_ptr<Building>> buildings_;
    auto findBuildingIterator(const int index) const;
public:
    BuildingManager() = default;
    ~BuildingManager() = default;

    const std::vector<std::unique_ptr<Building>>& getBuildings() const override;
    void addBuilding(std::unique_ptr<Building> building) override;
    bool removeBuilding(const int index) override;
    Building* getBuilding(const int index) override;
};

#endif
