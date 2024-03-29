#include "Workspace.h"
#include "GL/glut.h"

Workspace::Workspace() {
	axesLength = 10;
}

Workspace::Workspace(int length) {
	axesLength = length;
}

void Workspace::Draw() {
	DrawXYZAxes();
	DrawFloor();
}

void Workspace::DrawXYZAxes() {
	// XYZ���̕`��
	glBegin(GL_LINES);
	{
		glColor3d(1.0, 1.0, 0.0);	// yellow
		glVertex3d(0.0, 0.0, 0.0); glVertex3d(axesLength, 0.0, 0.0);	//x-axis
		glColor3d(1.0, 0.0, 0.0);	// red
		glVertex3d(0.0, 0.0, 0.0); glVertex3d(0.0, axesLength, 0.0);	//y-axis
		glColor3d(0.0, 0.0, 1.0);	// blue
		glVertex3d(0.0, 0.0, 0.0); glVertex3d(0.0, 0.0, axesLength);	//z-axis
	}
	glEnd();
}

void Workspace::DrawFloor()
{
	glColor3d(1.0, 1.0, 1.0);		// draw floor
	glBegin(GL_LINES);
	for (int i = -63; i < 64; i++) {
		glVertex3i(i * 2, 0, -256);
		glVertex3i(i * 2, 0, 256);
		glVertex3i(-256, 0, i * 2);
		glVertex3i(256, 0, i * 2);
	}
	glEnd();
}
