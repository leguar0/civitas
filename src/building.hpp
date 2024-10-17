#ifndef BUILDING_HPP
#define BUILDING_HPP

/*
enum class BuildingType {
    hospital,
    house,
    police_station,
    subway,
    apartment_building,
    mine,
    sawmill
};
*/

class Manageable 
{
public:
    virtual void upgrade() = 0;
};

class Workable
{
public:
    virtual double generateMoney() = 0;
};

class Building
    : public Manageable
{
private:
    static int nextId;

    int id_;
    int level;
public:
    Building();
    ~Building() = default;

    void upgrade();

    int getId() const;
    int getLevel() const;
};

class House
    : public Building
{
private:

public:
    House() = default;
    ~House() = default;
};

class Mine
    : public Building, public Workable
{
private:
public: 
    Mine() = default;
    ~Mine() = default;

    double generateMoney() override;
};

class PoliceStation
    : public Building, public Workable
{
private:
public:
    PoliceStation() = default;
    ~PoliceStation() = default;

    double generateMoney() override;
};

class Hospital
    : public Building, public Workable
{
private:
public:
    Hospital() = default;
    ~Hospital() = default;

    double generateMoney() override;
};

#endif
