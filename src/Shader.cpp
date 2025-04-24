#include "Shader.h"

#include <iostream>
#include <sstream>
#include <fstream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string vertexCode = loadFile(vertexPath);
	std::string fragmentCode = loadFile(fragmentPath);

	GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode);
	GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

	mProgramID = glCreateProgram();
	glAttachShader(mProgramID, vertexShader);
	glAttachShader(mProgramID, fragmentShader);
	glLinkProgram(mProgramID);

	if (!checkLinkStatus(mProgramID))
	{
		std::cout << "[Shader.cpp] Failed to link program." << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

// destructor
Shader::~Shader()
{
	glDeleteProgram(mProgramID);
}

// use
void Shader::use() const
{
	glUseProgram(mProgramID);
}

// 
GLuint Shader::GetProgram() const
{
	return mProgramID;
}

// load from glsl
std::string Shader::loadFile(const std::string& path)
{
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

// compile shader
GLuint Shader::compileShader(GLenum type, const std::string& code)
{
	GLuint shader = glCreateShader(type);
	const char* source = code.c_str();
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	if (!checkCompileErrors(shader))
	{
		std::cout << "[Shader.h] Compilation Failed." << std::endl;
	}

	return shader;
}

// check compile 
bool Shader::checkCompileErrors(GLuint shader)
{
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cout << "[Shader.h] Compile Error: " << infoLog << std::endl;
		return false;
	}

	return true;
}

// checkl link
bool Shader::checkLinkStatus(GLuint program)
{
	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << "[Shader] Link error: " << infoLog << std::endl;
		return false;
	}
	return true;
}

void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(mProgramID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(mProgramID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	glUniform1i(glGetUniformLocation(mProgramID, name.c_str()), (float)value);
}

void Shader::setVec3(const std::string& name, const glm::vec3& vec) const
{
	glUniform3fv(glGetUniformLocation(mProgramID, name.c_str()), 1, &vec[0]);
}

void Shader::setVec4(const std::string& name, const glm::vec4& vec) const
{
	glUniform4fv(glGetUniformLocation(mProgramID, name.c_str()), 1, &vec[0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(mProgramID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}