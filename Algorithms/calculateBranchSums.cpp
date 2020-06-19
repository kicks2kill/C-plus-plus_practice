#include <vector>

using namespace std;

class BinaryTree {
    public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

void calculatebranchSums(BinaryTree *node, int runningSum, vector<int> &sums);

vector<int> branchSums(BinaryTree *root) {
    vector<int> sums;
    calculatebranchSums(root, 0, sums);
    return sums;
}

void calculateBranchSums(BinaryTree *node, int runningSum, vector<int> &sums) {
    if(node == NULL)
        return;

    int newRunningSum = runningSum + node->value;
    if(node->left == NULL && node->right == NULL) {
        sums.push_back(newRunningSum);
        return;
    }

    calculatebranchSums(node->left, newRunningSum, sums);
    calculatebranchSums(node->right, newRunningSum, sums);
}