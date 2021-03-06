#include "SkyBox.h"
#include "GameData.h"
#include "Transform.hpp"

#define WORLDSIZE 170

SkyBox::SkyBox() {
	texture = new Texture("textures/sky.ppm");
}

SkyBox::~SkyBox() {

}

void SkyBox::Update() {

}

void SkyBox::Draw() {
	texture->SetTexture();
	glEnable(GL_TEXTURE_2D);

	//四角形ポリゴン
	//z+方向
	glBegin(GL_QUADS);
	{
		glVertex3d(WORLDSIZE, WORLDSIZE, WORLDSIZE);
		glVertex3d(WORLDSIZE, 0, WORLDSIZE);
		glVertex3d(-WORLDSIZE, 0, WORLDSIZE);
		glVertex3d(-WORLDSIZE, WORLDSIZE, WORLDSIZE);
	}
	glEnd();
	//z-方向
	glBegin(GL_QUADS);
	{
		glVertex3d(-WORLDSIZE, WORLDSIZE, -WORLDSIZE);
		glVertex3d(-WORLDSIZE, 0, -WORLDSIZE);
		glVertex3d(WORLDSIZE, 0, -WORLDSIZE);
		glVertex3d(WORLDSIZE, WORLDSIZE, -WORLDSIZE);
	}
	glEnd();
	//x-方向
	glBegin(GL_QUADS);
	{
		glVertex3d(-WORLDSIZE, WORLDSIZE, WORLDSIZE);
		glVertex3d(-WORLDSIZE, 0, WORLDSIZE);
		glVertex3d(-WORLDSIZE, 0, -WORLDSIZE);
		glVertex3d(-WORLDSIZE, WORLDSIZE, -WORLDSIZE);
	}
	glEnd();
	//x+方向
	glBegin(GL_QUADS);
	{
		glVertex3d(WORLDSIZE, WORLDSIZE, -WORLDSIZE);
		glVertex3d(WORLDSIZE, 0, -WORLDSIZE);
		glVertex3d(WORLDSIZE, 0, WORLDSIZE);
		glVertex3d(WORLDSIZE, WORLDSIZE, WORLDSIZE);
	}
	glEnd();

	//y+方向
	glBegin(GL_QUADS);
	{
		glVertex3d(WORLDSIZE, WORLDSIZE, -WORLDSIZE);
		glVertex3d(WORLDSIZE, WORLDSIZE, WORLDSIZE);
		glVertex3d(-WORLDSIZE, WORLDSIZE, WORLDSIZE);
		glVertex3d(-WORLDSIZE, WORLDSIZE, -WORLDSIZE);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}