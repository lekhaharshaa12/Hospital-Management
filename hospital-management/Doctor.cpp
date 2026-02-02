#include "Doctor.h"
#include <iostream>
using namespace std;

void Doctor::input() {
    cout << "Enter Doctor ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Specialization: ";
    cin >> specialization;
}

void Doctor::display() {
    cout << id << "\t" << name << "\t" << specialization << endl;
}
