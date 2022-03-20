#include <iostream>
#include <vector>

int main() {
  std::vector <int> vec(20);
  int num;
  std::cout << "Enter number in database: " << std::endl;

  int count = 0;
    std::cin >> num;
  while (num != -2) {
      if (num == -1) {
          std::cout << "Numbers from the database: " << std::endl;
          for (int i = count; i < vec.size(); ++i)
              std::cout << vec[i] << " ";
          for (int i = 0; i < count; ++i)
              std::cout << vec[i] << " ";
      }
      else {
          vec[count] = num;
          count++;
          if (count == 20)
              count = 0;
      }
      std::cin >> num;
  }
  return 0;
}