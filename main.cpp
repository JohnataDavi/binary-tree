#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <fstream>
#include <windows.h>

#include "Node.h"
#include "Tree.h"

/*
+-----------------------------------------------+
|   Binary Tree             |                   |
|-----------------------------------------------|
|   NOME                    |   R.A.            |
|-----------------------------------------------|
|   Johnata Davi Teixeira S.|   2018010459      |
|-----------------------------------------------|
|   FUNCIONALIDADES                             |
|-----------------------------------------------|
|   - Inicializa                                | - OK
|   - Insere + Contador de Tempo                | - OK
|   - Remove                                    | - OK
|   - Pesquisa                                  | - OK
|   - Imprime (in-order)                        | - OK
|   - Imprime largura                           | - OK
|   - Altura                                    | - OK
+-----------------------------------------------+
|   GITHUB |   github.com/JohnataDavi           |
+-----------------------------------------------+

    Soluções para alguns dos problemas enfrentados:
        https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
        https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
        http://www.cplusplus.com/doc/oldtutorial/templates/
*/

using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0 ;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main(int argc, char *argv[])
{
//    ofstream out;
//    ifstream in;
//    int x = 500000, range = 999999;
    Tree<int> arv;
    int key = 300;                         // for int // variavel ultilizada pelo pesquisa e delete
    //float key = 10.7;                    // for float
    //char key = 'a';                      // for char
    string txt;


    // Criando um arquivo(input.txt) com valores aleatorios,
    // que posteriomente são ultilizados para inserção.
    /*
    srand (time(NULL));
    out.open("input.txt");
    StartCounter();
    while(x--){
        out<< rand() % range;
        out << endl;
        //arv.inserir(n);
        //cout << n << " ";
        //arv.inserir(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/range)));
    }
    cout << "Tempo gasto para inserir um elemento na arvore: " << GetCounter() <<"ms\n";

    x=500000;
    in.open("input.txt");

    StartCounter();
    while(x--){
        in >> key;
        arv.inserir(key);
    }
    cout << "Tempo gasto para inserir um elemento na arvore: " << GetCounter() <<"ms\n";
    out.close();
    */
    /*
    // float or double
    arv.inserir(10.7);
    arv.inserir(5.8);
    arv.inserir(3.1);
    arv.inserir(9.7);
    arv.inserir(12.6);
    arv.inserir(11.5);
    arv.inserir(15.5);
    arv.inserir(16.1);
    arv.inserir(17.2);
    arv.inserir(1.5);
    arv.inserir(8.9);
    arv.inserir(7.3);
    */
    // int
    StartCounter();
    arv.inserir(300);
    cout << "Tempo gasto para inserir um elemento na arvore: " << GetCounter() <<"ms\n";
    arv.inserir(200);
    arv.inserir(100);
    arv.inserir(50);
    arv.inserir(25);
    arv.inserir(250);
    arv.inserir(275);
    arv.inserir(400);
    arv.inserir(350);
    arv.inserir(500);
    arv.inserir(450);
    arv.inserir(600);
    arv.inserir(650);
    arv.inserir(475);
    arv.inserir(225);
    arv.inserir(125);
    arv.inserir(115);

    cout << "Tempo gasto para inserir todos elemento na arvore: " << GetCounter() <<"ms\n";

    cout << endl;
    arv.imprime(arv.getRaiz(), 0);

    cout << "\nProcurando pelo '" << key <<"'... ";
    bool encontrado = arv.searchKey(arv.getRaiz(), key);
    txt = (encontrado) ? "Encontrado!" : "Nao encontrado!";
    cout << txt;

    if(encontrado){
        arv.deleteNode(arv.getRaiz(), key);
        cout << "\nNo '" << key << "' deletado!";
        cout << "\nProcurando pelo '" << key << "'... ";
        txt = (arv.searchKey(arv.getRaiz(), key)) ? "Encontrado!" : "Nao encontrado!";
        cout << txt << endl;
    }

    cout << endl << endl;
    arv.imprime(arv.getRaiz(), 0);

    cout << "\nPercurso em Largura:\n";
    //arv.printLevelOrder(arv.getRaiz());
    arv.printLargura();

    int h = arv.height(arv.getRaiz());
    cout << "\nAltura: " << h << endl;

    cout << "\nEm ordem: ";
    arv.emOrdem(arv.getRaiz());

    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
