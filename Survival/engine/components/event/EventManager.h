#pragma once
#include "EventNode.h"

class EventManager
{
public:
	EventManager();
	~EventManager();

	EventBus* CreateNewEventBus();
	Event* CreateNewEvent();

private:
	std::vector<EventBus*> m_eventBuses;
	std::vector<Event*> m_events;
};

