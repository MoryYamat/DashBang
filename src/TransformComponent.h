#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <glm/gtc/quaternion.hpp> // ‚Ü‚¸‚±‚Á‚¿‚ÅŽŽ‚·


#include "Component.h"

class TransformComponent : public Component
{
public:
	TransformComponent(class Actor* owner);

	void SetPosition(const glm::vec3& pos) { mPosition = pos; }
	void SetRotation(const glm::quat& rot) { mRotation = rot; }
	void SetScale(const glm::vec3& scale) { mScale = scale; }

	glm::vec3 GetPosition() const { return mPosition; }
	glm::quat GetRotation() const { return mRotation; }
	glm::vec3 GetScale() const { return mScale; }

	glm::mat4 GetWorldTransform() const;

	glm::vec3 GetForward() const {
		return mRotation * glm::vec3(0, 0, -1);
	}

	glm::vec3 GetRight() const {
		return mRotation * glm::vec3(1, 0, 0);
	}

	glm::vec3 GetUp() const {
		return mRotation * glm::vec3(0, 1, 0);
	}

private:
	glm::vec3 mPosition = glm::vec3(0.0f);
	glm::quat mRotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
	glm::vec3 mScale = glm::vec3(1.0f);

};