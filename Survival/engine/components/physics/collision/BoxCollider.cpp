#include "BoxCollider.h"

bool BoxCollider::Collides(BoxCollider collider)
{
	return (m_position.x < collider.m_position.x + collider.m_size.x &&
		m_position.x + m_size.x > collider.m_position.x &&
		m_position.y < collider.m_position.y + collider.m_size.y &&
		m_position.y + m_size.y > collider.m_position.y);
}
