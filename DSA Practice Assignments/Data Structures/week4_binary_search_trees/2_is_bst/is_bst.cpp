#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define MIN_INT (-2147483647 - 1)
#define MAX_INT (2147483647)

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree, int idx, int min_yet, int max_yet) {
    /*
    if(tree[idx].left==-1 && tree[idx].right==-1)
        return true;
    else if(tree[idx].left==-1)
        return (tree[idx].key<tree[tree[idx].right].key && IsBinarySearchTree(tree, tree[idx].right));
    else if(tree[idx].right==-1)
        return (tree[idx].key>tree[tree[idx].left].key && IsBinarySearchTree(tree, tree[idx].left));
    else
        return (tree[idx].key>tree[tree[idx].left].key && tree[idx].key<tree[tree[idx].right].key && IsBinarySearchTree(tree, tree[idx].left) && IsBinarySearchTree(tree, tree[idx].right) );
    */
    if(idx==-1)
        return true;
    if(tree[idx].key<min_yet || tree[idx].key>max_yet)
        return false;

    return(IsBinarySearchTree(tree, tree[idx].left, min_yet, tree[idx].key) && IsBinarySearchTree(tree, tree[idx].right, tree[idx].key, max_yet));
}

int main() {
  int nodes;
  cin >> nodes;

  if(nodes==0){
    cout<<"CORRECT"<<endl;
    return 0;
  }

  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree, 0, MIN_INT, MAX_INT)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
