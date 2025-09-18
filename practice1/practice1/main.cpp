#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// To make a build, copy and paste the glew32.dll file into the inner folder named after this project.
using namespace std;

void init(GLFWwindow* window){}

void display(GLFWwindow* window, double currentTime) {
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2-program1", NULL, NULL);
	glfwMakeContextCurrent(window);
	
	if (glewInit() != GLEW_OK) { 
		exit(EXIT_FAILURE);}

	glfwSwapInterval(1);
	init(window);

	while (!glfwWindowShouldClose(window)){
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}