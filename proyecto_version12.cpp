#include <iostream>
#include <string>

using namespace std;

class Habitacion {
private:
    string nombre;
    int capacidadMaxima;
    float costoPorNoche;

public:
    Habitacion(string n, int cap, float costo) : nombre(n), capacidadMaxima(cap), costoPorNoche(costo) {}

    string getNombre() const { return nombre; }
    int getCapacidadMaxima() const { return capacidadMaxima; }
    float getCostoPorNoche() const { return costoPorNoche; }

    float calcularCostoTotal(int numPersonas, int numDias, float descuentoAdultoMayor, float descuentoNino) const {
        float costoTotal = costoPorNoche * numDias;
        float descuentoTotal = 0.0;

        // Aplicar descuentos según la edad de cada persona
        for (int i = 0; i < numPersonas; ++i) {
            int edadPersona;
            cout << "Ingrese la edad de la persona " << i + 1 << ": ";
            cin >> edadPersona;

            if (edadPersona > 65) {
                descuentoTotal += descuentoAdultoMayor * costoPorNoche * numDias;
            } else if (edadPersona < 8) {
                descuentoTotal += descuentoNino * costoPorNoche * numDias;
            }
        }

        costoTotal -= descuentoTotal;
        return costoTotal;
    }
};

struct RegistroReserva {
    string nombreCliente;
    string tipoHabitacion;
    int numPersonas;
    int numDias;
    float costoTotal;
};

int main() {
    Habitacion habitaciones[4] = {
        {"Habitación Normal", 3, 3000},
        {"Suite", 6, 8000},
        {"Habitación Imperial", 10, 12000},
        {"Villa", 15, 20000}
    };

    const float descuentoAdultoMayor = 0.3;  // 30%
    const float descuentoNino = 0.2;         // 20%

    RegistroReserva historial[10]; // Arreglo estático para almacenar hasta 10 reservas
    float gananciasDelDia = 0.0;
    int reservacionesRealizadas = 0;

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
            cout << i + 1 << ". " << habitaciones[i].getNombre() << " - Máximo " << habitaciones[i].getCapacidadMaxima() << " personas - Costo: $" << habitaciones[i].getCostoPorNoche() << " pesos la noche." << endl;
        }

        cout << "\nSeleccione el tipo de habitación (1 - 4): ";
        cin >> tipoHabitacion;

        if (tipoHabitacion < 1 || tipoHabitacion > 4) {
            cout << "Tipo de habitación inválido. Por favor, seleccione un tipo válido." << endl;
            continue;
        }

        float costoTotal = habitaciones[tipoHabitacion - 1].calcularCostoTotal(numPersonas, numDias, descuentoAdultoMayor, descuentoNino);

        // Mostrar información sobre descuentos aplicados
        if (costoTotal < habitaciones[tipoHabitacion - 1].getCostoPorNoche() * numDias) {
            cout << "\n¡Felicitaciones! Se aplicaron descuentos en su reserva." << endl;
            cout << "El costo total de la reserva con descuento sería de $" << costoTotal << "." << endl;
        } else {
            cout << "\nEl costo total de la reserva sería de $" << costoTotal << " sin descuentos aplicados." << endl;
        }

        // Registrar reserva en historial
        historial[reservacionesRealizadas] = {nombreCliente, habitaciones[tipoHabitacion - 1].getNombre(), numPersonas, numDias, costoTotal};

        gananciasDelDia += costoTotal;
        ++reservacionesRealizadas;

        cout << "\n¿Desea hacer otra reserva? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    // Mostrar historial de reservas
    cout << "\n--- Historial de Reservas del Día ---" << endl;
    for (int i = 0; i < reservacionesRealizadas; ++i) {
        cout << "Reserva " << i + 1 << ":" << endl;
        cout << "Cliente: " << historial[i].nombreCliente << endl;
        cout << "Habitación: " << historial[i].tipoHabitacion << endl;
        cout << "Número de personas: " << historial[i].numPersonas << endl;
        cout << "Número de días: " << historial[i].numDias << endl;
        cout << "Costo total: $" << historial[i].costoTotal << endl;
        cout << "-------------------------------" << endl;
    }

    cout << "\nReservaciones realizadas hoy: " << reservacionesRealizadas << endl;
    cout << "Ganancias totales del día: $" << gananciasDelDia << endl;
    cout << "Gracias por visitarnos. ¡Hasta luego!" << endl;

    return 0;
}
