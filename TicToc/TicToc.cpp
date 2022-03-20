#include <iostream>

char check_won(char win, char tic[3][3]) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((tic[0][0] == 'X' && tic[0][1] == 'X' && tic[0][2] == 'X') ||
                (tic[1][0] == 'X' && tic[1][1] == 'X' && tic[1][2] == 'X') ||
                (tic[2][0] == 'X' && tic[2][1] == 'X' && tic[2][2] == 'X') ||
                (tic[0][0] == 'X' && tic[1][0] == 'X' && tic[2][0] == 'X') ||
                (tic[0][1] == 'X' && tic[1][1] == 'X' && tic[2][1] == 'X') ||
                (tic[2][0] == 'X' && tic[2][1] == 'X' && tic[3][2] == 'X') ||
                (tic[0][0] == 'X' && tic[1][1] == 'X' && tic[2][2] == 'X') ||
                (tic[0][2] == 'X' && tic[1][1] == 'X' && tic[2][0] == 'X')) {
                return win = 'X';
            }
            else if ((tic[0][0] == 'O' && tic[0][1] == 'O' && tic[0][2] == 'O') ||
                (tic[1][0] == 'O' && tic[1][1] == 'O' && tic[1][2] == 'O') ||
                (tic[2][0] == 'O' && tic[2][1] == 'O' && tic[2][2] == 'O') ||
                (tic[0][0] == 'O' && tic[1][0] == 'O' && tic[2][0] == 'O') ||
                (tic[0][1] == 'O' && tic[1][1] == 'O' && tic[2][1] == 'O') ||
                (tic[2][0] == 'O' && tic[2][1] == 'O' && tic[3][2] == 'O') ||
                (tic[0][0] == 'O' && tic[1][1] == 'O' && tic[2][2] == 'O') ||
                (tic[0][2] == 'O' && tic[1][1] == 'O' && tic[2][0] == 'O')) {
                return win = 'O';
            }
        }
    }
    return 0;
}

int main() {
    char tic[3][3];
    char space = ' ';
    int count = 0;
    char won;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tic[i][j] = space;
            count++;
        }
    }

    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            std::cout << tic[i][j] << " | ";
        } std::cout << std::endl;
    }
    std::cout << "-------------" << std::endl;

    int x, y;
    while (count != 0) {
        std::cout << "Enter the X coordinates" << std::endl;
        std::cin >> x >> y;
        if (tic[x][y] != 'O' && tic[x][y] != 'X') {
            tic[x][y] = 'X';
            count--;
            std::cout << "-------------" << std::endl;
            for (int i = 0; i < 3; ++i) {
                std::cout << "| ";
                for (int j = 0; j < 3; ++j) {
                    std::cout << tic[i][j] << " | ";
                }std::cout << std::endl;
            }
            std::cout << "-------------" << std::endl;
            char check_won(char won, char tic[3][3]);
            won = check_won(won, tic);
            if (won == 'X')  break;
        }
        else {
            std::cout << "Repeat the input" << std::endl;
        }
        if (count == 0) { break; }

        std::cout << "Enter the O coordinates" << std::endl;
        std::cin >> x >> y;
        if (tic[x][y] != 'X' && tic[x][y] != 'O') {
            tic[x][y] = 'O';
            count--;
            std::cout << "-------------" << std::endl;
            for (int i = 0; i < 3; ++i) {
                std::cout << "| ";
                for (int j = 0; j < 3; ++j) {
                    std::cout << tic[i][j] << " | ";
                }std::cout << std::endl;
            }
            std::cout << "-------------" << std::endl;

            char check_won(char won, char tic[3][3]);
            won = check_won(won, tic);
            if (won == 'O')  break;
        }
        else {
            std::cout << "Repeat the input" << std::endl;
        }
    }
    if (won == 'X' || won == 'O') {
        std::cout << "Won: " << won << std::endl;
    }
    else
        std::cout << "Draw." << std::endl;
}