#pragma once
#include <string>
#include <memory>

struct Message
{
	~Message()
	{
	}
};

typedef std::shared_ptr<Message> MSGPtr;