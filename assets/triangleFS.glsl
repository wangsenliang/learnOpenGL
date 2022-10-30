#version 330 core

out vec4 FragColor;
in vec3 Color;    // 顶点颜色  从vs中拿到的
in vec2 TexCoord;       // 纹理坐标   从vs中拿到的

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
void main()
{
//	FragColor = vec4(texture(ourTexture, TexCoord).xyz, 1);
//	FragColor = texture(ourTexture, TexCoord);

//	FragColor = vec4(Color, 1);

//	FragColor = vec4(Color, 1)* texture(ourTexture, TexCoord);

	vec3 Texture1 = texture(ourTexture1, TexCoord).xyz;
	vec3 Texture2 = texture(ourTexture2, TexCoord).xyz;
	FragColor = vec4(mix(Texture1, Texture2, 0.8), 1);
}