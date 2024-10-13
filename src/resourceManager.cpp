#include "resourceManager.hpp"

#include <random>
#include <algorithm>

ResourceManager::ResourceManager()
    : money_(100.0)
{
    people_.insert({
        {Gender::male, 5},
        {Gender::female, 5}
    });

    resources_.insert({
        {Resource::stone, 0},
        {Resource::wood, 0},
        {Resource::coal, 0},
        {Resource::food, 0},
        {Resource::water, 0}
    });
}

bool ResourceManager::removeMoney(int money)
{
    if (money_ >= money) {
        money_ -= money;

        return true;
    }
    return false;
}

void ResourceManager::newGenerationPeople()
{
    int male = people_.at(Gender::male);
    int female = people_.at(Gender::female);

    int pairs = std::min(male, female);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pairs);
    int newMales = dis(gen);
    int newFemales = pairs - newMales;

    people_[Gender::male] += newMales;
    people_[Gender::female] += newFemales;
}

void ResourceManager::generateMoney()
{
    money_ += (people_[Gender::male]+people_[Gender::female])*0.15;
}

void ResourceManager::addResource(Resource resource, int amount)
{
    int newValue = amount + resources_[resource];
    resources_[resource] = newValue;
}

bool ResourceManager::consumeResource(Resource resource, int amount)
{
    int value = resources_[resource];
    if (value >= amount) {
        value -= amount;
        resources_[resource] = value;

        return true;
    }
    return false;
}

int ResourceManager::getPeople() const
{
    return (people_.at(Gender::male) + people_.at(Gender::female) );
}

double ResourceManager::getMoney() const
{
    return money_;
}

int ResourceManager::getResourceAmount(Resource resource) const
{
    return resources_.at(resource);
}

bool ResourceManager::hasEnoughResources(Resource resource, int amount) const
{
    return resources_.at(resource) >= amount;
}
