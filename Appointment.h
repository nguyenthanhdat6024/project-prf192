#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include"Patient.h"

typedef struct{
	int idPatient;
	int day,month,year;
	char nameDoctor[MAX_NAME_LENGHT];
	double fee;
}Appointment;

void printAppointment( Appointment* ap, Patient* pt);

#endif