#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
public:
  string mostCommonWord(string paragraph, vector<string> &banned)
  {
    unordered_set<string> ban;
    unordered_map<string, int> mark;
    for (string str : banned)
    {
      ban.insert(str);
    }
    int head = 0, tail = 0;
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    int count = 0;
    string res;
    while (head < paragraph.size())
    {
      if (paragraph[head] == ' ')
      {
        head++;
        continue;
      }
      tail = head;
      while (tail < paragraph.size() && paragraph[tail] != ' ' && paragraph[tail] != ',' && paragraph[tail] != '.')
      {
        tail++;
      }
      string str = paragraph.substr(head, tail - head);
      if (!ban.count(str))
      {
        mark[str]++;
        if (mark[str] > count)
        {
          count = mark[str];
          res = str;
        }
      }
      head = tail + 1;
    }
    return res;
  }
};

int main()
{
  string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
  vector<string> banned = {"hit"};
  Solution s1;
  string res;
  res = s1.mostCommonWord(paragraph, banned);
  cout << res << endl;
  return 0;
}