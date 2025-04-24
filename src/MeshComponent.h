#pragma once

#include "Component.h"

#include "Mesh.h"
#include "Shader.h"

class MeshComponent : public Component
{
public:
	MeshComponent(class Actor* owner, Mesh* mesh, Shader* shader);
	~MeshComponent();

	void Draw() const;

	void SetMesh(Mesh* mesh) { mMesh = mesh; }
	void SetShader(Shader* shader) { mShader = shader; }

private:
	Mesh* mMesh;
	Shader* mShader;
};