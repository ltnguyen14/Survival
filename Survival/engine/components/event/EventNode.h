#pragma once
#include "EventBus.h"

class EventNode
{
public:
	EventNode();
	virtual ~EventNode();

protected:
	void AddEventBus(EventBus* eventBus);

	std::function<void (Event)> GetNotifyFunction();

	void SendEvent(Event event);

	virtual void OnNotify(Event event) = 0;

private:
	std::vector<EventBus*> m_eventBuses;
};

