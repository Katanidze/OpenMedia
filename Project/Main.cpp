#include <iostream>
#include <string>
#include "..\StaticLib\Header.h"
#include <Windows.h>

using namespace std;

int main()
{
    std::string yearInput;
    int year = 0;
    std::string input;
    std::cout << "Enter year the Open Media company was founded: ";
    std::cin >> yearInput;
    try
    {
        year = stoi(yearInput);//Обработаем исключения после ввода года
    }
    catch (std::invalid_argument)
    {
        std::cout << "Only numbers are allowed!\n";//Говорим, что можно вводить только числа
    }
    catch (std::out_of_range)
    {
        std::cout << "You can't be that old!\n";//Говорим, что число слишком большое
    }
    catch (...)
    {
        std::cout << "Unknown error!\n";//Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
    }

    if (year > 0 && year < 2022)
    {
        founding_date(year);
    }
    else
    {
        std::cout << "Invalid number!\n";
    }
    std::cout << "Enter Yes or No: ";
    std::cin >> input;
    if (input == "Yes" || input == "yes")
    {
        cout << "Loading DyanamicLib.dll.." << endl;
        HINSTANCE load;
        load = LoadLibrary(L"DyanamicLib.dll");
        if (load != NULL) {
            cout << "Library loaded!" << endl;
        }
        else return printf("Error load DyanamicLib.dll!\n");
        typedef int (*t) ();
        t CheckTime;
        CheckTime = (t)GetProcAddress(load, "CheckTime");
        CheckTime();
        FreeLibrary(load);
    }
    else if (input == "No" || input == "no")
    {
        cout << "Not? Okay.." << endl;
    }
    else return printf("Invalid value!\n");
    return 1;
}