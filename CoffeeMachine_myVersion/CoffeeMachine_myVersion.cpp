#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    int remainsMilk = 0, remainsWater = 0;
    int water, milk;
    int limit = 1;

    std::cout << "Введите количество воды в кофемашине: ";
    std::cin >> water;
    std::cout << "Введите количество молока в кофемашине: ";
    std::cin >> milk;

    std::string kofe;
    std::cout << "Какой кофе вы хотите? американо или латте: ";
    std::cin >> kofe;

    for (int waterInKofe = 0; water >= 270; waterInKofe = water) {

        for (int milkInKofe = 0; milk >= 30; milkInKofe = milk) {

            if (kofe == "латте" && milk >= 30 && water >= 270) {
                milk = milk - 30;
                water = water - 270;
                std::cout << "Ваш напиток готов.\n";
                std::cout << "Сейчас в кофемашинке " << water << " мл. воды.\n";
                std::cout << "Сейчас в кофемашинке " << milk << " мл. молока.\n";
            }
            if (kofe == "Американо" && water >= 300) {
                water = water - 300;
                std::cout << "Ваш напиток готов.\n";
                std::cout << "Сейчас в кофемашинке " << water << " мл. воды.\n";
                std::cout << "Сейчас в кофемашинке " << milk << " мл. молока.\n";
            }
            if (water < 270 || water < 300) {
                std::cout << "Не хватает воды.\n";
                std::cout << "Сейчас в кофемашинке " << water << " мл. воды.\n";
                break;
            }
            if (milk < 30) {
                std::cout << "Не хватает молока.\n";
                std::cout << "Сейчас в кофемашинке " << milk << " мл. молока.\n";
                break;
            }
            std::cout << "Следующий инженер. Какой кофе вы хотите? американо или латте: ";
            std::cin >> kofe;
            limit++;
        }
        std::cout << "Всего было приготовлено " << limit << " шт. кофе.\n";
    }
    return 0;
}