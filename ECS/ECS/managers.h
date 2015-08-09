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

class EntityManager
{
protected:
	std::map<std::string, std::map<std::shared_ptr<Entity>, std::shared_ptr<Component>>> database;
	int nextID;
public:
	EntityManager()
	{
		nextID = 0;
	}

	EntityPtr create()
	{
		EntityPtr entity = EntityPtr(new Entity(nextID));
		nextID++;
		return entity;
	}

	void addComponent(EntityPtr entity)
	{
	}

	void removeComponent(EntityPtr entity, std::string componentType)
	{
	}
};

class SystemManager
{
public:
	SystemManager()
	{}
};