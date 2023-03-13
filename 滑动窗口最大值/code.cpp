#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int head = 0, tail = k - 1;
        while (tail < nums.size()) {
            res.push_back(*max_element(nums.begin() + head, nums.begin() + tail + 1));
            vector<int> n{nums.begin() + head, nums.begin() + tail + 1};
            tail++;
            head++;
        }
        return res;
    }
};

int main() {
  Solution s1;
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  vector<int> res = s1.maxSlidingWindow(nums, 3);

  return 0;
}