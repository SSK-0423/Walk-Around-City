#include "SpyderLeg.h"
#include <math.h>
#define PI 3.141592

SpyderLeg::SpyderLeg()
{
	animator = nullptr;
	legRotateY = 15;
	legRotateZ = 30;
	firstJointRotate = 90;
	secondJointRotate = 30;
	speed = 0.01;
	material.SetMaterial(param);
	material2.SetMaterial(param2);
}

void SpyderLeg::Draw(float x, float y, float z, int num) {
	glPushMatrix();
	{
		//右足
		if (x > 0) {
			glTranslated(2, 0, 0);
			//glRotated(30 * (sin(legRotateZ * (PI / 180))) / 2, 0, 0, 1);
			//glRotated(15 * num + 15 * sin(legRotateY * (PI / 180)), 0, 1, 0);
			glRotated(15 * num + legRotateY, 0, 1, 0);
			glRotated(legRotateZ, 0, 0, 1);
			glTranslated(x / 2, y, z);
			//第一関節
			glPushMatrix();
			{
				int sizeX = 3;
				glTranslated(2, 0, 0);
				//glRotated(-90 + 30 * (sin((legRotateZ) * (PI / 180))), 0, 0, 1);
				glRotated(-firstJointRotate, 0, 0, 1);
				glTranslated(sizeX / 2.0f, 0, 0);
				glPushMatrix();
				{
					//第二関節
					glPushMatrix();
					{
						glTranslated(sizeX / 2.0f, 0, 0);
						//glRotated(-30, 0, 0, 1);
						glRotated(-secondJointRotate, 0, 0, 1);
						glTranslated(1.0, 0, 0);
						glPushMatrix();
						{
							glColor3d(0.5, 0.4, 0);
							//glMaterialfv(GL_FRONT, GL_AMBIENT, mtr[1]);
							glScaled(2, 1, 0.5);
							material2.EnableMaterial(AMBIENT | DIFFUSE);
							glutSolidCube(1);
							glColor3d(0.5, 0.25, 0);
							//glMaterialfv(GL_FRONT, GL_AMBIENT, mtr[0]);
						}
						glPopMatrix();
					}
					glPopMatrix();
					material.EnableMaterial(AMBIENT | DIFFUSE);
					glScaled(sizeX, 1, 0.5);
					glutSolidCube(1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glScaled(4, 1, 0.5);
			glutSolidCube(1);
		}
		// 左足
		else {
			glTranslated(-2, 0, 0);
			//glRotated(-30 * (sin((legRotateZ) * (PI / 180))) / 2, 0, 0, 1);
			//glRotated(-15 * num - 15 * sin((legRotateY) * (PI / 180)), 0, 1, 0);
			glRotated(-15 * num - legRotateY, 0, 1, 0);
			glRotated(-legRotateZ, 0, 0, 1);
			glTranslated(x / 2, y, z);
			//第一関節
			glPushMatrix();
			{
				int sizeX = 3;
				glTranslated(-2, 0, 0);
				//glRotated(90 - 75 * (sin((legRotateZ) * (PI / 180))), 0, 0, 1);
				glRotated(firstJointRotate, 0, 0, 1);
				glTranslated(-sizeX / 2.0f, 0, 0);
				glPushMatrix();
				{
					//第二関節
					glPushMatrix();
					{
						glTranslated(-sizeX / 2.0f, 0, 0);
						//glRotated(30, 0, 0, 1);
						glRotated(secondJointRotate, 0, 0, 1);
						glTranslated(-1.0, 0, 0);
						glPushMatrix();
						{
							glColor3d(0.5, 0.4, 0);
							//glMaterialfv(GL_FRONT, GL_AMBIENT, mtr[1]);
							glScaled(2, 1, 0.5);
							glutSolidCube(1);
							glColor3d(0.5, 0.25, 0);
							//glMaterialfv(GL_FRONT, GL_AMBIENT, mtr[0]);
						}
						glPopMatrix();
					}
					glPopMatrix();
					glScaled(sizeX, 1, 0.5);
					glutSolidCube(1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glScaled(4, 1, 0.5);
			glutSolidCube(1);
		}
	}
	glPopMatrix();
}

void SpyderLeg::Animation() {
	animator->Animation(legRotateY, legRotateZ, firstJointRotate, secondJointRotate, speed);
}

void SpyderLeg::SetPosition(float x, float y, float z) {

}

void SpyderLeg::SetAnimator(Animator<double&, double&, double&, double&, float&>& animator)
{
	this->animator = &animator;
}
