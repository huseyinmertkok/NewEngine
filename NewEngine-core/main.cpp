#include "src/graphics/window.h"

#include "src/maths/maths.h"

int main() {

	using namespace newengine;
	using namespace graphics;
	using namespace maths;

	Window window("New Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 10.f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vector2 a(1.0f, 2.0f);
	Vector2 b(1.0f, 2.0f);

	Vector2 c = a + b;

	Matrix4 position = Matrix4::translation(Vector3(2, 3, 4));

	Vector4 column2 = position.columns[2];

	std::cout << &position.elements[4] << std::endl;

	std::cout << &position.columns[1].x << std::endl;

	while (!window.closed()) {
		window.clear();

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();

		//glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}