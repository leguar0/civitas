#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <unordered_map>
#include "iResourceManager.hpp"

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