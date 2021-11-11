#include <GLFW/glfw3.h>

#include "./Chessboard/Chessboard.h"

int main() {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	Chessboard Board;
	Board.PrintBoard();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS);
		glVertex2f(-0.1f, 0.1f); // top left
		glVertex2f(0.1f, 0.1f); // top right
		glVertex2f(0.1f, -0.1f); // bottom right
		glVertex2f(-0.1f, -0.1f); // bottom left
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}