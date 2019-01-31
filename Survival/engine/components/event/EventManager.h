#pragma once
#include "EventNode.h"

class EventManager
{
public:
	EventManager();
	~EventManager();

	EventBus* CreateNewEventBus();

private:
	std::vector<EventBus*> m_eventBuses;
};

