#include <iostream>
#include "AnalogSensor.h"
#include "Container.h"
#include "Drive.h"
#include "OperatorInterface.h"
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

bool conveyor_1(Container& con_1, Container& con_2, AnalogSensor& i0, AnalogSensor& i5, AnalogSensor& i1, AnalogSensor& i2,
    Drive& q0, Drive& q1, Drive& q2, Drive& q3, Drive& q4, Drive& q5, Drive& q9, OperatorInterface& pult) {
    pult.Set_start(0);
    if (con_1.Get_N() > 0) { i1.Set_I(1); }
    
    if (i1.Get_I() == 0) {
        pult.Set_stop(0);
        pult.Set_q_empty(1);
        pult.Set_q_emergency(1);
        q0.Set_Q(0); q1.Set_Q(0); q2.Set_Q(0);
        printf("\x1B[32mEmergency Stop! First container EMPTY!!\033[0m\n");
        cout << "To exit, enter 0" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        return false;
    } 
    else {
        q3.Set_Q(1);
        con_1.Set_N(con_1.Get_N() - 1);
        con_1.Get_N() > 0 ? i1.Set_I(1) : i1.Set_I(0);
        printf("\x1B[32mThe bottom of the first container is open...\033[0m\n");
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    printf("\x1B[32mThe bottom of the first container is close...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    q3.Set_Q(0); 

    i5.Set_I(1); q9.Set_Q(1);
    printf("\x1B[32mThe cutting machine has started working...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(100));
    i5.Set_I(0); q9.Set_Q(0);
    printf("\x1B[32mThe cutting machine has finished working..\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i0.Set_I(1); q4.Set_Q(1); q5.Set_Q(0);
    printf("\x1B[32mThe lid of the second container is open...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    con_2.Set_N(con_2.Get_N() + 1);
    i0.Set_I(0);
    con_2.Get_N() >= con_2.Get_Max() ? i2.Set_I(1) : i2.Set_I(0);
    if (i2.Get_I() == 1) {
        pult.Set_stop(1);
        pult.Set_q_emergency(1);
        pult.Set_q_full(1);
        q0.Set_Q(0); q1.Set_Q(0); q2.Set_Q(0);
        printf("\x1B[32mEmergency Stop. Second container FULL!!!\033[0m\n");
        cout << "To exit, enter 0" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        return false;
    }
    return true;
}

bool conveyor_2(Container& con_2, Container& con_3, AnalogSensor& i6, AnalogSensor& i7, AnalogSensor& i2, AnalogSensor& i3,
    Drive& q0, Drive& q1, Drive& q2, Drive& q4, Drive& q5, Drive& q6, Drive& q7, Drive& q10, OperatorInterface& pult) {
    q4.Set_Q(0);
    printf("\x1B[32mThe lid of the second container is close...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(1));
    if (con_2.Get_N() >= con_2.Get_Max()) { i2.Set_I(1); };

    if (i2.Get_I() == 1) {
        pult.Set_stop(1);
        pult.Set_q_emergency(1);
        pult.Set_q_full(1);
        q0.Set_Q(0); q1.Set_Q(0); q2.Set_Q(0);
        printf("\x1B[32mEmergency Stop. Second container FULL!!!\033[0m\n");
        cout << "To exit, enter 0" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        return false;
    }
    else if (con_2.Get_N() == 0) { return true; }
    else {
        q5.Set_Q(1);
        con_2.Set_N(con_2.Get_N() - 1);
        printf("\x1B[32mThe bottom of the second container is open...\033[0m\n");
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    q5.Set_Q(0);
    printf("\x1B[32mThe bottom of the second container is close...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i7.Set_I(1); q10.Set_Q(1); 
    printf("\x1B[32mThe milling machine has started working...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(100));
    i7.Set_I(0); q10.Set_Q(0);
    printf("\x1B[32mThe milling machine has finished working...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i6.Set_I(1); q6.Set_Q(1); q7.Set_Q(0);
    con_3.Set_N(con_3.Get_N() + 1);
    printf("\x1B[32mThe lid of the third container is open...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i6.Set_I(0);
    con_3.Get_N() >= con_3.Get_Max() ? i3.Set_I(1) : i3.Set_I(0);
    if (i3.Get_I() == 1) {
        pult.Set_stop(1);
        pult.Set_q_emergency(1);
        pult.Set_q_full(1);
        q0.Set_Q(0); q1.Set_Q(0); q2.Set_Q(0);
        printf("\x1B[32mEmergency Stop. Third container FULL!!!\033[0m\n");
        cout << "To exit, enter 0" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        return false;
    }
    return true;
}

bool conveyor_3(Container& con_3, Container& con_4, AnalogSensor& i8, AnalogSensor& i9, AnalogSensor& i3, AnalogSensor& i4,
    Drive& q0, Drive& q1, Drive& q2, Drive& q6, Drive& q7, Drive& q8, Drive& q11, OperatorInterface& pult) {
    q6.Set_Q(0);
    printf("\x1B[32mThe lid of the third container is close...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    con_3.Get_N() >= con_3.Get_Max() ? i3.Set_I(1) : i3.Set_I(0);
    if (i3.Get_I() == 1) {
        pult.Set_stop(1);
        pult.Set_q_emergency(1);
        pult.Set_q_full(1);
        q0.Set_Q(0); q1.Set_Q(0); q2.Set_Q(0);
        printf("\x1B[32mEmergency Stop. Third container FULL!!!\033[0m\n");
        cout << "To exit, enter 0" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        return false;
    }
    else if (con_3.Get_N() == 0) { return true; }
    else {
        q7.Set_Q(1);
        con_3.Set_N(con_3.Get_N() - 1);
        printf("\x1B[32mThe bottom of the third container is open...\033[0m\n");
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    q7.Set_Q(0); 
    printf("\x1B[32mThe bottom of the third container is close...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i9.Set_I(1); q11.Set_Q(1); 
    printf("\x1B[32mThe assembly machine has started working...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(100));
    i9.Set_I(0); q11.Set_Q(0);
    printf("\x1B[32mThe assembly machine has finished working...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i8.Set_I(1); q8.Set_Q(1);
    con_4.Set_N(con_4.Get_N() + 1);
    printf("\x1B[32mThe lid of the fourth container is open...\033[0m\n");
    this_thread::sleep_for(chrono::milliseconds(50));
    i8.Set_I(0);

    con_4.Get_N() >= con_4.Get_Max() ? i4.Set_I(1) : i4.Set_I(0);
    if (i4.Get_I() == 1) {
        pult.Set_stop(1);
        pult.Set_q_emergency(1);
        pult.Set_q_full(1);
        q0.Set_Q(0); q1.Set_Q(0); q2.Set_Q(0);
        printf("\x1B[32mEmergency Stop. Fourth container FULL!!!\033[0m\n");
        cout << "To exit, enter 0" << endl;
        this_thread::sleep_for(chrono::milliseconds(1));
        return false;
    }
    return true;
}

string pult() {
    string s;
    while (s != "stop" and s != "1" and s != "0") {
        cin >> s;
        cout << "*";
    }
    if (s == "stop") { cout << "*STOP**" << endl; }
    if (s == "0") { cout << "*Exiting the program is completed**" << endl; }
    if (s == "1") { cout << "*START. Enter 'start' to start the production process. After you can enter 'stop' to stop the production process**" << endl; }
    return s;
}


void function()
{
    Container con_1, con_2, con_3, con_4;
    AnalogSensor i0, i1, i2, i3, i4, i5, i6, i7, i8, i9;
    Drive q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11;
    OperatorInterface pult;
    ofstream fout("data2.txt");
    ifstream fin("data.txt");
    
    unsigned int n1, n2, n3, n4;
    fin >> n1 >> n2 >> n3 >> n4;
    con_1.Set_Max(n1);
    con_2.Set_Max(n2);
    con_3.Set_Max(n3);
    con_4.Set_Max(n4);
    fin >> n1 >> n2 >> n3 >> n4;
    con_1.Set_N(n1);
    con_2.Set_N(n2);
    con_3.Set_N(n3);
    con_4.Set_N(n4);

    //start
    string p;
    cin >> p;
    if (p == "start") { pult.Set_start(1); };
    if (pult.Get_start() == 1 and pult.Get_q_full() == 0 and pult.Get_q_empty() == 0 and pult.Get_q_emergency() == 0) {
        q0.Set_Q(1); q1.Set_Q(1); q2.Set_Q(1);
        i2.Set_I(0); i3.Set_I(0); i4.Set_I(0);
        i5.Set_I(0); i0.Set_I(0);
    }
    else {
        cout << "Incorrect input. To exit, enter 0." << endl;
        return;
    }
    bool flag = true;
    while (flag) {

        flag = conveyor_1(con_1, con_2, i0, i5, i1, i2, q0, q1, q2, q3, q4, q5, q9, pult);
        fout << "container 1: max " << con_1.Get_Max() << " : now " << con_1.Get_N() << endl;
        fout << "container 2: max " << con_2.Get_Max() << " : now " << con_2.Get_N() << endl;
        fout << "container 3: max " << con_3.Get_Max() << " : now " << con_3.Get_N() << endl;
        fout << "container 4: max " << con_4.Get_Max() << " : now " << con_4.Get_N() << endl;
        fout << endl;
        if (flag == false) { break; }
        flag = conveyor_2(con_2, con_3, i6, i7, i2, i3, q0, q1, q2, q4, q5, q6, q7, q10, pult);
        fout << "container 1: max " << con_1.Get_Max() << " : now " << con_1.Get_N() << endl;
        fout << "container 2: max " << con_2.Get_Max() << " : now " << con_2.Get_N() << endl;
        fout << "container 3: max " << con_3.Get_Max() << " : now " << con_3.Get_N() << endl;
        fout << "container 4: max " << con_4.Get_Max() << " : now " << con_4.Get_N() << endl;
        fout << endl;
        if (flag == false) { break; }
        if (i1.Get_I() == 1) {
            flag = conveyor_1(con_1, con_2, i0, i5, i1, i2, q0, q1, q2, q3, q4, q5, q9, pult);
            fout << "container 1: max " << con_1.Get_Max() << " : now " << con_1.Get_N() << endl;
            fout << "container 2: max " << con_2.Get_Max() << " : now " << con_2.Get_N() << endl;
            fout << "container 3: max " << con_3.Get_Max() << " : now " << con_3.Get_N() << endl;
            fout << "container 4: max " << con_4.Get_Max() << " : now " << con_4.Get_N() << endl;
            fout << endl;
        }

        if (flag == false) { break; }
        flag = conveyor_3(con_3, con_4, i8, i9, i3, i4, q0, q1, q2, q6, q7, q8, q11, pult);
        fout << "container 1: max " << con_1.Get_Max() << " : now " << con_1.Get_N() << endl;
        fout << "container 2: max " << con_2.Get_Max() << " : now " << con_2.Get_N() << endl;
        fout << "container 3: max " << con_3.Get_Max() << " : now " << con_3.Get_N() << endl;
        fout << "container 4: max " << con_4.Get_Max() << " : now " << con_4.Get_N() << endl;
        fout << endl;
        if (flag == false) {

            break;
        }
        if (i1.Get_I() == 1) {
            flag = conveyor_2(con_2, con_3, i6, i7, i2, i3, q0, q1, q2, q4, q5, q6, q7, q10, pult);
            fout << "container 1: max " << con_1.Get_Max() << " : now " << con_1.Get_N() << endl;
            fout << "container 2: max " << con_2.Get_Max() << " : now " << con_2.Get_N() << endl;
            fout << "container 3: max " << con_3.Get_Max() << " : now " << con_3.Get_N() << endl;
            fout << "container 4: max " << con_4.Get_Max() << " : now " << con_4.Get_N() << endl;
            fout << endl;
        }
    }

}

int main()
{
   
    cout << "Enter 1 to start the program" << endl;

    thread th(function);
    pult();
    pult();
    th.detach();

    return 0;
}