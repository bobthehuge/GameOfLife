#include "common.h"

void WindowRunloop(GLFWwindow* window, GLuint vao, GLuint tex)
{
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);    

        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
        glfwSwapBuffers(window);
    
        GameUpdate();
        
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, BOARD_WIDTH, BOARD_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, CellBoard);

        sleep(0.4);
    }
}

int main(void)
{   
    float vertices[] = {
    //  Position      Texcoords
        -1.0f,  1.0f,  0.0f, 0.0f, // Top-left
         1.0f,  1.0f,  1.0f, 0.0f, // Top-right
         1.0f, -1.0f,  1.0f, 1.0f, // Bottom-right
        -1.0f, -1.0f,  0.0f, 1.0f // Bottom-left
    };

    GLuint indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };
    
    GameInit();
    glfwInit();
    
    GLFWwindow* window = WindowCreate();
    glfwMakeContextCurrent(window);

    glewInit();

    GLuint vert = NewShader(GL_VERTEX_SHADER, "Shaders/vert.glsl");
    GLuint frag = NewShader(GL_FRAGMENT_SHADER, "Shaders/frag.glsl");

    GLuint shaderProg = glCreateProgram();
    glAttachShader(shaderProg, vert);
    glAttachShader(shaderProg, frag);
    glLinkProgram(shaderProg);

    glDeleteShader(vert);
    glDeleteShader(frag);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    GLint posAttrib = glGetAttribLocation(shaderProg, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float)*4, 0);
    
    GLint texAttrib = glGetAttribLocation(shaderProg, "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float)*4, 
        (void*)(sizeof(float)*2));

    glUseProgram(shaderProg);
    
    GLuint tex = NewTexture(CellBoard);
    WindowRunloop(window, vao, tex);

    glDetachShader(shaderProg, vert);
    glDetachShader(shaderProg, frag);
    glDeleteTextures(1, &tex);
    glfwTerminate();

    return 0;
}
