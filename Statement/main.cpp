#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream statement;
    float sum = 0;
    std::vector<std::string> firstName;
    std::vector<std::string> lastName;
    std::vector<std::string> salary;
    std::vector<std::string> data;
    std::vector<float> salaryList;

    statement.open (R"(H:\Home work\C-plus-plus\Statement\Statement.txt)");

    if (!statement.is_open())
    {
        std::cout << "Could not open the file!";
    }
    else
    {
        int i = 0;
        int max = 0;
        char buffer[80];
        while (!statement.eof())
        {
            statement >> buffer;
            firstName.emplace_back(buffer);
            statement >> buffer;
            lastName.emplace_back(buffer);
            statement >> buffer;
            salary.emplace_back(buffer);
            statement >> buffer;
            data.emplace_back(buffer);

            salaryList.push_back(std::stof(salary[i]));
            sum += salaryList[i];

            if (salaryList[i] > salaryList[max])
                max = i;
            i++;
        }
        std::cout << "Total amount of payments: " << sum << std::endl;
        std::cout << "Maximum payout amount: " << firstName[max] << " " << lastName[max] << " " << salary[max] << " " << data[max] << std::endl;
    }

    statement.close();
    return 0;
}