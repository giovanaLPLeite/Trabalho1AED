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
        float loadFactor();
        int insert(HashEntry x);
        int search(HashKey k, HashEntry &x);
        void remove(HashKey k, HashEntry &x);
        void clear();
        int size();
    private:
        enum EntryStatus { LIVRE, OCUPADO, REMOVIDO };
    
        struct HashSlot {
            HashEntry entry;
            EntryStatus status;
        };

        static const int MaxList = 101;
        int count;                   
        HashSlot table[MaxList];

        int hash(HashKey k); 
};
//nota: rever a parte privada
