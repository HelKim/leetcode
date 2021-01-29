//
// Created by zhengxiaojian on 2021/1/11.
//

#ifndef CPP_12_H
#define CPP_12_H

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        int base = 1;
        while (num > 0) {
            s = get_str((num % 10) * base) + s;
            base *= 10;
            num /= 10;
        }
        return s;
    }

    string get_str(int num) {
        string s;

        switch (num) {
            case 1:
            case 2:
            case 3:
                for (int i = 0; i < num; ++i) {
                    s.push_back('I');
                }
                break;
            case 4:
                s = "IV";
                break;
            case 5:
                s = "V";
                break;
            case 6:
            case 7:
            case 8:
                s = "V" + get_str(num - 5);
                break;
            case 9:
                s = "IX";
                break;
            case 10:
            case 20:
            case 30:
                for (int i = 0; i < num; i += 10) {
                    s += "X";
                }
                break;
            case 40:
                s = "XL";
                break;
            case 50:
                s = "L";
                break;
            case 60:
            case 70:
            case 80:
                s = "L" + get_str(num - 50);
                break;
            case 90:
                s = "XC";
                break;
            case 100:
            case 200:
            case 300:
                for (int i = 0; i < num; i += 100) {
                    s += "C";
                }
                break;
            case 400:
                s = "CD";
                break;
            case 500:
                s = "D";
                break;
            case 600:
            case 700:
            case 800:
                s += "D" + get_str(num - 500);
                break;
            case 900:
                s = "CM";
                break;
            case 1000:
            case 2000:
            case 3000:
                for (int i = 0; i < num; i += 1000)
                    s += "M";
                break;
        }

        return s;
    }
};

#endif //CPP_12_H
