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
    int people_;
public:
    Building(BuildingType type);
    ~Building() = default;

    void addPeople(int people);
    void removePeople(int people);

    int getPeople() const;
};


#endif