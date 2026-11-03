/*****************************************************************//*!
\file   main.cpp
\brief  Open a GLFW window and draw a triangle.

\note
    This class is highly based on the Shader class tutorial from LearnOpenGL,
    authored by Joey de Vries.
    License: CC BY-NC 4.0
    Reference: https://learnopengl.com/Getting-started/
*//******************************************************************/

//#include <iostream>
//#include "SakuraEngine/graphics/Shader.h"
//
//void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//
//int main()
//{
//    //Set the viewport.
//    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
//
//    //Set a callback to update the viewport when the window is resized.
//    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
//
//    //render loop
//    while (!glfwWindowShouldClose(window))
//    {
//        //Activate the shader.
//        shader.Use();
//    }
//}

#include "SakuraEngine.h"

class ExampleLayer : public SKR::Layer
{
public:
    ExampleLayer() : Layer{ "Example" } {}

    void OnUpdate() override {  }

    void OnEvent(SKR::Event& event) override {  }
};

class Sandbox : public SKR::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

SKR::Application* SKR::CreateApplication()
{
    return new Sandbox();
}