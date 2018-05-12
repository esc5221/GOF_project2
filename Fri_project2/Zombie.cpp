/*
- 5/10 12:00 choi : cpp 파일 생성, 함수 정의함
- 5/12 02:15 choi : 형우가 만든 Zombie 클래스 인수함.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Zombie.h"
using namespace std;


Zombie::Zombie(int tp, int mc) {
	moving_type = tp;
	moving_coefficient = mc;
	life = 1;
	pos[0] = rand() % 100;
	pos[1] = rand() % 100;
}

int Zombie::getX() {
	return pos[0];
}
int Zombie::getY() {
	return pos[1];
}
void Zombie::moving() {		// 좀비의 움직임을 결정하는 함수
	if (moving_type == 0) {				// 무빙타입 0 (멍청)
		srand(time(NULL));				// 시간에 따라 다른 시드값
		static int i = 0;				// moving이 idle함수에서 돌아가므로 static으로 정의해 초기화 한번만
		static int time_rand = 0;		
		static int k = moving_coefficient + time_rand;
		if (i=k) {
			int rd = rand() % 4;
			time_rand = (int)(0.6*moving_coefficient*(rand()-16383) / 32767);
		}
		i++;
	}
}	

// noZomchk 함수는 메인 함수에서 구현해야 할듯. noZom[100][100]을 Zombie 클래스로 불러오기 까다로움.
//bool Zombie::noZomchk() {
//	if(noZom[pos[0]][pos[1]]==1)
//}

void Zombie::change_pos(int k) {	// 좀비의 위치를 실제로 변경, k = 0,1,2,3으로 u,d,r,l의 방향을 switch문으로 실행
	switch (k) {
	case 0: // up
		pos[1]++;
		break;
	case 1: // down
		pos[1]--;
		break;
	case 2: // right
		pos[0]++;
		break;
	case 3: // left
		pos[0]--;
		break;
	}
}

void Zombie::die() {
	life = 0;
}

void Zombie::draw(){
	if (life = 1) {
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(pos[0], pos[1]);
		glVertex2f(pos[0] + 1, pos[1]);
		glVertex2f(pos[0] + 1, pos[1] + 1);
		glVertex2f(pos[0], pos[1] + 1);
		glEnd();
	}
}
