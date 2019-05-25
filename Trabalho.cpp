#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
const int PRIMO = 37;
const int TAM = 7;
using namespace std;
//teste
//---------------------------Evandro--------------------------------------------

//----------------------------NÓ------------------------------------------------
template <class TYPE>
class No{
public:
    No(const TYPE &);
    TYPE getData()const;

    TYPE data;
    No<TYPE> *proximoPtr;//proximo no da lista
};

template<class TYPE>
No<TYPE>::No(const TYPE &info)
{
    data = info;
    proximoPtr = 0;
}

template<class TYPE>

TYPE No<TYPE>::getData()const{
    return data;
}
//----------------------------NÓ------------------------------------------------

//----------------------------LISTA---------------------------------------------
template<class TYPE>

class Lista{

public:
    Lista();//construtor
    ~Lista();//destrutor
    int tamanho;
    void inserirFrente(const TYPE &);
    void inserirAtras(const TYPE &);
    bool removerFrente(TYPE &);
    bool removerAtras(TYPE &);
    bool estaVazia()const;
    void print()const;
    string busca(const string &);
    string get(const int &);

private:
    No<TYPE> *primeiroPtr;
    No<TYPE> *ultimoPtr;

    //Alocar novo no;
    No<TYPE> *getNovoNo(const TYPE &);
};

//Construtor Padrao
template<class TYPE>
Lista<TYPE>::Lista(){
    tamanho = 0;
    primeiroPtr = 0;
    ultimoPtr = 0;
}

//Destrutor
template<class TYPE>

Lista<TYPE>::~Lista(){
    //Lista não está vazia
    if(!estaVazia()){
        No <TYPE> *atualPtr = primeiroPtr;
        No <TYPE> *temporarioPtr;
        //exclui nós restantes
        while(atualPtr != 0){
            temporarioPtr = atualPtr;
            atualPtr = atualPtr->proximoPtr;
            delete temporarioPtr;
        }
    }
}


//insere nó no inicio da lista
template<class TYPE>
void Lista<TYPE>::inserirFrente(const TYPE &valor){
    No<TYPE> *novoPtr = getNovoNo(valor); // novo nó

    //Lista está vazia
    if(estaVazia()){
        primeiroPtr = ultimoPtr = novoPtr; //nova lista tem apenas um nó
    }
    else{
        tamanho += 1;
        novoPtr->proximoPtr = primeiroPtr; // aponta o novo nó para o primeiro nó anterior
        primeiroPtr = novoPtr; //aponta primeiroPtr para o novo nó
    }
}

//insere nó no fim da lista
template<class TYPE>
void Lista<TYPE>::inserirAtras(const TYPE &valor){
    No<TYPE> *novoPtr = getNovoNo(valor); // novo nó

    //Lista está vazia
    if(estaVazia()){
        primeiroPtr = ultimoPtr = novoPtr; //nova lista tem apenas um nó
    }
    else{
        tamanho += 1;
        ultimoPtr-> proximoPtr = novoPtr; // atualiza o ultimo nó anterior
        ultimoPtr = novoPtr; //novo último nó
    }
}

//exclui nó do começo da lista
template<class TYPE>
bool Lista<TYPE>::removerFrente(TYPE &valor){
    //Lista está vazia
    if(estaVazia()){
        return false; //exclusao mal sucedida
    }
    else{
        No<TYPE> *temporarioPtr = primeiroPtr;//armazena temporarioPtr para excluir

        //Lista tem um elemento
        if(primeiroPtr == ultimoPtr){
            primeiroPtr = ultimoPtr = 0;//nenhum nó permanace depois da exclusao
        }
        else{
            primeiroPtr = primeiroPtr->proximoPtr;//aponta para segundo nó anterior
        }

        tamanho -= 1;
        valor = temporarioPtr->data;//retorna os dados sendo removidos
        delete temporarioPtr;//reinvidica nó frontal anterior
        return true;//exclusao bem sucedida;

    }
}


