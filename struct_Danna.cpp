#include <iostream>
using namespace std;

// Definición de la estructura
struct Rectangulo {
    float longitud;
    float ancho;
};

// Función para calcular el área de un rectángulo
float calcularArea(Rectangulo rect) {
    return rect.longitud * rect.ancho;
}

int main() {
    // Declaración e inicialización de una variable tipo Rectangulo
    Rectangulo rectangulo1 = {5.0, 3.0};

    // Cálculo del área del rectángulo
    float area = calcularArea(rectangulo1);

    // Impresión del área del rectángulo
    cout << "El área del rectángulo es: " << area << " unidades cuadradas" << endl;

    return 0;
}
