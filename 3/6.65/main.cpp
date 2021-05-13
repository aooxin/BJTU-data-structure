#include <stdio.h>
#include <malloc.h>

typedef char elemtype;
typedef struct BTNode {
    elemtype data;
    struct BTNode* Lchild, * Rchild;
}BiTNode, * BiTree;

void print(BiTree bt)
{
    if (bt != NULL)
    {
        printf("%c", bt->data);
        print(bt->Lchild);
        print(bt->Rchild);
    }
}
int Search(char ino[], char a)
{
    int i = 0;
    while (ino[i])
    {
        if (a == ino[i])
            return i;
        else
            i++;
    }
}
void CrtBT(BiTree& T, char pre[], char ino[],int ps, int is, int n) 
{
    // pre 先序序列，
    // ino 中序序列,,ps为先序序列的开始位置，is为中序序列的开始位置，n为序列长度'
    int k;
    if (n == 0) 
        T = NULL;
    else {
        k = Search(ino, pre[ps]); //查询先序序列中的第一个字符在中序序列中的位置
        if (k == -1)  T = NULL;
        else 
        {
            T = (BiTNode*)malloc(sizeof(BiTNode));
            T->data = pre[ps];        //建立树根
            if (k == is) 
                T->Lchild = NULL; //先序序列中第一个字符在中序序列中也是第一个字符，则表示没有左子树
            else 
                CrtBT(T->Lchild, pre, ino,ps + 1, is, k - is);
            if (k == is + n - 1)
                T->Rchild = NULL; //先序序列中第一个字符在中序序列中是最后一个字符，则表示没有右子树
            else 
                CrtBT(T->Rchild, pre, ino, ps + 1 + (k - is), k + 1, n - (k - is) - 1);

        }
    }
}  
int main()
{
    int n=11,ps=0,is=0;
    char pre[] = { 'E','B','A','D','C','F','H','G','I','K','J' };
    char ino[] = { 'A','B','C','D','E','F','G','H','I','J','K' };
    BiTree tree;
    CrtBT(tree, pre, ino, ps, is,n);
    print(tree);

    return 0;
}

