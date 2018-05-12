/* 
- 5/10 12:00 kimh : ������Ʈ ù��
- 5/12 02:01 kimh : ������ ������ ����⸸ �ص� 5�� 12���� ����
- 5/12 02:38 choi : ������Ʈ �ϳ��� �������! �ַ��,������Ʈ �̸��� Fri_project2
*/

#include <GL/glut.h>
#include <sstream>
#include "Zombie.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>


#define WIDTH 600		
#define HEIGHT 600	

using namespace std;

//100*140 ĭ�� ����� �Ʒ� 100*100�� ���ӿ�, �� 100*40ĭ�� ���÷��� 
int w = 100; int h = 140;

//�츮�� ������ 3��
int life = 3;

//���� �����
Zombie zombie1(10, 15);
Zombie zombie2(90, 85);
Zombie zombie3(15, 80);

//�÷��̾� �����
Player player(50, 50);

//���� ������ ����
//...�� �̷��� ���� ���ϰ� ���񿡼� �����غþ�. // 
int noZom[100][100];

//��, �Ʒ�, ������, ���� ������ 0,1,2,3���� ǥ���.
int sp_key = 4;
/*
idle function :
1. �÷��̾ �̵���Ų��.(������). �̶� �ݴ� ���� �̵� x.
2. ������� �̵���Ų��. ���� ���� �÷��̾� ���� ���� �ö󰡸� ����� �����Ѵ�.
3. ���� ���� �÷��̾��� ��� ��->���.
4. ���� �÷��̾ �÷��̾��� ��� �� ->���
5. ���� �÷��̾ �ڽ��� ���� �� -> ���� ������Ʈ.
6. ���� ���� �÷��̾��� ���� �� -> ���� ���
��!
*/

void idle() {

}

//�ݴ�������� �̵��϶�� �Է��� �Ÿ���.
void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (sp_key != 1) {
			sp_key = 0; break;
		}
	case GLUT_KEY_DOWN:
		if (sp_key != 0) {
			sp_key = 1; break;
		}
	case GLUT_KEY_RIGHT:
		if (sp_key != 3) {
			sp_key = 2; break;
		}
	case GLUT_KEY_LEFT:
		if (sp_key != 2) {
			sp_key = 3; break;
		}
	}
}

void draw_string(void* font, const char* str, float x, float y) {
	glRasterPos2f(x, y);
	for (int i = 0; i < strlen(str); i++)
		glutBitmapCharacter(font, str[i]);
}

void renderScene() {
	// Clear Color and Depth Buffers
	//100*100���� �����

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	
	//���� ���� ������ ũ�� 
	float ratio;
	ratio = player.getArea() / 10000 * 100;

	//���м� �׸���.
	glBegin(GL_LINES);
	glVertex2f(0, 101); glVertex2f(100, 101);
	glEnd();
	

	if (ratio < 70 || life>0) {
		//ratio ��� float�� string���� �ٲٰ� char*�� �ٲپ ���÷���
		stringstream ss(stringstream::in | stringstream::out);
		ss << ratio;
		string s = ss.str() + "percent! Reach 70 percent!";
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, s.c_str(), 25, 120);

		//���� ���¸� �׸���.

		glutSwapBuffers();
	}
	else if (life = 0) {
		//�й�
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Game over!", 25, 120);
		glutSwapBuffers();
	}
	else if (ratio >70){
		//�¸�
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "You win!", 25, 120);
		glutSwapBuffers();
	}
	
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(50, 50);
	glVertex2f(51, 50);
	glVertex2f(51, 51);
	glVertex2f(50, 51);
	glEnd();
	glutSwapBuffers();
}

void main(int argc, char **argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Drawing Square & Equilateral Triangle");

	//randomizing ��
	srand(time(NULL));
	
	// register callbacks
	glutDisplayFunc(renderScene);
	/*
	//����Ű �Է�
	glutSpecialFunc(processSpecialKeys);

	/*idle function : 
	1. �÷��̾ �̵���Ų��.(������). �̶� �ݴ� ���� �̵� x.
	2. ������� ��ġ�� �÷��̾��� ��ġ �� ��θ� ���Ѵ�.
	3. ���� ���� �÷��̾��� ��� ��->���.
	4. ���� �÷��̾ �÷��̾��� ��� �� ->���
	5. ���� �÷��̾ �ڽ��� ���� �� -> ���� ������Ʈ.
	
	glutIdleFunc(idle);
	*/

	// enter GLUT event processing cycle
	glutMainLoop();
	}
