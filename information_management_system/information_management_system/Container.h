#pragma once
class Container
{
private:
	unsigned int Max;
	unsigned int N;
public:
	Container();
	Container(unsigned int n, unsigned int m);
	void Set_Max(unsigned int m);
	void Set_N(unsigned int n);
	unsigned int Get_N();
	unsigned int Get_Max();
};

