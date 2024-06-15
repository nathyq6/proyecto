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

    float calcularCostoTotal(int numAdultos, int numNinos, int numDias, float descuentoAdultoMayor, float descuentoNino) const {
        float costoTotal = costoPorNoche * numDias;
        float descuento = 0.0;

        if (numAdultos > 60) {
            descuento += descuentoAdultoMayor * numAdultos;
        }

        if (numNinos < 10) {
            descuento += descuentoNino * numNinos;
        }

        costoTotal -= descuento;
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

    cout << "Bienvenido al Hotel Paralish" << endl;
    cout << "¿Desea hacer una reserva? (s/n): ";
    char opcion;
    cin >> opcion;

    if (opcion != 's' && opcion != 'S') {
        cout << "Gracias por visitarnos. Hasta luego." << endl;
        return 0;
    }

    string nombreCliente;
    int edadCliente;
    int numAdultos;
    int numNinos;
    int numDias;
    int tipoHabitacion;

    cout << "\nPor favor ingrese los siguientes datos para realizar la reserva:" << endl;

    cout << "Ingrese su nombre: ";
    cin.ignore();
    getline(cin, nombreCliente);

    cout << "Ingrese su edad: ";
    cin >> edadCliente;

    if (edadCliente > 60) {
        cout << "¡Felicitaciones! Usted tiene un descuento del 30% por ser mayor de 60 años." << endl;
    } else if (edadCliente < 10) {
        cout << "¡Felicitaciones! Usted tiene un descuento del 15% por ser menor de 10 años." << endl;
    }

    cout << "Ingrese el número de adultos que se hospedarán: ";
    cin >> numAdultos;

    cout << "Ingrese el número de niños que se hospedarán (menores de 10 años): ";
    cin >> numNinos;

    cout << "Ingrese el número de días de estancia: ";
    cin >> numDias;

    cout << "\nTipos de habitación disponibles:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << habitaciones[i].getNombre() << endl;
    }

    cout << "\nSeleccione el tipo de habitación (1 - 4): ";
    cin >> tipoHabitacion;

    if (tipoHabitacion < 1 || tipoHabitacion > 4) {
        cout << "Tipo de habitación inválido. Por favor, seleccione un tipo válido." << endl;
        return 0;
    }

    float descuentoAdultoMayor = (edadCliente > 60) ? 0.3 : 0.0;
    float descuentoNino = (edadCliente < 10) ? 0.15 : 0.0;

    float costoTotal = habitaciones[tipoHabitacion - 1].calcularCostoTotal(numAdultos, numNinos, numDias, descuentoAdultoMayor, descuentoNino);

    cout << "\nEl costo total de la reserva sería de $" << costoTotal << " con el descuento aplicado." << endl;

    return 0;
}
