#include <glad/glad.h>; // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Shader
{
public:
	Shader(const char* vs, const char* fs);
	~Shader();

	void use();
	unsigned int getId() {
		return shaderProgramId;
	}
	
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgramId, name.c_str()), (int)value);
	}
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgramId, name.c_str()), value);
	}
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(shaderProgramId, name.c_str()), value);
	}
	void setFloat4(const std::string& name, float value1, float value2, float value3, float value4) const
	{
		glUniform4f(glGetUniformLocation(shaderProgramId, name.c_str()),value1,value2,value3,value4);
	}

	/*int vertexColorLocation = glGetUniformLocation(shader.getId(), "newColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);*/


private:
	

	std::string loadShaderSrc(const char* filePath);
	unsigned int shaderProgramId;
};

Shader::Shader(const char* vs, const char* fs)
{
	shaderProgramId = glCreateProgram();

	// vs
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	string vertexShaderSource = loadShaderSrc(vs);
	const char* vShaderCode = vertexShaderSource.c_str();
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);
	
	// fs
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	string fragmentShaderSource = loadShaderSrc(fs);
	const char* fShaderCode = fragmentShaderSource.c_str();
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);


	// link vs and fs
	glAttachShader(shaderProgramId, vertexShader);
	glAttachShader(shaderProgramId, fragmentShader);
	glLinkProgram(shaderProgramId);
}

std::string Shader::loadShaderSrc(const char* filePath) {
	ifstream file;     // 文 件
	stringstream buf;  // 文件buffer
	string ret = "";   // 读取文件到 ret

	file.open(filePath);

	if (file.is_open()) {
		buf << file.rdbuf();   // 将文件读取至buf
		ret = buf.str();
	}
	else {
		cout << "can not open file" << endl;
	}
	file.close();

	return ret;
}

void Shader::use() {
	glUseProgram(shaderProgramId);
}

Shader::~Shader()
{
	glDeleteProgram(shaderProgramId);
}