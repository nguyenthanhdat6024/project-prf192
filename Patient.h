#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGHT 100

typedef struct{
	int id;
	char name[MAX_NAME_LENGHT];
	int birthYear;
	char bloodType[5];
	char contactNumber[12];
}Patient;

void printPatient(const Patient* pt);

void printPatientAndFee(const Patient* pt);
#endif