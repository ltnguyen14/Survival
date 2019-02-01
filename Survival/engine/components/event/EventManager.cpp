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

Event* EventManager::CreateNewEvent(std::string eventMessage) {
	Event* event = new Event();
	event->EVENT_NAME = eventMessage;

	m_events.push_back(event);
	return event;
}
