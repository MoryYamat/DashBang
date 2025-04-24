#pragma once

#include <GLAD/glad.h>
#include <GLM/glm.hpp>

#include <vector>

struct Vertex {
	glm::vec3 Position;
};

class Mesh
{
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
	~Mesh();

	void Draw() const;

private:
	
	std::vector<Vertex> mVertices;
	std::vector<unsigned int> mIndices;

	GLuint mVAO = 0;
	GLuint mVBO = 0;
	GLuint mEBO = 0;


	void setupMesh();

};