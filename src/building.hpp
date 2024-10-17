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

class Buildable 
{
public:
    virtual void build() = 0;
    virtual void upgrade() = 0;
    virtual void demolish() = 0;
};

class Workable
{
public:
    virtual double generateMoney() = 0;
};

class Building
    : public Buildable
{
private:
    static int nextId;

    int id_;
public:
    Building();
    ~Building() = default;

    void upgrade();
    void demolish();

    virtual void build() = 0;

    int getId() const;
};

class House
    : public Building
{
private:

public:
    House() = default;
    ~House() = default;

    void build();
};

class Mine
    : public Building, public Workable
{
private:
public: 
    Mine() = default;
    ~Mine() = default;

    void build();
    double generateMoney();
};

class PoliceStation
    : public Building, public Workable
{
private:
public:
    PoliceStation() = default;
    ~PoliceStation() = default;

    void build();
    double generateMoney();
};

class Hospital
    : public Building, public Workable
{
private:
public:
    Hospital() = default;
    ~Hospital() = default;

    void build();
    double generateMoney();
};

#endif
