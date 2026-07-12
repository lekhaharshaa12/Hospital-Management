#include "Appointment.h"
#include "InputUtil.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Appointment::input() {
    patientId = getValidInt("Enter Patient ID: ");
    doctorId = getValidInt("Enter Doctor ID: ");
    date = getValidString("Enter Date (DD-MM-YYYY): ");
}

void Appointment::display() {
    cout << left << setw(15) << patientId 
         << setw(15) << doctorId 
         << setw(15) << date << endl;
}

