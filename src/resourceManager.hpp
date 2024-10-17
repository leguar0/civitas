#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <unordered_map>

enum class Gender : unsigned char
{
    male = 'M',
    female = 'F'
};

enum class Resource : unsigned char
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

class ResourceManager
    : public IResourceManager
{
private:
    std::unordered_map<Gender, int> people_;
    double money_;
    std::unordered_map<Resource, int> resources_;
public:
    ResourceManager();
    ~ResourceManager() = default;

    int getPeople() const override;
    double getMoney() const override;
    int getResourceAmount(Resource resource) const override;
    bool removeMoney(double amount) override;
    void addResource(Resource resource, int amount) override;
    bool consumeResource(Resource resource, int amount) override;

    void newGenerationPeople();
    void generateMoney();
    bool hasEnoughResources(Resource resource, int amount) const;
};

#endif