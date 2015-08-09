#pragma once
#include <string>
#include <map>
#include <memory>
#include "managers.h"

class EntityManager;
class SystemManager;

class Component
{
public:
	std::string type;

	Component(std::string type) : type(type) {}
};

class Entity
{
	int _GUID;
public:
	Entity(int GUID): _GUID(GUID) {}

	int GUID()
	{
		return _GUID;
	}
};

class System
{
protected:
	EntityManager entityManager;
	SystemManager systemManager;
public:
	std::string type;

	System(std::string type, EntityManager entityManager, SystemManager systemManager) : type(type), entityManager(entityManager), systemManager(systemManager) {}
};