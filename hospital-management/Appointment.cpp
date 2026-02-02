#include "Appointment.h"
#include <iostream>
using namespace std;

void Appointment::input() {
    cout << "Enter Patient ID: ";
    cin >> patientId;

    cout << "Enter Doctor ID: ";
    cin >> doctorId;

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> date;
}

void Appointment::display() {
    cout << patientId << "\t" << doctorId << "\t" << date << endl;
}
