#include "Container.h"

using namespace std;

Container::Container(): N(0), Max(0) {};

Container::Container(unsigned int n, unsigned int m) {
	N = n;
	Max = m;
}

void Container::Set_N(unsigned int n) {
	N = n;
}

unsigned int Container::Get_N() {
	return N;
}

void Container::Set_Max(unsigned int m) { Max = m; }
unsigned int Container::Get_Max() { return Max; }
