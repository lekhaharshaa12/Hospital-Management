#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include <vector>

class Hospital {
public:
    void addPatient();
    void viewPatients();

    void addDoctor();
    void viewDoctors();

    void bookAppointment();
    void viewAppointments();

    void menu();
};

#endif
