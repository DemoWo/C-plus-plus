#include <iostream>

int main() {
  int numbers[15] = {114,111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
  int sequence;
  int sum = 0;

    sequence = ((numbers[5] + numbers[14]) * 14) / 2;

    for (int i = 0; i < 15; ++i){
      sum += numbers[i];
    }

    int duplicate = sum - sequence;
    std::cout << "Duplicate: " << duplicate << std::endl;
    return 0;
}