#include <iostream.h>
#include <conio.h>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void preorderTraversal(TreeNode* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(TreeNode* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (node != NULL) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void setRoot(TreeNode* node) {
        root = node;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    clrscr();

    BinaryTree tree;

    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    tree.setRoot(root);

    // Perform traversals
    tree.preorder();
    tree.inorder();
    tree.postorder();

    getch();
    return 0;
}
