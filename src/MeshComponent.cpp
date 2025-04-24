#include "MeshComponent.h"

#include "Actor.h"

#include <glm/gtc/matrix_transform.hpp>

MeshComponent::MeshComponent(Actor* owner, Mesh* mesh, Shader* shader)
	: Component(owner)
	, mMesh(mesh)
	, mShader(shader)
{

}

MeshComponent::~MeshComponent()
{

}

void MeshComponent::Draw() const
{
	if (mMesh && mShader)
	{
		mShader->use();

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, GetOwner()->GetPosition());

		//model = glm::rotate(model, GetOwner()->GetRotation().x, glm::vec3(1.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, GetOwner()->GetRotation().y, glm::vec3(0.0f, 1.0f, 0.0f));
		//model = glm::rotate(model, GetOwner()->GetRotation().z, glm::vec3(0.0f, 0.0f, 1.0f));

		model = glm::scale(model, GetOwner()->GetScale());

		mShader->setMat4("model", model);

		mMesh->Draw();
	}
}