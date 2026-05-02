#include "AppointmentManager.h"

int am_start(AppointmentManager* am) {
	(*am).count=0;
	return loadFileAppointment((*am).Appointments, &(*am).count, MAX_APPOINTMENT) ? 0 : 1;
}

int am_scheduleNewAppointment(AppointmentManager* am, Appointment ap, patientManager* pm, const char* name) {

	if ((*am).count>=MAX_APPOINTMENT) return -1;
	for (int i=0; i<(*pm).count; i++) {
		if(strcmp((*pm).Patients[i].name, name) == 0) {
			ap.idPatient=(*pm).Patients[i].id;
			(*am).Appointments[(*am).count++] = ap;
			return 1;
		}
	}
	return 0;
}

double am_calculateFee(AppointmentManager* am, int idBuffer) {
	double totalFee=0;
	for (int i=0; i<(*am).count; i++) {
		if(idBuffer == (*am).Appointments[i].idPatient) {
			totalFee += (*am).Appointments[i].fee;
		}
	}
	return totalFee;
}

void am_printAppointmentByDoctor(AppointmentManager* am, patientManager* pm,const char* nameBuffer) {
	int found = 0;
	for(int i=0; i<(*am).count; i++) {
		if(strcmp((*am).Appointments[i].nameDoctor, nameBuffer) == 0) {
			for(int j=0; j < (*pm).count; j++) {
				if((*am).Appointments[i].idPatient == (*pm).Patients[j].id) {
					printAppointment(&(*am).Appointments[i], &(*pm).Patients[j]);
					found=1;
				}
			}
		}
	}
	if(found == 0) {
		printf("Not Appointment for %s",nameBuffer);
	}
}

void am_sortByTotalFee(patientManager* pm, AppointmentManager* am) {
	for (int i=0; i<(*pm).count-1; i++) {
		// Bubble Sort
		for (int j=0; j<(*pm).count-1; j++) {
			if (am_calculateFee(&(*am), (*pm).Patients[j].id) > am_calculateFee(&(*am), (*pm).Patients[j+1].id)) {
				Patient temp = (*pm).Patients[j+1];
				(*pm).Patients[j+1] = (*pm).Patients[j];
				(*pm).Patients[j] = temp;
			}
		}
	}
}

int am_saveFile(const AppointmentManager* am) {
	return fileSaveAppoinment((*am).Appointments, (*am).count);
}