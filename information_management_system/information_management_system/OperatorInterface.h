#pragma once
class OperatorInterface
{
private:
	char start; //������ ������
	char stop; //������ ���������
	char q_empty; //��������, ������������, ��� ������ ��������� ����
	char q_full; //��������, ��������������� � ������������ �����������
	char q_emergency; //�������� ��������� ���������
public:
	OperatorInterface();
	void Set_start(char i);
	void Set_stop(char i);
	void Set_q_empty(char i);
	void Set_q_full(char i);
	void Set_q_emergency(char i);
	char Get_start();
	char Get_stop(); 
	char Get_q_empty();
	char Get_q_full();
	char Get_q_emergency();
};

