#include "AVLTree.h"
AVLTree::AVLTree(){
    root = NULL;
}                         

AVLTree::~AVLTree(){
    clear();
}

bool AVLTree::empty(){
    return root == NULL;
}  

bool AVLTree::full(){
    return false;
}

void AVLTree::clear(){
    clear(root);
    root = NULL;
}  

void AVLTree::clear(TreePointer &t){
    if(t != NULL){
        clear((*t).leftNode);
        clear((*t).rightNode);
        delete t;
    }
}

bool AVLTree::search(int x){
    return rSearch(x, root);
}  

bool AVLTree::rSearch(int x, TreePointer t) {
    if (t == NULL){
        return false;
    } 
    if (x < t->entry.ISBN){
        return rSearch(x, t->leftNode);
    }  
    if (x > t->entry.ISBN){
        return rSearch(x, t->rightNode); 
    } 
    return true; 
}

void AVLTree::insert(TreeEntry x){
    bool h = false;
    searchInsert(x, root, h);
} 

void AVLTree::searchInsert(TreeEntry x, TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    if (pA == NULL){ 
        pA = new TreeNode{x, 1, 0, NULL, NULL};
        h = true; 
    } 
    else if (x.ISBN < pA->entry.ISBN) {
        searchInsert(x, pA->leftNode, h);
        if(h){
            switch(pA->bal){
                case -1: 
                    pA->bal = 0;
                    h = false; 
                    break;
                case  0: 
                    pA->bal = +1;
                    break;     
                case +1: 
                    pB = pA->leftNode;
                    if(pB->bal == +1){
                        pA->leftNode = pB->rightNode; 
                        pB->rightNode = pA;
                        pA->bal = 0; 
                        pA = pB;
                    } 
                    else {
                        pC = pB->rightNode; 
                        pB->rightNode = pC->leftNode;
                        pC->leftNode = pB; 
                        pA->leftNode = pC->rightNode;
                        pC->rightNode = pA;
                        if(pC->bal == +1){
                            pA->bal = -1;
                        }  
                        else{
                            pA->bal = 0;
                        } 
                        if(pC->bal == -1){
                            pB->bal = +1;
                        }  
                        else{
                            pB->bal = 0;
                        } 
                        pA = pC;
                    }
                    pA->bal = 0;
                    h = false; 
                    break;
            }
        }
    } 
    else if(x.ISBN > pA->entry.ISBN){
        searchInsert(x, pA->rightNode, h);
        if (h){
            switch(pA->bal){
                case +1: 
                    pA->bal = 0;    
                    h = false; 
                    break;
                case  0: 
                    pA->bal = -1; 
                    break;   
                case -1: 
                    pB = pA->rightNode;
                    if(pB->bal == -1){
                        pA->rightNode = pB->leftNode; 
                        pB->leftNode = pA;
                        pA->bal = 0; 
                        pA = pB;
                    } 
                    else{ 
                        pC = pB->leftNode; 
                        pB->leftNode = pC->rightNode;
                        pC->rightNode = pB; 
                        pA->rightNode = pC->leftNode;
                        pC->leftNode = pA;
                        if(pC->bal == -1){
                            pA->bal = +1;
                        } 
                        else{
                            pA->bal = 0;
                        }
                        if(pC->bal == +1){
                            pB->bal = -1;
                        } 
                        else{
                            pB->bal = 0;
                        }
                        pA = pC;
                    }
                    pA->bal = 0; 
                    h = false; 
                    break;
            }
        }
    } else {
        pA->count++;
    }
}

bool AVLTree::remove(TreeEntry x){
    bool h = false;
    return remove(x, root, h);
} 

bool AVLTree::remove(TreeEntry x, TreePointer &p, bool &h) {
    TreePointer q;
    bool result;
    if (p == NULL) return false;

    if (x.ISBN < p->entry.ISBN) {
        result = remove(x, p->leftNode, h);
        if (h){
            balanceL(p, h);
        }
    } 
    else if(x.ISBN > p->entry.ISBN){
        result = remove(x, p->rightNode, h);
        if(h){
            balanceR(p, h);
        } 
    } 
    else{ 
        q = p;
        if (q->rightNode == NULL){ 
            p = q->leftNode; 
            h = true; 
        }
        else if(q->leftNode == NULL){ 
            p = q->rightNode; 
            h = true; 
        }
        else{
            removeMin(q, q->rightNode, h);
            if(h){
                balanceR(p, h);
            }
        }
        delete q;
        return true;
    }
    return result;
}

