#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& array, int min, int max) {
    int mid = min + (max - min) / 2;  // Encontrar el índice del elemento de en medio
    swap(array[mid], array[max]);     // Mover el pivote (elemento del medio) al final
    int pivot = array[max];           // Ahora el pivote es el último elemento
    int i = min - 1;                  // Índice del elemento más pequeño

    for (int j = min; j < max; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);  // Intercambiar si el elemento es menor al pivote
        }
    }
    swap(array[i + 1], array[max]);    // Colocar el pivote en su lugar correcto
    return i + 1;                      // Retornar la posición del pivote
}

void quickSort(vector<int>& vec, int min, int max) {
    if (min < max) {
        int pivot = partition(vec, min, max);  // Obtener el índice del pivote
        // Ordenar los elementos antes y después de la partición
        quickSort(vec, min, pivot - 1);
        quickSort(vec, pivot + 1, max);
    }
}

int main() {
    vector<int> vec = {15, 18, 11, 23, 6, 9, 10};
    quickSort(vec, 0, vec.size() - 1);
    
    cout << "Arreglo ordenado: ";
    for (int s = 0; s < vec.size(); s++) {
        cout << vec[s] << ", ";
    }
    cout << endl;

    return 0;
}
