#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int secondsPassed;
int lastsecond;


void printShaderLog(GLuint shader) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetShaderInfoLog(shader, len, &chWrittn, log);
		cout << "Shader Info Log:" << log << endl;
		free(log);
	}
}
void printProgramLog(int prog) {
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
	if (len > 0) {
		log = (char*)malloc(len);
		glGetProgramInfoLog(prog, len, &chWrittn, log);
		cout << "Program Info Log:" << log << endl;
		free(log);
	}
}
bool checkOpenGLError() {
	bool foundError = false;
	int glErr = glGetError();
	while (glErr != GL_NO_ERROR) {
		cout << "glErr:" << glErr << endl;
		foundError = true;
		glErr = glGetError();
	}
	return foundError;
}

string readShaderSource(const char* filePath) {
	string content;
	ifstream fileStream(filePath, ios::in);
	string line = "";
	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

GLuint createShaderProgram() {
	GLint vertCompiled;
	GLint fragCompiled;
	GLint linked;

	// Create Shader Objects with glCreateSahder
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);	// vShader is an uint variable that stores the Vertex Shader Object ID
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER); // fShader is a uint variable that stores the Fragment Shader Object ID

	// Vertex processing. Position of vector
	string vertShaderStr = readShaderSource("vertShader.glsl");
	// Fragment processing. Color of vector
	string fragShaderStr = readShaderSource("fragShader.glsl");

	const char* vertShaderSrc = vertShaderStr.c_str();
	const char* fragShaderSrc = fragShaderStr.c_str();

	// Loads the GLS code from our strings into our shader objects
	// glShaderSource( uint variable that stores shader , n string vars in shader source code ,  array of pointers to strings containing source code , secret param )
	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);

	// Compile the Vertex Shaders and check for vertex errors.
	glCompileShader(vShader);
	checkOpenGLError();
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1) {
		cout << "vertex compilation failed" << endl;
		printShaderLog(vShader);
	}
	// Compile the Fragment Shaders and check for fragment errors.
	glCompileShader(fShader);
	checkOpenGLError();
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragCompiled != 1) {
		cout << "fragment compilation failed" << endl;
		printShaderLog(fShader);
	}

	GLuint vfProgram = glCreateProgram();	// Create program object vfProgram
	glAttachShader(vfProgram, vShader);		// attach vShader to the program object
	glAttachShader(vfProgram, fShader);		// attach fShader to the program obejct

	glLinkProgram(vfProgram);				// request GLSL compiler to ensure they're compatible 
	checkOpenGLError();
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1) {
		cout << "linking failed" << endl;
		printProgramLog(vfProgram);
	}

	return vfProgram;
}

void Timer(double currentTime) {
	secondsPassed = int(currentTime);
	if ((secondsPassed != 0)) {
		if (secondsPassed != lastsecond) {
			system("cls");
			cout << secondsPassed;
			lastsecond = secondsPassed;
		}
	}
	else lastsecond = secondsPassed;
}