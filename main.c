#include "hospital.h"

void addPatient(Patient **patients, int *count) {
    *patients = (Patient*)realloc(*patients, (*count + 1) * sizeof(Patient));
    if (*patients == NULL) return;
    printf("New Patient ID: "); scanf("%d", &(*patients)[*count].id);
    printf("New Patient Name: "); scanf("%s", (*patients)[*count].name);
    (*count)++;
    printf("Patient added successfully.\n");
}

void deletePatient(Patient **patients, int *count) {
    if (*count == 0) { printf("No records to delete.\n"); return; }
    int id, found = -1;
    printf("Enter Patient ID to delete: "); scanf("%d", &id);
    for(int i=0; i<*count; i++) if((*patients)[i].id == id) found = i;
    if(found != -1) {
        for(int i=found; i<*count-1; i++) (*patients)[i] = (*patients)[i+1];
        (*count)--;
        if (*count > 0) *patients = (Patient*)realloc(*patients, (*count) * sizeof(Patient));
        else { free(*patients); *patients = NULL; }
        printf("Patient deleted.\n");
    } else printf("ID not found.\n");
}

void addDoctor(Doctor **doctors, int *count) {
    *doctors = (Doctor*)realloc(*doctors, (*count + 1) * sizeof(Doctor));
    if (*doctors == NULL) return;
    printf("New Doctor ID: "); scanf("%d", &(*doctors)[*count].id);
    printf("New Doctor Name: "); scanf("%s", (*doctors)[*count].name);
    (*count)++;
    printf("Doctor added successfully.\n");
}

void deleteDoctor(Doctor **doctors, int *count) {
    if (*count == 0) { printf("No records to delete.\n"); return; }
    int id, found = -1;
    printf("Enter Doctor ID to delete: "); scanf("%d", &id);
    for(int i=0; i<*count; i++) if((*doctors)[i].id == id) found = i;
    if(found != -1) {
        for(int i=found; i<*count-1; i++) (*doctors)[i] = (*doctors)[i+1];
        (*count)--;
        if (*count > 0) *doctors = (Doctor*)realloc(*doctors, (*count) * sizeof(Doctor));
        else { free(*doctors); *doctors = NULL; }
        printf("Doctor deleted.\n");
    } else printf("ID not found.\n");
}

int main() {
    Patient *patients = NULL; int pCount = 0;
    Doctor *doctors = NULL; int dCount = 0;
    int choice, sub, sid;

    while(1) {
        printf("\n--- HOSPITAL AUTOMATION SYSTEM ---\n");
        printf("1. Doctor Login\n2. Patient Login\n3. Register (Doctor/Patient)\n4. Delete (Doctor/Patient)\n0. Exit\nSelection: ");
        if(scanf("%d", &choice) != 1) break;
        if(choice == 0) break;

        switch(choice) {
            case 1: 
                if(dCount == 0) printf("No registered doctors.\n");
                else {
                    for(int i=0; i<dCount; i++) printf("[%d] Dr. %s\n", doctors[i].id, doctors[i].name);
                    printf("Login ID: "); scanf("%d", &sid);
                    for(int i=0; i<dCount; i++) if(doctors[i].id == sid) printf("Welcome, Dr. %s\n", doctors[i].name);
                }
                break;
            case 2: 
                if(pCount == 0) printf("No registered patients.\n");
                else {
                    for(int i=0; i<pCount; i++) printf("[%d] %s\n", patients[i].id, patients[i].name);
                    printf("Login ID: "); scanf("%d", &sid);
                    for(int i=0; i<pCount; i++) if(patients[i].id == sid) printf("Welcome, %s\n", patients[i].name);
                }
                break;
            case 3: 
                printf("1. Add Patient\n2. Add Doctor\nSelection: "); scanf("%d", &sub);
                if(sub == 1) addPatient(&patients, &pCount); else addDoctor(&doctors, &dCount);
                break;
            case 4: 
                printf("1. Delete Patient\n2. Delete Doctor\nSelection: "); scanf("%d", &sub);
                if(sub == 1) deletePatient(&patients, &pCount); else deleteDoctor(&doctors, &dCount);
                break;
        }
    }
    free(patients); free(doctors);
    return 0;
}