//exclui nó do fim da lista
template<class TYPE>
bool Lista<TYPE>::removerAtras(TYPE &valor){
    //Lista está vazia
    if(estaVazia()){
        return false; //exclusao mal sucedida
    }
    else{
        No<TYPE> *temporarioPtr = ultimoPtr;//armazena temporarioPtr para excluir

        //Lista tem um elemento
        if(primeiroPtr == ultimoPtr){
            primeiroPtr = ultimoPtr = 0;//nenhum nó permanace depois da exclusao
        }
        else{
            No<TYPE> *atualPtr = primeiroPtr;

            //localiza do segundo ao último elemento
            while(atualPtr->proximoPtr != ultimoPtr){
                atualPtr = atualPtr->proximoPtr;//move para próximo nó
            }

            ultimoPtr = atualPtr; //remove último nó
            atualPtr->proximoPtr = 0; //esse é o ultimo nó
        }

        tamanho -= 1;
        valor = temporarioPtr->data;//retorna valor do último nó antigo
        delete temporarioPtr;//reinvidiace o primeiro último nó
        return true;//exclusao bem sucedida;

    }
}

//Lista esta vazia?
template<class TYPE>
bool Lista<TYPE>::estaVazia()const{
    return primeiroPtr == 0;
}

//retorna ponteiro para nó recentemente alocado
template<class TYPE>
No<TYPE> *Lista<TYPE>::getNovoNo(const TYPE &valor){
    return new No<TYPE>(valor);
}

//exibe o conteúdo da Lista
template<class TYPE>
void Lista<TYPE>::print()const{
    if(estaVazia()){
        cout<< "A lista esta vazia"<<"\n";
        return;
    }

    No<TYPE> *atualPtr = primeiroPtr;

    while(atualPtr != 0){
        cout << atualPtr->data << ' ';
        atualPtr = atualPtr->proximoPtr;
        cout << "\n";

    }

}

template<class TYPE>
string Lista<TYPE>::busca(const string &chaveRecebida){

    No<TYPE> *atualPtr = primeiroPtr;

    // cout << atualPtr->data.chave;

    while(atualPtr != 0){
        if(atualPtr->data.chave == chaveRecebida){
            return atualPtr->data.simbolo;
        }
        atualPtr = atualPtr->proximoPtr;
    }

    return "-1";

}

template<class TYPE>
string Lista<TYPE>::get(const int &indice){

    No<TYPE> *atualPtr = primeiroPtr;

    // cout << atualPtr->data.chave;
    int contador = 0;

    while(atualPtr != 0){
        if(contador == indice){
            return atualPtr->data;
        }
        contador += 1;
        atualPtr = atualPtr->proximoPtr;
    }

    return "-1";

}

//----------------------------LISTA---------------------------------------------


//----------------------------PILHA---------------------------------------------
template<class TYPE>
//Pilha
class Pilha: private Lista<TYPE>{
public:
    void push(const TYPE &data){
        Lista<TYPE>::inserirFrente(data);
    }

    bool pop(TYPE &data){
        return Lista<TYPE>::removerFrente(data);
    }

    bool pilhaEstaVazia(){
        return Lista<TYPE>::estaVazia();
    }

    void printPilha()const{
        Lista<TYPE>::print();
    }
};
//----------------------------PILHA---------------------------------------------

//----------------------------FILA----------------------------------------------

template <class TYPE>
class Fila: private Lista<TYPE>{
public:

    void enfileira(const TYPE &data){
        Lista<TYPE>::inserirFrente(data);
    }

    bool desenfileira(TYPE &data){
        Lista<TYPE>::removerFrente(data);
    }

    bool filaEstaVazia(){
        return Lista<TYPE>::estaVazia();
    }

    void printFila()const{
        Lista<TYPE>::print();
    }
};

