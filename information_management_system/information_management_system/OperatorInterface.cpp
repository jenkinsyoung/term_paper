#include "OperatorInterface.h"
using namespace std;

OperatorInterface::OperatorInterface() :start(0), stop(0), q_empty(0), q_full(0), q_emergency(0) {}

void OperatorInterface::Set_start(char i) { start = i; }
void OperatorInterface::Set_stop(char i) { stop = i; }
void OperatorInterface::Set_q_empty(char i) { q_empty = i; }
void OperatorInterface::Set_q_full(char i) { q_full = i; }
void OperatorInterface::Set_q_emergency(char i) { q_emergency = i; }

char OperatorInterface::Get_start() { return start; }
char OperatorInterface::Get_stop() { return stop; }
char OperatorInterface::Get_q_empty() { return q_empty; }
char OperatorInterface::Get_q_full() { return q_full; }
char OperatorInterface::Get_q_emergency() { return q_emergency; }
