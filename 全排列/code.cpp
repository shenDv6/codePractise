#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> path;
  vector<vector<int>> res;

  void bt(vector<int> &nums, vector<int> path, vector<bool> used) {
    if (path.size() == nums.size()) {
      res.emplace_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        used[i] = true;
        path.emplace_back(nums[i]);
        bt(nums, path, used);
        used[i] = false;
        path.pop_back();
      }
    }
  }

  vector<vector<int>> func(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    bt(nums, path, used);
    return res;
  }
};


int main() {
  Solution s1;
  vector<int> nums = {1,2,3};
  vector<vector<int>> res = s1.func(nums);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j];
    }
    cout <<endl;
  }
  return 0;
}
