#include <iostream>
#include <string>

using namespace std;


struct RegistroReserva {
    string nombreCliente;
    string tipoHabitacion;
    int numPersonas;
    int numDias;
    int fechaSalidaEstimada; 

    RegistroReserva() {}

    
    RegistroReserva(string nombre, string tipo, int personas, int dias, int fecha)
        : nombreCliente(nombre), tipoHabitacion(tipo), numPersonas(personas), numDias(dias), fechaSalidaEstimada(fecha) {}
};


class Habitacion {
private:
    string nombre;
    int capacidadMaxima;
    float costoPorNoche;
    int disponibles;

public:
    Habitacion(string n, int cap, float costo, int disp) : nombre(n), capacidadMaxima(cap), costoPorNoche(costo), disponibles(disp) {}

    string getNombre() const { return nombre; }
    int getCapacidadMaxima() const { return capacidadMaxima; }
    float getCostoPorNoche() const { return costoPorNoche; }
    int getDisponibles() const { return disponibles; }
    void reservarHabitacion() { --disponibles; }
    void liberarHabitacion() { ++disponibles; }

    // Método para calcular el costo total de la reserva
    float calcularCostoTotal(int numPersonas, int numDias, float descuentoAdultoMayor, float descuentoNino) const {
        float costoTotal = costoPorNoche * numDias;
        float descuentoTotal = 0.0;

       

        costoTotal -= descuentoTotal;
        return costoTotal;
    }
};

// Función para mostrar el calendario de disponibilidad de habitaciones
void mostrarCalendario(const Habitacion habitaciones[], int numTipos) {
    cout << "\n--- Calendario de Disponibilidad de Habitaciones ---" << endl;
    for (int i = 0; i < numTipos; ++i) {
        cout << "Habitación " << habitaciones[i].getNombre() << ":" << endl;
        cout << "   Disponibles: " << habitaciones[i].getDisponibles() << endl;
    }
    cout << "----------------------------------------------------" << endl;
}

int main() {
    Habitacion habitaciones[4] = {
        {"Habitación Normal", 3, 3000, 4},
        {"Suite", 6, 8000, 4},
        {"Habitación Imperial", 10, 12000, 4},
        {"Villa", 15, 20000, 4}
    };

    const float descuentoAdultoMayor = 0.3;  // 30%
    const float descuentoNino = 0.2;         // 20%

    int reservacionesRealizadas = 0;
    RegistroReserva historial[10]; 

    cout << "Bienvenido al Hotel Paralish" << endl;

    char opcion;
    do {
        if (reservacionesRealizadas >= 10) {
            cout << "Se ha alcanzado el límite máximo de 10 reservaciones por día." << endl;
            break;
        }

        string nombreCliente;
        int numPersonas;
        int numDias;
        int tipoHabitacion;

        cout << "\n¿Desea hacer una reserva? (s/n): ";
        cin >> opcion;

        if (opcion != 's' && opcion != 'S') {
            cout << "Gracias por visitarnos. ¡Hasta luego!" << endl;
            break;
        }

        cout << "\nPor favor ingrese los siguientes datos para realizar la reserva:" << endl;

        cout << "Ingrese su nombre: ";
        cin.ignore();
        getline(cin, nombreCliente);

        cout << "Ingrese el número de personas que estarán en la habitación (incluyéndose usted): ";
        cin >> numPersonas;

        cout << "Ingrese el número de días de estancia: ";
        cin >> numDias;

        cout << "\nTipos de habitación disponibles:" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << habitaciones[i].getNombre() << " - Disponibles: " << habitaciones[i].getDisponibles() << " - Costo: $" << habitaciones[i].getCostoPorNoche() << " pesos la noche." << endl;
        }

        cout << "\nSeleccione el tipo de habitación (1 - 4): ";
        cin >> tipoHabitacion;

        if (tipoHabitacion < 1 || tipoHabitacion > 4) {
            cout << "Tipo de habitación inválido. Por favor, seleccione un tipo válido." << endl;
            continue;
        }

      
        if (habitaciones[tipoHabitacion - 1].getDisponibles() <= 0) {
            cout << "Lo sentimos, no hay habitaciones disponibles de ese tipo." << endl;
            continue;
        }

        
        float costoTotal = habitaciones[tipoHabitacion - 1].calcularCostoTotal(numPersonas, numDias, descuentoAdultoMayor, descuentoNino);
        habitaciones[tipoHabitacion - 1].reservarHabitacion();

        if (costoTotal < habitaciones[tipoHabitacion - 1].getCostoPorNoche() * numDias) {
            cout << "\n¡Felicitaciones! Se aplicaron descuentos en su reserva." << endl;
            cout << "El costo total de la reserva con descuento sería de $" << costoTotal << "." << endl;
        } else {
            cout << "\nEl costo total de la reserva sería de $" << costoTotal << " sin descuentos aplicados." << endl;
        }

        
        historial[reservacionesRealizadas] = RegistroReserva(nombreCliente, habitaciones[tipoHabitacion - 1].getNombre(), numPersonas, numDias, numDias); // Almacenar solo el número de días de estancia estimado
        ++reservacionesRealizadas;

        
        mostrarCalendario(habitaciones, 4);

        cout << "\n¿Desea hacer otra reserva? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "\n--- Historial de Reservas del Día ---" << endl;
    for (int i = 0; i < reservacionesRealizadas; ++i) {
        cout << "Reserva " << i + 1 << ":" << endl;
        cout << "Cliente: " << historial[i].nombreCliente << endl;
        cout << "Habitación: " << historial[i].tipoHabitacion << endl;
        cout << "Número de personas: " << historial[i].numPersonas << endl;
        cout << "Número de días: " << historial[i].numDias << endl;
        cout << "Fecha de salida estimada: " << historial[i].fechaSalidaEstimada << " días desde hoy." << endl;
        cout << "-------------------------------" << endl;
    }

    cout << "Gracias por visitarnos. ¡Hasta luego!" << endl;

    return 0;
}
