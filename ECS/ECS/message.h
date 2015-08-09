#pragma once
#include <string>
#include <memory>

struct Message
{
	// Base message data structure.
	// Structs can be defined using {1, 2, 3} can they not?
	~Message()
	{
	}
};

typedef std::shared_ptr<Message> MSGPtr;