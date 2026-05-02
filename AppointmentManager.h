#ifndef MANAGERAPPOINTMENT_H
#define MANAGERAPPOINTMENT_H

#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "FileHelper.h"
#include "Appointment.h"
#include "PatientManager.h"


#define MAX_APPOINTMENT 1000

typedef struct{
	Appointment Appointments[MAX_APPOINTMENT];
	int count;
}AppointmentManager;


int am_start(AppointmentManager* am);

// Schedule new appointment
// return -1 -> file data full
// return 1 -> schedule appointment successfull
// return 0 -> schedule error
int am_scheduleNewAppointment(AppointmentManager* am, Appointment ap, patientManager* pm, const char* name);

// calculate patient's fee
// return total fee of the paient
double am_calculateFee(AppointmentManager* am, int idBuffer);

// print appointment matching Doctor's name buffer
void am_printAppointmentByDoctor(AppointmentManager* am, patientManager* pm,const char* nameBuffer);

// Sort by Patient's Total Fee
// use "for" two time to double check the Sorting
void am_sortByTotalFee(patientManager* pm, AppointmentManager* am);

int am_saveFile(const AppointmentManager* am);
#endif