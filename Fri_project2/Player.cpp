/*
- 5/12 02:55 choi : Player Ŭ������ ���� ���� ������.
*/
#include "Player.h"
#include <GL/glut.h>

//Player�� �����ϴ� ���� �޾Ƽ� ���������.
Player::Player(int x, int y) {
		pos[0] = x;
		pos[1] = y;
}

//Area ũ�� �޴� �Լ�
int Player::getArea() {
		return Area.size();
}

//� ���� �� �÷��̾��� ������ �ִ��� Ȯ���ϴ� �Լ�
bool Player::isInArea(int x, int y) {
	if (area[x][y] == 1) return true;
	else return false;
}


//� ���� �� �÷��̾��� ��ο� �ִ��� Ȯ���ϴ� �Լ�
bool Player::isInPath(int x, int y) {

}

//�÷��̾� �ֱ�
void Player::die() {

}

//�÷��̾� �׷��ִ� �Լ�
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