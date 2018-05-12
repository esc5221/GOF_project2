/*플레이어는 자신의 위치를 저장하고 빨간색으로 display
자신이 이동했던 경로를 저장하고 회색으로 display
플레이어는 자신의 영역을 저장하고 보라색으로 display
플레이어는 경로의 방향이 바뀔 때마다 그 위치를 저장, main에서 linked list로 이를 이용.

*/
#pragma once
#include <vector>
using namespace std;

class Player {
public:
	//Player는 시작하는 점을 받아서 만들어진다.
	Player(int x, int y);

	//Area 크기 받는 함수
	int getArea();
	
	//어떤 점이 이 플레이어의 영역에 있는지 확인하는 함수
	bool isInArea(int x, int y);


	//어떤 점이 이 플레이어의 경로에 있는지 확인하는 함수
	bool isInPath(int x, int y);

	//플레이어 주금
	void die();

	//플레이어 그려주는 함수
	void draw();

private:
	////시작 위치
	//int start_pos[2]; &&&& 시작위치는 필요없다고 생각. 그냥 바로 pos에 넣으면 됨

	int life;
	int pos[2];
	int area[100][100];
	vector<int> Area;
	vector<int> Path;

};




