#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Printer/printer.hpp"

void process_input(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {

    glfwInit(); // Initialize the GLFW library

    // Set hints for the next call to glfwCreatWindow
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Set the callback for resizing the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD manages function pointers for OpenGL. We need to initialize GLAD
    // before we call any OpenGL function.
    // We pass GLAD the function to load the address of the OpenGL function
    // pointers. GLFW provides 'glfwGetProcAddress' that defines the correct
    // function based on the OS.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        process_input(window);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events
        // Checks if any events are triggered. Events are registered to via a 
        // callback.
        glfwPollEvents();

        // Will swap the color buffer that is used for the render iteration and
        // show it as output to the screen.
        glfwSwapBuffers(window);

    }

    glfwTerminate();
    return 0;
}

void process_input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
