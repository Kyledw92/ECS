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
	}

	void Send(ComponentPtr componentType, std::function<void(ComponentPtr, MSGPtr)> func)
	{
	}
};