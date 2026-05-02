#include "FileHelper.h"

int fileSavePatient(const Patient* Patients, int count, int lastId) {
	FILE* filePatient = fopen(FILE_PATIENT, "w");
	if(!filePatient) return 0;

	fprintf(filePatient, "%d\n", lastId);

	for (int i=0; i<count; i++) {
		fprintf(filePatient,"%d,%s,%d,%s,%s\n", Patients[i].id, Patients[i].name, Patients[i].birthYear, Patients[i].bloodType, Patients[i].contactNumber);
	}
	fclose(filePatient);
	return 1;
}

int fileSaveAppoinment(const Appointment* Appointments, int count) {
	FILE* fileAppointment = fopen(FILE_APPOINTMENT, "w");
	if(!fileAppointment) return 0;

	for (int i=0; i<count; i++) {
		fprintf(fileAppointment,"%d,%d,%d,%d,%s,%.2lf\n", Appointments[i].idPatient, Appointments[i].day, Appointments[i].month, Appointments[i].year, Appointments[i].nameDoctor, Appointments[i].fee);
	}
	fclose(fileAppointment);
	return 1;
}

int loadFilePatient(Patient* Patients, patientManager* pm, int* count, int maxFile) {
	FILE* filePatient = fopen(FILE_PATIENT, "r");
	if(!filePatient) {
        (*pm).lastId = 1000; 
		return 1;
	}

	char line[256];
	if (fgets(line, sizeof(line), filePatient)) {
        pm->lastId = atoi(line);
    }
	*count=0;
	while (fgets(line, sizeof(line), filePatient) && *count< maxFile) {
		// delete /n in the end of the string
		line[strcspn(line, "\n")] = 0;
		char* IdPatient_str = strtok(line, ",");
		char* name = strtok(NULL, ",");
		char* birthYear_str = strtok(NULL, ",");
		char* bloodType_str = strtok(NULL, ",");
		char* contactNumber_str = strtok(NULL, ",");

		if (IdPatient_str && name && birthYear_str && bloodType_str && contactNumber_str) {
			Patients[*count].id = atoi(IdPatient_str);
			strncpy(Patients[*count].name, name, MAX_NAME_LENGHT);
			Patients[*count].birthYear = atoi(birthYear_str);
			strncpy(Patients[*count].bloodType, bloodType_str, 4);
			strncpy(Patients[*count].contactNumber, contactNumber_str, 10);
			(*count)++;

		}
	}
	fclose(filePatient);
	return 1;
}

int loadFileAppointment(Appointment* Appointments, int* count, int maxFile) {
	FILE* fileAppointment = fopen(FILE_APPOINTMENT, "r");
		if(!fileAppointment) {
		return 1;
	}

	char line[256];
	*count=0;
	while (fgets(line, sizeof(line), fileAppointment) && *count< maxFile) {

		char* Idpatient_str = strtok(line, ",");
		char* day_str = strtok(NULL, ",");
		char* month_str = strtok(NULL, ",");
		char* year_str = strtok(NULL, ",");
		char* nameDoctor_str = strtok(NULL, ",");
		char* fee_str = strtok(NULL, ",");

		if (Idpatient_str && day_str && month_str && year_str && nameDoctor_str && fee_str) {
			Appointments[*count].idPatient = atoi(Idpatient_str);
			Appointments[*count].day = atoi(day_str);
			Appointments[*count].month = atoi(month_str);
			Appointments[*count].year = atoi(year_str);
			strncpy(Appointments[*count].nameDoctor, nameDoctor_str, MAX_NAME_LENGHT);
			Appointments[*count].fee = atof(fee_str);
			(*count)++;
		}
	}
	fclose(fileAppointment);
	return 1;
}