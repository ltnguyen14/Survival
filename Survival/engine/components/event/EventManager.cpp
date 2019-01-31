#include "EventManager.h"

EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

EventBus* EventManager::CreateNewEventBus()
{
	EventBus* newEventBus = new EventBus();
	m_eventBuses.push_back(newEventBus);
	return newEventBus;
}
