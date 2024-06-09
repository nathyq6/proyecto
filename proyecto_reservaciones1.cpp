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
};


class Reserva {
private:
    string nombreCliente;
    const Habitacion& habitacion;
    int numDias;
public:
    Reserva(string nombre, const Habitacion& hab, int dias) : nombreCliente(nombre), habitacion(hab), numDias(dias) {}

  
    float calcularCostoTotal(float descuentoAdultoMayor, float descuentoNino) const {
        float costoTotal = habitacion.getCostoPorNoche() * numDias;
      
        if (numDias >= 60) {
            costoTotal *= (1 - descuentoAdultoMayor);
        } else if (numDias < 10) {
            costoTotal *= (1 - descuentoNino);
        }
        return costoTotal;
    }

 
    void imprimirReserva() const {
        cout << "Nombre del cliente: " << nombreCliente << endl;
        cout << "Tipo de habitacion: " << habitacion.getNombre() << endl;
        cout << "Capacidad máxima: " << habitacion.getCapacidadMaxima() << " personas" << endl;
        cout << "Costo por noche: $" << habitacion.getCostoPorNoche() << endl;
        cout << "Número de días: " << numDias << endl;
        cout << "Costo total de la reserva: $" << calcularCostoTotal(0.4, 0.35) << endl;
    }
};

int main() {
  
    Habitacion normal("Habitación Normal", 3, 3000);
    Habitacion suite("Suite", 6, 8000);
    Habitacion imperial("Habitación Imperial", 10, 12000);
    Habitacion villa("Villa", 15, 20000);

   
    Reserva reserva1("Juan", suite, 5);


    cout << "Información de la reserva:" << endl;
    reserva1.imprimirReserva();

    return 0;
}
