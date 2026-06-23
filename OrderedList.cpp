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
    if(full()){
        cout << "Lista Cheia" << endl;
        abort();
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
ListEntry OrderedList::remove(ListEntry x){
    int i, p;
    if(empty()){
        cout << "Lista Vazia" << endl;
        abort();
    }
    p = search(x);
    if(p == 0){
        return;
    }
    for(i = p; i < count; i++){
        entry[i] = entry[i+1];
    }
    count--;
}
bool OrderedList::empty(){
    return(count == 0);
}
bool OrderedList::full(){
    return (count == MaxList);
}
int OrderedList::search(ListEntry x){
    int m, L = 1, R = count;
    while(L < R){
        m = (R + L)/2;
        if(entry[m].ISBN < x.ISBN){
            L = m + 1;
        }
        else{
            R = m;
        }
    }
    return (entry[R].ISBN != x.ISBN ? 0 : R);
}
void OrderedList::clear(){
    count = 0;
}
int OrderedList::size(){
    return count;
}