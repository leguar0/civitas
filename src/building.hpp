#ifndef BUILDING_HPP
#define BUILDING_HPP

enum class BuildingType {
    hospital,
    house,
    police_station,
    post,
    power_station,
    subway,
    apartment_building
};

class Building
{
private:
    BuildingType type_;
public:
    Building(BuildingType type);
    ~Building() = default;
};


#endif