//----------------------------FILA----------------------------------------------


//----------------------------HASH----------------------------------------------

struct Dupla{
    string simbolo;
    string chave;
};


int strParaInt(string chave){
    int acumulador = 0;
    for(int i = 0; i < strlen(chave.c_str()); i++){
        acumulador += (int)chave[i];
    }
    acumulador *= PRIMO;
    return acumulador;
}

int h(string chave){

    return strParaInt(chave) % TAM;
}


class TabelaHash: Lista<Dupla>{

public:

    Lista<Dupla> th[TAM];

    TabelaHash(){
        for(int i = 0; i < TAM; i++){
            Lista<Dupla> lista;
            th[i] = lista;
        }

    }

    ~TabelaHash(){};

    void inserirElemento(const string &chave, const string &data){
        int i = h(chave);
        // cout<< "i:"<<i<<"\n";
        Dupla dupla = {data,chave};

        th[i].inserirAtras(dupla);
    }


     string buscarElemento(const string &chave){
        string chaveStr = chave;
        int i = h(chave);
        return th[i].busca(chaveStr);
    }



};

//----------------------------HASH----------------------------------------------
//---------------------------Evandro--------------------------------------------



//---------------------------Vinicius-------------------------------------------

//CODIGO AQUI

//---------------------------Vinicius-------------------------------------------





//---------------------------Evandro--------------------------------------------
string traduzirCaractere(string chave, TabelaHash &hash){
    // cout<<chave<<"/"<<"\n";
    return hash.buscarElemento(chave);
}

string traduzirLinha(string palavra, TabelaHash &hash){

    // cout<<"funcao"<<endl;
    // cout<< strlen(palavra.c_str()) << endl;


    string tmp = "";
    string traduzido = "";
    // cout<<strlen(palavra.c_str());

    for(int i = 0; i < strlen(palavra.c_str()); i++){
        tmp += palavra[i];
        // cout << tmp << endl;
        // cout << i;
        // cout<< i;
        if(strlen(tmp.c_str()) == 3){
            // cout << tmp << traduzirCaractere(tmp,dicionario) << endl;


            traduzido += traduzirCaractere(tmp, hash);
            // cout<< traduzido<< endl;
            tmp = "";
        }

    }
    return traduzido;

}

void traduzirString(TabelaHash &hash, Lista<string> &lista){
    // const int TAM = 100;
    // char vetor[][4] = {":::","A",".::","B",":.:","C","::.","D",":..","E",".:.","F","..:","G","...","H","|::","I",":|:","J","::|","K","|.:","L",".|:","M",".:|","N","|:.","O",":|.","P",":.|","Q","|..","R",".|.","S","..|","T",".||","U","|.|","V","||.","W","-.-","X",".--","Y","--.","Z","---"," ","~","~"};



    string traduzido = "";

    string recebido = "";

    while(true){


        getline(cin,recebido);

        if(recebido == "~"){
            lista.inserirAtras("~");
            break;
        }
        lista.inserirAtras(traduzirLinha(recebido, hash));
    }
}

//Struct auxiliar a funcao de reconhecer instrucoes
struct Intrucao{
    string comando;
    string letra;
};


