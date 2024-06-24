#include <iostream>
#include <string>

using namespace std;
struct Empleado {
    string nombre;
    int edad;
    float salario;
    bool empleadoValido; // Para controlar si el empleado está inicializado o no
};

Empleado crearEmpleado() {
    Empleado nuevoEmpleado;
    cout << "Ingrese el nombre del empleado: ";
    cin >> nuevoEmpleado.nombre;
    cout << "Ingrese la edad del empleado: ";
    cin >> nuevoEmpleado.edad;
    cout << "Ingrese el salario del empleado: ";
    cin >> nuevoEmpleado.salario;
    nuevoEmpleado.empleadoValido = true; // Marcar como válido
    return nuevoEmpleado;
}


void mostrarEmpleado(const Empleado& empleado) {
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Edad: " << empleado.edad << endl;
    cout << "Salario: $" << empleado.salario << endl;
    cout << "--------------------------" << endl;
}

void actualizarEmpleado(Empleado& empleado) {
    cout << "Ingrese la nueva edad del empleado: ";
    cin >> empleado.edad;
    cout << "Ingrese el nuevo salario del empleado: ";
    cin >> empleado.salario;
    cout << "Empleado actualizado correctamente." << endl;
}

void eliminarEmpleado(Empleado& empleado) {
    empleado.empleadoValido = false; 
    cout << "Empleado eliminado correctamente." << endl;
}

int main() {
    Empleado empleado;
    empleado.empleadoValido = false; 
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Agregar empleado" << endl;
        cout << "2. Mostrar empleado" << endl;
        cout << "3. Actualizar empleado" << endl;
        cout << "4. Eliminar empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                empleado = crearEmpleado();
                cout << "Empleado agregado correctamente." << endl;
                break;
            case 2:
                if (empleado.empleadoValido) {
                    mostrarEmpleado(empleado);
                } else {
                    cout << "No hay empleado para mostrar." << endl;
                }
                break;
            case 3:
                if (empleado.empleadoValido) {
                    actualizarEmpleado(empleado);
                } else {
                    cout << "No hay empleado para actualizar." << endl;
                }
                break;
            case 4:
                if (empleado.empleadoValido) {
                    eliminarEmpleado(empleado);
                } else {
                    cout << "No hay empleado para eliminar." << endl;
                }
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                return 0;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
