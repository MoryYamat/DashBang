#include "TransformComponent.h"



TransformComponent::TransformComponent(Actor* owner)
	: Component(owner)
{

}

glm::mat4 TransformComponent::GetWorldTransform() const
{
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, mPosition);
	transform *= glm::toMat4(mRotation);
	transform = glm::scale(transform, mScale);

	return transform;
}