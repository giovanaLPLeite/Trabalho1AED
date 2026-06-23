#ifndef AVLTREE_H
#define AVLtree_H

#include <iostream>
#include "Livro.h"
using namespace std;

typedef Livro TreeEntry;

class AVLTree {
public:
    AVLTree();                          
    ~AVLTree();                        
    bool empty();                       
    bool full();                        
    void clear();                       

    bool search(TreeEntry x);           
    void insert(TreeEntry x);          
    bool remove(TreeEntry x);          
    
    void preOrder();
    void inOrder();
    void postOrder();
    int nodes();                        
    int height();                       
    void print();                       

private:
    struct TreeNode;
    typedef TreeNode* TreePointer;

    struct TreeNode {
        TreeEntry entry;
        int count;                      
        int bal;                        
        TreePointer leftNode, rightNode;
    };

    TreePointer root;                  

    
    void clear(TreePointer &t);
    bool rSearch(TreeEntry x, TreePointer t);
    
    
    void searchInsert(TreeEntry x, TreePointer &pA, bool &h);
    
    
    bool remove(TreeEntry x, TreePointer &p, bool &h);
    void removeMin(TreePointer &q, TreePointer &r, bool &h);
    
    void balanceL(TreePointer &pA, bool &h); 
    void balanceR(TreePointer &pA, bool &h); 
    
    int nodes(TreePointer t);
    int height(TreePointer t);
    void print(TreePointer t, int s);
    void preOrder(TreePointer t);
    void inOrder(TreePointer t);
    void postOrder(TreePointer t);
};

#endif
