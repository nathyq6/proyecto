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

int main() {
    Habitacion habitaciones[4] = {
        {"Habitación Normal", 3, 3000},
        {"Suite", 6, 8000},
        {"Habitación Imperial", 10, 12000},
        {"Villa", 15, 20000}
    };

    const float descuentoAdultoMayor = 0.3;  // 30%
    const float descuentoNino = 0.2;         // 20%

    float gananciasDelDia = 0.0;
    int reservacionesRealizadas = 0;

    cout << "Bienvenido al Hotel Paralish" << endl;

    char opcion;
    do {
        if (reservacionesRealizadas >= 10) {
            cout << "Se ha alcanzado el límite máximo de reservaciones por día." << endl;
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

        cout << "\nHabitaciones disponibles:" << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "Tipo de habitacion              Capacidad   Costo por noche" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << i + 1 << ".  ";
            cout.width(20); cout << left << habitaciones[i].getNombre();
            cout.width(12); cout << right << habitaciones[i].getCapacidadMaxima();
            cout.width(10); cout << "personas   $";
            cout.width(7); cout << fixed << habitaciones[i].getCostoPorNoche() << endl;
        }
        cout << "--------------------------------------------------------------" << endl;

        cout << "\nSelecciona el tipo de habitación (1 - 4): ";
        cin >> tipoHabitacion;

        if (tipoHabitacion < 1 || tipoHabitacion > 4) {
            cout << "Tipo de habitación inválido. Por favor, seleccione un tipo válido." << endl;
            continue;
        }

        float costoTotal = habitaciones[tipoHabitacion - 1].calcularCostoTotal(numPersonas, numDias, descuentoAdultoMayor, descuentoNino);

        if (costoTotal < habitaciones[tipoHabitacion - 1].getCostoPorNoche() * numDias) {
            cout << "\n Se aplicaron descuentos en su reserva." << endl;
            cout << "El costo total de la reserva con descuento es de $" << costoTotal << "." << endl;
        } else {
            cout << "\nEl costo total de la reserva es de $" << costoTotal << " sin descuentos aplicados." << endl;
        }

        gananciasDelDia += costoTotal;
        ++reservacionesRealizadas;

        cout << "\n--------------------------------------------------------------" << endl;
        cout << "¡Reserva realizada exitosamente!" << endl;
        cout << "--------------------------------------------------------------" << endl;

        cout << "\n¿Desea hacer otra reserva? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "\nReservaciones del día: " << reservacionesRealizadas << endl;
    cout << "Ganancias totales del día: $" << gananciasDelDia << endl;
    cout << "Gracias por visitarnos. ¡Hasta luego!" << endl;

    return 0;
}
