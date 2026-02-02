#include "Hospital.h"
#include <iostream>
#include <fstream>
using namespace std;

void Hospital::addPatient() {
    Patient p;
    p.input();

    ofstream file("patients.txt", ios::app);
    file << p.id << " " << p.name << " " << p.age << " " << p.disease << endl;
    file.close();

    cout << "Patient Added Successfully!\n";
}

void Hospital::viewPatients() {
    ifstream file("patients.txt");

    Patient p;
    cout << "\nID\tName\tAge\tDisease\n";

    while (file >> p.id >> p.name >> p.age >> p.disease) {
        p.display();
    }

    file.close();
}

void Hospital::addDoctor() {
    Doctor d;
    d.input();

    ofstream file("doctors.txt", ios::app);
    file << d.id << " " << d.name << " " << d.specialization << endl;
    file.close();

    cout << "Doctor Added Successfully!\n";
}

void Hospital::viewDoctors() {
    ifstream file("doctors.txt");

    Doctor d;
    cout << "\nID\tName\tSpecialization\n";

    while (file >> d.id >> d.name >> d.specialization) {
        d.display();
    }

    file.close();
}

void Hospital::bookAppointment() {
    Appointment a;
    a.input();

    ofstream file("appointments.txt", ios::app);
    file << a.patientId << " " << a.doctorId << " " << a.date << endl;
    file.close();

    cout << "Appointment Booked Successfully!\n";
}

void Hospital::viewAppointments() {
    ifstream file("appointments.txt");

    Appointment a;
    cout << "\nPatientID\tDoctorID\tDate\n";

    while (file >> a.patientId >> a.doctorId >> a.date) {
        a.display();
    }

    file.close();
}

void Hospital::menu() {
    int choice;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Book Appointment\n";
        cout << "6. View Appointments\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                viewPatients();
                break;

            case 3:
                addDoctor();
                break;

            case 4:
                viewDoctors();
                break;

            case 5:
                bookAppointment();
                break;

            case 6:
                viewAppointments();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);
}
