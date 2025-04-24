// context control

#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

class Renderer
{
public:
	Renderer();

	~Renderer();


	void Initialize(GLFWwindow* window);

	void BeginFrame();

	void Draw();

	//void DrawMesh(Mesh* mesh, Shader* shader);

	void EndFrame();

	Shader* GetShader() const { return mShader; }

private:
	Shader* mShader = nullptr;

	GLuint mVAO = 0;
	GLuint mVBO = 0;

	GLFWwindow* mWindow = nullptr;
};