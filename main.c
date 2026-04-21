#include "hastane.h"

void addPatient(Patient **patients, int *patientCount) {
    *patients = realloc(*patients, (*patientCount + 1) * sizeof(Patient));
    if (*patients == NULL) { printf("Memory error!\n"); return; }
    
    printf("Patient ID: "); scanf("%d", &(*patients)[*patientCount].id);
    printf("Patient Name: "); scanf("%s", (*patients)[*patientCount].name);
    (*patientCount)++;
    printf("Patient added successfully.\n");
}

void addDoctor(Doctor **doctors, int *doctorCount) {
    *doctors = realloc(*doctors, (*doctorCount + 1) * sizeof(Doctor));
    if (*doctors == NULL) { printf("Memory error!\n"); return; }

    printf("Doctor ID: "); scanf("%d", &(*doctors)[*doctorCount].id);
    printf("Doctor Name: "); scanf("%s", (*doctors)[*doctorCount].name);
    (*doctorCount)++;
    printf("Doctor added successfully.\n");
}

int main() {
    Patient *patients = NULL;
    Doctor *doctors = NULL;
    int patientCount = 0, doctorCount = 0, choice;

    while(1) {
        printf("\n--- HOSPITAL AUTOMATION SYSTEM ---\n");
        printf("1. Doctor Login (List)\n2. Patient Login (List)\n3. Add User (Doctor/Patient)\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 0) break;

        switch(choice) {
            case 1:
                printf("\n--- Registered Doctors ---\n");
                for(int i = 0; i < doctorCount; i++) 
                    printf("ID: %d - Name: %s\n", doctors[i].id, doctors[i].name);
                break;
            case 2:
                printf("\n--- Registered Patients ---\n");
                for(int i = 0; i < patientCount; i++) 
                    printf("ID: %d - Name: %s\n", patients[i].id, patients[i].name);
                break;
            case 3:
                printf("1. Add Patient\n2. Add Doctor\nSelection: ");
                int subChoice; scanf("%d", &subChoice);
                if(subChoice == 1) addPatient(&patients, &patientCount);
                else if(subChoice == 2) addDoctor(&doctors, &doctorCount);
                break;
            default: 
                printf("Invalid selection!\n");
        }
    }

    free(patients);
    free(doctors);
    return 0;
}