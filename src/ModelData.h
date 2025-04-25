#pragma once

#include <GLM/glm.hpp>
//#include <GLM/gtc/matrix_transform.hpp>

#include <vector>

#define MAX_BONE_INFLUENCE 4

//
//enum class VertexAttribType
//{
//	Float3, Float2, Int4, Flot4
//};

struct VertexData {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 tangent;
	glm::vec3 bitangent;

	int boneIDs[MAX_BONE_INFLUENCE] = { 0 };
	float weights[MAX_BONE_INFLUENCE] = { 0 };
};

struct MeshData
{
	std::vector<VertexData> vertices;
	std::vector<unsigned int> indices;


};

struct ModelData
{
	std::vector<MeshData> meshes;
};

// 所有権を委譲して、コピーを減らす
//Mesh::Mesh(MeshData&& data) {
//	mVertices = std::move(data.vertices);
//	mIndices = std::move(data.indices);
//}


//enum class VertexAttribType {
//	Float3, Float2, Int4, Float4
//};
//
//struct VertexAttrib {
//	std::string name; // "position", "normal", ...
//	VertexAttribType type;
//	size_t offset;
//};
//
//struct VertexLayout {
//	size_t stride;
//	std::vector<VertexAttrib> attributes;
//};
