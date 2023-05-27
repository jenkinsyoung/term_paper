#pragma once
class AnalogSensor
{
private:
	char I;
public:
	AnalogSensor();
	AnalogSensor(char i);
	void Set_I(char i);
	int Get_I();
};