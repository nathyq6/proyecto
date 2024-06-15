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

            if (edadPersona > 60) {
                descuentoTotal += descuentoAdultoMayor * costoPorNoche * numDias;
            } else if (edadPersona < 10) {
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

    const float descuentoAdultoMayor = 0.4;  // 40%
    const float descuentoNino = 0.35;        // 35%

    cout << "Bienvenido al Hotel Paralish" << endl;

    char opcion;
    do {
        string nombreCliente;
        int numPersonas;
        int numDias;
        int tipoHabitacion;

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
            return 0;
        }

        float costoTotal = habitaciones[tipoHabitacion - 1].calcularCostoTotal(numPersonas, numDias, descuentoAdultoMayor, descuentoNino);

        if (costoTotal < habitaciones[tipoHabitacion - 1].getCostoPorNoche() * numDias) {
            cout << "\n¡Felicitaciones! Se aplicaron descuentos en su reserva." << endl;
            cout << "El costo total de la reserva con descuento sería de $" << costoTotal << "." << endl;
        } else {
            cout << "\nEl costo total de la reserva sería de $" << costoTotal << " sin descuentos aplicados." << endl;
        }

        cout << "\n¿Desea hacer otra reserva? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "Gracias por visitarnos. ¡Hasta luego!" << endl;

    return 0;
}
