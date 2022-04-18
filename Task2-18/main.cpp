#include <iostream>

int step(int& stp){
    return stp;
}

int main() {
    int n;
    std::cout << "Enter the step number: " << std::endl;
    std::cin >> n;

    step(n);

    std::cout << n << std::endl;
    return 0;
}
