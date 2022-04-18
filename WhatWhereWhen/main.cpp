#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void print_result (int experts, int viewer)
{
    for (int i = 0; i < 5; i++){
        std::cout << "|";
        if (i == 1)
            std::cout << " Experts: ";
        if (i == 3)
            std::cout << "  Viewer: ";
        for (int j = 0; j < 20; j++){
            if (i == 0 || i == 2 || i == 4)
                std::cout << "-";
            if (j == 9){
                std::cout << "|";
                if (i == 1)
                    std::cout << "    " << experts << "     ";
                if (i == 3)
                    std::cout << "    " << viewer << "     ";
            }
            if (j == 19)
                std::cout << "|";
        } std::cout << std::endl;
    }
}

bool KMP(std::string str, std::string substr)
{
    std::vector<int> matches;
    std::vector<int> p(substr.size() + str.size(), -1);

    for (int i = 0, j = -1;i < substr.size();)
    {
        while (j > -1 && substr[i] != substr[j])
            j = p[j];
        i++;
        j++;
        p[i] = j;
    }
    for (int i=0, j = 0;i < str.size();)
    {
        while (j > -1 && str[i] != substr[j])
            j = p[j];
        i++;
        j++;
        if (j == substr.size())
        {
            return true;
        }

    }
    return false;
}

bool sectors_check (bool check, int sector)
{
    char quest[80];
    char answer[80];
    std::string answerExperts;
    std::string pathQ = R"(H:\Home work\C-plus-plus\WhatWhereWhen\Questions\)" + std::to_string(sector) + "\\question.txt";
    std::string pathA = R"(H:\Home work\C-plus-plus\WhatWhereWhen\Questions\)" + std::to_string(sector) + "\\answer.txt";
    std::ifstream fileQ;
    std::ifstream fileA;
    fileQ.open(pathQ);
    fileA.open(pathA);

    if (!fileQ.is_open() && !fileA.is_open())
        std::cerr << "Unable to open the file!";
    else {

        fileQ.read(quest, sizeof quest);
        quest[fileQ.gcount()] = '\0';
        std::cout << quest;
        std::cout << std::endl;

        std::cout << "Enter a response option:" << std::endl;
        std::cin >> answerExperts;

        fileA.read(answer, sizeof answer);
        answer[fileA.gcount()] = '\0';

        (KMP(std::string(answer), answerExperts)) ? check = true : check = false;

        fileQ.close();
        fileA.close();
    }
    return check;
}

int main() {
    bool check;
    bool check_quest[14];

    std::cout << "The game begins: " << std::endl;
    int experts = 0, viewer = 0;
    print_result(experts, viewer);
    int sectors;
    while (experts != 6 && viewer != 6){
        std::cout << "Input numbers sectors 1 - 13: " << std::endl;
        std::cin >> sectors;
        if ((sectors < 1 || sectors > 13) || check_quest[sectors]) {
            std::cerr << "Error input!" << std::endl;
        } else {
            check_quest[sectors] = true;
            check = sectors_check(check, sectors);
            check ? experts++ : viewer++;
            print_result(experts, viewer);
        }
    }

    std::cout << (experts == 6 ? "Experts won!" : "Viewer won!") << std::endl;

    return 0;
}