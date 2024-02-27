#include <glad/glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const GLuint SCR_WIDTH = 800;
const GLuint SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n" \
                                 "layout (location = 0) in vec3 aPos;\n" \
                                 "void main()\n" \
                                 "{\n" \
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" \
                                 "}\0";

const char* fragmentShaderSource = "#version 330 core\n" \
                                   "out vec4 FragColor;\n;" \
                                   "void main()\n" \
                                   "{\n" \
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" \
                                   "}\n\0";

const char* fragmentShaderSource_1 = "#version 330 core\n" \
                                   "out vec4 FragColor;\n;" \
                                   "void main()\n" \
                                   "{\n" \
                                   "   FragColor = vec4(1.0f, 0.2f, 0.5f, 1.0f);\n" \
                                   "}\n\0";

int main(void)
{
    // glfw: initilize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw: window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (NULL == window) {
        puts("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        puts("Failed to initialize GLAD");
        return -1;
    }

    // build and compile our shader program
    // vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s", infoLog);
    }

    // fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile erroes
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s", infoLog);
    }

    GLuint fragmentShader_1 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader_1, 1, &fragmentShaderSource_1, NULL);
    glCompileShader(fragmentShader_1);
    // check for shader compile erroes
    glGetShaderiv(fragmentShader_1, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader_1, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT_1::COMPILATION_FAILED\n%s", infoLog);
    }

    // link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s", infoLog);
    }
    glDeleteShader(fragmentShader);

    GLuint shaderProgram_1 = glCreateProgram();
    glAttachShader(shaderProgram_1, vertexShader);
    glAttachShader(shaderProgram_1, fragmentShader_1);
    glLinkProgram(shaderProgram_1);
    // check linking errors
    glGetProgramiv(shaderProgram_1, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram_1, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM_1::LINKING_FAILED\n%s", infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader_1);

    float vertices[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f,

        0.0f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
        0.25f,  1.0f, 0.0f,
    };

    float vertices_1[] = {
       -0.75f, -1.0f, 0.0f,
       -0.25f, -1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,
    };
    
    GLuint VBO;
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    GLuint VBO_1;
    GLuint VAO_1;
    glGenVertexArrays(1, &VAO_1);
    glGenBuffers(1, &VBO_1);
    glBindVertexArray(VAO_1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glUseProgram(shaderProgram_1);
        glBindVertexArray(VAO_1);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO_1);
    glDeleteBuffers(1, &VBO_1);
    glDeleteProgram(shaderProgram);
    glDeleteProgram(shaderProgram_1);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        glfwSetWindowShouldClose(window, true);
    }
}

