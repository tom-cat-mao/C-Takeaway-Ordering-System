#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 创建新的树节点
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 向树中插入节点
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }

}

// 在树中查找节点
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// 在树中删除节点
void deleteNode(Node** root, int data) {
    if (*root == NULL) {
        return;
    }

    if (data < (*root)->data) {
        deleteNode(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        deleteNode(&((*root)->right), data);
    }
    else // 找到需要删除的节点
    {
        Node* temp;
        // 没有子节点或只有一个子节点的情况
        if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            // 有两个子节点的情况，找到右子树中最小的节点替代当前节点
            Node* minValueNode = (*root)->right;
            while (minValueNode->left != NULL) {
                minValueNode = minValueNode->left;
            }

            (*root)->data = minValueNode->data;
            deleteNode(&((*root)->right), minValueNode->data);
        }


    }

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
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 8);
    insert(&root, 1);
    insert(&root, 6);

    printf("中序遍历树：");
    inorderTraversal(root);
    printf("\n");

    // 在树中查找节点
    Node* node = search(root, 6);
    if (node != NULL) {
        printf("找到节点：%d\n", node->data);
    }
    else {
        printf("未找到节点\n");
    }

    // 在树中删除节点
    deleteNode(&root, 3);

    printf("删除节点后的中序遍历树：");
    inorderTraversal(root);
    printf("\n");

    return 0;
}