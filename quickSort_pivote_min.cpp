#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int> &array, int min, int max){
    int pivot = array[min]; //Se elige como pivote el primer elemento del arreglo
    int i = min + 1;
    for(int j = i; j <=max; j++){
        if(array[j] < pivot){
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[min], array[i-1]);
    return i-1;

}
void quickSort(vector <int> &vec, int min, int max){
   if(min < max){
    int pivot = partition(vec, min, max);
    //Ordenar los elementos antes y después de la partición
    quickSort(vec, min, pivot-1);
    quickSort(vec, pivot+1, max);
   }

};

int main(){
    vector <int> vector = {15, 18, 11, 23, 6, 9, 10};
    quickSort(vector, 0, vector.size()-1);
    cout << "Arreglo ordenado: ";
    for(int s = 0; s < vector.size(); s++){
        cout << vector[s] << ", ";
    }

}