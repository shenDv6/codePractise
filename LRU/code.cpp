#include<iostream>
#include<unordered_map>
using namespace std;

struct DLinkNode {
  int key;
  int val;
  DLinkNode *pre;
  DLinkNode *next;
  DLinkNode() : key(0), val(0), pre(nullptr), next(nullptr) {}
  DLinkNode(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr){}
};


class LRU {
private:
  unordered_map<int, DLinkNode*> mark;
  DLinkNode *head = new DLinkNode();
  DLinkNode *tail = new DLinkNode();
  int size = 0;
  int capacity = 0;

public:
  LRU(int cap) {
    capacity = cap;
    head->next = tail;
    tail->pre = head;
  }

  int get(int k) {
    if (mark.count(k)) {
      return mark[k]->val;
      moveToHead(mark[k]);
    }
    return -1;
  }

  void put(int key, int value) {
    if (mark.count(key)) {
      mark[key]->val = value;
      moveToHead(mark[key]);
    } else {
      if (size == capacity) {
        DLinkNode *node = removeTail();
        mark.erase(node->key);
        delete node;
        size--;
      }
      DLinkNode *node = new DLinkNode(key, value);
      addToHead(node);
      mark[key] = node;
      size++;
    }
    
  }

  void addToHead(DLinkNode *node) {
    node->next = head->next;
    head->next->pre = node;
    node->pre = head;
    head->next = node;
  }

  void removeNode(DLinkNode *node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
  }

  void moveToHead(DLinkNode *node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkNode* removeTail() {
    DLinkNode* node = tail->pre;
    node->pre->next = tail;
    tail->pre = node->pre;
    return node;
  }
};

int main() {
  LRU s1(3);
  s1.put(1,1);
  s1.put(2,2);
  s1.put(3,3);
  s1.put(4,4);
  s1.put(5,5);
  cout << s1.get(2) << endl;

  return 0;
}

