#include "HashTable.h"
#include <iostream>

HashTable::HashTable(){
    count=0;
    for(int i=0; i<MaxList; i++){
        table[i]=NULL;
    }
}

HashTable::~HashTable(){
    clear();
}

int HashTable::hash(HashKey k){
    return k % MaxList;
}

bool HashTable::full(){
    return false;
}

bool HashTable::empty(){
    return count==0;
}

int HashTable::size(){
    return count;
}

float HashTable::loadFactor(){
    return static_cast<float>(count) / MaxList;
}

void HashTable::clear(){
    for(int i=0;i<MaxList;i++){
        HashSlot* current = table[i];
        while (current != NULL){
            HashSlot* deletar = current;
            current = current->next;
            delete deletar;
        }
        table[i]=NULL;
    }
    count=0;
}

int HashTable::insert(HashEntry x){
    int index = hash(x.ISBN);

    HashSlot* newHS = new HashSlot;

    newHS->entry=x;
    newHS->next=table[index];
    table[index]=newHS;

    count++;
    return index;
}

int HashTable::search(HashKey k, HashEntry &x, int &consultas){
    int index = hash(k);
    HashSlot* current = table[index];

    consultas = 0;

    while(current!=NULL){
        consultas++;
        if(current->entry.ISBN==k){
            x=current->entry;
            return index;
        }
        current = current->next;
    }
    return -1; //não foi encontrado
}

bool HashTable::remove(HashKey k, HashEntry &x){
    int index = hash(k);
    HashSlot* current = table[index];
    HashSlot* previous = NULL;

    while (current!=NULL){
        if(current->entry.ISBN==k){
            x=current->entry;
            if(previous==NULL){
                table[index]=current->next;
            }
            else{
                previous->next=current->next;
            }

            delete current;
            count--;
            return true;
        }
        previous=current;
        current=current->next;
    }

    return false;
}