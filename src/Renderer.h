// context control

#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Game.h"

#include "Shader.h"
#include "MeshComponent.h"

class Renderer
{
public:
	Renderer(class Game* game);

	~Renderer();


	bool Initialize(int width, int height, const char* title);

	void BeginFrame();
	void Draw();
	void EndFrame();

	Shader* GetShader() const { return mShader; }

	void AddMeshComp(class MeshComponent* mesh);
	void RemoveMeshComp(class MeshComponent* mesh);

	GLFWwindow* GetWindow() const { return mWindow; }

private:
	class Game* mGame;

	GLFWwindow* mWindow = nullptr;


	class Shader* mShader = nullptr;

	class Shader* mMeshShader = nullptr;

	std::vector<class MeshComponent*> mMeshComps;

	GLuint mVAO = 0;
	GLuint mVBO = 0;

};

// Rendering Pipeline
// Game::generateOutput() ->
// Renderer::Draw() ->
// MeshComponent::mMesh -> 
// Mesh::Draw()
//