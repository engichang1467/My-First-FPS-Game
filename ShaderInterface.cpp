#include "ShaderInterface.h"
#include <stdio.h>
#include <stdlib.h>

GLuint ShaderInterface::getProgramHandle()
{
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex()
{
    return _aPositionVertex;
}

GLint ShaderInterface::get_uColor()
{
    return _uColor;
}

ShaderInterface::ShaderInterface(char *VS, char *FS)
{
    _vertexShaderString = loadTextFromFile(VS);
    _fragmentShaderString = loadTextFromFile(FS);

    shader = new ShaderLoader(_vertexShaderString, _fragmentShaderString);

    free(_vertexShaderString);
    free(_fragmentShaderString);

    _aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");

    _uColor = glGetUniformLocation( shader->getProgramHandle(), "uColor");
}

ShaderInterface::~ShaderInterface()
{
    delete shader;
}

char *ShaderInterface::loadTextFromFile(char *file)
{
    FILE *currentFile = fopen(file, "rt");
    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile);   

    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count +1));
    count = (int)fread(data, sizeof(char), count, currentFile);
    data[count] = '\0';

    fclose(currentFile);

    return data;
}