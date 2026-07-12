#include "Hospital.h"
#include "InputUtil.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

bool Hospital::patientExists(int id) {
    ifstream file("patients.txt");
    if (!file) return false;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        if (getline(ss, token, '|')) {
            try {
                if (stoi(token) == id) {
                    file.close();
                    return true;
                }
            } catch (...) {
                // Skip corrupted parsing
            }
        }
    }
    file.close();
    return false;
}

bool Hospital::doctorExists(int id) {
    ifstream file("doctors.txt");
    if (!file) return false;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        if (getline(ss, token, '|')) {
            try {
                if (stoi(token) == id) {
                    file.close();
                    return true;
                }
            } catch (...) {
                // Skip corrupted parsing
            }
        }
    }
    file.close();
    return false;
}

void Hospital::addPatient() {
    Patient p;
    p.input();

    if (patientExists(p.id)) {
        cout << "\nError: Patient with ID " << p.id << " already exists!\n";
        return;
    }

    ofstream file("patients.txt", ios::app);
    if (!file) {
        cout << "\nError: Could not open patients.txt for writing.\n";
        return;
    }
    file << p.id << "|" << p.name << "|" << p.age << "|" << p.disease << "\n";
    file.close();

    cout << "\nPatient Added Successfully!\n";
}

void Hospital::viewPatients() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\nNo patients registered yet (patients.txt not found).\n";
        return;
    }

    string line;
    bool hasData = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (!hasData) {
            cout << "\n" << left << setw(10) << "ID" 
                 << setw(25) << "Name" 
                 << setw(10) << "Age" 
                 << setw(25) << "Disease" << endl;
            cout << string(70, '-') << endl;
            hasData = true;
        }

        stringstream ss(line);
        string id_str, name, age_str, disease;
        if (getline(ss, id_str, '|') &&
            getline(ss, name, '|') &&
            getline(ss, age_str, '|') &&
            getline(ss, disease)) {
            Patient p;
            try {
                p.id = stoi(id_str);
                p.name = name;
                p.age = stoi(age_str);
                p.disease = disease;
                p.display();
            } catch (...) {
                // Skip corrupted line
            }
        }
    }

    if (!hasData) {
        cout << "\nNo patients registered yet.\n";
    }

    file.close();
}

void Hospital::addDoctor() {
    Doctor d;
    d.input();

    if (doctorExists(d.id)) {
        cout << "\nError: Doctor with ID " << d.id << " already exists!\n";
        return;
    }

    ofstream file("doctors.txt", ios::app);
    if (!file) {
        cout << "\nError: Could not open doctors.txt for writing.\n";
        return;
    }
    file << d.id << "|" << d.name << "|" << d.specialization << "\n";
    file.close();

    cout << "\nDoctor Added Successfully!\n";
}

void Hospital::viewDoctors() {
    ifstream file("doctors.txt");
    if (!file) {
        cout << "\nNo doctors registered yet (doctors.txt not found).\n";
        return;
    }

    string line;
    bool hasData = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (!hasData) {
            cout << "\n" << left << setw(10) << "ID" 
                 << setw(25) << "Name" 
                 << setw(25) << "Specialization" << endl;
            cout << string(60, '-') << endl;
            hasData = true;
        }

        stringstream ss(line);
        string id_str, name, spec;
        if (getline(ss, id_str, '|') &&
            getline(ss, name, '|') &&
            getline(ss, spec)) {
            Doctor d;
            try {
                d.id = stoi(id_str);
                d.name = name;
                d.specialization = spec;
                d.display();
            } catch (...) {
                // Skip corrupted line
            }
        }
    }

    if (!hasData) {
        cout << "\nNo doctors registered yet.\n";
    }

    file.close();
}

void Hospital::bookAppointment() {
    Appointment a;
    a.input();

    if (!patientExists(a.patientId)) {
        cout << "\nError: Patient ID " << a.patientId << " does not exist!\n";
        return;
    }
    if (!doctorExists(a.doctorId)) {
        cout << "\nError: Doctor ID " << a.doctorId << " does not exist!\n";
        return;
    }

    ofstream file("appointments.txt", ios::app);
    if (!file) {
        cout << "\nError: Could not open appointments.txt for writing.\n";
        return;
    }
    file << a.patientId << "|" << a.doctorId << "|" << a.date << "\n";
    file.close();

    cout << "\nAppointment Booked Successfully!\n";
}

void Hospital::viewAppointments() {
    ifstream file("appointments.txt");
    if (!file) {
        cout << "\nNo appointments booked yet (appointments.txt not found).\n";
        return;
    }

    string line;
    bool hasData = false;

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (!hasData) {
            cout << "\n" << left << setw(15) << "PatientID" 
                 << setw(15) << "DoctorID" 
                 << setw(15) << "Date" << endl;
            cout << string(45, '-') << endl;
            hasData = true;
        }

        stringstream ss(line);
        string pid_str, did_str, date;
        if (getline(ss, pid_str, '|') &&
            getline(ss, did_str, '|') &&
            getline(ss, date)) {
            Appointment a;
            try {
                a.patientId = stoi(pid_str);
                a.doctorId = stoi(did_str);
                a.date = date;
                a.display();
            } catch (...) {
                // Skip corrupted line
            }
        }
    }

    if (!hasData) {
        cout << "\nNo appointments booked yet.\n";
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
        
        choice = getValidInt("Enter choice: ");

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
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);
}

