#include <iostream>
#include <map>
#include <queue>

class Triage {
private:
    std::map<int, std::queue<std::string>> patients; // Mapa de pacientes por nivel de urgencia

public:
    void AddPatient(int urgency, std::string patient_name) {
        patients[urgency].push(patient_name);
    }

    void PassPatient() {
        if (!patients.empty()) {
            auto highest_urgency = patients.begin(); // Obtiene el nivel de urgencia más bajo (primer elemento del mapa)
            auto& patient_queue = highest_urgency->second; // Obtiene la cola de pacientes para ese nivel de urgencia

            std::cout << "Atendiendo a: " << patient_queue.front() << std::endl;
            patient_queue.pop();

            // Si no quedan pacientes en ese nivel de urgencia, lo elimina del mapa
            if (patient_queue.empty()) {
                patients.erase(highest_urgency);
            }
        }
        else {
            std::cout << "No hay más pacientes en espera." << std::endl;
        }
    }

    void Print() {
        std::cout << "Lista de pacientes por nivel de urgencia:" << std::endl;

        for (const auto& urgency_queue : patients) {
            int urgency = urgency_queue.first;
            const auto& patient_queue = urgency_queue.second;

            std::cout << "Nivel de urgencia " << urgency << ":" << std::endl;
            std::queue<std::string> temp_queue = patient_queue; // Copia temporal de la cola para no modificarla
            while (!temp_queue.empty()) {
                std::cout << "- " << temp_queue.front() << std::endl;
                temp_queue.pop();
            }
        }
    }
};

int main() {
    Triage myTriage;

    // Agrega pacientes al triaje
    myTriage.AddPatient(1, "Pablo");
    myTriage.AddPatient(5, "Maria");
    myTriage.AddPatient(3, "Luis");
    myTriage.AddPatient(2, "Pancho");
    myTriage.AddPatient(1, "Juan");
    myTriage.AddPatient(4, "Pepe");
    myTriage.AddPatient(5, "Ana");
    myTriage.AddPatient(1, "Pedro");

    // Atiende a los pacientes
    myTriage.PassPatient();
    myTriage.PassPatient();

    // Imprime la lista de pacientes por nivel de urgencia
    myTriage.Print();

    return 0;
}