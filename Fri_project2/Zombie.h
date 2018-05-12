/* 
- 5/10 12:00 choi : header 파일 생성
- 5/12 02:52 choi : 형우가 한거 추가
*/
#pragma once

class Zombie {
public:
	Zombie(int tp, int mc); // tp : 좀비의 타입(멍청or똑똑)  mc : 무빙계수
							// 시작 위치 랜덤함수로 배정

	int getX();
	int getY();

	void moving();			// 좀비의 움직임을 결정하는 함수. 
							// 그냥 rand()를 쓰면 좀비가 제자리에서 안벗어나므로
							// 무빙계수를 주어서 좀비가 같은 방향으로 가는 시간을 다르게 할 수 있게 함
							// ex) 무빙계수가 크면 더 긴 시간동안 같은 방향으로 진행 후 랜덤한 방향으로 바꾼다. 
	bool noZomchk();			// noZom에 있는지 확인. noZom에 있으면 False로 정함.

	void change_pos(int k);	// 좀비의 위치를 실제로 변경하는 함수, k = 0,1,2,3으로 u,d,r,l의 방향을 switch문으로 실행

	void die();

	void draw();

protected:
	int  pos[2];					// 좀비의 위치 (x,y)
	int  moving_type;				// 좀비 움직임의 타입 변수
	int  moving_coefficient;		// 좀비 움직임의 활동정도를 결정하는 무빙계수 (0:random, 1:smart)
	int  life;
};