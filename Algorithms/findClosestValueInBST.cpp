#include <vector>
#include <cmath>
#include <float.h>

struct BST {
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBST(BST *tree, int target);
int findClosestValueInBSTHelper(BST *tree, int target, int closest);

int findClosestValueInBST(BST *tree, int target) {
    return findClosestValueInBSTHelper(tree, target, tree->value);
}

int findClosestValueInBSTHelper(BST *tree, int target, int closest) {
    BST *currentNode = tree;
    while(currentNode != NULL) {
        if(abs(target - closest) > abs(target - currentNode->value)) {
            closest = currentNode->value;
        }
        if(target < currentNode->value) {
            currentNode = currentNode->left;
        } else if (target > currentNode-> value) {
                currentNode = currentNode->right;             
        } else {
            break;
        }
    }
        return (int)closest;
}