#pragma once

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Component.h"

class CameraComponent : public Component
{
public:
	CameraComponent(class Actor* owner);

	glm::mat4 GetViewMatrix() const;
	glm::mat4  GetProjectionMatrix() const;

	void SetPerspective(float fov, float aspect, float nearZ, float farZ);

private:
	float mFOV;
	float mAspect;
	float mNearClip;
	float mFarClip;
};