#include<string>
#include "Livro.h"
using namespace std;

typedef Livro ListEntry;
class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        void insert(ListEntry x);
        void remove(ListEntry x);
        bool full();
        bool empty();
        int search(int x);
        void clear();
        int size();
    private:
        static const int MaxList = 100;
        int count;
        ListEntry entry[MaxList+1];
};
