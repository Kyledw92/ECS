#pragma once
#include <map>
#include <functional>
#include "models.h"
#include "message.h"

class MessageSystem : public System
{
public:
	MessageSystem(EntityManager entityManager, SystemManager systemManager) : System("MessageSystem", entityManager, systemManager) {}

	void Send(EntityPtr entity, std::string componentType, std::function<void(ComponentPtr, MSGPtr)> func)
	{
		// Send message (callback) to a component within an entity.
	}

	void Send(ComponentPtr component, std::function<void(ComponentPtr, MSGPtr)> func)
	{
		// Send message (callback) to a component directly.
	}
};