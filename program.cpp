#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <string>                                         //sem uso grande por enquanto
#include <windows.h>                                       //para ter a função Sleep()
using namespace std;

const int Linhas = 4; const int Colunas = 8;            //variáveis para o void

int maiorRepeticao(const int vetorArmazenador[], int tamanho) {
    unordered_map<int, int> contagem;  // dicionário valor -> quantidade
    int maxRep = 0;

    for (int i = 0; i < tamanho; i++) {
        contagem[vetorArmazenador[i]]++;            // conta cada número
        if (contagem[vetorArmazenador[i]] > maxRep) {
            maxRep = contagem[vetorArmazenador[i]];
        }
    }

    // Se o maior grupo for menor que 2, não conta como repetição
    return (maxRep >= 2 ? maxRep : 0);
}

void mostrarCorrida(bool corridaCavalo[Linhas][Colunas]) {                        //função secundária tipo void para que eu possa trabalhar na parte visual da corrida 
    for (int i=0; i<Linhas; i++) {                                           //sim, precisa declarar o i denovo
        cout << "Cavalo " << i + 1 << " | ";
        for (int j=0; j<Colunas; ++j) {
            cout << (corridaCavalo[i][j] ? ">" : "-") << " ";
        }
        cout << endl;
    }
    Sleep(1000);                                     //a função Sleep é em milissegundos, 1000ms são equivalentes a 1s, lembre-se disso!
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");                     //para aceitar acentuação
    int OP,i,j,NumerosSorteados[6],NumerosEscolhidos[6],Contador,girarTambor, VidaUsuario=3, VidaBot=3, escolhaBot, escolhaCavalo; 
    //variável de opção e opção 2, variável para função (for), vetor tipo Int para armazenar números, vida do usuário e do robô, variável de escolha do robô, variável de escolha do cavalo
    int progresso[Linhas] = { 0 }, vencedor = -1, Palpite = 0, NumeroEscolhido, jogadas, numeroAleatorio, palpiteAuxiliar = 0;
    int vetorArmazenador[5] = { 0 }, n = sizeof(vetorArmazenador) / sizeof(vetorArmazenador[0]);
    char Nome[30], s[3], R[3], atirarArmar, Resposta[3]; //vetor tipo Char para colocar seu nome, vetor para armazenar símbolos, vetor para armazenar resposta,
    float Dinheiro, apostaValor; //variável que representa o dinheiro inicial do jogador
    bool Condicionador = false, vencedorCorrida = false;   //pra aplicar uma condição de verdade ou falso  
    OP=0; Dinheiro=100; Contador=0;
    char megaSimbolo[165] = {'@','#','$','&','*','%','/','?','!','<','>','|','=','-', '_'};   //vetor gigante para mais simbolos da nova slot machine!
    vector<char> Simbolos = {'@','#','$','&','*','%','/','?','!'};                //vetor tipo char para armazenar símbolos (slot machine)
    bool revolver[6] = {false, false, false, false, false, false};                         //vetor tipo bool armazenando false em todas as posições
    bool corridaCavalo[4][8] = {
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},                        //matriz tipo bool armazendo false em todas as posições (de forma bem verbosa)
        {false, false, false, false, false, false, false, false}                         // uma opção menos verbosa seria *bool corridaCavalo[4][8] = { false };*
    };

    cout << "Antes de jogar, por favor digite seu nome: ";
    cin.getline(Nome, 30);
    Sleep(1000);
    if (strcmp(Nome, "adm.Engel09") == 0) {
        cout << "Seja bem vindo chefe!" << endl;
        Dinheiro = 999000;
    } else {
        cout << "Ola " << Nome << "! Bem vindo a Diversao Virtual! Voce tem 100 reais para comecar sua diversao." << endl;
    }
    Sleep(1250);

    do {                                                                                       //Menu Principal
       cout << endl; 
       cout << "========= Diversao Virtual =========" << endl;  
       cout << "1. MegaSena (RS20 de entreda)" << endl;                          //MegaSena de 1 a 60 
       cout << "2. Alavanca da Sorte (RS10 de entrada)" << endl;                  //Slot Machine 
       cout << "3. Corrida de Cavalo (RS15 de entrada)" << endl;                   //Corrida de Cavalos, você aposta no que achar ser o que vai chegar em primeiro
       cout << "4. Jogo da Adivinhacao (RS20 de entrada)" << endl;                  //Autoexplicativo
       cout << "5. EM PROGRESSO!!!! " << endl;
       cout << "6. Alavanca do Milhão (RS20 de entrada)" << endl;
       cout << "7. Roleta Russa (RS50 para jogar)" << endl;                                //Roleta Russa com chance de triplicar o valor de entrada
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
            if (Dinheiro<20) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                break;
            } else if (Dinheiro<=0) {
                cout << "GAME OVER! Voce ficou sem dinheiro para apostar!" << endl;
                return 0;
            }
            Condicionador = false;
            Dinheiro -= 20;
            cout << "-20 reais." << endl;
            Sleep(500);
            cout << "Boa noite " << Nome << "! Vou gerar 6 numeros diferentes e se voce tem que acertar pelo menos um deles." << endl;
            cout << endl;
            srand(time(NULL));
            for (i=0;i<6;i++) {
                NumerosSorteados[i] = rand()%60+1;                                       //Geração de 6 números aleatórios
            }
            Sleep(2000);
            cout << "Geracao aleatoria feita! Agora escreva os numeros. " << endl;
            Sleep(250);                      
            for (i=0;i<6;i++) {
                cout << "Escreva o " << i+1 << "o numero: ";                         //leitura de 6 números do usuário
                Sleep(500);
                cin >> NumerosEscolhidos[i];
                if (NumerosEscolhidos[i]>60) {
                    cout << "Escolha um numero entre 1 e 60!" << endl;
                    Sleep(500);
                    cout << "Escreva o " << i+1 << "o numero: ";
                    cin >> NumerosEscolhidos[i];
                    Sleep(1000);
                }
            } 
            cout << endl;
            for (i=0;i<6;i++) {
                cout << i+1 << "o numero sorteado: " << NumerosSorteados[i] << " / " << i+1 << "o numero escolhido: " << NumerosEscolhidos[i] << endl;
                Sleep(1000);
                if (NumerosSorteados[i]==NumerosEscolhidos[i]) {
                    Condicionador = true;
                    cout << endl << "Parabens, voce acertou o numero sorteado, na sua respectiva casa! +100 reais" << endl;                 //Caso acerte o numero junto da casa
                    cout << endl; 
                    Sleep(650);
                    Dinheiro = Dinheiro + 100;
                } else {
                    for (j=0;j<6;j++) {
                    if (NumerosSorteados[i]==NumerosEscolhidos[j]) {                     
                        Condicionador = true;
                        cout << endl <<"Parabens, voce acertou o numero sorteado, mas nao foi na respectiva casa. +30 reais" << endl;        //Caso acerte o número apenas
                        cout << endl;
                        Sleep(650);
                        Dinheiro = Dinheiro + 30; 
                        } 
                    }
                }
            }
            if (Condicionador==false) {      //se as estruturas condicionais não forem executadas, o Condicionador continuará como false, resultando na execução desta condição.
                Sleep(1000);
                cout << "Que pena! Parece que voce nao acertou nem um numero. Talvez na proxima voce consiga!" << endl;      //Caso não acerte nada
                Sleep(500);
            }
            cout << endl;
            Contador += 1;
        break;                   //final case 1

        case 2: 
            Dinheiro -= 10;
            if (Dinheiro<10) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                Sleep(500);
                break;
            } else if (Dinheiro<=0) {
                cout << "GAME OVER! Voce ficou sem dinheiro para apostar!" << endl;
                Sleep(500);
                return 0;
            }
            cout << "-10 reais." << endl;
            Sleep(250);
            cout << "Bem vindo a Alavanca da Sorte " << Nome << "! Basta inserir uma aposta que desejar e caso venca, essa aposta volta para voce em dobro, mas caso perca a aposta fica com a gente." << endl;
            Sleep(1000);
            cout << "Cada valor tem um numero de vezes que voce pode puxar a alavanca, aqui vai uma tabela de precos com as jogadas." << endl;
            Sleep(500);
            do {                                                                          //começo do "do"
                cout << endl;
                cout << "========= Tabela de Valores =========" << endl;
                cout << "10 reais = 1 jogada." << endl;
                cout << "20 reais = 2 jogadas." << endl;
                cout << "40 reais = 3 jogadas." << endl;
                cout << "60 reais = 4 jogadas." << endl;
                cout << "100+ reais = 5 jogadas." << endl;
                cout << "Digite 0 para desistir (sem retorno do valor de entrada)." << endl;                //Menu de valores da aposta
                cout << "=====================================" << endl;
                Sleep(500);
                cout << "Qual vai ser o valor da sua aposta? "; 
                cin >> apostaValor;
                cout << endl; 
                if (apostaValor==10) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;                                     //interação simples com o jogador
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    cout << endl; 
                    Sleep(800);                                    
                    for (i=0;i<1;i++) {
                        cout << "Simbolos sorteados: ";
                        Sleep(500);
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];                    //sorteia 3 simbolos aleatoriamente
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2] && s[1]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;      
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;
                            cout << endl;   
                            Sleep(750);                                      
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2] && s[1]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]==s[2] && s[0]!=s[1] && s[1]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[1]==s[2] && s[2]!=s[0] && s[0]!=s[1]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true; 
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                            Sleep(500);
                        }
                    }                                                      //terminação do primeiro "for"
                }                                                     //terminação da primeira condição de valor da aposta

                if (apostaValor==20) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    Sleep(800);
                    for (i=0;i<2;i++) {
                        cout << "Simbolos sorteados: ";
                        Sleep(500);
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;  
                            Sleep(500);    
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;  
                            cout << endl; 
                            Sleep(750);                                      
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                            Sleep(500);
                        }
                        if (i==0) {                                                     //pergunta para não começar instantaneamente a segunda tentativa
                            cout << "Vamos para a segunda tentativa do senhor? ";
                            cin >> R;
                            cout << endl;
                        }
                    }                                               //terminação do segundo "for"
                }                                                //terminação da segunda condição de valor da aposta

                if (apostaValor==40) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    Sleep(800);
                    for (i=0;i<3;i++) {
                        cout << "Simbolos sorteados: ";
                        Sleep(500);
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl; 
                            Sleep(500);     
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;
                            cout << endl;         
                            Sleep(750);                                
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                            Sleep(500);
                        }
                        if (i==1 || i==0) {                                                     //pergunta para não começar instantaneamente a segunda/terceira tentativa
                            if (i==0) {
                                cout << "Vamos para a " << i+2 << "a tentativa do senhor? ";
                            } else if (i==1){
                                cout << "Vamos para a " << i+2 <<"a tentativa do senhor? ";
                            } else 
                                cout << "Vamos para a " << i+1 << "a tentativa do senhor? ";
                            cin >> R;
                            if (R[0]=='n' || R[0]=='N') {
                                cout << "Ok, vamos cancelar as tentativas." << endl;
                                Sleep(500);
                                break;
                            }
                            cout << endl;
                        }
                    }                                               //terminação do terceiro "for"
                }                                                //terminação da terceira condição de valor da aposta

                if (apostaValor==60) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    Sleep(800);
                    for (i=0;i<4;i++) {
                        cout << "Simbolos sorteados: ";
                        Sleep(500);
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl; 
                            Sleep(500);     
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;
                            cout << endl;
                            Sleep(750);                                         
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                            Sleep(500);
                        }
                        if (i==2 || i==1 || i==0) {                                               //pergunta para não começar instantaneamente a segunda/terceira/quara tentativa
                            if (i==0) {
                                cout << "Vamos para a " << i+2 << "a tentativa do senhor? ";
                            } else if (i==1) {
                                cout << "Vamos para a " << i+2 <<"a tentativa do senhor? ";
                            } else 
                                cout << "Vamos para a " << i+1 << "a tentativa do senhor? ";
                            cin >> R;
                            if (R[0]=='n' || R[0]=='N') {
                                cout << "Ok, vamos cancelar as tentativas." << endl;
                                Sleep(500);
                                break;
                            }
                            cout << endl;
                        }
                    }                                               //terminação do quarto "for"
                }                                                //terminação da quarta condição de valor da aposta

                if (apostaValor>=100) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;                                                           //interação com o jogador
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    Sleep(600);
                    for (i=0;i<5;i++) {
                        cout << "Simbolos sorteados: ";
                        Sleep(500);
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;    
                            Sleep(500);  
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;
                            cout << endl;                    
                            Sleep(750);                     
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && (s[0]!=s[2] && s[1]!=s[2])) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            Sleep(500);
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            cout << endl;
                            Sleep(750);
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                            Sleep(800);
                        }
                        if (i==3 || i==2 ||i==1 || i==0) {                                                     //pergunta para não começar instantaneamente a próxima tentativa
                            if (i==0) {                                                                       
                                cout << "Vamos para a " << i+2 << "a tentativa do senhor? ";                  
                            } else if (i==1) {
                                cout << "Vamos para a " << i+2 <<"a tentativa do senhor? ";                    //pequena interação com o jogador
                            } else 
                                cout << "Vamos para a " << i+1 << "a tentativa do senhor? ";
                            cin >> R;
                            if (R[0]=='n' || R[0]=='N') {
                                cout << "Ok, vamos cancelar as tentativas." << endl;
                                Sleep(500);
                                break;
                            }
                            cout << endl;
                        }
                    }                                               //terminação do quinto "for"
                }                                                //terminação da quinta condição de valor da aposta

                if (apostaValor==0) {                     //condição de desistência
                    cout << "Voce escolheu desistir do jogo. Voltando ao menu principal." << endl;
                    Contador +=1;
                    Sleep(500);
                    break;
                }

                if (apostaValor<10 || (apostaValor>10 && apostaValor<20) || (apostaValor>20 && apostaValor<40) || (apostaValor>40 && apostaValor<100) ) {
                    cout << "Digite um valor valido camarada." << endl;
                    Sleep(500);
                    cout << "Qual vai ser o valor da sua aposta? "; 
                    cin >> apostaValor;
                    Sleep(500);
                }

            } while (apostaValor!=0);                         //condição da função "do"
            cout << endl;
        break;                       //final case 2

        case 3: 
            if (Dinheiro<15) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;                //Caso o jogador não tenha dinheiro para pagar a entrada
                Sleep(500);
                break;
            } else if (Dinheiro<=0) {
                cout << "GAME OVER! Voce ficou sem dinheiro para apostar!" << endl;
                Sleep(500);
                return 0;
            }
            Dinheiro -= 15;
            apostaValor = 0; vencedor = -1; vencedorCorrida = false; 
            srand(time(NULL));
            cout << "-15 reais." << endl;
            cout << "Boa noite " << Nome << "! Esta e uma corrida de cavalos. Aqui voce apostara no cavalo que voce acha que vai ganhar." << endl;
            Sleep(1150);
            cout << "Caso seu cavalo ganhe, teu dinheiro apostado sera dobrado. Senao, voce so perdera seu dinheiro mesmo." << endl;
            Sleep(1000);
            cout << endl << "Qual vai ser o seu cavalo? (1, 2, 3 ou 4) ";
            cin >> escolhaCavalo;
            Sleep(500);
            cout << endl << "Quanto sera apostado nele? ";
            cin >> apostaValor;
            Sleep(650);
            if (apostaValor>Dinheiro) {
                do {
                    cout << "O senhor nao possui esse dinheiro para apostar." << endl;
                    Sleep(750);
                    cout << "Quanto sera apostado nele? ";
                    cin >> apostaValor;
                    Sleep(250);
                } while (apostaValor>0 );
            } else {
                Dinheiro -= apostaValor;
            }

            cout << endl << "Apostas feitas, vamos dar inicio a corrida. 3, 2, 1. **BANG**" << endl;
            cout << "APROVEITEM O ESPETACULO!" << endl;
            srand(time(NULL) + rand());                                //evita que o mesmo cavalo ganhe

            for (int i = 0; i < Linhas; i++) {
                progresso[i] = 0;                                     //zera a posição dos cavalos
                for (int j = 0; j < Colunas; j++) {
                    corridaCavalo[i][j] = false;                    //limpa a parte visual
                }
            }

            while (!vencedorCorrida) {
                for (i=0; i<Linhas; i++) {
                    if (progresso[i]<Colunas) {
                        if (rand() % 2 == 0) {
                            corridaCavalo[i][progresso[i]] = true;                //preguiça de explicar isso
                            progresso[i]++;
                        }
                    }
                    if (progresso[i] == Colunas) {
                        vencedorCorrida = true;
                        vencedor = i;
                        break;
                    }   
                }
                mostrarCorrida(corridaCavalo);                              //mostra a parte visual do negócio todo
            }               //while fecha-chave

            cout << "Cavalo " << vencedor + 1 << " venceu a corrida!" << endl;
            if (vencedor+1==escolhaCavalo) {
                apostaValor = apostaValor * 2;
                Dinheiro = Dinheiro + apostaValor;
                cout << "Voce ganhou, parabens! Sua aposta foi dobrada e devolvida ao seu bolso." << endl;   
                Sleep(500);                     
            } else {
                cout << "Bom, nao da para esperar que va ganhar todas ne?" << endl;
                Sleep(500);
            }
            break;                                                                   //final case 3
        
        case 4:
            VidaUsuario = 5;
            if (Dinheiro<20) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                Sleep(500);
                break;
            }
            Dinheiro -= 20;
            cout << "-20 reais" << endl;
            cout << "As regras sao simples, voce tem 5 chances de acertar o numero que a maquina esta pensando entre 1 e 20." << endl;
            Sleep(1333);
            cout << "Se voce acertar, ganha o dobro do valor da entrada." << endl;
            Sleep(888);
            cout << "Boa sorte, voce vai precisar." << endl;
            cout << endl;
            Sleep(200);

            srand(time(0));
            NumeroEscolhido = rand() % 20 + 1;
            for (i=0;i<=5;i++) {
                if (VidaUsuario==0) {
                    cout << "Voce ficou sem palpites!" << endl;
                    Sleep(500);
                    cout << "O numero certo era: " << NumeroEscolhido << endl;
                    Sleep(100);
                    break;
                }
                cout << "Qual vai ser seu " << i+1 << "o palpite: ";
                cin >> Palpite;
                if (Palpite==NumeroEscolhido) {
                    Sleep(1000);
                    cout << "Parabens! Voce acertou o numero!" << endl;
                    Sleep(300);
                    break;
                } else {
                    Sleep(1000);
                    cout << "Voce errou." << endl;
                    VidaUsuario = VidaUsuario - 1;
                    Sleep(300);
                    cout << "-1 de Vida" << endl;
                    Sleep(500);
                    cout << "Vida atual e de: " << VidaUsuario << endl;
                    cout << endl;
                }
            }
            break;

        case 6:
            jogadas = 0;
            Dinheiro -= 20;
            if (Dinheiro < 20) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                Sleep(500);
                break;
            } else if (Dinheiro<=0) {
                cout << "GAME OVER! Voce ficou sem dinheiro para apostar!" << endl;
                Sleep(500);
                return 0;
            }
            cout << "-20 reais." << endl;
            Sleep(250);
            cout << "Bem vindo a Alavanca do Milhao " << Nome << "! Basta inserir uma aposta que desejar e caso venca, essa aposta volta para voce em triplo! Mas caso perca, a aposta fica com a gente." << endl;
            Sleep(1000);
            cout << "Vamos comecar!" << endl;
            Sleep(500);
            Palpite = 0;
            do {
                cout << endl;
                cout << "======== Apostas =======" << endl;
                cout << "10 reais = 1 jogada." << endl;
                cout << "20 reais = 2 jogadas." << endl;
                cout << "30 reais = 3 jogadas." << endl;
                cout << "40 reais = 4 jogadas." << endl;
                cout << "50+ reais = 5 jogadas." << endl;
                cout << "========================" << endl;
                cout << "Digite seu valor de aposta (0 para desistir): ";
                cin >> Palpite;
                if (Palpite==0) {
                    cout << "Voce escolheu desistir do jogo. Voltando ao menu principal." << endl;                    //caso escolha desistir
                    Contador +=1;
                    Sleep(500);
                    break;
                }
                if (Palpite > 50) {                                                                             //caso a aposta seja maior que 50
                    cout << "Você terá 5 jogadas por apostar mais de 50 reais." << endl;
                    jogadas = 5;
                    palpiteAuxiliar += Palpite;
                    Palpite = 50;
                }
                switch (Palpite) {
                    case 10:
                        srand(time(0));
                        cout << "Voce apostou 10 reais e tera 1 jogada." << endl;
                        cout << endl;
                        jogadas = 1;
                        for (i = 0; i < jogadas; i++) {
                            for (j = 0; j < 5; j++) {
                                vetorArmazenador[j] = rand() % 16;                  //gera 5 numeros aleatorios entre 0 e 15
                                cout << megaSimbolo[vetorArmazenador[j]];      //mostra os simbolos correspondentes aos numeros gerados
                                Sleep(300);
                            }
                            if (maiorRepeticao(vetorArmazenador, n) == 2) {
                                cout << endl << "Parabens! Voce conseguiu dois simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 2 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 2);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 3) {
                                cout << endl << "Incrivel! Voce conseguiu tres simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 3 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 3);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 4) {
                                cout << endl << "Que grande sorte! Voce conseguiu quatro ou cinco simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 4 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 4);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 5) {
                                cout << endl << "FENOMENAL!!!!! Voce conseguiu os 5 símbolos iguais!!!! Parabens pelo seu dinheiro quinplificado!!" << endl;
                                if (Palpite == 50 && palpiteAuxiliar > 50) {
                                    Palpite = palpiteAuxiliar;
                                }
                                Palpite = Palpite * 5;
                                Sleep(500);
                            } else {
                                cout << endl << "Que pena, voce nao conseguiu nem dois simbolos iguais. Tente novamente!" << endl;
                                Sleep(500);
                            }
                            Sleep(2500);
                            cout << endl;
                        }
                        break;
                    case 20:
                        srand(time(0));
                        cout << "Voce apostou 20 reais e tera 2 jogadas." << endl;
                        cout << endl;
                        jogadas = 2;
                        for (i = 0; i < jogadas; i++) {
                            for ( j = 0; j < 5; j++) {
                                vetorArmazenador[j] = rand() % 16;                  //gera 5 numeros aleatorios entre 0 e 15
                                cout << megaSimbolo[vetorArmazenador[j]];      //mostra os simbolos correspondentes aos numeros gerados
                                Sleep(300);
                            }
                            if (maiorRepeticao(vetorArmazenador, n) == 2) {
                                cout << endl << "Parabens! Voce conseguiu dois simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 2 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 2);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 3) {
                                cout << endl << "Incrivel! Voce conseguiu tres simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 3 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 3);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 4) {
                                cout << endl << "Que grande sorte! Voce conseguiu quatro ou cinco simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 4 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 4);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 5) {
                                cout << endl << "FENOMENAL!!!!! Voce conseguiu os 5 símbolos iguais!!!! Parabens pelo seu dinheiro quinplificado!!" << endl;
                                if (Palpite == 50 && palpiteAuxiliar > 50) {
                                    Palpite = palpiteAuxiliar;
                                }
                                Palpite = Palpite * 5;
                                Sleep(500);
                            } else {
                                cout << endl << "Que pena, voce nao conseguiu nem dois simbolos iguais. Tente novamente!" << endl;
                                Sleep(500);
                            }
                            Sleep(2500);
                            cout << endl;
                        }
                        break;
                    case 30:
                        srand(time(0));
                        cout << "Voce apostou 30 reais e tera 3 jogadas." << endl;
                        cout << endl;
                        jogadas = 3;
                        for (i = 0; i < jogadas; i++) {
                            for ( j = 0; j < 5; j++) {
                                vetorArmazenador[j] = rand() % 16;                  //gera 5 numeros aleatorios entre 0 e 15
                                cout << megaSimbolo[vetorArmazenador[j]];      //mostra os simbolos correspondentes aos numeros gerados
                                Sleep(300);
                            }
                            if (maiorRepeticao(vetorArmazenador, n) == 2) {
                                cout << endl << "Parabens! Voce conseguiu dois simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 2 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 2);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 3) {
                                cout << endl << "Incrivel! Voce conseguiu tres simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 3 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 3);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 4) {
                                cout << endl << "Que grande sorte! Voce conseguiu quatro ou cinco simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 4 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 4);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 5) {
                                cout << endl << "FENOMENAL!!!!! Voce conseguiu os 5 símbolos iguais!!!! Parabens pelo seu dinheiro quinplificado!!" << endl;
                                if (Palpite == 50 && palpiteAuxiliar > 50) {
                                    Palpite = palpiteAuxiliar;
                                }
                                Palpite = Palpite * 5;
                                Sleep(500);
                            } else {
                                cout << endl << "Que pena, voce nao conseguiu nem dois simbolos iguais. Tente novamente!" << endl;
                                Sleep(500);
                            }
                            Sleep(2500);
                            cout << endl;
                        }
                        break;
                    case 40:
                        srand(time(0));
                        cout << "Voce apostou 40 reais e tera 4 jogadas." << endl;
                        cout << endl;
                        jogadas = 4;
                        for (i = 0; i < jogadas; i++) {
                            for ( j = 0; j < 5; j++) {
                                vetorArmazenador[j] = rand() % 16;                  //gera 5 numeros aleatorios entre 0 e 15
                                cout << megaSimbolo[vetorArmazenador[j]];      //mostra os simbolos correspondentes aos numeros gerados
                                Sleep(300);
                            }
                            if (maiorRepeticao(vetorArmazenador, n) == 2) {
                                cout << endl << "Parabens! Voce conseguiu dois simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 2 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 2);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 3) {
                                cout << endl << "Incrivel! Voce conseguiu tres simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 3 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 3);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 4) {
                                cout << endl << "Que grande sorte! Voce conseguiu quatro ou cinco simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 4 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 4);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 5) {
                                cout << endl << "FENOMENAL!!!!! Voce conseguiu os 5 símbolos iguais!!!! Parabens pelo seu dinheiro quinplificado!!" << endl;
                                if (Palpite == 50 && palpiteAuxiliar > 50) {
                                    Palpite = palpiteAuxiliar;
                                }
                                Palpite = Palpite * 5;
                                Sleep(500);
                            } else {
                                cout << endl << "Que pena, voce nao conseguiu nem dois simbolos iguais. Tente novamente!" << endl;
                                Sleep(500);
                            }
                            Sleep(2500);
                            cout << endl;
                        }
                        break;
                    case 50:
                        srand(time(0));
                        cout << "Voce apostou 50 reais e tera 5 jogadas." << endl;
                        cout << endl;
                        jogadas = 5;
                        for (i = 0; i < jogadas; i++) {
                            for ( j = 0; j < 5; j++) {
                                vetorArmazenador[j] = rand() % 16;                  //gera 5 numeros aleatorios entre 0 e 15
                                cout << megaSimbolo[vetorArmazenador[j]];      //mostra os simbolos correspondentes aos numeros gerados
                                Sleep(300);
                            }
                            if (maiorRepeticao(vetorArmazenador, n) == 2) {
                                cout << endl << "Parabens! Voce conseguiu dois simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 2 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 2);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 3) {
                                cout << endl << "Incrivel! Voce conseguiu tres simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 3 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 3);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 4) {
                                cout << endl << "Que grande sorte! Voce conseguiu quatro ou cinco simbolos iguais!" << endl;
                                Sleep(500);
                                cout << "Dinheiro ganho = " << Palpite * 4 << endl;
                                cout << endl;
                                Sleep(750);
                                Dinheiro = Dinheiro + (Palpite * 4);
                            } else if (maiorRepeticao(vetorArmazenador, n) == 5) {
                                cout << endl << "FENOMENAL!!!!! Voce conseguiu os 5 símbolos iguais!!!! Parabens pelo seu dinheiro quinplificado!!" << endl;
                                if (Palpite == 50 && palpiteAuxiliar > 50) {
                                    Palpite = palpiteAuxiliar;
                                }
                                Palpite = Palpite * 5;
                                Sleep(500);
                            } else {
                                cout << endl << "Que pena, voce nao conseguiu nem dois simbolos iguais. Tente novamente!" << endl;
                                Sleep(500);
                            }
                            Sleep(2500);
                            cout << endl;
                        }
                        break;
                    default:
                        cout << "Valor de aposta invalido. Tente novamente." << endl;
                        break;
                }   
            } while (apostaValor!=0);
        break;

        case 7: 
            if (Dinheiro<50) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                break;
            }
            Dinheiro -= 50;
            cout << "-50 reais." << endl;
            cout << "Bem vindo a Roleta Russa! Nesse jogo, o programa ira gerar um numero aleatorio de 1 a 6 e voce tem que escolher entre atirar em si mesmo ou engatilhar a arma e atirar" << endl;
            Sleep(1000);
            cout << "Voce comeca com 3 vidas, cada vez que atirar-te em si mesmo e a bala for verdadeira, voce perde uma vida.";
            Sleep(750);
            cout << " Explicacoes a parte, vamos comecar." << endl;
            Sleep(500);
            cout << endl << "Voce escolhe puxar o gatilho ou engatilhar a arma (A ou B).";
            Sleep(500);
            cout << endl << "Caso deseja sair, digite 'C' para voltar, sem devolucao do valor de entrada. ";
            Sleep(750);
            cin >> atirarArmar;
            if (atirarArmar=='C') {
                cout << "Retornando ao menu principal." << endl;             //opção de desistência
                Sleep(1000);
                break;
            }
            srand(time(NULL));
            for (j=0;j<3;j++) {
                girarTambor = rand() % 6;
                revolver[girarTambor] = true;
                for (i=0;i<6;i++) {
                    cout << endl <<"Atirar(A) ou Engatilhar(B): ";                 //opção de atirar ou engatilhar antes de atirar
                    cin >> atirarArmar;
                    cout << endl;
                    Sleep(750);
                    if (atirarArmar=='A' || atirarArmar=='a') {                               //opção de atirar no seco
                        if (revolver[i]==true) {
                            cout << "Ouch! Voce perdeu uma vida!" << endl;
                            VidaUsuario--;
                            Sleep(250);
                            cout << "Vida restante do jogador: " << VidaUsuario << endl;
                            i = i*0 + 6;
                            revolver[girarTambor] = false;
                            Sleep(500);
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                            Sleep(1000);
                        } else {
                            cout << "Ok, voce sobreviveu, minha vez." << endl;
                            Sleep(500);
                        }
                    }
                    if (atirarArmar=='B' || atirarArmar=='b') {                               //opção de engatilhar antes de atirar
                        if (revolver[i+1]==true) {
                            cout << "OUCH! Nao deu muita sorte nessa ein!" << endl;
                            VidaUsuario--;
                            Sleep(500);
                            cout << "Vida restante do jogador: " << VidaUsuario << endl;
                            i = i*0 + 6;
                            revolver[girarTambor] = false;
                            Sleep(500);
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                            Sleep(1000);
                        } else {
                            cout << "Sortudo maldito! Minha vez." << endl;
                            Sleep(500);
                        }
                    }

                    escolhaBot = rand() % 2;                                  //randomização de escolha do bot entre 0 e 1
                    if (escolhaBot==0) {
                        cout << endl << "**APERTA O GATILHO**" << endl;
                        if (revolver[i+1]==true) {
                            cout << "**BANG** AI CACETE, sorte sua!" << endl;
                            VidaBot--; 
                            Sleep(500);
                            cout << "Vida restante da casa: " << VidaBot << endl;
                            i = i*0 + 6;                                              //Caso ele escolha atirar
                            revolver[girarTambor] = false;
                            Sleep(500);
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                            Sleep(1000);
                        } else {
                            cout << "Ufa! sua vez." << endl;
                            Sleep(500);
                        }
                    } else if (escolhaBot==1) {
                        cout << endl << "**ENGATILHA O REVOLVER**" << endl;
                        if (revolver[i+2]==true) {
                            cout << "**BANG** AAAAAAH! CARALHO!" << endl;
                            VidaBot--;
                            Sleep(500);
                            cout << "Vida restante da casa: " << VidaBot << endl;
                            i = i*0 + 6;                                             //Caso ele escolha engatilhar
                            revolver[girarTambor] = false;
                            Sleep(500);
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                            Sleep(1000);
                        } else {
                            cout << "Meu cu chegou a passar nem wi-fi kkkkkk" << endl;
                            Sleep(500);
                        }
                    }
                    
                    if (VidaUsuario==0) {
                        cout << "Que pena, voce morreu seu but, perdeste 25 reais" << endl;
                        Dinheiro = Dinheiro - 25;                                        //se o jogador perde
                        Sleep(500);
                    } else if (VidaBot==0) {
                        cout << "Droga! Perdi para um palerma como voce. Parabens, voce triplicou seu valor de entrada" << endl;
                        Dinheiro = Dinheiro + (Dinheiro * 3);                           //se o jogador ganhar
                        Sleep(500);
                    }
                }
            }
        Contador = Contador + 1;
        cout << endl;
        break;                  //final case 7
       
       default:
        if (OP>8 || OP<0) {
            cout << "Digite um numero valido." << endl;                     //caso o usuário tente ser engraçadinho e escrever um número maior que 8 ou menor que 0
            break;
        } else if (OP==8) {
            cout << "Saindo do jogo..." << endl;                           //apenas uma interação básica com o usuário
            Sleep(1250);
            return 0;
        }
        break;
       }         //switch fecha-chave
       if (Dinheiro<=0 || Dinheiro<10) {
            cout << "GAME OVER! Voce ficou sem dinheiro para apostar!" << endl;                  //caso fique sem dinheiro, seu mundo acaba
            return 0;
       }
    } while (OP!=8);          //do fecha-chave
    
    return 0;
}        //int main() fecha-chave

// Mais nada para baixo, apenas... o vazio..., o vazio é tão... aconchegante...