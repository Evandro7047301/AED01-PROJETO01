#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//---------------------------Evandro--------------------------------------------

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

    cout << traduzirString();
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






    // const int TAM = 100;
    // char vetor[][4] = {":::","A",".::","B",":.:","C","::.","D",":..","E",".:.","F","..:","G","...","H","|::","I",":|:","J","::|","K","|.:","L",".|:","M",".:|","N","|:.","O",":|.","P",":.|","Q","|..","R",".|.","S","..|","T",".||","U","|.|","V","||.","W","-.-","X",".--","Y","--.","Z","---"," ","~","~"};
    // string traduzido;
    //
    // string recebido;
    //
    // while(true){
    //
    //     getline(cin, recebido);
    //     if(recebido == "~"){
    //         traduzido += "~";
    //         break;
    //     }
    //     traduzido += traduzirLinha(recebido, vetor) + "\n";
    // }
    // cout<<traduzido;


}
//---------------------------Evandro--------------------------------------------
