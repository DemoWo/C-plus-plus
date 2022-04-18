#include <iostream>
#include <cstring>

bool check(const char& word, const  char& check_word) {
    std::string strWord = &word;
    std::string strCheck = &check_word;

    if (strCheck.size() != 0){
        for (size_t i = 0; i < strWord.size(); i++){
            for (size_t j = 0; ; j++){
                if (!strCheck[j])
                    return true;
                if (strWord[i+j] != strCheck[j]) {
                    break;
                }
            }
        }
    }
    return false;
}

int main() {
    const char* a = "Hello world";
    const char* b = "wor";
    bool checkFirst = check(*a, *b);
    const char* c = "banana";
    bool checkSecond = check(*a, *c);

    std::cout << (checkFirst ? "True!" : "False!") << std::endl;
    std::cout << (checkSecond ? "True!" : "False!") << std::endl;

    return 0;
}