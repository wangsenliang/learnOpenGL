#version 330 core
layout (location = 0) in vec3 aPos;   // vertex data �е�λ������
layout (location = 1) in vec3 aColor; // vertex data �е���ɫ����
layout (location = 2) in vec2 aTexCoord;    // vertex data �е���������


out vec2 TexCoord;
out vec3 Color;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   TexCoord = aTexCoord;
   Color = aColor;
}