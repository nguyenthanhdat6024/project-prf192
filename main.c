#include <stdio.h>
#include "consoleIO.h"
#include "patientManager.h"
#include "AppointmentManager.h"


int main() {

	patientManager pm;
	AppointmentManager am;

	if(pm_start(&pm)!=0 ) {
		printf("intilized file erorr.\n");
	} else printf("intilized file successfully.\n");

	if(am_start(&am)!=0) {
		printf("intilized file erorr.\n");
	} else printf("intilized file successfully.\n");

	int choice=-1;
	char nameBuffer[100];
	char blTypeBuffer[5];
	char conNumberBuffer[12];
	do {
		io_display();
		choice = io_readInt("");
		switch (choice) {
			case 1:
				printf("\n---------**--------Add Patient-----------**------------\n");
				Patient pt;
				io_readString("Enter Patient's Name: ", pt.name, 100);
				pt.birthYear = io_readInt("Enter Birth Year: ");
				io_readString("Enter Blood Type: ", pt.bloodType, 5);
				io_readString("Enter Contact Number: ", pt.contactNumber, 12);

				int result = pm_addNewPatient(&pm, pt);
				if (result == 1) {
					printf("Add new patient successfully.\n");
				} else {
					printf("Data is full.\n");
				}
				break;
			case 2:
				printf("\n----------**---------Update Patient---------**---------\n");
				io_readString("Enter Patient's Name: ", nameBuffer, sizeof(nameBuffer));
				io_readString("Enter New Contact Number: ", conNumberBuffer, sizeof(conNumberBuffer));

				result = pm_updatePatient(&pm, nameBuffer, conNumberBuffer);
				if(result==1) {
					printf("Update patient's contact number successfully.\n");
				} else printf("Update error: Not found patient.\n");
				break;
			case 3:
				printf("\n--------**-----------Remove Patient---------**--------\n");
				io_readString("Enter Patient's Name: ", nameBuffer, sizeof(nameBuffer));
				if(pm_removePatient(&pm, nameBuffer) == 1) {
					printf("Removed patient Successfully.\n");
				} else printf("Removed erorr: Not found patient.\n");
				break;
			case 4:
				printf("\n-----------------Schudule New Appointment--------------\n");
				Appointment ap;
				io_readString("Enter Patient's Name: ", nameBuffer, 100);
				ap.day = io_readInt("Enter day: ");
				ap.month = io_readInt("Enter month: ");
				ap.year = io_readInt("Enter year: ");
				io_readString("Enter Doctor's Name: ", ap.nameDoctor, 100);
				ap.fee = io_readDouble("Enter Hospital Fee: ");
				
				result = am_scheduleNewAppointment(&am, ap, &pm, nameBuffer);
				if (result == 0) {
					printf("Could not found the patient to schedule an appointment.\n");
				} else if(result == 1) {
					printf("Schudule new appointment successfully.\n");
				} else printf("List appointment was full.\n");
				break;
			case 5:
				printf("\n---------------Calculate Hospital Fee------------------\n");
				io_readString("Enter Patient's Name: ", nameBuffer, 100);
				int yearBuffer = io_readInt("Enter patient's birth year: ");
				
				result = pm_checkId(&pm, nameBuffer, yearBuffer);
				if (result !=-1) {
					printf("Total hospital Fee of %s : %.2lf", nameBuffer, am_calculateFee(&am, result));
				} else printf("Not found patient to calculate.\n");
				break;
			case 6:
				printf("\n-------------Group Appointment By Doctor---------------\n");
				io_readString("Enter Dotor's Name: ", nameBuffer, 100);
				am_printAppointmentByDoctor(&am, &pm,nameBuffer);
				break;
			case 7:
				printf("\n----------------Search Patient By Name-----------------\n");
				io_readString("Enter Patient's Name: ", nameBuffer, 100);
				pm_searchByName(&pm, nameBuffer);
				break;
			case 8:
				printf("\n---------------Sort Patient By Birth Year--------------\n");
				pm_sortByBirthYear(&pm);
				io_printPatientList(pm.Patients, pm.count);
				break;
			case 9:
				printf("\n---------------Sort Patient By Total Fee---------------\n");
				am_sortByTotalFee(&pm, &am);
				io_printPatientAndFee(&am, &pm);
				break;
			case 10:
				printf("\n---------***-----------Save File--------***------------\n");
				if(pm_saveFile(&pm) && am_saveFile(&am)) {
					printf("Save successfully.\n");
				} else printf("Save failed.\n");
				break;
			case 0:
				printf("Goodbye!");
				break;
		}
	} while(choice != 0);

	return 0;
}