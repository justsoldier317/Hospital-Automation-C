#ifndef HASTANE_H
#define HASTANE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialty[50];
} Doctor;


void addPatient(Patient **patients, int *patientCount);
void addDoctor(Doctor **doctors, int *doctorCount);

#endif