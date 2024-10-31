#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.h"
#include "Shape.h"

int main(void) {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        return -2;
    }

    float positions[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f,
         0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    // Update shader path here
    Shape* rectangle = new Shape("rectangle", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    Shape::AddShape("rectangle", rectangle);

    Renderer renderer;
    float r = 0.0f;
    float increment = 0.05f;

    while (!glfwWindowShouldClose(window)) {
        renderer.Clear();

        rectangle->Draw(renderer, r);

        if (r > 1.0f) increment = -0.05f;
        else if (r < 0.0f) increment = 0.05f;

        r += increment;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete rectangle; // Clean up
    glfwTerminate();
    return 0;
}
