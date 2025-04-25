#include "Actor.h"

#include <algorithm>


Actor::Actor(Game* game)
	: mGame(game)
	, mState(State::Active)
	, mPosition(0.0f)
	, mScale(1.0f)
	, mRotation(0.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
}

void Actor::Update(float deltaTime)
{
	// ƒx[ƒXƒNƒ‰ƒX‚Å‚Í‰½‚à‚µ‚È‚¢
}

void Actor::Draw()
{
	// ¡Œã‚ÌŠg’£‚ÅRenderer“n‚µ‚Ä•`‰æ—\’è
}

void Actor::updateComponents(float deltaTime)
{
	for (auto component : mComponents)
	{
		component->Update(deltaTime);
	}
}

void Actor::AddComponent(Component* component)
{
	//
	mComponents.emplace_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		std::iter_swap(iter, mComponents.end() - 1);
		mComponents.pop_back();
	}
}

void Actor::ProcessInput(GLFWwindow* window, float deltaTime)
{
	for (Component* c : mComponents)
	{
		c->ProcessInput(window, deltaTime);
	}
}
