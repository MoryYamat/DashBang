// OpenGL Buffers

#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>

#include <vector>

#include "ModelData.h"

//struct Vertex {
//	glm::vec3 Position;
//};

class Mesh
{
public:
	Mesh(const std::vector<VertexData>& vertices, const std::vector<unsigned int>& indices);

	Mesh(MeshData&& data);

	~Mesh();

	void Draw() const;

	std::vector<VertexData> GetVertexArray() { return mVertices; }
	unsigned int GetNumIndices() { return static_cast<unsigned int>(mIndices.size()); }

private:
	
	std::vector<VertexData> mVertices;
	std::vector<unsigned int> mIndices;

	GLuint mVAO = 0;
	GLuint mVBO = 0;
	GLuint mEBO = 0;


	// set OpenGL Buffers
	void setupMesh();

};