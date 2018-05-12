/* 
- 5/10 12:00 choi : header ���� ����
- 5/12 02:52 choi : ���찡 �Ѱ� �߰�
*/
#pragma once

class Zombie {
public:
	Zombie(int tp, int mc); // tp : ������ Ÿ��(��ûor�ȶ�)  mc : �������
							// ���� ��ġ �����Լ��� ����

	int getX();
	int getY();

	void moving();			// ������ �������� �����ϴ� �Լ�. 
							// �׳� rand()�� ���� ���� ���ڸ����� �ȹ���Ƿ�
							// ��������� �־ ���� ���� �������� ���� �ð��� �ٸ��� �� �� �ְ� ��
							// ex) ��������� ũ�� �� �� �ð����� ���� �������� ���� �� ������ �������� �ٲ۴�. 
	bool noZomchk();			// noZom�� �ִ��� Ȯ��. noZom�� ������ False�� ����.

	void change_pos(int k);	// ������ ��ġ�� ������ �����ϴ� �Լ�, k = 0,1,2,3���� u,d,r,l�� ������ switch������ ����

	void die();

	void draw();

protected:
	int  pos[2];					// ������ ��ġ (x,y)
	int  moving_type;				// ���� �������� Ÿ�� ����
	int  moving_coefficient;		// ���� �������� Ȱ�������� �����ϴ� ������� (0:random, 1:smart)
	int  life;
};