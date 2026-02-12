# 🏥 Hospital Management System – C++ Project

A simple and modular **Hospital Management System** implemented in **C++** using **Object-Oriented Programming (OOP)** and file handling.  
This project allows managing **patients, doctors, and appointments** efficiently in a console-based application.

---

## 📌 Project Description

The Hospital Management System is a console-based application designed to automate and simplify hospital management tasks.  
It uses **OOP principles** like classes, objects, and encapsulation, and **file handling** to store data permanently.

**Functionalities include:**

- Adding new patients and viewing patient records  
- Adding new doctors and viewing doctor records  
- Booking and viewing appointments  
- Persistent storage using `.txt` files  

---

## ✨ Features

### 🧑 Patient Management
- Add new patient records  
- View all patients  

### 👨‍⚕ Doctor Management
- Add new doctor records  
- View all doctors  

### 📅 Appointment System
- Book appointments between patients and doctors  
- View all appointments  

### 💻 Technical Features
- Console-based menu-driven system  
- Uses C++ OOP concepts (classes, objects, encapsulation)  
- File handling for persistent storage  
- Modular design using multiple files (`.h` and `.cpp`)  
- Uses STL vector for storing objects in memory  

---

## 🛠 Technologies Used

| Category      | Technology      |
|--------------|----------------|
| Programming  | C++             |
| OOP Concepts | Classes, Objects, Encapsulation |
| File Handling| Reading/Writing `.txt` files |
| Tools        | Any C++ compiler (g++, Code::Blocks, Visual Studio) |

---

## 📁 Project Structure

HospitalManagement/
│── main.cpp
│── Patient.h
│── Patient.cpp
│── Doctor.h
│── Doctor.cpp
│── Appointment.h
│── Appointment.cpp
│── Hospital.h
│── Hospital.cpp
│── README.md
│── patients.txt (auto-generated)
│── doctors.txt (auto-generated)
│── appointments.txt (auto-generated)


---

## 🚀 How to Run Locally

### Step 1 – Open Terminal / Command Prompt

Navigate to the project folder, e.g.:


D:\c++\HospitalManagement


---

### Step 2 – Compile the Project

Run the following command to compile all files:

```bash
g++ main.cpp Patient.cpp Doctor.cpp Appointment.cpp Hospital.cpp -o hospital


Step 3 – Run the Executable

On Windows PowerShell, run:

.\hospital.exe


On Linux/Mac, run:

./hospital


Step 4 – Use the Program

You will see a menu:


===== HOSPITAL MANAGEMENT SYSTEM =====
1. Add Patient
2. View Patients
3. Add Doctor
4. View Doctors
5. Book Appointment
6. View Appointments
0. Exit

Enter the corresponding number to perform operations.