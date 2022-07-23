// 이진탐색트리 및 운행법

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINS

typedef struct NODE btree;

struct NODE{
    int data;
    btree *left;      // 좌측 포인트
    btree *right;     // 우측 포인터
} *ROOT = NULL;

btree *make_tree(btree *root, int Key){            // 이진탐색트리 생성(새로운 자료 삽입)
    if(root == NULL){
        root = (btree *)malloc(sizeof(btree));
        root->data = Key;
        root->left = root->right = NULL;
    }
    else if(Key < root->data)
        root->left = make_tree(root->left, Key);
    else
        root->right = make_tree(root->right, Key);
    return root;
}

void preorder(btree *root){            // 전위운행 (중,좌,우)
    if(root){
        printf("%3d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(btree *root){            // 중위운행 (좌,중,우)
    if(root){
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}

void postorder(btree *root){            // 후위운행 (좌,우,중)
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->data);
    }
}

int main()
{
    int n;  // switch용
    int i; 
    int Key[] = {7, 8, 5, 4, 6, 9};
  
    btree *root = NULL;
  
    ROOT = make_tree(root,Key[0]);
    root = ROOT;
    for(i=1; i<6; i++)
        root = make_tree(root,Key[i]);  // 키 주어진 키로 트리 생성
        
    while(1){
        printf("\n\nPreorder : 1, Inorder : 2, Postorder : 3 => ");
        scanf("%d", &n);
        if(n>3) break;
        switch(n){
            case 1:
                preorder(root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
        }
    }
    return 0;
}
