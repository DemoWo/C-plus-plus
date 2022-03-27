#include <iostream>

int main() {
    int row = 10;
    int colm = 10;
    char playerFirst[row][colm];
    char playerTwo[row][colm];
    int num = 0;
    char table[row][colm];

    while (num != 2) {
        int litShip = 4; //маленькие корабли в одну клетку
        int smallShip = 3; // небольшие корабли в две клетки
        int middleShip = 2; // средние корабли в три клетки
        int bigShip = 1; // большой корабль в 4 клетки

        if (num == 0) {
            std::cout << "The first player fills in the table: " << std::endl;
            //playerFirst[row][colm];
        }
        if (num == 1) {
            std::cout << "The second player fills in the table: " << std::endl;
            //playerTwo[row][colm];
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colm; ++j) {
                table[i][j] = '0';
            }
        }
        while (litShip != 0) {
            int x, y;
            std::cout << "Enter the location of the little ship: " << litShip << " ships left!"<< std::endl;
            std::cin >> x >> y;

            if (table[x][y] == '0')
                table[x][y] = 'L';
            else {
                std::cout << "Error: " << std::endl;
                litShip++;
            }
            litShip--;
        }

        while (smallShip != 0) {
            int startX, startY ,  endX , endY;
            std::cout << "Enter the location of the small ship: " << smallShip << " ships left!"<< std::endl;
            std::cout << "Start location: " << std::endl;
            std::cin >> startX >> startY;
            std::cout << "End location: " << std::endl;
            std::cin >> endX >> endY;

            if (endX - startX == 1 || endY - startY == 1) {
                table[startX][startY] = 'S';
                table[endX][endY] = 'S';
                smallShip--;
            } else {
                std::cout << "Error: " << std::endl;
                break;
            }
        }

        while (middleShip != 0) {
            int x, y, z, c;
            std::cout << "Enter the location of the middle ship: " << middleShip << " ships left!" << std::endl;
            std::cout << "Start location: " << std::endl;
            std::cin >> x >> y;
            std::cout << "End location: " << std::endl;
            std::cin >> z >> c;
            if (x > z || y > c) {
                std::cout << "Input error repeat the input: " << std::endl;
            } else {
            //столбец
                if (y == c) {
                    for (int i = x; i < z; ++i) {
                        if (table[i][c] == '0') {
                            if (z - x == 3)
                                table[i][c] = 'M';
                            else {
                                std::cout << "Input error repeat the input: " << std::endl;
                                middleShip++;
                                break;
                            }
                        } else {
                            std::cout << "Input error repeat the input: " << std::endl;
                            middleShip++;
                            break;
                        }
                    }
                }

                // строка
            else if (x == z) {
                for (int j = y; j < c; ++j) {
                    if (table[z][j] == '0') {
                        if (c - y == 3)
                            table[z][j] = 'M';
                        else {
                            std::cout << "Input error repeat the input: " << std::endl;
                            middleShip++;
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Input error repeat the input: " << std::endl;
                middleShip++;
                break;
            }
            middleShip--;
        }
    }

        while (bigShip != 0) {
            int x, y, z, c;
            std::cout << "Enter the location of the big ship: " << bigShip << " ships left!" << std::endl;
            std::cout << "Start location: " << std::endl;
            std::cin >> x >> y;
            std::cout << "End location: " << std::endl;
            std::cin >> z >> c;
            if (x > z || y > c) {
                std::cout << "Input error repeat the input: " << std::endl;
            } else {
                //столбец
                if (y == c) {
                    for (int i = x; i < z; ++i) {
                        if (table[i][c] == '0') {
                            if (z - x == 4) {
                                table[i][c] = 'B';
                            } else {
                                std::cout << "Input error repeat the input: " << std::endl;
                                bigShip++;
                                break;
                            }
                        } else {
                            std::cout << "Input error repeat the input: " << std::endl;
                            bigShip++;
                            break;
                        }
                    }
                }
                    // строка
                else if (x == z) {
                    for (int j = y; j < c; ++j) {
                        if (table[z][j] == '0') {
                            if (c - y == 4) {
                                table[z][j] = 'B';
                            } else {
                                std::cout << "Input error repeat the input: " << std::endl;
                                bigShip++;
                                break;
                            }
                        }
                    }
                } else {
                    std::cout << "Input error repeat the input: " << std::endl;
                    bigShip++;
                    break;
                }
                bigShip--;
            }
        }

        for (int i = 0; i < row; ++i) {
            std::cout << "---------------------------------------|" << std::endl;
            for (int j = 0; j < colm; ++j) {
                if (num == 0) {
                    playerFirst[i][j] = table[i][j];
                }
                if (num == 1) {
                    playerTwo[i][j] = table[i][j];
                }
                std::cout << " " << table[i][j] << " |";
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------------------|" << std::endl;
        num++;
    }

    int countFirst = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colm; ++j) {
            if (playerFirst[i][j] == 'B' || playerFirst[i][j] == 'L' || playerFirst[i][j] == 'S' ||
                playerFirst[i][j] == 'M') {
                countFirst++;
            }
        }
    }

    int countTwo = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < colm; ++j) {
            if (playerTwo[i][j] == 'B' || playerTwo[i][j] == 'L' || playerTwo[i][j] == 'S' || playerTwo[i][j] == 'M') {
                countTwo++;
            }
        }
    }

    int x, y;
    bool won = true;
    while (countFirst != 0 || countTwo != 0) {
        std::cout << "The first player strikes at the coordinates: " << std::endl;
        std::cin >> x >> y;
        if (playerTwo[x][y] == 'B' || playerTwo[x][y] == 'L' || playerTwo[x][y] == 'S' || playerTwo[x][y] == 'M') {
            playerTwo[x][y] = ' ';
            std::cout << "Hit!" << std::endl;
            countTwo--;
            //std::cout << countTwo << std::endl;
            if (countTwo == 0) {
                won = true;
                break;
            }
        } else std::cout << "Miss!" << std::endl;

        std::cout << "The second player strikes at the coordinates: " << std::endl;
        std::cin >> x >> y;
        if (playerFirst[x][y] == 'B' || playerFirst[x][y] == 'L' || playerFirst[x][y] == 'S' ||
            playerFirst[x][y] == 'M') {
            playerFirst[x][y] = ' ';
            std::cout << "Hit!" << std::endl;
            countFirst--;
            //std::cout << countFirst << std::endl;
            if (countFirst == 0) {
                won = false;
                break;
            }
        } else std::cout << "Miss!" << std::endl;

    }
    std::cout << (won ? "Won First Player!" : "Won Second Player!") << std::endl;

    std::cout << "The result of hitting the ships: " << std::endl;
    for (int i = 0; i < row; ++i) {
        std::cout << "---------------------------------------|" << std::endl;
        for (int j = 0; j < colm; ++j) {
            std::cout << " " << playerFirst[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------|" << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < row; ++i) {
        std::cout << "---------------------------------------|" << std::endl;
        for (int j = 0; j < colm; ++j) {
            std::cout << " " << playerTwo[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------|" << std::endl;

    return 0;
}
