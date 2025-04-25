#pragma once

#include "Actor.h"
#include "ModelData.h"

#include "TransformComponent.h"

#include <vector>
#include <memory>

//utils factory Actor* CreateModselActor()

class Test3DActor : public Actor
{
public:
	Test3DActor(class Game* game);

private:

	ModelData mModel;

	std::vector<Mesh*> mMeshes;

	TransformComponent* mTransform;
	//std::vector<std::unique_ptr<class Mesh>> mMeshes;// OpenGL Buffer

};