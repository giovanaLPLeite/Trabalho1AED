#include "OrderedList.h"
#include <iostream>
using namespace std;
OrderedList::OrderedList(){
    count = 0;
}

OrderedList::~OrderedList(){
    cout << "Lista Ordenada destruída" << endl;
}

void OrderedList::insert(ListEntry x){
    int i, j;
    Livro l;
    int consultas;
    if(full()){
        cout << "Lista Cheia" << endl;
        abort();
    }

    if(search(x.ISBN, l, consultas)!=0){
        cout<<"\n-----------------------------------------------------------------"<<endl;
        cout<<"Erro: Um livro com o ISBN "<<x.ISBN<<" ja foi inserido no acervo."<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        return;
    }

    i = 1;
    while(i <= count && x.ISBN > entry[i].ISBN){
        i++;
    }
    for(j = count; j >= i; j--){
        entry[j+1] = entry[j];
    }
    entry[i] = x;
    count++;
}

bool OrderedList::remove(ListEntry x){
    int i, p;
    Livro l;
    int consultas;
    if(empty()){
        //cout << "Lista Vazia" << endl;
        //abort();
        return false;
    }
    p = search(x.ISBN, l, consultas);
    if(p == 0){
        //cout << "elemento não encontrado" << endl;
        //abort();
        return false;
    }
    for(i = p; i < count; i++){
        entry[i] = entry[i+1];
    }
    count--;
    //cout << "elemento removido da lista ordenada!" << endl;
    return true;
}

bool OrderedList::empty(){
    return(count == 0);
}

bool OrderedList::full(){
    return (count == MaxList);
}

int OrderedList::search(int x, Livro &l, int &consultas){
    int m, L = 1, R = count;
    consultas=0;

    while(L < R){
        consultas++;
        m = (R + L)/2;
        if(entry[m].ISBN < x){
            L = m + 1;
        }
        else{
            R = m;
        }
    }
    consultas++;
    if(entry[R].ISBN==x){
        l=entry[R];
        return R;
    }

    return 0;
}

void OrderedList::clear(){
    count = 0;
}

int OrderedList::size(){
    return count;
}