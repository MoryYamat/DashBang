#pragma once 

#include "ModelData.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>

// stateless
class AssimpImporter
{
public:
	static ModelData Import(const std::string& path);

private:
	static void processNode(aiNode* node, const aiScene* scene, ModelData& modelData);

	static MeshData processMesh(aiMesh* mesh, const aiScene* scene, ModelData& modelData);

};