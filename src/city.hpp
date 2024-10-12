#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include "building.hpp"
#include "buildingManager.hpp"

class City
{
private:
    BuildingManager buildingManager_;
    int people_;
    float money_;
public:
    City();
    ~City() = default;

    const std::vector<Building>& getBuildings() const;
    Building* getBuilding(const int id);

    bool addBuilding(BuildingType type);
    bool removeBuilding(const int id);

    bool addPeopleToBuilding(const int id, const int people);
    bool removePeopleFromBuilding(const int id, const int people);
};

#endif
