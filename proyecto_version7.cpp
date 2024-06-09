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

    
    const int numDiasSemana = 7;
    const int numHabitaciones = 4;
    float gananciasTotales = 0.0;

   
    for (int dia = 0; dia < numDiasSemana; ++dia) {
        cout << "\nReservas para el día " << dia + 1 << endl;
        for (int habitacion = 0; habitacion < numHabitaciones; ++habitacion) {
          
            cout << "\nIngrese los datos de la reserva para la habitación " << habitaciones[habitacion].getNombre() << " del día " << dia + 1 << endl;
            cout << "Ingrese su nombre: ";
            getline(cin, nombreCliente);
            cout << "Ingrese el número de adultos que se hospedarán: ";
            cin >> numAdultos;
            cout << "Ingrese el número de niños que se hospedarán (menores de 10 años): ";
            cin >> numNinos;
            cout << "Ingrese el número de días de estancia: ";
            cin >> numDias;

            
            float costoTotal = habitaciones[habitacion].calcularCostoTotal(numAdultos, numNinos, numDias, 0.4, 0.35);
            cout << "Costo total de la reserva: $" << costoTotal << endl;
            
        
            gananciasTotales += costoTotal;

          
            cin.ignore();
        }
    }

 
    cout << "\nGanancias totales de la semana: $" << gananciasTotales << endl;

    return 0;
}
