#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

int main() {
    int OP,i,NumerosSorteados[6],NumerosEscolhidos[6],Contador; //variável de opção, variável para função (for), vetor tipo Int para armazenar números
    char Nome[30]; //vetor tipo Char para colocar seu nome
    float Dinheiro; //variável que representa o dinheiro inicial do jogador
    bool Condicionador = false;   //pra aplicar uma condição de verdade ou falso  
    OP=0; Dinheiro=100; Contador=0;

    cout << "Antes de jogar, por favor digite seu nome: ";
    cin >> Nome;
    cout << "Ola " << Nome << "! Bem vindo a Diversao Virtual! Voce tem 100 reais para comecar sua diversão." << endl;

    do {
       cout << "========= Diversao Virtual =========" << endl;  
       cout << "1. MegaSena (RS20 para jogar)" << endl;
       cout << "2. Roleta da Sorte (RS10 de entrada para jogar)" << endl;
       cout << "3. Corrida de Cavalo (RS10 de entrada para jogar)" << endl;
       cout << "4. " << endl;
       cout << "5. " << endl;
       cout << "6. " << endl;
       cout << "7. Roleta Russa (RS50 para jogar)" << endl; 
       cout << "8. Sair" << endl;  
       if (Contador==0) {
        cout << "Voce apostou nenhuma vez." << endl; 
       } else if (Contador!=0) {
        cout << "Voce apostou " << Contador << " vezes ate agora." << endl;
       }
       cout << "Dinheiro atual: " << Dinheiro << " reais" << endl; 
       cout << "====================================" << endl; 
       cout << "Sua escolha: ";
       cin >> OP;
       switch (OP) {

        case 1:
            Dinheiro -= 20;
            cout << "-20 reais." << endl;
            cout << "Boa noite " << Nome << "! Vou gerar 6 numeros diferentes e se voce tem que acertar pelo menos um deles." << endl;
            srand(time(NULL));
            for (i=0;i<6;i++) {
                NumerosSorteados[i] = rand()%60+1;
            }
            cout << "Geracao aleatoria feita! Agora escreva os numeros: " << endl;
            for (i=0;i<6;i++) {
                cout << "Escreva o " << i+1 << "o numero: ";
                cin >> NumerosEscolhidos[i];
            } 
            cout << endl;
            for (i=0;i<6;i++) {
                cout << i+1 << "o numero sorteado: " << NumerosSorteados[i] << " / " << i+1 << "o numero escolhido: " << NumerosEscolhidos[i] << endl;
                if (NumerosSorteados[i]==NumerosEscolhidos[i]) {
                    Condicionador = true;
                    cout << endl << "Parabens, voce acertou o numero sorteado, na sua respectiva casa! +150 reais" << endl;
                    cout << endl;
                    Dinheiro = Dinheiro + 150;
                } else {
                    for (int j=0;j<6;j++) {
                    if (NumerosSorteados[i]==NumerosEscolhidos[j]) {                     
                        Condicionador = true;
                        cout << endl <<"Parabens, voce acertou o numero sorteado, mas nao foi na respectiva casa. +50 reais" << endl;
                        cout << endl;
                        Dinheiro = Dinheiro + 50; 
                        } 
                    }
                }
            }
            if (Condicionador==false) {      //se as estruturas condicionais não forem executadas, o Condicionador continuará como false, resultando na execução desta condição.
                cout << "Que pena! Parece que voce nao acertou nem um numero. Talvez na proxima voce consiga!" << endl;
            }
            Contador += 1;
        break;                   //final case 1

        case 2: 
            Dinheiro -= 10;
            
            Contador += 1;
        break;                  //final case 2

        case 7: 
            Dinheiro -= 50;
            cout << "Bem vindo a Roleta Russa! Nesse jogo, o programa ira gerar um numero aleatorio de 1 a 6 e voce tem que escolher entre atirar em si mesmo ou atirar no oponente." << endl;
            cout << "Voce começa com 3 vidas, cada vez q tu atirar em si mesmo e for verdadeira, voce perde uma vida e perde a vez, senão voce ganha um vez extra.";
        break;                  //final case 7
       
       default:
        if (OP>8) {
            cout << "Digite um numero valido." << endl;
            break;
        } else if (OP==8) {
            cout << "Saindo do jogo..." << endl;
            break;
        }
        break;
       }         //switch fecha-chave
    } while (OP!=8);          //do fecha-chave
    
    return 0;
}        //int main() fecha-chave