#include<iostream>
#include "OrderedList.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "Livro.h"
using namespace std;

int main(){
    OrderedList lista;
    AVLTree tree;
    HashTable hash;

    while(true){
        int op;
        cout << "1. Cadastrar um livro\n2. Remover um livro do catálogo\n 3. Buscar Livro por Lista\n4. Buscar livro por AVLTree\n 5. Buscar livro por HashTable\n 6. Sair\nEscolha uma opção: " << endl;
        cin >> op;
        switch(op){
            case 1:{
                Livro l;
                cout << "Digite o código ISBN: ";
                cin >> l.ISBN;
                cout << "Digite o título: ";
                cin.ignore();
                getline(cin, l.titulo);
                cout << "Digite o(a) autor(a): ";
                cin.ignore();
                getline(cin, l.autor);
                cout << "Digite a editora: ";
                cin.ignore();
                getline(cin, l.editora);
                cout << "Digite o ano de publicação: ";
                cin >> l.ano;
                lista.insert(l);
                tree.insert(l);
                hash.insert(l);
                break;
            }
            case 2:{ 
                Livro l;
                cout << "Digite o código ISBN: ";
                cin >> l.ISBN;
                cout << "Digite o título: ";
                cin.ignore();
                getline(cin, l.titulo);
                cout << "Digite o(a) autor(a): ";
                cin.ignore();
                getline(cin, l.autor);
                cout << "Digite a editora: ";
                cin.ignore();
                getline(cin, l.editora);
                cout << "Digite o ano de publicação: ";
                cin >> l.ano;
                lista.remove(l);
                tree.remove(l);
                hash.remove(l.ISBN, l);
                break;
            }
            case 3:{ 
                Livro l;
                cout << "Digite o código ISBN: ";
                cin >> l.ISBN;
                cout << "Digite o título: ";
                cin.ignore();
                getline(cin, l.titulo);
                cout << "Digite o(a) autor(a): ";
                cin.ignore();
                getline(cin, l.autor);
                cout << "Digite a editora: ";
                cin.ignore();
                getline(cin, l.editora);
                cout << "Digite o ano de publicação: ";
                cin >> l.ano;
                lista.search(l);
                break;
            }
            case 4:{ 
                Livro l;
                cout << "Digite o código ISBN: ";
                cin >> l.ISBN;
                cout << "Digite o título: ";
                cin.ignore();
                getline(cin, l.titulo);
                cout << "Digite o(a) autor(a): ";
                cin.ignore();
                getline(cin, l.autor);
                cout << "Digite a editora: ";
                cin.ignore();
                getline(cin, l.editora);
                cout << "Digite o ano de publicação: ";
                cin >> l.ano;
                tree.search(l);
                break;
            }
            case 5:{ 
                Livro l;
                cout << "Digite o código ISBN: ";
                cin >> l.ISBN;
                cout << "Digite o título: ";
                cin.ignore();
                getline(cin, l.titulo);
                cout << "Digite o(a) autor(a): ";
                cin.ignore();
                getline(cin, l.autor);
                cout << "Digite a editora: ";
                cin.ignore();
                getline(cin, l.editora);
                cout << "Digite o ano de publicação: ";
                cin >> l.ano;
                hash.search(l.ISBN, l);
                break;
            }
            case 6:
                return false;
                break;
        }
    }

    return 0;
}