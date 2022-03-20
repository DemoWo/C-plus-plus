#include <iostream>
#include <string>

bool email_left (bool left, std::string text_left){
    std::string str = "!#$%&'*+-/=?^_`{|}~";
    left = true;
    bool sym;

    for (int i = 0; i < text_left.length(); i++) {
        if (text_left.length() > 0 && text_left.length() <= 64) {

            if (text_left[i] == '@'|| ((text_left[i] == '.'
                                        && text_left[i - 1] == '.') ||  text_left[0] == '.'
                                       || text_left[text_left.length() - 1] == '.')) {
                left = false;
                break;
            }
            if (text_left[i] == '.' ||(text_left[i] >= '0' && text_left[i] <= '9')
                || (text_left[i] >= 'A' && text_left[i] <= 'Z')
                || (text_left[i] >= 'a' && text_left[i] <= 'z')){
                left = true;
            } else {
                for (int k = 0; k < str.length(); k++){
                    sym = true;
                    if (str[k] == text_left[i]){
                        sym = true;
                        break;
                    } else sym = false;
                }
                left = sym;
                break;
            }
        }
    }
    if (!left) {
        //std::cout << "No" << std::endl;
        return left = false;
    }else {
        //std::cout << "Yes" << std::endl;
        return left = true;
    }
}

bool email_right (bool right, std::string text_right){
    right = false;
    std::string str = "!#$%&'*+-/=?^_`{|}~";
    int i;

    bool sym;

    for (int i = 0; i < text_right.length(); i++) {
        if (text_right.length() > 0  && text_right.length() <= 63) {

            if  ((text_right[i] == '.' && text_right[i - 1] == '.')
                 ||  text_right[0] == '.'
                 || text_right[text_right.length() - 1] == '.') {
                right = false;
                break;
            }
            if (text_right[i] == '.' ||(text_right[i] >= '0' && text_right[i] <= '9')
                || (text_right[i] >= 'A' && text_right[i] <= 'Z')
                || (text_right[i] >= 'a' && text_right[i] <= 'z')){
                right = true;
            } else {
                for (int k = 0; k < str.length(); k++){
                    sym = true;
                    if (str[k] == text_right[i]){
                        sym = false;
                        break;
                    } else sym = true;
                }
                right = sym;
                break;
            }
        }
    }
    if (!right) {
        //std::cout << "No" << std::endl;
        return right = false;
    } else {
        //std::cout << "Yes" << std::endl;
        return right = true;
    }
}

std::string email_check (std::string str){
    int middle = 0;
    char dog;
    std::string left;
    std::string right;

    for (int i = 0; i < str.length(); i++){
        if (str[i]  == '@') {
            middle = i;
            dog = str[i];
        }
    }//находим середину.

    for (int k = 0; k < middle; k++){
        left += str[k];
    } // левая часть.
    if (dog == '@'){
        for (int j = middle + 1; j < str.length(); j++){
            right += str[j];
        }
    }// правая часть.

    bool l;
    bool emailLeft = email_left(l, left);

    bool r;
    bool emailRight = email_right(r, right);

    if (emailLeft == false || emailRight == false) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
    return str;
}

int main() {
    std::string email;
    std::cout << "Input email: " << std::endl;
    std::cin >> email;

    email = email_check(email);
}