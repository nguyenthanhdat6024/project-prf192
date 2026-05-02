#include "Appointment.h"

void printAppointment( Appointment* ap, Patient* pt){
	printf("Doctor's name: %-20s  | Patient's Name: %-25s | Appointment date: %d//%d//%d\n", ap->nameDoctor, pt->name, ap->day, ap->month, ap->year);
}
