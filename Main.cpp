#include<iostream>
#include <cstdlib>
#include "OrderedList.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "Livro.h"
using namespace std;

void limparTela() {
    system("cls");
}

void aguardarEntrada() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void exibirLivro(Livro l){
    cout<<"\n---------------------------------------"<<endl;
    cout<<"Informacoes do livro buscado:"<<endl;
    cout<<"Titulo: "<<l.titulo<<endl;
    cout<<"Autor: "<<l.autor<<endl;
    cout<<"Editora: "<<l.editora<<endl;
    cout<<"Genero: "<<l.genero<<endl;
    cout<<"Ano: "<<l.ano<<endl;
    cout<<"---------------------------------------"<<endl;
}

void printTitle(){
    cout<<"======================================"<<endl;
    cout<<"Gerenciamento de Acervo de Biblioteca"<<endl;
    cout<<"======================================"<<endl;
    cout<<endl;
}

void popular(int n, HashTable &hash, OrderedList &lista, AVLTree &tree){
    for(int i=0; i<n; i++){
        Livro novoLivro;
        novoLivro.ISBN=1000+i;
        novoLivro.titulo="titulo " + to_string(i);
        novoLivro.autor="autor " + to_string(i);
        novoLivro.editora="editora " + to_string(i);
        novoLivro.genero="genero " + to_string(i);
        novoLivro.ano=1;

        lista.insert(novoLivro);
        tree.insert(novoLivro);
        hash.insert(novoLivro);
    }
}

int main(){
    OrderedList lista;
    AVLTree tree;
    HashTable hash;

    //popular(500, hash, lista, tree);

    while(true){
        int op;
        limparTela();
        printTitle();
        cout << "[1] Cadastrar um livro\n[2] Remover um livro do catalogo\n[3] Buscar Livro por Lista\n[4] Buscar livro por AVLTree\n[5] Buscar livro por HashTable\n[6] Sair\n\nEscolha uma opcao: ";
        cin >> op;
        switch(op){
            case 1:{
                limparTela();
                printTitle();
                Livro l;
                cout << "Digite o codigo ISBN: ";
                cin >> l.ISBN;
                cout << "Digite o titulo: ";
                cin.ignore();
                getline(cin, l.titulo);
                cout << "Digite o(a) autor(a): ";
                getline(cin, l.autor);
                cout << "Digite a editora: ";
                getline(cin, l.editora);
                cout << "Digite o genero: ";
                getline(cin, l.genero);
                cout << "Digite o ano de publicacao: ";
                cin >> l.ano;
                lista.insert(l);
                tree.insert(l);
                hash.insert(l);
                aguardarEntrada();
                break;
            }
            case 2:{ 
                limparTela();
                printTitle();
                Livro l;
                cout << "Digite o codigo ISBN: "<<endl;;
                cin >> l.ISBN;
                if(lista.remove(l)==true && tree.remove(l) == true && hash.remove(l.ISBN, l) == true){

                    cout <<"\n-------------------------------------" << endl;
                    cout << "Livro removido do acervo." << endl;
                    cout <<"-------------------------------------" <<endl;
                }
                else{
                    cout <<"\n-------------------------------------" << endl;
                    cout<<"Livro nao esta presente no acervo.";
                    cout <<"-------------------------------------" <<endl;
                }
                aguardarEntrada();
                break;
            }
            case 3:{ 
                limparTela();
                printTitle();
                Livro l;
                int consultas;
                int ISBN;
                cout << "Digite o codigo ISBN: ";
                cin >> ISBN;
                if(lista.search(ISBN, l, consultas) == 0){
                    cout <<"\n-------------------------------------" << endl;
                    cout <<"Livro nao foi encontrado no acervo!" << endl;
                    cout <<"Foram feitas "<<consultas<<" consultas."<<endl;
                    cout <<"-------------------------------------" << endl;
                }
                else{
                    cout << "\nLivro encontrado na posicao " << lista.search(ISBN, l, consultas)<<" da lista.";
                    exibirLivro(l);
                }
                aguardarEntrada();
                break;
            }
            case 4:{ 
                limparTela();
                printTitle();
                Livro l;
                int consultas;
                int ISBN;
                cout << "Digite o codigo ISBN: ";
                cin >> ISBN;
                if(tree.search(ISBN, l, consultas) == 0){
                    cout <<"\n-------------------------------------" << endl;
                    cout <<"Livro nao foi encontrado no acervo!" << endl;
                    cout <<"Foram feitas "<<consultas<<" consultas."<<endl;
                    cout <<"-------------------------------------" << endl;
                }
                else{
                    cout << "\nLivro encontrado!";
                    exibirLivro(l);
                }
                aguardarEntrada();
                break;
            }
            case 5:{ 
                limparTela();
                printTitle();
                int consultas;
                Livro l;
                int k;
                cout << "Digite o codigo ISBN: ";
                cin >> k;
                if(hash.search(k, l, consultas) != -1){
                    cout << "\nLivro encontrado!";
                    exibirLivro(l);
                }
                else{
                    cout <<"\n-------------------------------------" << endl;
                    cout <<"Livro nao foi encontrado no acervo!" << endl;
                    cout <<"Foram feitas "<<consultas<<" consultas."<<endl;
                    cout <<"-------------------------------------" << endl;
                }
                aguardarEntrada();
                break;
            }
            case 6:
                return 0;
                break;
        }
    }

    return 0;
}