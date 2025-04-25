#include "Test3DActor.h"

#include "AssimpImporter.h"

#include "Mesh.h"

#include <iostream>

Test3DActor::Test3DActor(Game* game)
	: Actor(game)
{
	mTransform = new TransformComponent(this);

	// path?
	ModelData model = AssimpImporter::Import("Assets/Models/Ch44_nonPBR.fbx");
	mModel = std::move(model);

	for (auto& meshData : mModel.meshes)
	{
		Mesh* mesh = new Mesh(std::move(meshData));
		new MeshComponent(this, mesh);
		mMeshes.push_back(mesh);
	}

	mTransform->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	mTransform->SetScale(glm::vec3(0.1f));

	std::cout << "[Test3DActor]: Load completed with " << mModel.meshes.size() << "meshes." << std::endl;
}