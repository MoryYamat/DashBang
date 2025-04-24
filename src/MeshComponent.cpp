#include "MeshComponent.h"

#include "Actor.h"

#include <glm/gtc/matrix_transform.hpp>

MeshComponent::MeshComponent(Actor* owner)
	: Component(owner)
	, mMesh(nullptr)
	, mVisible(true)
{
	mOwner->GetGame()->GetRenderer()->AddMeshComp(this);
}

MeshComponent::~MeshComponent()
{
	mOwner->GetGame()->GetRenderer()->RemoveMeshComp(this);
}

// 
void MeshComponent::Draw(Shader* shader) const
{
	//if (mMesh)
	//{
	//	mMesh->Draw();
	//	//glDrawElements(GL_TRIANGLES, mMesh->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
	//}
}