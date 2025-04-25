#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <vector>


#include "Actor.h"

#include "Renderer.h"

class Actor;

class Game
{
public:
	Game();

	bool Initialize();

	void RunLoop();
	void Shutdown();

	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);
	void UpdateActor(float deltaTime);

	GLFWwindow* GetWindow() const;

	class Renderer* GetRenderer() { return mRenderer; }

private:
	bool mIsRunning;

	GLFWwindow* mWindow;
	class Renderer* mRenderer;
	
	float mLastFrame;

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	bool mUpdatingActors = false;

	void processInput();

	void updateGame();

	void generateOutput();

	void loadData();
	void unloadData();

	Actor* CreateFreeCamera();
};