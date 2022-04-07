#include <iostream>
#include <string>

enum note
{
    DO = 1,  //1
    RE = 2, //2
    MI = 4,//3
    FA = 8,//4
    SOL = 16,//5
    LA = 32,//6
    SI = 64//7
};

int check_num (int num){
    num = (1 << (num - 1));
    return num;
}

bool check_note (std::string noteCheck, bool checkNote){
    for (int i = 0; i < noteCheck.size(); i++) {
        if (noteCheck[i] >= '1' && noteCheck[i] <= '7') {
            checkNote = true;
        } else {
            checkNote = false;
            break;
        }
    }
    return checkNote;
}

void notes_print (std::string melody[], int row){
    std::string notion;
    int notes;

    for (int i = 0; i < row; i++) {
        notion = melody[i];
        bool d = true;
        bool r = true;
        bool m = true;
        bool f = true;
        bool s = true;
        bool l = true;
        bool si = true;

        for (int j = 0; j < notion.size(); j++) {
            int num = notion[j] - '0';
            notes = check_num(num);

            if (notes & SI && si) { //7
                std::cout << "SI" << " ";
                si = false;
            } else if (notes & LA && l) { //6
                std::cout << "LA" << " ";
                l = false;
            } else if (notes & SOL && s) { //5
                std::cout << "SOL" << " ";
                s = false;
            } else if (notes & FA && f) { //4
                std::cout << "FA" << " ";
                f = false;
            } else if (notes & MI && m) { //3
                std::cout << "MI" << " ";
                m = false;
            } else if (notes & RE && r) { //2
                std::cout << "RE" << " ";
                r = false;
            } else if (notes & DO && d) {  //1
                std::cout << "DO" << " ";
                d = false;
            }
        }
        std::cout << "| ";
    }
}

int main() {
    int row = 12;
    std::string melody[row];
    bool checkNot = true;

    int count = row;
    for (int i = 0; i < row; i++ ){
        std::cout << "Enter " << count << " sounds of melodies: " << std::endl;
        std::cin >> melody [i];
        checkNot = check_note(melody[i], checkNot);

        if (checkNot) {
            count --;
        } else {
            std::cout << "Incorrect input!" << std::endl;
            i--;
        }
    }

    notes_print(melody, row);

    return 0;
}