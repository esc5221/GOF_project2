/*
- 5/12 02:55 choi : Player 클래스에 정의 대충 구성함.
*/
#include "Player.h"
#include <GL/glut.h>

//Player는 시작하는 점을 받아서 만들어진다.
Player::Player(int x, int y) {
		pos[0] = x;
		pos[1] = y;
}

//Area 크기 받는 함수
int Player::getArea() {
		return Area.size();
}

//어떤 점이 이 플레이어의 영역에 있는지 확인하는 함수
bool Player::isInArea(int x, int y) {
	if (area[x][y] == 1) return true;
	else return false;
}


//어떤 점이 이 플레이어의 경로에 있는지 확인하는 함수
bool Player::isInPath(int x, int y) {

}

//플레이어 주금
void Player::die() {

}

//플레이어 그려주는 함수
void Player::draw() {
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