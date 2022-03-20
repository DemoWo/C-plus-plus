#include <iostream>
#include <cmath>

int main(){
    float a, b, c;
    std::cout << "a, b, c:";
    std::cin >> a >> b >> c;
    if (a < 0){
        std::cout << "Not a quadratic equation!" << std::endl;
    }
    if (b > 0){
        float discriminant = (b * 2) - (4 * a * c);
        if (discriminant == 0){
            float x1 = (-b + std::sqrt(discriminant)) / (2  * a);
            float x2 = (-b + std::sqrt(discriminant)) / (2 * a);
            std::cout << "Root 1, 2: " << x1 << ", " << x2 << std::endl;
        }else if (discriminant > 1){
            float x = b + std::sqrt(discriminant * discriminant) / (2 * a);
            std::cout << "Root: " << x << std::endl;
        }else{
            std::cout << "Complex scenario is not supported!" << std::endl;
        }
    }
    return 0;
}