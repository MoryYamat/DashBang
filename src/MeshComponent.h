#pragma once

#include "Component.h"

#include "Mesh.h"
#include "Shader.h"

class MeshComponent : public Component
{
public:
	MeshComponent(class Actor* owner);
	MeshComponent(class Actor* owner, Mesh* mesh);
	~MeshComponent();


	void SetVisible(bool visible) { mVisible = visible; }
	bool GetVisible() const { return mVisible; }

	void Draw(Shader* shader) const;

	virtual void SetMesh(class Mesh* mesh) { mMesh = mesh; }

	const class Mesh* GetMesh() const { return mMesh; }

	//void SetMesh(Mesh* mesh) { mMesh = mesh; }
	//void SetShader(Shader* shader) { mShader = shader; }

protected:

	Mesh* mMesh;

	bool mVisible;
};