int main(){
//---------------------------Evandro--------------------------------------------
    TabelaHash hash;

    // cout << dupla.chave;

    hash.inserirElemento (":::", "A");
    hash.inserirElemento (".::", "B");
    hash.inserirElemento (":.:", "C");
    hash.inserirElemento ("::.", "D");
    hash.inserirElemento (":..", "E");
    hash.inserirElemento (".:.", "F");
    hash.inserirElemento ("..:", "G");
    hash.inserirElemento ("...", "H");
    hash.inserirElemento ("|::", "I");
    hash.inserirElemento (":|:", "J");
    hash.inserirElemento ("::|", "K");
    hash.inserirElemento ("|.:", "L");
    hash.inserirElemento (".|:", "M");
    hash.inserirElemento (".:|", "N");
    hash.inserirElemento ("|:.", "O");
    hash.inserirElemento (":|.", "P");
    hash.inserirElemento (":.|", "Q");
    hash.inserirElemento ("|..", "R");
    hash.inserirElemento (".|.", "S");
    hash.inserirElemento ("..|", "T");
    hash.inserirElemento (".||", "U");
    hash.inserirElemento ("|.|", "V");
    hash.inserirElemento ("||.", "W");
    hash.inserirElemento ("-.-", "X");
    hash.inserirElemento (".--", "Y");
    hash.inserirElemento ("--.", "Z");
    hash.inserirElemento ("---", " ");
    hash.inserirElemento (":  ", ":");
    hash.inserirElemento ("~", "~");



    //------Teste da funcao traduzir string
    Lista<string> lista;
    traduzirString(hash, lista);
    lista.print();
    //------Teste da funcao traduzir string



    // cout << hash.busca(".::");

    // string a = "teste01";
    // string b = "teste01";
    //
    // string lista[2];
    // lista[0] = a;
    // lista[1] = b;
    //
    // cout<< lista[0];



    // hash.buscarElemtno(".::")



    // //TesteBusca
    // Lista<int> lista;
    // int numero = 0;
    // lista.inserirAtras(0);
    // int numero02 = 1;
    // cout<<lista.busca(1)<< "\n";
    // //TesteBusca

    // // //------TESTE-PILHA------
    // Pilha<int> pilha;
    // int numero = 1;
    // pilha.push(1);
    // pilha.printPilha();
    // pilha.push(1);
    // pilha.printPilha();
    // pilha.pop(numero);
    // pilha.printPilha();
    // pilha.pop(numero);
    // pilha.printPilha();
    // cout<<"\n";
    // cout << pilha.pilhaEstaVazia()<< "\n";
    // cout << "\n";
    // // // ------TESTE-PILHA-------

    // //------TESTE-FILA------
    // Fila<int> fila;
    // int numero01 = 1;
    // int numero02 = 2;
    // fila.enfileira(1);
    // fila.printFila();
    // fila.enfileira(1);
    // fila.printFila();
    // fila.desenfileira(numero02);
    // fila.printFila();
    // fila.desenfileira(numero01);
    // fila.printFila();
    // cout<<"\n";
    // cout << fila.filaEstaVazia()<< "\n";
    // cout << "\n";
    // //------TESTE-FILA-------



    //------Teste da funcao traduzir string
    // cout << traduzirString();
    //------Teste da funcao traduzir string

    //-dicionario-//
    // tabelaHash th;
    // th.insere (":::", "A");
    // th.insere (".::", "B");
    // th.insere (":.:", "C");
    // th.insere ("::.", "D");
    // th.insere (":..", "E");
    // th.insere (".:.", "F");
    // th.insere ("..:", "G");
    // th.insere ("...", "H");
    // th.insere ("|::", "I");
    // th.insere (":|:", "J");
    // th.insere ("::|", "K");
    // th.insere ("|.:", "L");
    // th.insere (".|:", "M");
    // th.insere (".:|", "N");
    // th.insere ("|:.", "O");
    // th.insere (":|.", "P");
    // th.insere (":.|", "Q");
    // th.insere ("|..", "R");
    // th.insere (".|.", "S");
    // th.insere ("..|", "T");
    // th.insere (".||", "U");
    // th.insere ("|.|", "V");
    // th.insere ("||.", "W");
    // th.insere ("-.-", "X");
    // th.insere (".--", "Y");
    // th.insere ("--.", "Z");
    // th.insere ("---", " ");
    // th.insere ("~", "~");
    //-dicionario-//
//---------------------------Evandro--------------------------------------------

//--------------------------Vinicius--------------------------------------------

//CODIGO AQUI

//--------------------------Vinicius--------------------------------------------

return 0;

}
