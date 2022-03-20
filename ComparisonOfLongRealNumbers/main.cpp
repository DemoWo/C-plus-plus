#include <iostream>

std::string number_check (std::string number){
    bool ok;
    int count = 0;

    for (int d = 0; d < number.length(); d++){
        if (number[d] == '.') {
            count++;
        }
    }
    if (count > 1) {
        ok = false;
    }
    for (int i = 0; i < number.length(); i++) {
        if ((number[i] >= '0' && number[i] <= '9') || number[i] == '.' || number[i] == '-') {
            ok = true;
        } else ok = false;
    }

    if (!ok){
       //std::cout << "No.\n";
        return number = "Error";
    }
    else {
       //std::cout << "Yes.\n" << number;
       return number;
    }
}

int main() {
    std::string number;
    std::cout << "Input number: " << std::endl;
    std::getline(std::cin, number);

    int middle;
    std::string left, right;

    for (int i = 0; i < number.length(); i++){
        if (number[i] == ' ') {
            middle = i;
        }
    }
    for (int k = 0; k < middle; k++) {
        left += number[k];
    }
    //std::cout << left  << std::endl;
    std::string leftNum = number_check(left);

    for (int k = middle + 1; k < number.length(); k++){
        right += number[k];
    }

    std::string rightNum = number_check(right);

    if (leftNum == "Error" || rightNum == "Error") std::cout << "Error input number" << std::endl;
    else if (leftNum > rightNum) std::cout << "More" << std::endl;
    else if (leftNum < rightNum) std::cout << "Less" << std::endl;
    else if (leftNum == rightNum) std::cout << "Equal" << std::endl;
}