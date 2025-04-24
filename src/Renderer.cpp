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

	// �X�}�[�g�|�C���^�́H
	// �X�}�[�g�|�C���^�́H
	// �X�}�[�g�|�C���^�́H
	mShader = new Shader("shaders/basic.vertex.glsl", "shaders/basic.fragment.glsl");

	glViewport(0, 0, 1280, 720);
	glEnable(GL_DEPTH_TEST);

	std::cout << "[Renderer.h] Renderer initialization succeeded!" << std::endl;

}

// �`�惉�C�t�T�C�N�����ו������邱�ƂŁA�g������f�o�b�O�����₷������

// �o�b�t�@�N���A
void Renderer::BeginFrame()
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw()
{
	mShader->use();

}

// �o�b�t�@�X���b�v
void Renderer::EndFrame()
{
	glfwSwapBuffers(mWindow);
}