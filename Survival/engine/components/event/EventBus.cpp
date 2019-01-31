#include "EventBus.h"

EventBus::EventBus()
{
}


EventBus::~EventBus()
{
}

void EventBus::AddConsumer(std::function<void(Event)> consumer)
{
	m_consumers.push_back(consumer);
}

void EventBus::AddEvent(Event * event)
{
	m_events.push(*event);
}

void EventBus::Notify()
{
	while (!m_events.empty()) {
		for (auto iter = m_consumers.begin(); iter != m_consumers.end(); iter++) {
			(*iter)(m_events.front());
		}

		m_events.pop();
	}
}
