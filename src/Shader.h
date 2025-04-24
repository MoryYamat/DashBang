#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include <GLM/glm.hpp>

#include <string>

class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void use() const;

	GLuint GetProgram() const;

	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, const glm::vec3& vec) const;
	void setVec4(const std::string& name, const glm::vec4& vec) const;
	void setMat4(const std::string& name, const glm::mat4& mat) const;


private:
	// single responsibility

	std::string loadFile(const std::string& path);

	GLuint compileShader(GLenum type, const std::string& code);

	bool checkCompileErrors(GLuint shader);

	bool checkLinkStatus(GLuint program);

	GLuint mProgramID;
};