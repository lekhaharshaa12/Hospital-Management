#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
using namespace std;

class Appointment {
public:
    int patientId;
    int doctorId;
    string date;

    void input();
    void display();
};

#endif
