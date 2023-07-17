#include "Triage.h"


void Triage::AddPatient(int urgency, std::string patient_name) {
    if (urgency >= 1 && urgency <= 5) {
        // Crea un nuevo objeto de tipo Patient con el nombre y nivel de urgencia dados
        Patient newPatient(patient_name, urgency);  
         // Agrega el paciente a la cola correspondiente según su nivel de urgencia
        queues[urgency - 1].Enqueue(newPatient); 
    }
}

void Triage::PassPatient() {
    for (int i = 0; i < 5; i++) {
        if (!queues[i].IsEmpty()) {
            // Remueve al primer paciente en la cola con el nivel de urgencia más bajo
            queues[i].Dequeue();  
            break;
        }
    }
}

void Triage::Print() {
    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << "-> ";
        if (!queues[i].IsEmpty()) {
            // Crea una cola temporal para almacenar los pacientes de un nivel de urgencia
            LQueue<Patient> tempQueue = queues[i];  
            while (!tempQueue.IsEmpty()) {
                // Imprime el nombre del paciente en el frente de la cola temporal
                std::cout << tempQueue.Front().name;  
                // Remueve al paciente del frente de la cola temporal
                tempQueue.Dequeue();  
                if (!tempQueue.IsEmpty()) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << std::endl;
    }
}
