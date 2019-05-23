#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//---------------------------Evandro--------------------------------------------

//----------------------------NÓ------------------------------------------------
template <class TYPE>
class No{
public:
    No(TYPE &);
    TYPE getData();

    TYPE data;
    No<TYPE> *proximoPtr;//proximo no da lista
};

template<class TYPE>
No<TYPE>::No(TYPE &info)
{
    data = info;
    proximoPtr = 0;
}

template<class TYPE>

TYPE No<TYPE>::getData(){
    return data;
}

template<class TYPE>

class Lista{

public:
    Lista();//construtor
    ~Lista();//destrutor

    void inserirFrente(TYPE &);
    void inserirAtras(TYPE &);
    bool removerFrente(TYPE &);
    bool removerAtras(TYPE &);
    bool estaVazia();
    void print();
private:
    No<TYPE> *primeiroPtr;
    No<TYPE> *ultimoPtr;

    //Alocar novo no;
    No<TYPE> *getNovoNo(TYPE &);
};
//----------------------------NÓ------------------------------------------------

//----------------------------LISTA---------------------------------------------
//Construtor Padrao
template<class TYPE>
Lista<TYPE>::Lista(){
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
void Lista<TYPE>::inserirFrente(TYPE &valor){
    No<TYPE> *novoPtr = getNovoNo(valor); // novo nó

    //Lista está vazia
    if(estaVazia()){
        primeiroPtr = ultimoPtr = novoPtr; //nova lista tem apenas um nó
    }
    else{
        novoPtr->proximoPtr = primeiroPtr; // aponta o novo nó para o primeiro nó anterior
        primeiroPtr = novoPtr; //aponta primeiroPtr para o novo nó
    }
}

//insere nó no fim da lista
template<class TYPE>
void Lista<TYPE>::inserirAtras(TYPE &valor){
    No<TYPE> *novoPtr = getNovoNo(valor); // novo nó

    //Lista está vazia
    if(estaVazia()){
        primeiroPtr = ultimoPtr = novoPtr; //nova lista tem apenas um nó
    }
    else{
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

        valor = temporarioPtr->data;//retorna valor do último nó antigo
        delete temporarioPtr;//reinvidiace o primeiro último nó
        return true;//exclusao bem sucedida;

    }
}

//Lista esta vazia?
template<class TYPE>
bool Lista<TYPE>::estaVazia(){
    return primeiroPtr == 0;
}

//retorna ponteiro para nó recentemente alocado
template<class TYPE>
No<TYPE> *Lista<TYPE>::getNovoNo(TYPE &valor){
    return new No<TYPE>(valor);
}

//exibe o conteúdo da Lista
template<class TYPE>
void Lista<TYPE>::print(){
    if(estaVazia()){
        cout<< "A lista está vazia"<<"\n";
        return;
    }

    No<TYPE> *atualPtr = primeiroPtr;

    while(atualPtr != 0){
        cout << atualPtr->data << ' ';
        atualPtr = atualPtr->proximoPtr;
    }

    cout << "\n";
}
//----------------------------LISTA---------------------------------------------


//----------------------------PILHA---------------------------------------------
template<class TYPE>
//Pilha
class Pilha: private Lista<TYPE>{
public:
    void push(TYPE &data){
        Lista<TYPE>::inserirFrente(data);
    }

    bool pop(TYPE &data){
        return Lista<TYPE>::removerFrente(data);
    }

    bool pilhaEstaVazia(){
        return Lista<TYPE>::estaVazia();
    }

    void printPilha(){
        Lista<TYPE>::print();
    }
};
//----------------------------PILHA---------------------------------------------

//---------------------------Evandro--------------------------------------------



//---------------------------Vinicius-------------------------------------------

// class Fila {
// private:
//     int* frente;
//     int* tras;
//     char letra_;
//
//     bool isEmpty();
// public:
//     Fila();
//     ~Fila();
//
//     void enfileira(char);
//     void desenfilera(char);
// };
//
// Fila::Fila(){
//     this->frente = new char;
//     this->frente.proximo = NULL;
//     this->tras = this->frente;
// }
//
// void Fila::enfileira(Node letra){
//     this->tras.proximo = new char;
//     this->tras = this->tras.proximo;
//     this->tras.letra_ = letra;
//     this->tras.proximo = NULL;
// }
//
// void Fila::desenfilera(Node letra){
//     aux = this->frente;
//     this->frente = this->frente.proximo;
//     letra = this->frente.letra_;
//     delete aux;
// }

/*      Fila Class endl */

//---------------------------Vinicius-------------------------------------------





//---------------------------Evandro--------------------------------------------
string traduzirCaractere(string chave, char dicionario[][4]){
    for(int i = 0; i < 56; i++){
        if(chave == dicionario[i]){
            return dicionario[i+1];
        }
    }
}

string traduzirLinha(string palavra, char dicionario[][4]){
    // cout<<"funcao"<<endl;
    // cout<< strlen(palavra.c_str()) << endl;


    string tmp = "";
    string traduzido = "";

    for(int i = 0; i < strlen(palavra.c_str()); i++){
        tmp += palavra[i];
        // cout << tmp << endl;
        // cout << i;
        if(strlen(tmp.c_str()) == 3){
            // cout << tmp << traduzirCaractere(tmp,dicionario) << endl;


            traduzido += traduzirCaractere(tmp, dicionario);
            // cout<< traduzido<< endl;
            tmp = "";
        }

        if((i + 1) == strlen(palavra.c_str()) && tmp == ":"){
            traduzido += tmp;
            break;
        }

    }
    return traduzido;

}

string traduzirString(){
    const int TAM = 100;
    char vetor[][4] = {":::","A",".::","B",":.:","C","::.","D",":..","E",".:.","F","..:","G","...","H","|::","I",":|:","J","::|","K","|.:","L",".|:","M",".:|","N","|:.","O",":|.","P",":.|","Q","|..","R",".|.","S","..|","T",".||","U","|.|","V","||.","W","-.-","X",".--","Y","--.","Z","---"," ","~","~"};

    string traduzido;

    string recebido;

    while(true){

        getline(cin, recebido);
        if(recebido == "~"){
            traduzido += "~";
            break;
        }
        traduzido += traduzirLinha(recebido, vetor) + "\n";
    }

    return traduzido;
}


int main(){
    
    //------TESTEPILHA------
    Pilha<int> pilha;
    int numero = 1;
    pilha.push(numero);
    pilha.printPilha();
    pilha.push(numero);
    pilha.printPilha();
    pilha.pop(numero);
    pilha.printPilha();
    pilha.pop(numero);
    pilha.printPilha();
    cout << pilha.pilhaEstaVazia()<< "\n";
    //------TESTEPILHA-------

    
    
    //------Teste da funcao traduzir string
    //cout << traduzirString();
    //------Teste da funcao traduzir string
    return 0;

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


}
//---------------------------Evandro--------------------------------------------
