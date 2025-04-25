#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "Component.h"

class InputComponent : public Component
{
public:
	InputComponent(class Actor* owner, float moveSpeed = 5.0f, float turnspeed = 0.1f);


	void ProcessInput(GLFWwindow* window, float deltaTime) override;

	void SetMoveSpeed(float speed) { mMoveSpeed = speed; }
	void SetTurnSpeed(float speed) { mTurnSpeed = speed; }

private:
	float mMoveSpeed;
	float mTurnSpeed;

	bool mFirstMouse;
	double mLastX;
	double mLastY;
	float mYaw;
	float mPitch;
};