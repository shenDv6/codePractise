#include<iostream>
#include<unordered_map>
using namespace std;


// struct DLinkNode {
//   int key;
//   int val;
//   DLinkNode *pre;
//   DLinkNode *next;
//   DLinkNode(int x, int y, DLinkNode *_pre, DLinkNode *_next) : key(x), val(y), pre(_pre), next(_next) {}
//   DLinkNode(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr) {}
// };

// class Solutuon {
// private:
//   unordered_map<int, DLinkNode*> mark;
//   int size = 0;
//   int cap = 0;
//   DLinkNode *head = new DLinkNode(0,0);
//   DLinkNode *tail = new DLinkNode(0,0);
// public:
//   Solutuon(int capacity) {
//     cap = capacity;
//     head->next = tail;
//     tail->pre = head;
//   }

//   int get(int k) {
//     if (mark.count(k)) {
//       moveToHead(mark[k]);
//       return mark[k]->val;
//     }
//     return -1;
//   }

//   void put(int key, int value) {
//     if (mark.count(key)) {
//       mark[key]->val = value;
//       moveToHead(mark[key]);
//     } else {
//       if (size == cap) {
//         DLinkNode *node = removeTail();
//         mark.erase(node->key);
//         delete node;
//         size--;
//       }
//       DLinkNode *node = new DLinkNode(key, value);
//       addTohead(node);
//       mark[key] = node;
//       size++;
//     }
//   }

//   void addTohead(DLinkNode *node) {
//     node->next = head->next;
//     head->next->pre = node;
//     head->next = node;
//     node->pre = head;
//   }

//   void removeNode(DLinkNode *node) {
//     node->pre->next = node->next;
//     node->next->pre = node->pre;
//   }

//   void moveToHead(DLinkNode *node) {
//     removeNode(node);
//     addTohead(node);
//   }

//   DLinkNode* removeTail() {
//     DLinkNode* node = tail->pre;
//     node->pre->next = tail;
//     tail->pre = node->pre;
//     return node;
//   }

// };

// int main() {
//   Solutuon s1(5);
//   s1.put(1,1);
//   s1.put(2,2);
//   s1.put(3,3);
//   s1.put(4,4);
//   s1.put(5,5);
//   s1.put(6,6);
//   s1.put(7,7);
//   cout << s1.get(2)<< endl;
//   return 0;
// }

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

