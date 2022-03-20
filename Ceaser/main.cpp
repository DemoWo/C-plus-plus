#include <iostream>
#include <string>

constexpr char N_SYMBOLS = ('z' - 'a');

std::string encrypt_caesar(std::string result, int numbers){
    //numbers %= N_SYMBOLS;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            bool is_space = result[i] == ' ';
            if (is_space) {
                result[i] = ' ';
            } else {
                if (result[i] + numbers > 'Z') {
                    result[i] = 'A' + (numbers - ('Z' - result[i]));
                }
                else if (result [i] < 'A'){
                    result[i]--;
                } else {
                    result[i] = result[i] + numbers;
                }
            }
        }
            if ((result[i] >= 'a' && result[i] <= 'z')) {
                bool is_space = result[i] == ' ';
                if (is_space) {
                    result[i] = ' ';
                } else {
                    if (result[i] + numbers > 'z') {
                        result[i] = 'a' + (numbers - ('z' - result[i]));
                    }else {
                        result[i] = result[i] + numbers;
                    }
                }
            }
    }
    //std::cout<< "Result Caesar: " << result <<"\n" << std::endl;
    return result;
}

std::string decrypt_caesar(std::string word, int reverse){

    return encrypt_caesar(word, -reverse);
}

int main() {
    std::string text;
    std::cout << "Enter the text: \n";
    std::getline(std::cin,text);
    int num;
    std::cout << "Enter how much you want to shift the text: \n";
    std::cin >> num;

    text = encrypt_caesar(text, num);
    std::cout << text << std::endl;
    text = decrypt_caesar (text, num);
    std::cout << text << std::endl;

}