#include "AnalogSensor.h"
using namespace std;

AnalogSensor::AnalogSensor() :I(0) {};

AnalogSensor::AnalogSensor(char i) { I = i; };

void AnalogSensor::Set_I(char i) { I = i; };

int AnalogSensor::Get_I() {
	return I;
};
