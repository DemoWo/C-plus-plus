#include <iostream>
#include <vector>

int sort (int arr[6]){
    for (int k = 0; k < 6; k++)
        for (int j = k + 1; j < 6; j++)
            if (arr[k] > arr[j])
                std::swap(arr[j], arr[k]);
    return arr[6];
}

int main() {
    int arr[6];
    int num;

    std::cout << "Input numbers: " << std::endl;

    for (int i = 0; i < 5; i++){
        std::cin >> arr[i];
    }
    sort(arr);

    while (num != -2){
        std::cin >> num;
        if (num == -1){
            std::cout << "The fifth number in the array: " << arr[4] << std::endl;
        }
        if (num <= arr[4] && num != -1 && num != -2){
            arr[5] = num;
            sort(arr);
        }
    }

    std::cout << "The program is frozen!" << std::endl;
    return 0;
}