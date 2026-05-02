#ifndef MANAGERPATIENT_H
#define MANAGERPATIENT_H

#include "patient.h"

#define MAX_PATIENT 100

typedef struct{
	Patient Patients[MAX_PATIENT];
	int count;
	int lastId;
}patientManager;


int pm_start(patientManager* pm);

// Add new patient application
// return 1 is add successfully, return 0 is full patient
int pm_addNewPatient(patientManager* pm, Patient pt);

// Update Patient's contact number
// return 1 is update successfully
// return 0 is update error
int pm_updatePatient(patientManager* pm,const char* name, char* newContactNumber);

// Remove Patient's information
// return 1 is remove successfully
// return 0 is remove error
int pm_removePatient(patientManager* pm, const char* name);

// Search patient
// found = 1 is found
// found = 0 is not found
void pm_searchByName(patientManager* pm, const char* name);

// check patient ID
// return id if found patient in list
// return -1 is not found patient
int pm_checkId(patientManager* pm, char* name, int year);

// Sort by Patient's birth year
// use "for" two time to double check the Sorting
void pm_sortByBirthYear(patientManager* pm);

int pm_saveFile(const patientManager* pm);
#endif