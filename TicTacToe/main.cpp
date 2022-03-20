#include <iostream>

std::string comparison (std::string result){
  std::string o = "O";
  std::string x = "X";
  int countO = 0;
  int countX = 0;
  int countDot = 0;
  std::string answer;
  for (int i = 0; i < result.length(); i++){
    if (result[i] == 'O') countO++;
    if (result[i] == 'X') countX++;
    if (result[i] == '.') countDot++;

    if (result[i] == 'O' || result[i] == 'X'){
    if (result[0] == result[1] && result[1] == result[2])
      answer = result[0];
    else if (result[3] == result[4] && result[4] == result[5])
      answer = result[3];
    else if (result[6] == result[7] && result[7] == result[8])
      answer = result[6];

    if (result[0] == result[3] && result[3] == result[6])
      answer = result[0];
    else if (result[1] == result[4] && result[4] == result[7])
      answer = result[1];
    else if (result[2] == result[5] && result[5] == result[8])
      answer = result[2];

    else if (result[0] == result[4] && result[4] == result[8])
      answer = result[0];
    else if (result[2] == result[4] && result[4] == result[6])
      answer = result[2];
      }
  }

    if (countO > countX)
      std::cout << "Incorrect" << std::endl;
    else if (countDot > countO + countX)
      std::cout << "Nobody" << std::endl;
    else if (answer == x){
      if (countO >= countX)
        std::cout << "Incorrect" << std::endl;
    else std::cout << "Petya won" << std::endl;
    }
    else if (answer == o){
      if (countO < countX || countO >= countX)
        std::cout << "Incorrect" << std::endl;
      else std::cout << "Vanya won" << std::endl;
      }
    else {
        std::cout << "Nobody" << std::endl;
    }
  return result;
}

std::string check_str (std::string str){
  bool res;
  for (int i = 0; i < str.length() && str.length() == 3; i++){
    if (str[i] == 'O' || str[i] == 'X' || str[i] == '.')
      res = true;
    else {
      res = false;
    break;
    }
  }
  if (!res)
    return str = "Incorrect";
  else
    return str;
}

int main() {
  std::string str1, str2, str3;
  std::cout << "Input result: \n";
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  std::getline(std::cin, str3);

  std::string str1Check = check_str(str1);
  std::string str2Check = check_str(str2);
  std::string str3Check = check_str(str3);

  if (str1Check == "Incorrect" || str2Check == "Incorrect"
        || str3Check == "Incorrect")
    std::cout << "Incorrect" << std::endl;
  else {
    std::string result = str1Check + str2Check + str3Check;
    comparison(result);
    }
}