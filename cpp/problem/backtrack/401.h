//
// Created by zhengxiaojian on 2020/11/26.
//

#ifndef CPP_401_H
#define CPP_401_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if (num == 0) return {"0:00"};

        vector<int> hours = {1, 2, 4, 8};
        vector<int> minutes = {1, 2, 4, 8, 16, 32};

        vector<int> hours_result;
        vector<int> minutes_result;

        vector<string> result;

        for (int i = 0; i <= num; ++i) {
            int j = num - i;
            hours_result.clear();
            minutes_result.clear();
            backtrack(0, i, 0, hours, hours_result);
            backtrack(0, j, 0, minutes, minutes_result);

            if (i == 0) {
                for (auto m : minutes_result) {
                    string ms = get_minutes(m);
                    if (ms.empty()) continue;
                    result.push_back("0:" + move(ms));
                }
            } else if (j == 0) {
                for (auto h : hours_result) {
                    auto hs = get_hour(h);
                    if (hs.empty()) continue;
                    result.push_back(move(hs) + ":00");
                }
            } else {
                for (auto h : hours_result) {
                    auto hs = get_hour(h);
                    if (hs.empty()) continue;
                    for (auto m : minutes_result) {
                        auto ms = get_minutes(m);
                        if (ms.empty()) continue;
                        result.push_back(hs + ":" + move(ms));
                    }
                }
            }
        }

        return result;
    }

    void backtrack(int s, int e, int sum, vector<int> &nums, vector<int> &result) {
        if (nums.size() - s < e) return;

        if (e == 0) {
            result.push_back(sum);
            return;
        }

        for (int i = s; i < nums.size(); ++i) {
            backtrack(i + 1, e - 1, sum + nums[i], nums, result);
        }
    }

    string get_hour(int hour) {
        return hour > 11 ? "" : to_string(hour);
    }

    string get_minutes(int minutes) {
        if (minutes <= 9) return "0" + to_string(minutes);
        return minutes > 59 ? "" : to_string(minutes);
    }
};

#endif //CPP_401_H
