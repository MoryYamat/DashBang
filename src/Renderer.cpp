#include "Renderer.h"

#include <iostream>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	if (mShader)
	{
		delete mShader;
		mShader = nullptr;
	}

	//if (mVBO) glDeleteBuffers(1, &mVBO);
	//if (mVAO) glDeleteBuffers(1, &mVAO);
}

void Renderer::Initialize(GLFWwindow* window)
{

	float vertices[] = {
	0.0f, 0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f
	};

	mWindow = window;

	// スマートポインタは？
	// スマートポインタは？
	// スマートポインタは？
	mShader = new Shader("shaders/basic.vertex.glsl", "shaders/basic.fragment.glsl");

	glViewport(0, 0, 1280, 720);
	glEnable(GL_DEPTH_TEST);

	std::cout << "[Renderer.h] Renderer initialization succeeded!" << std::endl;

}

// 描画ライフサイクルを細分化することで、拡張性やデバッグをやりやすくする

// バッファクリア
void Renderer::BeginFrame()
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw()
{
	mShader->use();

}

// バッファスワップ
void Renderer::EndFrame()
{
	glfwSwapBuffers(mWindow);
}