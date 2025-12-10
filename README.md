# Dentist-Appointment-System
This repository contains my first C programming project: a Dentist Appointment Management System.
This is a fully console-based project designed for beginners but implemented with clean structure and real-clinic logic.

**Dentists in the System**

__The system includes two dentists, each with clear specialization:__

1️⃣ **Dr. Rahman – General Dentist**

__Handles:__

Regular checkups

Scaling and polishing

Cavity fillings

Basic dental treatments

Working hours: 10 AM – 10 PM

2️⃣**Dr. Karim – Oral Surgeon**

__Handles:__

Tooth extraction

Minor oral surgery

Implant consultation

Working hours: 3 PM – 8 PM

 **Login System**

__Before accessing the main system, the user must log in:__

Username: Paromita

Password: 1234

If either is incorrect, the program exits.

**Features**

✔ Add Appointment

Takes patient name, date, time, and doctor selection.

Rejects duplicate time slots.

✔ View Appointments

Displays:

Patient name

Appointment date

Time

Dentist selected

✔ Search Appointment

Searches by patient name and shows full details.

✔ Edit Appointment

Allows updating:

Name

Date

Time

Dentist
Also checks for time conflicts.

✔ Delete Appointment

Removes selected appointment and shifts the list.

✔ Sort Appointments by Date

Sorts in ascending order and saves to file.

✔ Automatic File Saving

Appointments are stored in clinic_data.txt using:

name|date|time|doctor

**Files Used**

clinic_data.txt

Automatically created and updated.

Stores all appointments even after program exits.

**How to Compile and Run**
Using GCC (Linux / Windows Terminal):

gcc main.c -o clinic
./clinic

__Using CodeBlocks / Dev-C++:__

Open the file

Click Build & Run

 **Project Structure**

DentistAppointmentSystem/
│── main.c
│── clinic_data.txt   (auto generated)
└── README.md

**Compile & Run**
gcc main.c -o clinic
./clinic

**Screenshots**

__Login Page,Main Menu,Add Appointment__
<img width="1483" height="762" alt="Screenshot 2025-12-11 021722" src="https://github.com/user-attachments/assets/4e9fbfac-351e-4509-b286-170a2c6270f0" />

__View Appointments__
<img width="1483" height="762" alt="Screenshot 2025-12-11 021808" src="https://github.com/user-attachments/assets/10b0caba-df77-4c85-ab5d-7328110a9c75" />

__Edit/Delete Screens,Sort Appointments,Exit__
<img width="1483" height="762" alt="Screenshot 2025-12-11 021828" src="https://github.com/user-attachments/assets/a1894d71-b87d-4fb6-b0d4-3e6223de32c9" />
<img width="1483" height="762" alt="Screenshot 2025-12-11 021844" src="https://github.com/user-attachments/assets/8e7b5044-6905-4940-baa2-d291bef6fb63" />
<img width="1483" height="762" alt="Screenshot 2025-12-11 021906" src="https://github.com/user-attachments/assets/debddbef-1a62-4a1f-a9e2-e620384eea86" />
<img width="1483" height="762" alt="Screenshot 2025-12-11 022217" src="https://github.com/user-attachments/assets/bd459ae1-dc7a-4fec-a2b4-d70ed2034210" />


 **Concepts Used**

Structures (struct)

Arrays

String handling

File I/O

Menu-driven program

Sorting + searching

 **Future Improvements**

Patient history

Emergency appointment mode

Show free time slots automatically


