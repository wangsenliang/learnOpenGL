#version 330 core
layout (location = 0) in vec3 aPos;   // vertex data 中的位置属性
layout (location = 1) in vec3 aColor; // vertex data 中的颜色属性
layout (location = 2) in vec2 aTexCoord;    // vertex data 中的纹理属性


out vec2 TexCoord;
out vec3 Color;

void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   TexCoord = aTexCoord;
   Color = aColor;
}