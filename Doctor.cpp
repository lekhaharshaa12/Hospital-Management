#include "Doctor.h"
#include "InputUtil.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Doctor::input() {
    id = getValidInt("Enter Doctor ID: ");
    name = getValidString("Enter Name: ");
    specialization = getValidString("Enter Specialization: ");
}

void Doctor::display() {
    cout << left << setw(10) << id 
         << setw(25) << name 
         << setw(25) << specialization << endl;
}

