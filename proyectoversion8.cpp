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

        if (numDias >= 60) {
            descuento += descuentoAdultoMayor * numAdultos;
        }

        if (numDias < 10) {
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

    string nombreCliente;
    int numAdultos;
    int numNinos;
    int numDias;
    int tipoHabitacion; 

    const int numDiasSemana = 7;
    float gananciasTotales = 0.0;

    cout << "Tipos de habitación disponibles:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << habitaciones[i].getNombre() << endl;
    }
    cout << endl;

    for (int dia = 0; dia < numDiasSemana; ++dia) {
        cout << "\nReservas para el día " << dia + 1 << endl;
        for (int reserva = 1; reserva <= 4; ++reserva) {
          
            cout << "\nIngrese los datos de la reserva " << reserva << " del día " << dia + 1 << endl;

            cout << "Seleccione el tipo de habitación (1 - 4): ";
            cin >> tipoHabitacion;
            cin.ignore(); 

            if (tipoHabitacion < 1 || tipoHabitacion > 4) {
                cout << "Tipo de habitación inválido. Por favor, seleccione un tipo válido." << endl;
                continue; 
            }

            cout << "Ingrese su nombre: ";
            getline(cin, nombreCliente);
            cout << "Ingrese el número de adultos que se hospedarán: ";
            cin >> numAdultos;
            cout << "Ingrese el número de niños que se hospedarán (menores de 10 años): ";
            cin >> numNinos;
            cout << "Ingrese el número de días de estancia: ";
            cin >> numDias;

            float costoTotal = habitaciones[tipoHabitacion - 1].calcularCostoTotal(numAdultos, numNinos, numDias, 0.4, 0.35);
            cout << "Costo total de la reserva: $" << costoTotal << endl;
            
            gananciasTotales += costoTotal;

            cin.ignore(); 
        }
    }

    cout << "\nGanancias totales de la semana: $" << gananciasTotales << endl;

    return 0;
}
