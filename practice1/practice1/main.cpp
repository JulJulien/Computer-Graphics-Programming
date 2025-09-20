#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"

// To make a build, copy and paste the glew32.dll file into the inner folder named after this project.
using namespace std;
#define numVAOs 1

float x = 0.0f;		// location of triangle on x axis
float inc = 0.01f;	// offset fro moving the triangle

// Graphics Language unsigned int = GLuint
GLuint renderingProgram;
GLuint vao[numVAOs];

// initializes a window where we can draw 3D scenes. Add initializing code here.
void init(GLFWwindow* window){
	renderingProgram = createShaderProgram();
	glGenVertexArrays(numVAOs, vao);	// Data is organized into buffers. The buffers are organized inot VAO Virtual Array Objects
	glBindVertexArray(vao[0]);
}
  
// display function is called constantly, and is where we write code that draws to the window.
void display(GLFWwindow* window, double currentTime) {
	// clear the background to black, each time
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);	

	glUseProgram(renderingProgram);

	x += inc;						// move triangle along x axis
	if (x > 1.0f)inc = -0.01f;		//switch to moving the triangle to the left
	if (x < -1.0f)inc = 0.01f;		// switch to moving the triangle to the right
	GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");	// get ptr to "offset"
	glProgramUniform1f(renderingProgram, offsetLoc, x);		// send value in "x" to "offset"

	glUseProgram(renderingProgram);		// Loads shaders onto GPU Hardware
	glPointSize(30.0f);		// 30 pixels  instead of 1
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, 3);	// Initiates pipeline processing

	Timer(currentTime);
}

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);}

	// Using OpenGL 4.4, naming the window, sizing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	GLFWwindow* window = glfwCreateWindow(1000, 1000, "Chapter2-program1", NULL, NULL);
	glfwMakeContextCurrent(window);
	
	if (glewInit() != GLEW_OK) { 
		exit(EXIT_FAILURE);}

	glfwSwapInterval(1);
	init(window);

	// display is repeatedly called until the window is closed.
	while (!glfwWindowShouldClose(window)){
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}