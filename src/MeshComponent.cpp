#include "MeshComponent.h"

#include "Actor.h"

#include "TransformComponent.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

MeshComponent::MeshComponent(Actor* owner)
	: Component(owner)
	, mMesh(nullptr)
	, mVisible(true)
{
	mOwner->GetGame()->GetRenderer()->AddMeshComp(this);

}

MeshComponent::MeshComponent(Actor* owner, Mesh* mesh)
	: Component(owner)
	, mMesh(mesh)
	, mVisible(true)
{
	mOwner->GetGame()->GetRenderer()->AddMeshComp(this);
}

MeshComponent::~MeshComponent()
{
	std::cout << "[Mesh Component.cpp]: Destructed " << std::endl;
	mOwner->GetGame()->GetRenderer()->RemoveMeshComp(this);
}

// 
void MeshComponent::Draw(Shader* shader) const
{
	TransformComponent* transform = mOwner->GetComponent<TransformComponent>();
	glm::mat4 model = transform->GetWorldTransform();

	shader->setMat4("model", model);

	mMesh->Draw();


	//glDrawElements(GL_TRIANGLES, mMesh->GetNumIndices(), GL_UNSIGNED_INT, nullptr);

}