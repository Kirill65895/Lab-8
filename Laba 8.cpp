#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arabicToRoman(int arabic) {
    if (arabic < 1 || arabic > 3999) {
        return "Неверный ввод.";
    }

    string roman = "";
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 13; ++i) {
        while (arabic >= values[i]) {
            roman += symbols[i];
            arabic -= values[i];
        }
    }

    return roman;
}

int romanToArabic(string roman) {
    int arabic = 0;
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i = 0; i < 13; ++i) {
        while (roman.find(symbols[i], 0) == 0) { 
            arabic += values[i];
            roman.erase(0, symbols[i].length());
        }
    }

    if (!roman.empty()) {
        return -1; 
    }

    return arabic;
}

int main() {
    setlocale(LC_ALL, "ru");

    int choice;
    string proga = "T";

    while (proga == "T")
    {
        
        cout << "Выберите действие:" << endl;
        cout << "1) Перевод из арабского в римское." << endl;
        cout << "2) Перевод из римского в арабское." << endl;
        cout << "3) Завершить программу." << endl;
        cout << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1: {
            int arabicNum;
            cout << "Введите арабское число: ";
            cin >> arabicNum;
            string romanNum = arabicToRoman(arabicNum);
            cout << "Римское число: " << romanNum << endl;
            cout << endl;
            break;
        }
        case 2: {
            string romanNum;
            cout << "Введите римское число: ";
            cin >> romanNum;
            int arabicNum = romanToArabic(romanNum);
            if (arabicNum != -1) {
                cout << "Арабское число: " << arabicNum << endl;
            }
            cout << endl;
            break;
        }
        case 3: {
            cout << "Программа завершена!";
            proga = "F";
            return 0;
        }
        default:
            break;
        }
    }
}