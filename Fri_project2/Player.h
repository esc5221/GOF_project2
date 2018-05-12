/*�÷��̾�� �ڽ��� ��ġ�� �����ϰ� ���������� display
�ڽ��� �̵��ߴ� ��θ� �����ϰ� ȸ������ display
�÷��̾�� �ڽ��� ������ �����ϰ� ��������� display
�÷��̾�� ����� ������ �ٲ� ������ �� ��ġ�� ����, main���� linked list�� �̸� �̿�.

*/
#pragma once
#include <vector>
using namespace std;

class Player {
public:
	//Player�� �����ϴ� ���� �޾Ƽ� ���������.
	Player(int x, int y);

	//Area ũ�� �޴� �Լ�
	int getArea();
	
	//� ���� �� �÷��̾��� ������ �ִ��� Ȯ���ϴ� �Լ�
	bool isInArea(int x, int y);


	//� ���� �� �÷��̾��� ��ο� �ִ��� Ȯ���ϴ� �Լ�
	bool isInPath(int x, int y);

	//�÷��̾� �ֱ�
	void die();

	//�÷��̾� �׷��ִ� �Լ�
	void draw();

private:
	////���� ��ġ
	//int start_pos[2]; &&&& ������ġ�� �ʿ���ٰ� ����. �׳� �ٷ� pos�� ������ ��

	int life;
	int pos[2];
	int area[100][100];
	vector<int> Area;
	vector<int> Path;

};




