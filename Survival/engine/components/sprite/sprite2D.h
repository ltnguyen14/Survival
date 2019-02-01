#pragma once
#include "../../platform/entities/entity.h"
#include "../../platform/texture/texture.h"
#include "../animator/animator.h"
#include "../gameComponents/inputManager.h"
#include "glm.hpp"

class PhysicsManager;

class Sprite2D : public Entity{
public:
	Sprite2D(glm::vec3 worldPosition, glm::vec2 size, const Texture& texture, glm::vec2 coord);
	virtual ~Sprite2D();

	void Bind() const;
	virtual void Update(InputManager* inputManager, PhysicsManager* physicsManager);

	glm::vec2 GetCenterPoint() { return { position.x + size.x, position.y + size.y }; };

	inline const unsigned int GetIndiciesCount() const { return m_ibo->GetCount(); };
	inline const Texture& GetTexture() const { return m_texture; };

public:
	inline void LoadAnimator(Animator& animator) { m_animator = &animator; };
	inline Animator* GetAnimator() const { return m_animator; };

protected:
	VertexArray* m_vao = nullptr;
	VertexBuffer* m_vbo = nullptr;
	IndexBuffer* m_ibo = nullptr;
	Animator* m_animator;
	const Texture& m_texture;
	glm::vec2 m_coord;
};