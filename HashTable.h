#include<string>
#include "Livro.h"
using namespace std;

typedef Livro HashEntry;
typedef int HashKey;
class HashTable{
    public:
        HashTable();
        ~HashTable();
        bool full();
        bool empty();
        int size(); 
        float loadFactor();
        int insert(HashEntry x);
        int search(HashKey k, HashEntry &x, int &consultas);
        bool remove(HashKey k, HashEntry &x);
        void clear(); 

    private:
    
        struct HashSlot {
            HashEntry entry;
            HashSlot* next;
        };

        static const int MaxList = 101;
        int count;   

        HashSlot* table[MaxList];

        int hash(HashKey k); 
};

