/*
- 5/10 12:00 choi : cpp ���� ����, �Լ� ������
- 5/12 02:15 choi : ���찡 ���� Zombie Ŭ���� �μ���.
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
void Zombie::moving() {		// ������ �������� �����ϴ� �Լ�
	if (moving_type == 0) {				// ����Ÿ�� 0 (��û)
		srand(time(NULL));				// �ð��� ���� �ٸ� �õ尪
		static int i = 0;				// moving�� idle�Լ����� ���ư��Ƿ� static���� ������ �ʱ�ȭ �ѹ���
		static int time_rand = 0;		
		static int k = moving_coefficient + time_rand;
		if (i=k) {
			int rd = rand() % 4;
			time_rand = (int)(0.6*moving_coefficient*(rand()-16383) / 32767);
		}
		i++;
	}
}	

// noZomchk �Լ��� ���� �Լ����� �����ؾ� �ҵ�. noZom[100][100]�� Zombie Ŭ������ �ҷ����� ��ٷο�.
//bool Zombie::noZomchk() {
//	if(noZom[pos[0]][pos[1]]==1)
//}

void Zombie::change_pos(int k) {	// ������ ��ġ�� ������ ����, k = 0,1,2,3���� u,d,r,l�� ������ switch������ ����
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
