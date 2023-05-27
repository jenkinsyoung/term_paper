#pragma once
class OperatorInterface
{
private:
	char start; //кнопка старта
	char stop; //кнопка остановки
	char q_empty; //лампочка, показывающая, что первый контейнер пуст
	char q_full; //лампочка, сигнализирующая о переполненых контейнерах
	char q_emergency; //лампочка аварийной остановки
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

