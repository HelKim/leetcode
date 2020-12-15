//
// Created by zhengxiaojian on 2020/12/13.
//

#ifndef CPP_215_H
#define CPP_215_H

#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();

        return findKthLargest(0, n - 1, n - k + 1, nums);
    }

    int findKthLargest(int s, int e, int k, vector<int> &nums) {
        if (s == e) return nums[s];

        int pivot = nums[s];

        int l = s;
        int r = e;
        while (l < r) {
            while (l < r && nums[r] >= pivot) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) ++l;
            nums[r] = nums[l];
        }
        nums[l] = pivot;

//        int pivotpos = s;
//        for (int i = s + 1; i <= e; ++i) {
//            if (nums[i] <= pivot) {
//                ++pivotpos;
//                if (i != pivotpos) swap(nums[i], nums[pivotpos]);
//            }
//        }
//        swap(nums[pivotpos], nums[s]);

        if (l + 1 == k) return nums[l];
        else if (l + 1 > k) return findKthLargest(s, l - 1, k, nums);
        else return findKthLargest(l + 1, e, k, nums);
    }
};

#endif //CPP_215_H
