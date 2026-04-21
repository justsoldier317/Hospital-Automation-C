#ifndef HASTANE_H
#define HASTANE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hasta Yapisi (Struct)
typedef struct {
    int id;
    char name[50];
} Patient;

// Doktor Yapisi (Struct)
typedef struct {
    int id;
    char name[50];
    char specialty[50];
} Doctor;

// Fonksiyon Prototipleri
// Bu fonksiyonlar main.c icinde detaylandirilmistir.
void addPatient(Patient **patients, int *patientCount);
void addDoctor(Doctor **doctors, int *doctorCount);

#endif