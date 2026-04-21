#include "hospital.h"


void addPatient(Patient **patients, int *patientCount) {
    *patients = (Patient*)realloc(*patients, (*patientCount + 1) * sizeof(Patient));
    if (*patients == NULL) return;
    printf("Enter Patient ID: "); scanf("%d", &(*patients)[*patientCount].id);
    printf("Enter Patient Name: "); scanf("%s", (*patients)[*patientCount].name);
    (*patientCount)++;
    printf("Success!\n");
}

void addDoctor(Doctor **doctors, int *doctorCount) {
    *doctors = (Doctor*)realloc(*doctors, (*doctorCount + 1) * sizeof(Doctor));
    if (*doctors == NULL) return;
    printf("Enter Doctor ID: "); scanf("%d", &(*doctors)[*doctorCount].id);
    printf("Enter Doctor Name: "); scanf("%s", (*doctors)[*doctorCount].name);
    (*doctorCount)++;
    printf("Success!\n");
}

int main() {
    Patient *patients = NULL;
    Doctor *doctors = NULL;
    int patientCount = 0, doctorCount = 0, choice, searchId;

    while(1) {
        printf("\n1. Doctor Login\n2. Patient Login\n3. Register\n0. Exit\nSelection: ");
        if(scanf("%d", &choice) != 1) break;
        if(choice == 0) break;

        switch(choice) {
            case 1:
                if(doctorCount == 0) printf("No doctors.\n");
                else {
                    for(int i=0; i<doctorCount; i++) printf("[%d] Dr. %s\n", doctors[i].id, doctors[i].name);
                    printf("ID to Login: "); scanf("%d", &searchId);
                    for(int i=0; i<doctorCount; i++) {
                        if(doctors[i].id == searchId) printf("Welcome Dr. %s\n", doctors[i].name);
                    }
                }
                break;
            case 2:
                if(patientCount == 0) printf("No patients.\n");
                else {
                    for(int i=0; i<patientCount; i++) printf("[%d] %s\n", patients[i].id, patients[i].name);
                    printf("ID to Login: "); scanf("%d", &searchId);
                    for(int i=0; i<patientCount; i++) {
                        if(patients[i].id == searchId) printf("Welcome %s\n", patients[i].name);
                    }
                }
                break;
            case 3:
                printf("1. Patient 2. Doctor: ");
                int sub; scanf("%d", &sub);
                if(sub == 1) addPatient(&patients, &patientCount);
                else addDoctor(&doctors, &doctorCount);
                break;
        }
    }
    free(patients); free(doctors);
    return 0;
}