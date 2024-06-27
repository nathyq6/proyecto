#include <iostream>
#include <conio.h> 


using namespace std;

void menu() {
    cout << "Seleccione la figura geometrica para calcular el area:\n";
    cout << "1. Cuadrado\n";
    cout << "2. Rectangulo\n";
    cout << "3. Triangulo\n";
    cout << "4. Salir\n";
}

void areaCuadrado() {
    float lado;
    cout << "Ingrese la longitud del lado del cuadrado: ";
    cin >> lado;
    cout << "El area del cuadrado es: " << lado * lado << endl;
}

void areaRectangulo() {
    float largo, ancho;
    cout << "Ingrese la longitud del largo del rectangulo: ";
    cin >> largo;
    cout << "Ingrese la longitud del ancho del rectangulo: ";
    cin >> ancho;
    cout << "El area del rectangulo es: " << largo * ancho << endl;
}

void areaTriangulo() {
    float base, altura;
    cout << "Ingrese la longitud de la base del triangulo: ";
    cin >> base;
    cout << "Ingrese la longitud de la altura del triangulo: ";
    cin >> altura;
    cout << "El area del triangulo es: " << (base * altura) / 2 << endl;
}

int main() {
    int opcion;
    do {
        system("cls"); 
        menu();
        opcion = getch() - '0'; 
        system("cls"); 
        switch(opcion) {
            case 1:
                areaCuadrado();
                break;
            case 2:
                areaRectangulo();
                break;
            case 3:
                areaTriangulo();
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
        if(opcion != 4) {
            cout << "Presione cualquier tecla para continuar...\n";
            getch(); 
        }
    } while(opcion != 4);

    return 0;
}
