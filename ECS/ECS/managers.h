#pragma once
#include <string>
#include <map>
#include <memory>
#include "models.h"

class Entity;
class Component;
class System;

typedef std::shared_ptr<Entity> EntityPtr;
typedef std::shared_ptr<Component> ComponentPtr;
typedef std::shared_ptr<System> SystemPtr;

class EntityManager
{
protected:
	std::map<std::string, std::shared_ptr<std::map<EntityPtr, ComponentPtr>>> database;
	int nextID;
public:
	EntityManager()
	{
		// Initialize unique IDs
		nextID = 0;
	}

	EntityPtr create()
	{
		// Create an entity with the next available unique ID, and increment the ID counter.
		EntityPtr entity = EntityPtr(new Entity(nextID));
		nextID++;
		return entity;
	}

	void addComponent(EntityPtr entity, ComponentPtr component)
	{
		// Add a component to the database, for a given entity, under a given component type.
		if (database.find(component->type) == database.end())
			database.insert({component->type, std::shared_ptr<std::map<EntityPtr, ComponentPtr>>(new std::map<EntityPtr, ComponentPtr>())});

		database[component->type]->insert({entity, component});
	}

	void removeComponent(EntityPtr entity, std::string componentType)
	{
		// Remove a component from an entity by type, and if their are no longer instances of a
		// type, remove the type from the database.
		database[componentType]->at(entity).reset();
		database[componentType]->erase(entity);

		if (database[componentType]->empty())
			database.erase(componentType);
	}

	std::shared_ptr<std::map <EntityPtr, ComponentPtr>> findAll(std::string componentType)
	{
		// Find all instances of a component type.
		if (database.find(componentType) == database.end())
			return std::shared_ptr<std::map<EntityPtr, ComponentPtr>>(&database[componentType]);
		return nullptr;
	}

	ComponentPtr get(EntityPtr entity, std::string componentType)
	{
		// Get component by type for a specified entity.
		if (database.find(componentType) == database.end() && database[componentType]->find(entity) == database[componentType]->end())
			return database[componentType]->at(entity);
		return nullptr;
	}

	void destroy(EntityPtr entity)
	{
		// Detatch shared ptrs from all components and finally the entity itself
		// then check if the component type in the map is no longer populated,
		// and if not, then remove it.
		for (auto itr = database.begin(); itr != database.end(); itr++)
		{
			itr->second->at(entity).reset();
			itr->second->erase(entity);
			entity.reset;

			if (itr->second->empty())
				database.erase(itr);
		}
			
	}
};

class SystemManager
{
	std::map<std::string, std::shared_ptr<SystemPtr>> systems;

	std::shared_ptr<EntityManager> entityManager;
public:
	
	SystemManager()
	{}

	void addSystem(SystemPtr system)
	{
	}

	void removeSystem(std::string type)
	{
	}

	void update(float dt)
	{
		// Run all system update functions.
		for (auto system : systems)
			system.second->get()->update(dt);
	}
};