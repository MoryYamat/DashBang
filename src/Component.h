#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Component
{
public:
	Component(class Actor* owner, int updateOrder = 100);

	virtual ~Component();

	virtual void Update(float deltaTime);

	virtual void ProcessInput(GLFWwindow* window, float deltaTime);

	const class Actor* GetOwner() const { return mOwner; }
	int GetUpdateOrder() const { return mUpdateOrder; }


protected:

	int mUpdateOrder;

	class Actor* mOwner;
};