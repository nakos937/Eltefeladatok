// Keszitette:  Nagy Ákos
// Email:       nakos1212@protonmail.com
#include<bits/stdc++.h>
using namespace std;

int preIndex = 0;
void printPost(char in[], char pre[], int inStrt,
               int inEnd, map<char, char> hm)
{
    if (inStrt > inEnd)
        return;

    // Find index of next item in preorder traversal in
    // inorder.
    int inIndex = hm[pre[preIndex++]];

    // traverse left tree
    printPost(in, pre, inStrt, inIndex - 1, hm);

    // traverse right tree
    printPost(in, pre, inIndex + 1, inEnd, hm);

    // print root node at the end of traversal
    cout << in[inIndex] << ";";
}

void printPostMain(char in[], char pre[],int n)
{
    map<char,char> hm ;
    for (int i = 0; i < n; i++)
    hm[in[i]] = i;

    printPost(in, pre, 0, n - 1, hm);
}

// Driver code
int main()
{
    char in[] = {'G','D','Z','H','N','M','C','E','T','I','A','B'};
    char pre[] = {'E','M','Z','G','D','N','H','C','I','T','B','A'};
    int n = sizeof(pre)/sizeof(pre[0]);

    printPostMain(in, pre, n);
    return 0;
}

