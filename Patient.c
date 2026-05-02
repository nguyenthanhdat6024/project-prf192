#include "Patient.h"

void printPatient(const Patient* pt){
	printf("ID: %-5d | Name: %-25s | Birth Year: %-5d | Blood Type: %-3s | Contact Number: %-10s\n", pt->id, pt->name,pt->birthYear,pt->bloodType,pt->contactNumber);
}

void printPatientAndFee(const Patient* pt){
	printf("Name: %-25s | Birth Year: %-5d | Total Fee: ", pt->name,pt->birthYear);
}