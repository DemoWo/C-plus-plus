#include <iostream>

void heapify(float numbers[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && numbers[left] > numbers[largest])
        largest = left;

    if (right < n && numbers[right] > numbers[largest])
        largest = right;

    if (largest != i){
        std::swap(numbers[i], numbers[largest]);
        heapify(numbers, n, largest);
    }
}

void heapSort(float numbers[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(numbers, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(numbers[0], numbers[i]);
        heapify(numbers, i, 0);
    }
}

void printArray(float numbers[], int n){
    for (int i = 0; i < n; ++i)
        std::cout << numbers[i] << " ";
    std::cout << "\n";
}

int main(){
    int x = 15;
    float numbers[x] ;
    for (int i = 0; i < x; ++i){
        std::cin >> numbers[i];
    }
    int n = sizeof(numbers) / sizeof(numbers[0]);

    heapSort(numbers, n);

    std::cout << "Sorted array is " << std::endl;
    printArray(numbers, n);

    return 0;
}