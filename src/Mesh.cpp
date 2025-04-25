#include "Mesh.h"

#include <iostream>

Mesh::Mesh(const std::vector<VertexData>& vertices, const std::vector<unsigned int>& indices)
	: mVertices(vertices)
	, mIndices(indices)
{
	setupMesh();
	std::cout << "indices :" << mIndices.size() << std::endl;
}

Mesh::Mesh(MeshData&& data)
    : mVertices(std::move(data.vertices))
    , mIndices(std::move(data.indices))
{
    setupMesh();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1, &mVBO);
	glDeleteBuffers(1, &mEBO);
}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    glGenBuffers(1, &mEBO);

    glBindVertexArray(mVAO);

    // 頂点バッファ設定（Vertexの配列）
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(VertexData), mVertices.data(), GL_STATIC_DRAW);

    // インデックスバッファ設定（mIndices）
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(unsigned int), mIndices.data(), GL_STATIC_DRAW);

    // 頂点属性の設定
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, position));
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    std::cout << "[Mesh.cpp]: Mesh setup completed" << std::endl;
}


void Mesh::Draw() const
{
	glBindVertexArray(mVAO);

	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mIndices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}