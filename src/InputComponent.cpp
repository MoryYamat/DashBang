#include "InputComponent.h"

#include "TransformComponent.h"
#include "Actor.h"


#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <GLM/gtx/quaternion.hpp>

#include <iostream>

InputComponent::InputComponent(Actor* owner, float moveSpeed, float turnspeed)
	:Component(owner)
	, mMoveSpeed(moveSpeed)
	, mTurnSpeed(turnspeed)
	, mFirstMouse(true)
	, mLastX(0.0)
	, mLastY(0.0)
	, mYaw(-90.0f)
	, mPitch(0.0f)
{

}

void InputComponent::ProcessInput(GLFWwindow* window, float deltaTime)
{
	TransformComponent* transform = mOwner->GetComponent<TransformComponent>();
	if (!transform) return;

	glm::vec3 pos = transform->GetPosition();
	glm::quat rot = transform->GetRotation();

	glm::vec3 forward = rot * glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 right = rot * glm::vec3(1.0f, 0.0f, 0.0f);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		pos += forward * mMoveSpeed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		pos -= forward * mMoveSpeed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		pos -= right * mMoveSpeed * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		pos += right * mMoveSpeed * deltaTime;

	transform->SetPosition(pos);


	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (mFirstMouse)
	{
		mLastX = xpos;
		mLastY = ypos;
		mFirstMouse = false;
	}

	float xoffset = static_cast<float>(xpos - mLastX);
	float yoffset = static_cast<float>(mLastY - ypos);
	mLastX = xpos;
	mLastY = ypos;

	xoffset *= -mTurnSpeed;
	yoffset *= mTurnSpeed;

	mYaw += xoffset;
	mPitch += yoffset;
	mPitch = glm::clamp(mPitch, -89.0f, 89.0f);

	glm::quat qPitch = glm::angleAxis(glm::radians(mPitch), glm::vec3(1, 0, 0));
	glm::quat qYaw = glm::angleAxis(glm::radians(mYaw), glm::vec3(0, 1, 0));
	glm::quat orientation = qYaw * qPitch;

	transform->SetRotation(orientation);

	//std::cout << "[InputComponent]: Camera Pos:" << pos.x << ", " << pos.y << ", " << pos.z << std::endl;
}
