#include "Game.h"

#include <iostream>
#include <algorithm>

#include "Test/TriangleActor.h"

#include "MeshComponent.h"

Game::Game()
	: mWindow(nullptr)
	, mIsRunning(true)
	, mLastFrame(0.0f)
{

}


bool Game::Initialize()
{
	if (!glfwInit())
	{
		std::cout << "[GLFW] Failed to initialize GLFW" << std::endl;
		return false;
	}

	// need to fix the hardcode
	// �������\�[�X�Ȃ̂�Game.h/.cpp�@�Ń��\�[�X��ێ�
	mWindow = glfwCreateWindow(1280, 720, "Game", nullptr, nullptr);
	if (!mWindow)
	{
		std::cout << "[GLFW] Failed to initialize GLFW" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(mWindow);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[GLAD] Failed to initialize GLAD" << std::endl;
		return false;
	}

	mRenderer.Initialize(mWindow);

	Shader* basicShader = mRenderer.GetShader();


	loadData();

	return true;

}

void Game::Shutdown()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
	std::cout << "Game Shutdown" << std::endl;
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
	glfwPollEvents();
	if (glfwWindowShouldClose(mWindow))
	{
		mIsRunning = false;
	}
}

void Game::generateOutput()
{
	mRenderer.BeginFrame();

	for (auto actor : mActors)
	{
		for (auto comp : actor->GetComponents())
		{
			// RTTI�ł�dynamic_cast�ł��AComponent��Draw()������Ȃ�
			if (auto meshComp = dynamic_cast<MeshComponent*>(comp))
			{
				meshComp->Draw();
			}
		}
	}

	mRenderer.EndFrame();
}

void Game::updateGame()
{
	float currentFrame = glfwGetTime();
	float deltaTime = currentFrame - mLastFrame;
	mLastFrame = currentFrame;

	
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
		// �����ƃX���b�v
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
		// Actor��Update���Ăяo��
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
	TriangleActor* tri = new TriangleActor(this);
	AddActor(tri);
}