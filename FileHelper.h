#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "Appointment.h"
#include "patientManager.h"
#include "AppointmentManager.h"

#define FILE_PATIENT "DataPatient.txt"
#define FILE_APPOINTMENT "DataAppointment.txt"

// Save data patient to file "DataPatient.txt"
// return 1 -> save data successful
// return 0 -> error 
int fileSavePatient(const Patient* Patients, int count, int lastId);

// Save data appointment to file "DataAppointment.txt"
// return 1 -> save data successful
// return 0 -> error 
int fileSaveAppoinment(const Appointment* Appointments, int count);

// Load data patient from file "DataPatient.txt"
// return 1 -> load data successful
int loadFilePatient(Patient* Patients, patientManager* pm, int* count, int maxFile);

// Load data appointment from file "DataAppointment.txt"
// return 1 -> load data successful
int loadFileAppointment(Appointment* Appointments, int* count, int maxFile);

#endif