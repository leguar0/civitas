#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <unordered_map>

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

class ResourceManager
{
private:
    std::unordered_map<Gender, int> people_;
    double money_;
    std::unordered_map<Resource, int> resources_;
public:
    ResourceManager();
    ~ResourceManager() = default;

    bool removeMoney(int money);
    
    void newGenerationPeople();
    void generateMoney();

    void addResource(Resource resource, int amount);
    bool consumeResource(Resource resource, int amount);

    int getPeople() const;
    double getMoney() const;
    int getResourceAmount(Resource resource) const;
    bool hasEnoughResources(Resource resource, int amount) const;
};

#endif