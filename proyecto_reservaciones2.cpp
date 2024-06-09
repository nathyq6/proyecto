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
    int numPersonas;
    int numDias;
public:
    Reserva(string nombre, const Habitacion& hab, int personas, int dias) : nombreCliente(nombre), habitacion(hab), numPersonas(personas), numDias(dias) {}


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
        cout << "Número de personas: " << numPersonas << endl;
        cout << "Número de días: " << numDias << endl;
        cout << "Costo total de la reserva: $" << calcularCostoTotal(0.4, 0.35) << endl;
    }
};

int main() {
 
    Habitacion normal("Habitación Normal", 3, 3000);
    Habitacion suite("Suite", 6, 8000);
    Habitacion imperial("Habitación Imperial", 10, 12000);
    Habitacion villa("Villa", 15, 20000);

   
    string nombreCliente;
    int tipoHabitacion;
    int numPersonas;
    int numDias;

  
    cout << "Bienvenido al sistema de reservas del Hotel Parálisis" << endl;
    cout << "Ingrese su nombre: ";
    getline(cin, nombreCliente);

    cout << "Seleccione el tipo de habitación:" << endl;
    cout << "1. Habitación Normal" << endl;
    cout << "2. Suite" << endl;
    cout << "3. Habitación Imperial" << endl;
    cout << "4. Villa" << endl;
    cout << "Opción: ";
    cin >> tipoHabitacion;
    getchar(); // Limpiar el búfer del teclado

    cout << "Ingrese el número de personas que se hospedarán: ";
    cin >> numPersonas;
    getchar(); // Limpiar el búfer del teclado

    cout << "Ingrese el número de días de estancia: ";
    cin >> numDias;
    getchar(); // Limpiar el búfer del teclado

    if (tipoHabitacion < 1 || tipoHabitacion > 4 || numPersonas <= 0) {
        cout << "Opción no válida o número de personas no válido. Saliendo del programa..." << endl;
        return 1;
    }

 
    const Habitacion& habitacionSeleccionada = (tipoHabitacion == 1) ? normal : (tipoHabitacion == 2) ? suite : (tipoHabitacion == 3) ? imperial : villa;

   
    if (numPersonas > habitacionSeleccionada.getCapacidadMaxima()) {
        cout << "El número de personas excede la capacidad máxima de la habitación. Saliendo del programa..." << endl;
        return 1;
    }

  
    Reserva reserva(nombreCliente, habitacionSeleccionada, numPersonas, numDias);

   
    cout << "\nInformación de la reserva:" << endl;
    reserva.imprimirReserva();

    return 0;
}
