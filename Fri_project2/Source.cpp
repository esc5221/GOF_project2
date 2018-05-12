/* 
- 5/10 12:00 kimh : 프로젝트 첫날
- 5/12 02:01 kimh : 주저리 주저리 떠들기만 해둔 5월 12일자 수정
- 5/12 02:38 choi : 프로젝트 하나로 만들었음! 솔루션,프로젝트 이름은 Fri_project2
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

//100*140 칸을 만들고 아래 100*100은 게임용, 위 100*40칸은 디스플레이 
int w = 100; int h = 140;

//우리의 생명은 3개
int life = 3;

//좀비 만들기
Zombie zombie1(10, 15);
Zombie zombie2(90, 85);
Zombie zombie3(15, 80);

//플레이어 만들기
Player player(50, 50);

//좀비가 못들어가는 영역
//...을 이렇게 구현 안하고 좀비에서 구현해봤어. // 
int noZom[100][100];

//위, 아래, 오른쪽, 왼쪽 순으로 0,1,2,3으로 표기됨.
int sp_key = 4;
/*
idle function :
1. 플레이어를 이동시킨다.(마지막). 이때 반대 방향 이동 x.
2. 좀비들을 이동시킨다. 만약 좀비가 플레이어 영역 위로 올라가면 좀비는 역행한다.
3. 만약 좀비가 플레이어의 경로 위->사망.
4. 만약 플레이어가 플레이어의 경로 위 ->사망
5. 만약 플레이어가 자신의 영역 위 -> 영역 업데이트.
6. 만약 좀비가 플레이어의 영역 안 -> 좀비 사망
끗!
*/

void idle() {

}

//반대방향으로 이동하라는 입력은 거른다.
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
	//100*100으로 맞춘다

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	
	//현재 영역 영역의 크기 
	float ratio;
	ratio = player.getArea() / 10000 * 100;

	//구분선 그리기.
	glBegin(GL_LINES);
	glVertex2f(0, 101); glVertex2f(100, 101);
	glEnd();
	

	if (ratio < 70 || life>0) {
		//ratio 라는 float을 string으로 바꾸고 char*로 바꾸어서 디스플레이
		stringstream ss(stringstream::in | stringstream::out);
		ss << ratio;
		string s = ss.str() + "percent! Reach 70 percent!";
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, s.c_str(), 25, 120);

		//현재 상태를 그린다.

		glutSwapBuffers();
	}
	else if (life = 0) {
		//패배
		draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Game over!", 25, 120);
		glutSwapBuffers();
	}
	else if (ratio >70){
		//승리
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

	//randomizing 함
	srand(time(NULL));
	
	// register callbacks
	glutDisplayFunc(renderScene);
	/*
	//방향키 입력
	glutSpecialFunc(processSpecialKeys);

	/*idle function : 
	1. 플레이어를 이동시킨다.(마지막). 이때 반대 방향 이동 x.
	2. 좀비들의 위치와 플레이어의 위치 및 경로를 비교한다.
	3. 만약 좀비가 플레이어의 경로 위->사망.
	4. 만약 플레이어가 플레이어의 경로 위 ->사망
	5. 만약 플레이어가 자신의 영역 위 -> 영역 업데이트.
	
	glutIdleFunc(idle);
	*/

	// enter GLUT event processing cycle
	glutMainLoop();
	}
