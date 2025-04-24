#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "Game.h"

#include "Component.h"

class Actor
{
public:
	enum class State {
		Active,
		Paused,
		Dead
	};


	Actor(class Game* game);
	virtual ~Actor();

	virtual void Update(float deltaTime);
	virtual void Draw();// Draw(Renderer&)

	//Components
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);
	void updateComponents(float deltaTime);


	// Transform
	void SetPosition(const glm::vec3& pos) { mPosition = pos; }
	void SetScale(const glm::vec3& scale) { mScale = scale; }
	void SetRotation(const glm::vec3& rotation) { mRotation = rotation; }

	const glm::vec3& GetPosition() const { return mPosition; }
	const glm::vec3& GetScale() const { return mScale; }
	const glm::vec3& GetRotation() const { return mRotation; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	// Actor.h ‚É’Ç‰Á
	const std::vector<Component*>& GetComponents() const { return mComponents; }

	class Game* GetGame() { return mGame; }

private:

	class Game* mGame;
	State mState = State::Active;

	// Transform
	glm::vec3 mPosition = glm::vec3(0.0f);
	glm::vec3 mScale = glm::vec3(1.0f);
	glm::vec3 mRotation = glm::vec3(0.0f);

	std::vector<Component*> mComponents;
};