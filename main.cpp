#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//Vertex Shader Source
const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main()
        {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
        }
    )";

//Fragment Shader Source 1
const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main()
        {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )";

//Fragment Shader Source 2
const char* fragmentShaderSource2 = R"(
        #version 330 core
        out vec4 FragColor;
        void main()
        {
            FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
        }
    )";

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
    glViewport(0, 0, 800, 600);

    //Set a callback to update the viewport when the window is resized.
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

    //Test verticies triangle.
    float verticies[] = {
        -0.5f,  0.3f, 0.f,
        -0.8f, -0.3f, 0.f,
        -0.2f, -0.3f, 0.f,
         0.5f,  0.3f, 0.f,
         0.8f, -0.3f, 0.f,
         0.2f, -0.3f, 0.f,
    };

    //Generate the vertex array object
    unsigned int VAO1, VAO2;
    glGenVertexArrays(1, &VAO1);
    glGenVertexArrays(1, &VAO2);

    //Generate the vertex buffer object
    unsigned int VBO1, VBO2;
    glGenBuffers(1, &VBO1);
    glGenBuffers(1, &VBO2);

    //Generate the element buffer object
    //unsigned int EBO;
    //glGenBuffers(1, &EBO);

    //Bind the vertex array object
    glBindVertexArray(VAO1);

    //Bind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);

    //Bind the element buffer
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //Copy the vertex data into the buffer's memory.
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    //Copy the index data into the element buffer's memory.
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

    //Specify the vertex attribute and enable them
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Do the same for the second triangle.
    glBindVertexArray(VAO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Unbind EBO after VAO
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //Create the vertex shader.
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    //Assign and compile the vertex shader source.
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //Check for vertex shader's compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Create the fragment shader.
    unsigned int fragmentShader, fragmentShader2;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);

    //Assign and compile the fragment shader source.
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //Check for fragment shader's compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Do the same for the second fragment shader.
    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShader2);

    glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Create a shader program
    unsigned int shaderProgram, shaderProgram2;
    shaderProgram = glCreateProgram();
    shaderProgram2 = glCreateProgram();

    //Attach the vertex and fragment shader and link them
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    //Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //Do the same for the second shader program
    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);

    glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //Activate the shader program
    glUseProgram(shaderProgram);

    //Delete the shaders since it's already linked to the program.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //render loop
    while (!glfwWindowShouldClose(window))
    {
        //Specify what color to clear the color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        glUseProgram(shaderProgram2);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 3, 3);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Delete the VAO, VBO, and shader program
    glDeleteVertexArrays(1, &VAO1);
    glDeleteVertexArrays(1, &VAO2);
    glDeleteBuffers(1, &VBO1);
    glDeleteBuffers(1, &VBO2);
    //glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;   
}