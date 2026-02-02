#include "Patient.h"
#include <iostream>
using namespace std;

void Patient::input() {
    cout << "Enter Patient ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Disease: ";
    cin >> disease;
}

void Patient::display() {
    cout << id << "\t" << name << "\t" << age << "\t" << disease << endl;
}