void AVLTree::removeMin(TreePointer &q, TreePointer &r, bool &h) {
    if (r->leftNode != NULL) {
        removeMin(q, r->leftNode, h);
        if(h){
            balanceL(r, h);
        }
    } 
    else{
        q->entry = r->entry; 
        q->count = r->count;
        q = r; 
        r = r->rightNode;
        h = true;
    }
}

void AVLTree::balanceL(TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    int balB, balC;
    switch (pA->bal) {
        case +1: 
            pA->bal = 0; 
            break;
        case  0: 
            pA->bal = -1; 
            h = false; 
            break;
        case -1:
            pB = pA->rightNode; 
            balB = pB->bal;
            if(balB <= 0){
                pA->rightNode = pB->leftNode;
                pB->leftNode = pA;
                if(balB == 0){ 
                    pA->bal = -1; 
                    pB->bal = +1; 
                    h = false; 
                }
                else{ 
                    pA->bal = 0; 
                    pB->bal = 0; 
                }
                pA = pB;
            } 
            else{
                pC = pB->leftNode; 
                balC = pC->bal;
                pB->leftNode = pC->rightNode; 
                pC->rightNode = pB;
                pA->rightNode = pC->leftNode; 
                pC->leftNode = pA;
                if(balC == -1){
                    pA->bal = +1;
                } 
                else{
                    pA->bal = 0;
                }
                if(balC == +1){
                    pB->bal = -1;
                } 
                else{
                    pB->bal = 0;
                }
                pA = pC; 
                pC->bal = 0;
            }
    }
}

void AVLTree::balanceR(TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    int balB, balC;
    switch (pA->bal) {
        case -1: 
            pA->bal = 0; 
            break;
        case  0: 
            pA->bal = +1; 
            h = false; 
            break;
        case +1:
            pB = pA->leftNode; 
            balB = pB->bal;
            if(balB >= 0){ 
                pA->leftNode = pB->rightNode; 
                pB->rightNode = pA;
                if(balB == 0){ 
                    pA->bal = +1; 
                    pB->bal = -1; 
                    h = false; 
                }
                else{ 
                    pA->bal = 0; 
                    pB->bal = 0; 
                }
                pA = pB;
            } 
            else{
                pC = pB->rightNode;
                balC = pC->bal;
                pB->rightNode = pC->leftNode; 
                pC->leftNode = pB;
                pA->leftNode = pC->rightNode; 
                pC->rightNode = pA;
                if(balC == +1){
                    pA->bal = -1;
                }
                else{
                    pA->bal = 0;
                }
                if(balC == -1){
                    pB->bal = +1;
                } 
                else{
                    pB->bal = 0;
                }
                pA = pC; 
                pC->bal = 0;
            }
    }
}

void AVLTree::preOrder(){
    preOrder(root); 
    cout << endl;
}

void AVLTree::preOrder(TreePointer t) {
    if (t != NULL){ 
        cout << t->entry.titulo << " "; 
        preOrder(t->leftNode); 
        preOrder(t->rightNode); 
    }
}

void AVLTree::inOrder(){
    inOrder(root); 
    cout << endl;
}

void AVLTree::inOrder(TreePointer t) {
    if (t != NULL){ 
        inOrder(t->leftNode); 
        cout << t->entry.titulo << " "; 
        inOrder(t->rightNode); 
    }
}

void AVLTree::postOrder(){
    postOrder(root); 
    cout << endl;
}

void AVLTree::postOrder(TreePointer t) {
    if (t != NULL){
        postOrder(t->leftNode); 
        postOrder(t->rightNode); 
        cout << t->entry.titulo << " "; 
    }
}

int AVLTree::nodes(){
    return nodes(root);
}

int AVLTree::nodes(TreePointer t){
    if (t == NULL){
        return 0;
    }
    return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}

int AVLTree::height(){
    return height(root);
}  

int AVLTree::height(TreePointer t) {
    if (t == NULL){
        return -1;
    }
    int L = height(t->leftNode), R = height(t->rightNode);
    return 1 + (L > R ? L : R);
}

void AVLTree::print(){
    print(root, 0);
}  

void AVLTree::print(TreePointer t, int s) {
    if (t != NULL){
        print(t->rightNode, s + 3);
        for (int i = 0; i < s; i++){
            cout << " ";
        }
        cout << t->entry.titulo << "(" << (t->bal > 0 ? "+" : "") << t->bal << ")" << endl;
        print(t->leftNode, s + 3);
    }
}

