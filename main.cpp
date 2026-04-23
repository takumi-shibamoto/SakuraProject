/*****************************************************************//*!
\file   main.cpp
\brief  Open a GLFW window and draw a triangle.

\note
    This class is highly based on the Shader class tutorial from LearnOpenGL,
    authored by Joey de Vries.
    License: CC BY-NC 4.0
    Reference: https://learnopengl.com/Getting-started/
*//******************************************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "engine/graphics/Shader.h"

void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLsizei WINDOW_WIDTH = 800;
GLsizei WINDOW_HEIGHT = 600;

int main()
{
    glfwInit();

    //Set the GLFW version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create the window.
    GLFWwindow* window = glfwCreateWindow(800, 600, "Sakura Project", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD." << std::endl;
        return -1;
    }

    //Set the viewport.
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    //Set a callback to update the viewport when the window is resized.
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

    //Test verticies triangle.
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.f, 0.f, 0.f,
         0.5f, -0.5f, 0.0f, 0.f, 1.f, 0.f,
         0.0f,  0.5f, 0.0f, 0.f, 0.f, 1.f
    };

    //Generate the vertex array object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    //Generate the vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    //Generate the element buffer object
    //unsigned int EBO;
    //glGenBuffers(1, &EBO);

    //Bind the vertex array object
    glBindVertexArray(VAO);

    //Bind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //Bind the element buffer
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //Copy the vertex data into the buffer's memory.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Copy the index data into the element buffer's memory.
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

    //Specify the vertex attribute and enable them
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Specify the color attribute and enable them
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Unbind EBO after VAO
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //Create a shader program.
    sakura::Shader shader("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");

    //render loop
    while (!glfwWindowShouldClose(window))
    {
        //Specify what color to clear the color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Activate the shader.
        shader.Use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Delete the VAO, VBO, and shader program
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(1, &EBO);

    glfwTerminate();
    return 0;   
}