#ifndef CONSOLEIO_H
#define CONSOLEIO_H

#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "PatientManager.h"
#include "AppointmentManager.h"

// clear buffer from user
void io_clearBuffer();

// display suggest option for user
void io_display();

// read string from user
void io_readString(const char* prompt, char* buffer, int size);

// read integer from user
int io_readInt(const char* prompt);

// read double from user
double io_readDouble(const char* prompt);

// print all patient int the list
void io_printPatientList(const Patient* Patient, int count);

// print Patient's information (name, birth year and total fee)
void io_printPatientAndFee(AppointmentManager* am, patientManager* pm);

#endif