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
    int numAdultos;
    int numNinos;
    int numDias;
public:
    Reserva(string nombre, const Habitacion& hab, int adultos, int ninos, int dias) : nombreCliente(nombre), habitacion(hab), numAdultos(adultos), numNinos(ninos), numDias(dias) {}

    float calcularCostoTotal(float descuentoAdultoMayor, float descuentoNino) const {
        float costoTotal = habitacion.getCostoPorNoche() * numDias;
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

  
    void imprimirReserva() const {
        cout << "Nombre del cliente: " << nombreCliente << endl;
        cout << "Tipo de habitacion: " << habitacion.getNombre() << endl;
        cout << "Capacidad máxima: " << habitacion.getCapacidadMaxima() << " personas" << endl;
        cout << "Costo por noche: $" << habitacion.getCostoPorNoche() << endl;
        cout << "Número de adultos: " << numAdultos << endl;
        cout << "Número de niños: " << numNinos << endl;
        cout << "Número de días: " << numDias << endl;
        cout << "Descuento aplicado: $" << calcularDescuento(0.4, 0.35) << endl;
        cout << "Costo total de la reserva: $" << calcularCostoTotal(0.4, 0.35) << endl;
    }

   
    float calcularDescuento(float descuentoAdultoMayor, float descuentoNino) const {
        float descuentoTotal = 0.0;

       
        if (numDias >= 60) {
            descuentoTotal += descuentoAdultoMayor * numAdultos * habitacion.getCostoPorNoche();
        }

      
        if (numDias < 10) {
            descuentoTotal += descuentoNino * numNinos * habitacion.getCostoPorNoche();
        }

        return descuentoTotal;
    }
};

int main() {
   
    Habitacion normal("Habitación Normal", 3, 3000);
    Habitacion suite("Suite", 6, 8000);
    Habitacion imperial("Habitación Imperial", 10, 12000);
    Habitacion villa("Villa", 15, 20000);

    
    string nombreCliente;
    int tipoHabitacion;
    int numAdultos;
    int numNinos;
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
    getchar(); 

    cout << "Ingrese el número de adultos que se hospedarán: ";
    cin >> numAdultos;
    getchar();

    cout << "Ingrese el número de niños que se hospedarán (menores de 10 años): ";
    cin >> numNinos;
    getchar(); 

    cout << "Ingrese el número de días de estancia: ";
    cin >> numDias;
    getchar(); 

  
    if (tipoHabitacion < 1 || tipoHabitacion > 4 || numAdultos <= 0 || numNinos < 0 || numDias <= 0) {
        cout << "Datos de reserva no válidos. Saliendo del programa..." << endl;
        return 1;
    }

  
    const Habitacion& habitacionSeleccionada = (tipoHabitacion == 1) ? normal : (tipoHabitacion == 2) ? suite : (tipoHabitacion == 3) ? imperial : villa;

   
    int numPersonas = numAdultos + numNinos;
    if (numPersonas > habitacionSeleccionada.getCapacidadMaxima()) {
        cout << "El número total de personas excede la capacidad máxima de la habitación. Saliendo del programa..." << endl;
        return 1;
    }

    
    Reserva reserva(nombreCliente, habitacionSeleccionada, numAdultos, numNinos, numDias);

  
    cout << "\nInformación de la reserva:" << endl;
    reserva.imprimirReserva();

    return 0;
}
