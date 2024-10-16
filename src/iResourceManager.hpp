#ifndef I_RESOURCE_MANAGER_HPP
#define I_RESOURCE_MANAGER_HPP

enum class Gender 
{
    male,
    female
};

enum class Resource
{
    stone, 
    wood,
    coal,
    water,
    food
};

class IResourceManager
{
public:
    virtual ~IResourceManager() = default;
    virtual int getPeople() const = 0;
    virtual double getMoney() const = 0;
    virtual int getResourceAmount(Resource resource) const = 0;
    virtual bool removeMoney(double amount) = 0;
    virtual void addResource(Resource resource, int amount) = 0;
    virtual bool consumeResource(Resource resource , int amount) = 0;
};

#endif
