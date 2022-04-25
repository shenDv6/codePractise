#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> func(vector<vector<int>> matrix) {
    vector<vector<int>> res;
    bool isReverse = true;
    vector<int> tmp;
    for (int j = 0; j < matrix[0].size(); j++) {
      int col = j;
      int row = 0;
      while (col >= 0) {
        tmp.push_back(matrix[row][col]);
        row++;
        col--;
      }
      if (isReverse) {
        reverse(tmp.begin(), tmp.end());
      }
      res.push_back(vector<int>{tmp.begin(), tmp.end()});
      isReverse = !isReverse;
      tmp.clear();
    }
    for (int i = 1; i < matrix.size(); i++) {
      int row = i;
      int col = matrix[0].size() - 1;
      while (row < matrix.size()) {
        tmp.push_back(matrix[row][col]);
        row++;
        col--;
      }
      if (isReverse) {
        reverse(tmp.begin(), tmp.end());
      }
      res.push_back(vector<int>{tmp.begin(), tmp.end()});
      isReverse = !isReverse;
      tmp.clear();
    }
    return res;
  }
};


int main() {
  Solution s1;
  vector<vector<int>> array = {{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> res = s1.func(array);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
  }
  cout << endl;

  return 0;
}