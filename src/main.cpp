#include <GLFW/glfw3.h>

#include "./Chessboard/Chessboard.h"

int main() {
	GLFWwindow* window;

	Start(window);

	/* Loop until the user closes the window */
	Update(window);

	glfwTerminate();
	return 0;
}

int Start(GLFWwindow* window) {
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

		/* Make the window's context current */
	glfwMakeContextCurrent(window);

	Chessboard Board;
	Board.PrintBoard();
}

void Update(GLFWwindow* window) {
	while (!glfwWindowShouldClose(window)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
}