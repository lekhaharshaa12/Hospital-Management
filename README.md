# Hospital Management System

A lightweight, reliable, and type-safe console-based Hospital Management System written in C++. This application manages records for patients, doctors, and patient-doctor appointments, persisting data locally in structured text files.

---

## Key Features

- **Robust Input Handling**: Integrates stream-safe input routines preventing program corruption or infinite loops on invalid user inputs (e.g., entering letters when numbers are expected).
- **Whitespace Support**: Fully supports string inputs with spaces (e.g., multi-word names like "John Doe" or diseases like "Type 2 Diabetes").
- **Reliable Local Persistence**: Saves all records into pipe-delimited (`|`) text files (`patients.txt`, `doctors.txt`, `appointments.txt`) for consistent line-by-line parsing.
- **Relational Integrity Validation**:
  - **Unique IDs**: Prevents registering patients or doctors with duplicate IDs.
  - **Referential Integrity**: Checks that both the Patient ID and Doctor ID exist in the database before booking an appointment.
- **Graceful File Handling**: Shows informative messages if database files are not found or contain no records.
- **Aligned CLI Output Layouts**: Utilizes column padding (`iomanip`) to display all records in clear, structured console tables.

---

## File Structure

- **[main.cpp](file:///d:/c++/hospital-management/main.cpp)**: Entry point of the program. Initializes the `Hospital` system and displays the menu.
- **[Hospital.h](file:///d:/c++/hospital-management/Hospital.h)** / **[Hospital.cpp](file:///d:/c++/hospital-management/Hospital.cpp)**: Coordinates patient, doctor, and appointment additions, list views, and integrity checks.
- **[Patient.h](file:///d:/c++/hospital-management/Patient.h)** / **[Patient.cpp](file:///d:/c++/hospital-management/Patient.cpp)**: Defines patient properties (ID, Name, Age, Disease) and input/output handlers.
- **[Doctor.h](file:///d:/c++/hospital-management/Doctor.h)** / **[Doctor.cpp](file:///d:/c++/hospital-management/Doctor.cpp)**: Defines doctor properties (ID, Name, Specialization) and input/output handlers.
- **[Appointment.h](file:///d:/c++/hospital-management/Appointment.h)** / **[Appointment.cpp](file:///d:/c++/hospital-management/Appointment.cpp)**: Defines appointment properties (Patient ID, Doctor ID, Date) and input/output handlers.
- **[InputUtil.h](file:///d:/c++/hospital-management/InputUtil.h)**: Provides inline utility functions for type-validated console readings and newline-safe string inputs.

---

## Getting Started

### Prerequisites

You need a C++ compiler supporting C++11 or higher (e.g., GCC/MinGW, Clang, or MSVC).

### Compilation

Open your terminal or command prompt in the project directory and run:

```bash
g++ main.cpp Hospital.cpp Patient.cpp Doctor.cpp Appointment.cpp -o hospital
```

### Running the Application

After compilation, execute the generated binary:

**On Windows:**
```cmd
hospital.exe
```

**On macOS / Linux:**
```bash
./hospital
```

---

## Usage Guide

1. **Add Patient**: Register a new patient. The program will prompt you for a unique Patient ID, name, age, and disease.
2. **View Patients**: Displays all registered patients in a clean tabular view.
3. **Add Doctor**: Register a new doctor. Prompts for a unique Doctor ID, name, and specialization.
4. **View Doctors**: Displays all registered doctors.
5. **Book Appointment**: Connects a patient with a doctor. The program will verify that both IDs exist in the system before prompting for the appointment date.
6. **View Appointments**: Displays all scheduled appointments.
7. **Exit**: Closes the application.
