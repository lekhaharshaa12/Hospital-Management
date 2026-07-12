#include "Patient.h"
#include "InputUtil.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Patient::input() {
    id = getValidInt("Enter Patient ID: ");
    name = getValidString("Enter Name: ");
    age = getValidInt("Enter Age: ");
    disease = getValidString("Enter Disease: ");
}

void Patient::display() {
    cout << left << setw(10) << id 
         << setw(25) << name 
         << setw(10) << age 
         << setw(25) << disease << endl;
}

