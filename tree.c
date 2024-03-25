#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 创建新的树节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 向树中插入节点
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// 在树中查找节点
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// 在树中删除节点
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // 找到需要删除的节点
        
        // 没有子节点或只有一个子节点的情况
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // 有两个子节点的情况，找到右子树中最小的节点替代当前节点
        Node* minValueNode = root->right;
        while (minValueNode->left != NULL) {
            minValueNode = minValueNode->left;
        }
        
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }
    
    return root;
}

// 中序遍历树
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    
    // 向树中插入节点
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 6);
    
    printf("中序遍历树：");
    inorderTraversal(root);
    printf("\n");
    
    // 在树中查找节点
    Node* node = search(root, 6);
    if (node != NULL) {
        printf("找到节点：%d\n", node->data);
    } else {
        printf("未找到节点\n");
    }
    
    // 在树中删除节点
    root = deleteNode(root, 3);
    
    printf("删除节点后的中序遍历树：");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}