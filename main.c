#include "booky.c"

void main()
{
    struct TreeNode * root;
    initTreeNode( &root, 5);  // passed ptr again by ref bcz malloc inside fn, not outside
    treeNodeAdd( root, 7);
    treeNodeAdd( root, 8);
    treeNodeAdd( root, 1);
    treeNodeAdd( root, 2);
    treeNodeAdd( root, 4);
    treeNodeAdd( root, 0);
    treeNodeAdd( root, 9);
    treeNodeAdd( root, 6);
    observeTree( root);
    treeNodeDelete( root, 8);
    observeTree( root);
    treeNodeDelete( root, 6);
    treeNodeAdd( root, 13);
    observeTree( root);
}

