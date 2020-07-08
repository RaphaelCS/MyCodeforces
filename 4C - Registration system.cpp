


#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;

#define CMD_LEN 40

typedef char ElementType;
struct AVLnode {

    AVLnode *parent, *Lchild, *Rchild;
    ElementType val[CMD_LEN];
    int height, num;

    AVLnode (ElementType *v) {
        strcpy(val, v);
        parent = Lchild = Rchild = NULL;
        height = num = 0;
    }

    bool operator< (const AVLnode b) {
        return strcmp (this->val, b.val) < 0 ;
    }

    bool operator> (const AVLnode b) {
        return strcmp (this->val, b.val) > 0 ;
    }

};

struct AVLtree {

    AVLnode *root;
    AVLtree (AVLnode *node) {
        root = node;
    }

    void insert (AVLnode *curr, AVLnode *node) {

        if ( *node < *curr ) {
            if ( curr->Lchild != NULL ) {
                insert (curr->Lchild, node);
            } else {
                curr->Lchild = node;
            }
        } else if ( *node > *curr ) {
            if ( curr->Rchild != NULL ) {
                insert (curr->Rchild, node);
            } else {
                curr->Rchild = node;
            }
        } else {
            curr->num ++;
            *node = *curr;
        }

        int L_h = curr->Lchild ? curr->Lchild->height : -1;
        int R_h = curr->Rchild ? curr->Rchild->height : -1;
        if ( abs(L_h - R_h) > 1 ) {
            Rotate (curr);
        }
        curr->height = max (L_h, R_h) + 1;

    }

    void Rotate(AVLnode *node) {

    }

};

int main ()
{
    int n;
    char cmd[CMD_LEN];
    scanf("%d", &n);

    scanf("%s", cmd);
    AVLnode *node = new AVLnode (cmd);
    AVLtree *Tree = new AVLtree (node);
    printf("OK\n");

    while ( --n ) {
        scanf("%s", cmd);
        node = new AVLnode (cmd);
        Tree->insert (Tree->root, node);
        
        if ( ! node->num ) {
            printf("OK\n");
        } else {
            printf("%s%d\n", node->val, node->num);
        }
    }
}
