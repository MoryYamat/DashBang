#include "Renderer.h"

#include <algorithm>
#include <iostream>

Renderer::Renderer(Game* game)
	: mGame(game)
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

bool Renderer::Initialize(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		std::cout << "[Renderer.cpp (GLFW)]: Failed to initialize GLFW" << std::endl;
		return false;
	}

	// need to fix the hardcode
	// 中枢リソースなのでGame.h/.cpp　でリソースを保持
	mWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!mWindow)
	{
		std::cout << "[Renderer.cpp (GLFW)]: Failed to initialize GLFW" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(mWindow);

	glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[Renderer.cpp (GLAD)]: Failed to initialize GLAD" << std::endl;
		return false;
	}

	// スマートポインタは？
	// スマートポインタは？
	// スマートポインタは？
	mShader = new Shader("shaders/basic.vertex.glsl", "shaders/basic.fragment.glsl");

	glViewport(0, 0, 1280, 720);
	glEnable(GL_DEPTH_TEST);

	std::cout << "[Renderer.cpp (Initialize)]: Renderer initialization succeeded!" << std::endl;

	return true;
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
	// settinig OpenGL Context
	mShader->use();

	mShader->setMat4("view", mCameraComponent->GetViewMatrix());
	mShader->setMat4("projection", mCameraComponent->GetProjectionMatrix());

	// 描画する必要のあるactorをすべて描画
	for (auto mc : mMeshComps)
	{
		if (mc->GetVisible())
		{
			// mc->GetMesh()->Draw();
			mc->Draw(mShader);
		}
	}
}

// バッファスワップ
void Renderer::EndFrame()
{
	glfwSwapBuffers(mWindow);
}

void Renderer::AddMeshComp(MeshComponent* mesh)
{
	mMeshComps.emplace_back(mesh);
}

void Renderer::RemoveMeshComp(MeshComponent* mesh)
{
	auto iter = std::find(mMeshComps.begin(), mMeshComps.end(), mesh);
	mMeshComps.erase(iter);
}