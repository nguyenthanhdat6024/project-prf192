#include <stdio.h>
#include <string.h>
#include "FileHelper.h"
#include "AppointmentManager.h"
#include "PatientManager.h"

int pm_start(patientManager* pm) {
	(*pm).count=0;
	return loadFilePatient((*pm).Patients, pm, &(*pm).count, MAX_PATIENT) ? 0 : 1;
}

int pm_addNewPatient(patientManager* pm, Patient pt) {

	if ((*pm).count>= MAX_PATIENT) return 0;
	(*pm).lastId++;
	pt.id = (*pm).lastId;
	(*pm).Patients[(*pm).count++] = pt;
	return 1;
}

int pm_updatePatient(patientManager* pm, const char* name, char* newContactNumber) {
	for (int i=0; i<(*pm).count; i++ ) {
		if (strcmp((*pm).Patients[i].name, name) == 0 ) {
			strcpy((*pm).Patients[i].contactNumber, newContactNumber);
			return 1;
		}
	}
	return 0;
}

int pm_removePatient(patientManager* pm, const char* name) {
	for(int i=0; i<(*pm).count; i++) {
		if(strcmp((*pm).Patients[i].name, name)==0) {
			for(int j=i; j<(*pm).count; j++) {
				(*pm).Patients[j] = (*pm).Patients[j+1];
			}
			(*pm).count--;
			return 1;
		}
	}
	return 0;
}

void pm_searchByName(patientManager* pm, const char* name) {
	int found=0;
	for(int i=0; i<(*pm).count; i++) {
		if(strcmp((*pm).Patients[i].name, name)==0) {
			printPatient(&(*pm).Patients[i]);
			found=1;
		}
	}
	if(found == 0) printf("(!). Not found or Not have on the list");
}

int pm_checkId(patientManager* pm, char* name, int year) {
	for (int i=0; i<(*pm).count; i++) {
		if(strcmp((*pm).Patients[i].name, name) == 0 && year == (*pm).Patients[i].birthYear) {
			return (*pm).Patients[i].id;
		}
	}
	return -1;
}

void pm_sortByBirthYear(patientManager* pm) {
	for (int i=0; i<(*pm).count-1; i++) {
		for (int j=0; j<(*pm).count-1; j++) {
			if((*pm).Patients[j].birthYear > (*pm).Patients[j+1].birthYear ) {
				Patient temp = (*pm).Patients[j+1];
				(*pm).Patients[j+1] = (*pm).Patients[j];
				(*pm).Patients[j] = temp;
			}
		}
	}
}

int pm_saveFile(const patientManager* pm) {
	return fileSavePatient((*pm).Patients, (*pm).count, (*pm).lastId);
}