#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
  string lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mark;
    int left = 0, right = 0;
    string res = "";
    while (right < s.size()) {
      if (mark.count(s[right]) != 0) {
        int pos = mark[s[right]];
        while (left <= pos) {
          mark.erase(s[left++]);
        }
      }
      mark[s[right]] = right;
      if (right - left + 1 > res.size()) {
        res = s.substr(left, right - left + 1);
      }
      right++;
    }
    return res;
  }
};


int main() {
  string s = "lasjdflaksdjf";
  Solution s1;
  string num = s1.lengthOfLongestSubstring(s);
  for (char c : num) {
    cout << c;
  }
  cout << endl;
  return 0;
}