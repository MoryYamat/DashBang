#include "Game.h"

#include <iostream>
#include <algorithm>

#include "Test/TriangleActor.h"
#include "Test/Test3DActor.h"

#include "MeshComponent.h"

#include "ModelData.h"
#include "AssimpImporter.h"

#include "CameraComponent.h"
#include "InputComponent.h"

Game::Game()
	: mWindow(nullptr)
	, mIsRunning(true)
	, mLastFrame(0.0f)
	, mRenderer(nullptr)
{

}

void Game::Shutdown()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();

	delete mRenderer;
	mRenderer = nullptr;

	std::cout << "[Game.cpp (Shutdown)]: The application shut down successfully." << std::endl;
}

bool Game::Initialize()
{
	mRenderer = new Renderer(this);
	if (!mRenderer->Initialize(1280, 720, "Game"))
	{
		return false;
	}


	loadData();


	std::cout << "[Game.cpp (Initialize)]: The application was successfully initialized" << std::endl;
	return true;

}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		processInput();
		updateGame();
		generateOutput();
	}
}

void Game::processInput()
{
	float currentFrame = glfwGetTime();
	float deltaTime = currentFrame - mLastFrame;
	mLastFrame = currentFrame;

	glfwPollEvents();
	if (glfwWindowShouldClose(GetWindow()))
	{
		mIsRunning = false;
	}
	for (Actor* a : mActors)
	{
		a->ProcessInput(mRenderer->GetWindow(), deltaTime);
	}

}

void Game::generateOutput()
{
	mRenderer->BeginFrame();



	mRenderer->Draw();
	//mRenderer->Draw();

	mRenderer->EndFrame();
}

void Game::updateGame()
{


	
}

void Game::AddActor(Actor* actor)
{
	if (mUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor)
{
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		// 末尾とスワップ
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::UpdateActor(float deltaTime)
{
	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		// ActorのUpdateを呼び出し
		actor->Update(deltaTime);
	}
	mUpdatingActors = false;

	for (auto actor : mPendingActors)
	{
		mActors.emplace_back(actor);
	}
	mPendingActors.clear();
}

void Game::loadData()
{
	//Actor* tri = new TriangleActor(this);
	//AddActor(tri);

	//ModelData model = AssimpImporter().Import("Assets/Models/Ch44_nonPBR.fbx");

	float windowAspect = 1280 / 720;

	Actor* testmodel = new Test3DActor(this);
	AddActor(testmodel);

	Actor* cam = CreateFreeCamera();


}


GLFWwindow* Game::GetWindow() const {
	return mRenderer ? mRenderer->GetWindow() : nullptr;
}


Actor* Game::CreateFreeCamera()
{
	Actor* camActor = new Actor(this);
	auto* camTransform = new TransformComponent(camActor);
	auto* cam = new CameraComponent(camActor);
	cam->SetPerspective(60.0f, 1280.0f / 720.0f, 0.1f, 100.0f);
	new InputComponent(camActor);
	AddActor(camActor);
	mRenderer->SetCameraComponent(cam);
	return camActor;

}