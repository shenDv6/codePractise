#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  int Partition(vector<int> &nums, int p, int r) {
    int j = p - 1;
    for (int i = p; i < r; i++) {
      if (nums[i] < nums[r]) {
        j++;
        swap(nums[i], nums[j]);
      }
    }
    j++;
    swap(nums[j], nums[r]);
    return j;
  }

  void QuickSort(vector<int> &nums, int p, int r) {
    if (p >= r) return;
    int q = Partition(nums, p, r);
    QuickSort(nums, p, q - 1);
    QuickSort(nums, q + 1, r);
  }

  vector<int> sort(vector<int> &nums) {
    QuickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};

int main() {
  Solution s1;
  vector<int> arry = {21,32,4,1,3,7,5,2,8,9,3,10};
  vector<int> res;
  res = s1.sort(arry);
  for (int i : res) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}

