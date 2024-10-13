#ifndef BUILDING_HPP
#define BUILDING_HPP

enum class BuildingType {
    hospital,
    house,
    police_station,
    post,
    power_station,
    subway,
    apartment_building,
    mine,
    sawmill
};

class Building
{
private:
    static int nextId;

    int id_;
    BuildingType type_;
public:
    Building(BuildingType type);
    ~Building() = default;

    int getId() const;
};

#endif