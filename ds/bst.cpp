#include <iostream>
#include <conio.h>

using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BinarySearchTree
{
private:
    TreeNode *root;

    TreeNode *insert(TreeNode *node, int value)
    {
        if (node == NULL)
        {
            return new TreeNode(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    int search(TreeNode *node, int value)
    {
        if (node == NULL)
        {
            return 0;
        }

        if (value == node->data)
        {
            return 1;
        }
        else if (value < node->data)
        {
            return search(node->left, value);
        }
        else
        {
            return search(node->right, value);
        }
    }

    void inorderTraversal(TreeNode *node)
    {
        if (node != NULL)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    int search(int value)
    {
        return search(root, value);
    }

    void printInorder()
    {
        cout << "Tree elements: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{

    BinarySearchTree bst;

    // Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Search for elements
    cout << "Is 40 in the tree? " << (bst.search(40) ? "Yes" : "No") << endl;
    cout << "Is 90 in the tree? " << (bst.search(90) ? "Yes" : "No") << endl;

    // Print inorder traversal
    bst.printInorder();

    getch();
    return 0;
}