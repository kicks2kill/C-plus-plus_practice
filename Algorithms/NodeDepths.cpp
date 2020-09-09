#include <vector>
using namespace std;


struct BinaryTree {
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

struct Level {
    BinaryTree *root;
    int depth;
};


int nodeDepths(BinaryTree *root) {
  int sumOfDepths = 0;
  vector<Level> stack = {{root, 0}}; //AFAIK, this initializes the entire 'stack' to 0
  while(stack.size() > 0){
      BinaryTree *node = stack.back().root;
      int depth = stack.back().depth;
      stack.pop_back();
      if(node == NULL)
            continue;
      sumOfDepths += depth;
      stack.push_back(Level{node->left, depth+1});
      stack.push_back(Level{node->right, depth + 1});
  } 
  return sumOfDepths;

}