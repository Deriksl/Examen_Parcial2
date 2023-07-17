#ifndef TRIAGE_H
#define TRIAGE_H

#include <iostream>
#include <string>
#include "LQueue.h"


class Triage {
private:
    struct Patient {
        std::string name;
        int urgency;
        Patient(std::string n, int u) : name(n), urgency(u) {}
    };

    // Arreglo de colas para almacenar pacientes en diferentes niveles de urgencia
    LQueue<Patient> queues[5];  

public:
    // Agrega un nuevo paciente a la cola correspondiente según su nivel de urgencia
    void AddPatient(int urgency, std::string patient_name); 
    // Atiende al siguiente paciente, removiendo al primero en la cola con el nivel de urgencia más bajo 
    void PassPatient(); 
    // Imprime el nombre de los pacientes presentes en cada nivel, en el orden en que se encuentran en las colas 
    void Print();  



};

#endif  

