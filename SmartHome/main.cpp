#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

void print_switches (int index){
    if (index & LIGHTS_INSIDE){
        std::cout << "The light inside is on! 2700k" << std::endl;
    }
    if (index & LIGHTS_OUTSIDE){
        std::cout << "The light outside is on!" << std::endl;
    }
    if (index & HEATERS){
        std::cout << "The heaters on!" << std::endl;
    }
    if (index & WATER_PIPE_HEATING){
        std::cout << "Water heating is on!" << std::endl;
    }
    if (index & CONDITIONER){
        std::cout << "Air conditioning is on!" << std::endl;
    }
}

bool light_check (std::string& answer,bool light){
    if (answer == "on" || answer == "off"){
        light = true;
    } else light = false;
    return light;
}

bool movement_check (const std::string& answer, bool movement){
    if (answer == "yes" || answer == "no"){
        movement = true;
    } else {
        movement = false;
    }
    return movement;
}

int tempOut_check (int tempOut){
    int status = 0;
    if (tempOut < 0)
        status |= WATER_PIPE_HEATING;
    else if (tempOut > 5)
        status &= ~WATER_PIPE_HEATING;
    print_switches(status);
    return 0;
}

void lightOut_check (int time, const std::string& movement){
    int status = 0;
    if ((time > 16 || time < 5) && movement == "yes"){
        status |= LIGHTS_OUTSIDE;
    }
    else if (movement == "no" || time < 16 || time > 5){
        status &= ~LIGHTS_OUTSIDE;
    }
    print_switches(status);
}

void heatingIns_ckeck(int tempIns){
    int status = 0;
    if (tempIns < 22)
        status |= HEATERS;
    else if (tempIns >= 25)
        status &= ~HEATERS;
    print_switches(status);
}

void conditioner_check(int tempIns){
    int status = 0;
    if (tempIns >= 30)
        status |= CONDITIONER;
    else if (tempIns <= 25)
        status &= ~CONDITIONER;
    print_switches(status);
}

void tempLight_check (int time, const std::string& light){
    int status = 0;
    if (time >= 16 && time <= 20 && light == "on"){
        status |= LIGHTS_INSIDE;
        print_switches(status);
    }
    else if (time >= 0 && light == "on")
        std::cout << "The light inside is on! 5000k" << std::endl;
}

void print_feature (){
    for(int i = 0 ; i < 35; i++){
        std::cout << "-";
    } std::cout << std::endl;
}

int main() {
    std::string dateIn;
    int time;
    int count = 0;
    int countSec = 0;
    bool check = true;

    while (count != 48) {

        if (count >= 24) {
            time = countSec;
            countSec++;
        } else
            time = count;

        std::cout << "At the moment " << time << " hours!" << std::endl;
        std::cout << "Enter the readings of the inside temperature ,outside temperature, motion sensor (yes/no) and light (on/off)." << std::endl;
        print_feature();
        std::getline(std::cin,dateIn);

        std::stringstream Input_Date (dateIn);
        std::string light, movement;
        int tempOuts, tempIns;
        Input_Date >> tempOuts >> tempIns >> movement >> light;

        bool movCheck = movement_check(movement,check);
        bool lightCheck = light_check(light, check);

        if (!movCheck || !lightCheck){
            std::cout << "Error input!" << std::endl;
        } else {
            print_feature();
            tempOut_check(tempOuts); // отопление в доме
            lightOut_check(time, movement); // садовое освещение вечером если есть движение
            heatingIns_ckeck(tempIns); // температура внутри
            conditioner_check(tempIns); //кондиционер
            tempLight_check(time, light); // изменение цветовой температуры в дом 5000K - 2700K
            count++;
            print_feature();
        }
    }
    return 0;
}