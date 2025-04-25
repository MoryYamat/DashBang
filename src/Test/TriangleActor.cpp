#include "TriangleActor.h"
#include "Game.h"
#include "MeshComponent.h"
#include "Mesh.h"
#include "Shader.h"

#include <vector>
#include <iostream>

TriangleActor::TriangleActor(Game* game)
	: Actor(game)
{
	std::vector<VertexData> vertices = {
	{ {0.0f,  0.5f, 0.0f} },
	{ {-0.5f, -0.5f, 0.0f} },
	{ {0.5f, -0.5f, 0.0f} }
	};
	
	std::vector<unsigned int> indices = { 0 ,1, 2 };

	Mesh* mesh = new Mesh(vertices, indices);

	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(mesh);

	std::cout << "[TEST/TriangleActor ]: triangle generated" << std::endl;
}