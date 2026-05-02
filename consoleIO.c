#include "consoleIO.h"

void io_clearBuffer(){
	int c;
	while((c=getchar()) != '\n' && c != EOF);
}

void io_display(){
	printf("\n=======================*******=========================\n");
	printf("1. Register New Paient.\n");
	printf("2. Upadate Patient's Information.\n");
	printf("3. Remove Patient's infomation.\n");
	printf("4. Schudule New Appoinment.\n");
	printf("5. Calculate Hospital Fee.\n");
	printf("6. Group Appointment By Doctor.\n");
	printf("7. Search Patient's information.\n");
	printf("8. Sort Patient By Birth Year.\n");	
	printf("9. Sort Patient By Total Fee.\n");	
	printf("10. Save File.\n");	
	printf("0.Exit.\n");
	printf("=======================================================\n");
	printf("enter your choice: ");
}

void io_readString(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int io_readInt(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= 0) {
            io_clearBuffer();
            return value;
        }
        printf("(!) Invalid input. Please enter a non-negative integer.\n");
        io_clearBuffer();
    }
}

double io_readDouble(const char* prompt){
	 double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1 && value >= 0) {
            io_clearBuffer();
            return value;
        }
        printf("(!) Invalid input. Please enter a non-negative integer.\n");
        io_clearBuffer();
    }
}

void io_printPatientList(const Patient* Patient, int count) {
    if (count == 0) {
        printf("(!) List is empty or no results found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        // Updated call to match Patient.h
        printPatient(&Patient[i]); 
    }
}

void io_printPatientAndFee(AppointmentManager* am, patientManager* pm) {
	if ((*pm).count == 0) {
		printf("(!) List is empty.\n");
		return;
	}
	for (int j = 0; j < (*pm).count; j++) {
		// Updated call to match Patient.h
		printPatientAndFee(&(*pm).Patients[j]);
		printf("%.2lf\n", am_calculateFee(&(*am), (*pm).Patients[j].id));
	}
}
