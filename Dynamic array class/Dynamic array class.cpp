// Dynamic array class.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

class DynamicArray {
private:
    int size;       // Número de elementos actualmente en el array
    int capacity;   // Capacidad máxima actual del array
    string* array;  // Puntero al array dinámico

public:
    // Constructor
    DynamicArray(int initialCapacity = 10) {
        size = 0; // Inicializamos el tamaño actual como 0
        capacity = initialCapacity; // Capacidad inicial
        array = new string[capacity]; // Creamos el array dinámico
    }

    // Destructor
    ~DynamicArray() {
        delete[] array; // Liberamos la memoria del array dinámico
    }

    // Método para insertar un elemento en una posición específica
    bool insert(string newElement, int position) {
        // Validamos que la posición esté en un rango válido
        if (position < 0 || position > size) {
            return false; // Retornamos false si la posición es inválida
        }

        // Si el array está lleno, necesitamos redimensionarlo
        if (size == capacity) {
            resize();
        }

        // Movemos los elementos hacia la derecha para hacer espacio
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }

        // Insertamos el nuevo elemento en la posición dada
        array[position] = newElement;
        size++; // Incrementamos el tamaño del array

        return true; // Operación exitosa
    }

    // Método para eliminar un elemento de una posición específica
    bool remove(int position) {
        // Validamos que la posición esté en un rango válido
        if (position < 0 || position >= size) {
            return false; // Retornamos false si la posición es inválida
        }

        // Movemos los elementos hacia la izquierda para cubrir el hueco
        for (int i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--; // Decrementamos el tamaño del array

        return true; // Operación exitosa
    }

    // Método para imprimir el contenido del array
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

private:
    // Método para redimensionar el array dinámico
    void resize() {
        // Duplicamos la capacidad
        capacity *= 2;

        // Creamos un nuevo array con la nueva capacidad
        string* newArray = new string[capacity];

        // Copiamos los elementos del array antiguo al nuevo
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }

        // Liberamos la memoria del array antiguo
        delete[] array;

        // Apuntamos al nuevo array
        array = newArray;
    }
};

// Programa principal
int main() {
    DynamicArray dynamicArray;

    // Insertamos elementos en el array
    dynamicArray.insert("A", 0);
    dynamicArray.insert("B", 1);
    dynamicArray.insert("C", 2);
    dynamicArray.insert("D", 3);

    cout << "Array despues de las inserciones: ";
    dynamicArray.print();

    // Eliminamos un elemento
    dynamicArray.remove(0);
    cout << "Array despues de eliminar el elemento en la posicion 1: ";
    dynamicArray.print();

    // Insertamos un nuevo elemento en la posición 1
    dynamicArray.insert("E", 0);
    cout << "Array despues de insertar 'E' en la posicion 1: ";
    dynamicArray.print();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
