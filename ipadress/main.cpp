#include <iostream>

bool first_ip (bool one, std:: string first){
    one = false;
    int number;
    for (int i = 0; i < first.length(); i++){
        if (first[0] == '0' && (first[1] >= '0' && first[1] <= '9')) one = false;
        else if (first[0] != '0' && first.length() <= 3 && (first[i] >= '0' && first[i] <= '9')){
            number = std::stoi(first);
            if (number > 255){
                one = false;
            } else one = true;
        } else one = false;
    }
    if (!one) {
        //std:: cout << "No" << std::endl;
        return one = false;
    } else {
        //std:: cout << "Yes" << std::endl;
        return one = true;
    }
}

bool second_ip (bool two, std:: string second){
    two = false;
    int number;
    for (int i = 0; i < second.length(); i++){
        if (second[0] == '0' && (second[1] >= '0' && second[1] <= '9')) two = false;
        else if (second.length() <= 3 && (second[i] >= '0' && second[i] <= '9')){
            number = std::stoi(second);
            if (number > 255){
                two = false;
            } else two = true;
        } else two = false;
    }

    if (!two) {
        //std:: cout << "No" << std::endl;
        return two = false;
    } else {
        //std:: cout << "Yes" << std::endl;
        return two = true;
    }
}

bool third_ip (bool three, std:: string third){
    three = false;
    int number;
    for (int i = 0; i < third.length(); i++){
        if (third[0] == '0' && (third[1] >= '0' && third[1] <= '9')) three = false;
        else if (third.length() <= 3 && (third[i] >= '0' && third[i] <= '9')){
            number = std::stoi(third);
            if (number > 255){
                three = false;
            } else three = true;
        } else three = false;

    }

    if (!three) {
        //std:: cout << "No" << std::endl;
        return three = false;
    } else {
        //std:: cout << "Yes" << std::endl;
        return three = true;
    }
}

bool fourth_ip (bool four, std:: string fourth){
    four = false;
    int number;
    for (int i = 0; i < fourth.length(); i++){
        if (fourth[0] == '0' && (fourth[1] >= '0' && fourth[1] <= '9')) four = false;
        else if (fourth.length() <= 3 && (fourth[i] >= '0' && fourth[i] <= '9')){
            number = std::stoi(fourth);
            if (number > 255){
                four = false;
            } else four = true;
        } else four = false;

    }

    if (!four) {
        //std:: cout << "No" << std::endl;
        return four = false;
    } else {
        //std:: cout << "Yes" << std::endl;
        return four = true;
    }
}

std::string ip_check (std::string ip_adress){
    bool ip;
    int dot_position1;
    int dot_position2;
    int dot_position3;
    std::string first, second, third, fourth;

    for (int i = 0; i < ip_adress.length(); i++){
        if (ip_adress[i] == '.') {
            dot_position1 = i;
            break;
        }
        first += ip_adress[i];
    }

    for (int h = dot_position1 + 1; h < ip_adress.length(); h++ ){
        if (ip_adress[h] == '.') {
            dot_position2 = h;
            break;
        }
        second += ip_adress[h];
    }

    for (int k = dot_position2 + 1; k < ip_adress.length(); k++ ){
        if (ip_adress[k] == '.') {
            dot_position3 = k;
            break;
        }
        third += ip_adress[k];
    }

    for (int j = dot_position3 + 1; j < ip_adress.length(); j++ ){
        fourth += ip_adress[j];
    }

    bool one, two, three, four;
    bool ipFirst = first_ip(one, first);
    bool ipSecond = second_ip(two, second);
    bool ipThird = third_ip(three, third);
    bool ipFourth = fourth_ip(four, fourth);


    if (ipFirst == false || ipSecond == false || ipThird == false || ipFourth == false ) {
        std:: cout << "No" << std::endl;
    } else {
        std:: cout << "Yes" << std::endl;
    }
    return ip_adress;

}

int main() {
    std::string ipAdress;
    std::cout << "Input IP adress: \n";
    std::getline(std::cin, ipAdress);

    ipAdress = ip_check(ipAdress);
}