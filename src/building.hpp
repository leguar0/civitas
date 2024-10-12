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
    mine
};

class Building
{
private:
    static int nextId;

    int id;
    BuildingType type_;
    int people_;
public:
    Building(BuildingType type);
    ~Building() = default;

    void addPeople(int people);
    void removePeople(int people);

    int getId() const;
    int getPeople() const;
};
int Building::nextId = 0;

#endif