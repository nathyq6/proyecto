#include <iostream>
#include <string>

using namespace std;


struct Persona {
    string nombre;
    int edad;
    string direccion;
};


void crearPersona(Persona personas[], int &cantidadPersonas) {
    if (cantidadPersonas < 100) { 
        Persona nuevaPersona;
        cout << "Ingrese el nombre: ";
        cin >> nuevaPersona.nombre;
        cout << "Ingrese la edad: ";
        cin >> nuevaPersona.edad;
        cout << "Ingrese la dirección: ";
        cin.ignore(); 
        getline(cin, nuevaPersona.direccion);

        personas[cantidadPersonas] = nuevaPersona;
        cantidadPersonas++;

        cout << "Persona agregada correctamente." << endl;
    } else {
        cout << "No se pueden agregar más personas. Arreglo lleno." << endl;
    }
}


void mostrarPersonas(const Persona personas[], int cantidadPersonas) {
    if (cantidadPersonas > 0) {
        cout << "Listado de personas:" << endl;
        for (int i = 0; i < cantidadPersonas; ++i) {
            cout << "Persona " << i + 1 << ":" << endl;
            cout << "Nombre: " << personas[i].nombre << endl;
            cout << "Edad: " << personas[i].edad << endl;
            cout << "Dirección: " << personas[i].direccion << endl;
            cout << endl;
        }
    } else {
        cout << "No hay personas registradas." << endl;
    }
}


void actualizarPersona(Persona personas[], int cantidadPersonas) {
    if (cantidadPersonas > 0) {
        int indice;
        cout << "Ingrese el índice de la persona a actualizar (1-" << cantidadPersonas << "): ";
        cin >> indice;
        if (indice > 0 && indice <= cantidadPersonas) {
            cout << "Ingrese el nuevo nombre: ";
            cin >> personas[indice - 1].nombre;
            cout << "Ingrese la nueva edad: ";
            cin >> personas[indice - 1].edad;
            cout << "Ingrese la nueva dirección: ";
            cin.ignore(); 
            getline(cin, personas[indice - 1].direccion);

            cout << "Persona actualizada correctamente." << endl;
        } else {
            cout << "Índice fuera de rango." << endl;
        }
    } else {
        cout << "No hay personas registradas." << endl;
    }
}


void eliminarPersona(Persona personas[], int &cantidadPersonas) {
    if (cantidadPersonas > 0) {
        int indice;
        cout << "Ingrese el índice de la persona a eliminar (1-" << cantidadPersonas << "): ";
        cin >> indice;
        if (indice > 0 && indice <= cantidadPersonas) {
           
            for (int i = indice - 1; i < cantidadPersonas - 1; ++i) {
                personas[i] = personas[i + 1];
            }
            cantidadPersonas--;

            cout << "Persona eliminada correctamente." << endl;
        } else {
            cout << "Índice fuera de rango." << endl;
        }
    } else {
        cout << "No hay personas registradas." << endl;
    }
}

int main() {
    Persona personas[100]; 
    int cantidadPersonas = 0; 

    int opcion;

    do {
    
        cout << "\n----- Menu -----" << endl;
        cout << "1. Agregar persona" << endl;
        cout << "2. Mostrar personas" << endl;
        cout << "3. Actualizar persona" << endl;
        cout << "4. Eliminar persona" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearPersona(personas, cantidadPersonas);
                break;
            case 2:
                mostrarPersonas(personas, cantidadPersonas);
                break;
            case 3:
                actualizarPersona(personas, cantidadPersonas);
                break;
            case 4:
                eliminarPersona(personas, cantidadPersonas);
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
