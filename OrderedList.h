#include<string>
#include "Livro.h"
using namespace std;

typedef Livro ListEntry;
class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        void insert(ListEntry x);
        bool remove(ListEntry x);
        bool full();
        bool empty();
        int search(int x, Livro &l, int &consultas);
        void clear();
        int size();
    private:
        static const int MaxList = 1000;
        int count;
        ListEntry entry[MaxList+1];
};
