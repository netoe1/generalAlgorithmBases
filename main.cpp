/*

Programa feito por Ely Torres Neto.
    Esse programa foi feito para testar as pontuações especiais do jogo General.

    Fluxo do programa
        1- Sortear valores pros 5 dados;
        2- Verificar o tipo de pontuação;
        3- Retornar no terminal o tipo de pontuação.
*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <locale>
#include <ctime>
#include <algorithm>

using namespace std;

void verificarGeneral(vector<int>&dados){
    int z = 0;
    for(int i = 0;i < dados.size() - 1;i++){
        if(dados[i] == dados[i + 1]){
            z++;
        }
    }

    if(dados.size() == z){
        cout << "GENERAL!" << endl;
    }
}

void verificarFula(vector<int>&dados){
    sort(dados.begin(),dados.end());

    if(dados[0] == dados[1] && dados[1] == dados[2] && (dados[2] !=  dados[3]) && dados[3] == dados[4] ||
        dados[0] == dados[1] && dados[2] != dados[3] && dados[2] == dados[3] && dados[3] == dados[4] 
    ){
        cout << "FULA!!" << endl;
    }

    // [0][1][2][3][4]
}

void verificarSequencia(vector<int>&dados){
    sort(dados.begin(),dados.end());

    if((dados[0] == 1 && dados[1] == 2 && dados[2] == 3 && dados[3] == 4  && dados[4] == 5) ||
        (dados[0] == 2 && dados[1] == 3 && dados[2] == 4 && dados[3] == 5 && dados[4] == 6) ||
        (dados[0] == 1 && dados[1] == 3 && dados[2] == 4 && dados[3] == 5  && dados[4] == 6)){
            cout << "SEQUENCIA!!" << endl;
        }
}

void verificarPoker(vector<int>&dados)
{
    sort(dados.begin(),dados.end());

    if(dados[0] == dados[1] && dados[1] == dados[2] && dados[2] == dados[3] && dados[4] != dados[3] ||
        dados[0] != dados[1] && dados[1] == dados[2] && dados[3] == dados[4] 
    ){
        cout << "POKER!";
    }
}

int main(void){
    setlocale(LC_ALL,"");
    srand(time(NULL));
    vector<int> dados;
    int sortear = rand() % 6;
    for(int i = 0; i < 5;i++){
        sortear = rand() % 6;
        if(sortear == 0){
            i--;
            sortear = rand() % 6;
        }
        else{
            dados.push_back(sortear);
        }

    }

    cout << "Dados sorteado:";
    for(int i = 0; i < dados.size();i++){
        cout << "[" << dados[i] << "] ";
    }
    cout << endl;

    verificarGeneral(dados);
    verificarFula(dados);
    verificarSequencia(dados);
    verificarPoker(dados);

}
