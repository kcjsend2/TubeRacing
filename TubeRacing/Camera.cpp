#include "framework.h"
#include "Camera.h"

void Camera::Render(GLuint ShaderProgram)
{
	// ���� ����
	glUseProgram(ShaderProgram);
	glm::mat4 Projection = glm::mat4(1.0f);
	Projection = glm::perspective(glm::radians(45.0f), (float)1000 / (float)1000, 0.1f, 100.0f);
	unsigned int ProjectionLocation = glGetUniformLocation(ShaderProgram, "projectionTransform");;
	glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, &Projection[0][0]);

	// ī�޶� �ʱ�ȭ
	glm::vec3 cameraPos = glm::vec3(posx, posy, posz);
	glm::vec3 cameraDirection = AT;
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 view = glm::mat4(1.0f);

	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	unsigned int viewLocation = glGetUniformLocation(ShaderProgram, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
}