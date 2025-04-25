#include "CameraComponent.h"

#include "TransformComponent.h"
#include "Actor.h"

CameraComponent::CameraComponent(Actor* owner)
	: Component(owner)
	, mFOV(45.0f)
	, mAspect(1.3333f)
	, mNearClip(0.1f)
	, mFarClip(100.0f)
{

}

void CameraComponent::SetPerspective(float fovDegrees, float aspect, float nearZ, float farZ)
{
	mFOV = fovDegrees;
	mAspect = aspect;
	mNearClip = nearZ;
	mFarClip = farZ;
}

glm::mat4 CameraComponent::GetProjectionMatrix() const
{
	return glm::perspective(glm::radians(mFOV), mAspect, mNearClip, mFarClip);
}

glm::mat4 CameraComponent::GetViewMatrix() const
{
	TransformComponent* transform = mOwner->GetComponent<TransformComponent>();
	if (!transform) return glm::mat4(1.0f);

	glm::vec3 position = transform->GetPosition();
	glm::vec3 target = position + transform->GetForward();
	glm::vec3 up = transform->GetUp();

	return glm::lookAt(position, target, up);
}