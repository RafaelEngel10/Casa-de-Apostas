#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <thread>                                           //thread e chrono são bibliotecas que adicionam DELAY na hora de mostrar mensagens
#include <chrono>                                           //vou adicionar DELAY em várias mensagens, algum dia aí
using namespace std;

const int LINHAS = 4; const int COLUNAS = 8;            //variáveis para o void 

void mostrarCorrida(bool corridaCavalo[LINHAS][COLUNAS]) {                        //função secundária tipo void para que eu possa trabalhar na parte visual da corrida 
    for (int i=0; i<LINHAS; i++) {                                           //sim, precisa declarar o i denovo
        cout << "Cavalo " << i + 1 << " | ";
        for (int j = 0; j < COLUNAS; ++j) {
            cout << (corridaCavalo[i][j] ? ">" : "-") << " ";
        }
        _sleep(2000);                                     //a função _sleep é em milissegundos, 2000ms são equivalentes a 2 segundos, lembre-se disso!
        cout << endl;
    }
    cout << endl;
}

int main() {
    int OP,i,j,NumerosSorteados[6],NumerosEscolhidos[6],Contador,girarTambor, VidaUsuario=3, VidaBot=3, escolhaBot, escolhaCavalo; 
    //variável de opção e opção 2, variável para função (for), vetor tipo Int para armazenar números, vida do usuário e do robô, variável de escolha do robô, variável de escolha do cavalo
    int progresso[LINHAS] = { 0 }, vencedor = -1;
    char Nome[30], s[3], R[3], atirarArmar; //vetor tipo Char para colocar seu nome, vetor para armazenar símbolos, vetor para armazenar resposta,
    float Dinheiro, apostaValor; //variável que representa o dinheiro inicial do jogador
    bool Condicionador = false, vencedorCorrida = false;   //pra aplicar uma condição de verdade ou falso  
    OP=0; Dinheiro=100; Contador=0;
    vector<char> Simbolos = {'@','#','$','&','*','%','/','?','!'};                //vetor tipo char para armazenar símbolos (slot machine)
    bool revolver[6] = {false, false, false, false, false, false};                         //vetor tipo bool armazenando false em todas as posições
    bool corridaCavalo[4][8] = {
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false},                        //matriz tipo bool armazendo false em todas as posições (de forma bem verbosa)
        {false, false, false, false, false, false, false, false}                         // uma opção menos verbosa seria *bool corridaCavalo[4][8] = { false };*
    };

    cout << "Antes de jogar, por favor digite seu nome: ";
    cin.getline(Nome,30);
    cout << "Ola " << Nome << "! Bem vindo a Diversao Virtual! Voce tem 100 reais para comecar sua diversao." << endl;

    do {                                                                                       //Menu Principal
       cout << "========= Diversao Virtual =========" << endl;  
       cout << "1. MegaSena (RS20 para jogar)" << endl;                                    //MegaSena de 1 a 60 
       cout << "2. Alavanca da Sorte (RS10 de entrada para jogar)" << endl;                  //Slot Machine 
       cout << "3. Corrida de Cavalo (RS15 de entrada para jogar)" << endl;                    //Corrida de Cavalos, você aposta no que achar ser o que vai chegar em primeiro
       cout << "4. " << endl;
       cout << "5. " << endl;
       cout << "6. " << endl;
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
            }
            Condicionador = false;
            Dinheiro -= 20;
            cout << "-20 reais." << endl;
            cout << "Boa noite " << Nome << "! Vou gerar 6 numeros diferentes e se voce tem que acertar pelo menos um deles." << endl;
            srand(time(NULL));
            for (i=0;i<6;i++) {
                NumerosSorteados[i] = rand()%60+1;                                       //Geração de 6 números aleatórios
            }
            cout << "Geracao aleatoria feita! Agora escreva os numeros. " << endl;                      
            for (i=0;i<6;i++) {
                cout << "Escreva o " << i+1 << "o numero: ";                         //leitura de 6 números do usuário
                cin >> NumerosEscolhidos[i];
                if (NumerosEscolhidos[i]>60) {
                    cout << "Escolha um numero entre 1 e 60!" << endl;
                    cout << "Escreva o " << i+1 << "o numero: ";
                    cin >> NumerosEscolhidos[i];
                }
            } 
            cout << endl;
            for (i=0;i<6;i++) {
                cout << i+1 << "o numero sorteado: " << NumerosSorteados[i] << " / " << i+1 << "o numero escolhido: " << NumerosEscolhidos[i] << endl;
                if (NumerosSorteados[i]==NumerosEscolhidos[i]) {
                    Condicionador = true;
                    cout << endl << "Parabens, voce acertou o numero sorteado, na sua respectiva casa! +100 reais" << endl;                 //Caso acerte o numero junto da casa
                    cout << endl; 
                    Dinheiro = Dinheiro + 100;
                } else {
                    for (j=0;j<6;j++) {
                    if (NumerosSorteados[i]==NumerosEscolhidos[j]) {                     
                        Condicionador = true;
                        cout << endl <<"Parabens, voce acertou o numero sorteado, mas nao foi na respectiva casa. +30 reais" << endl;        //Caso acerte o número apenas
                        cout << endl;
                        Dinheiro = Dinheiro + 30; 
                        } 
                    }
                }
            }
            if (Condicionador==false) {      //se as estruturas condicionais não forem executadas, o Condicionador continuará como false, resultando na execução desta condição.
                cout << "Que pena! Parece que voce nao acertou nem um numero. Talvez na proxima voce consiga!" << endl;      //Caso não acerte nada
            }
            cout << endl;
            Contador += 1;
        break;                   //final case 1

        case 2: 
            if (Dinheiro<10) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                break;
            }
            Dinheiro -= 10;
            cout << "-10 reais." << endl;
            cout << "Bem vindo a Alavanca da Sorte " << Nome << "! Basta inserir uma aposta que desejar e caso venca, essa aposta volta para voce em dobro, mas caso perca a aposta fica com a gente." << endl;
            cout << "Cada valor tem um numero de vezes que voce pode puxar a alavanca, aqui vai uma tabela de precos com as jogadas." << endl;
            do {                                                                          //começo do "do"
                cout << "========= Tabela de Valores =========" << endl;
                cout << "1 a 10 reais = 1 jogada." << endl;
                cout << "11 a 20 reais = 2 jogadas." << endl;
                cout << "21 a 50 reais = 3 jogadas." << endl;
                cout << "51 a 100 reais = 4 jogadas." << endl;
                cout << "100+ reais = 5 jogadas." << endl;
                cout << "Digite 0 para desistir (sem retorno do valor de entrada)." << endl;                //Menu de valores da aposta
                cout << "=====================================" << endl;
                cout << "Qual vai ser o valor da sua aposta? ";
                cin >> apostaValor; 
                if (apostaValor>=1 && apostaValor<=10) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;                                     //interação simples com o jogador
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    cout << endl;                                     
                    for (i=0;i<1;i++) {
                        cout << "Simbolos sorteados: ";
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];                    //sorteia 3 simbolos aleatoriamente
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;      
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;                                         
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]==s[2] && s[0]!=s[1]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[1]==s[2] && s[2]!=s[0]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true; 
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                        }
                    }                                                      //terminação do primeiro "for"
                }                                                     //terminação da primeira condição de valor da aposta

                if (apostaValor>=11 && apostaValor<=20) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    for (i=0;i<2;i++) {
                        cout << "Simbolos sorteados: ";
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;      
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;                                         
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
                        }
                        if (i==0) {                                                     //pergunta para não começar instantaneamente a segunda tentativa
                            cout << "Vamos para a segunda tentativa do senhor? ";
                            cin >> R;
                            cout << endl;
                        }
                    }                                               //terminação do segundo "for"
                }                                                //terminação da segunda condição de valor da aposta

                if (apostaValor>=21 && apostaValor<=50) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    for (i=0;i<3;i++) {
                        cout << "Simbolos sorteados: ";
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;      
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;                                         
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
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
                                break;
                            }
                            cout << endl;
                        }
                    }                                               //terminação do terceiro "for"
                }                                                //terminação da terceira condição de valor da aposta

                if (apostaValor>=51 && apostaValor<=100) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    for (i=0;i<4;i++) {
                        cout << "Simbolos sorteados: ";
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;      
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;                                         
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
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
                                break;
                            }
                            cout << endl;
                        }
                    }                                               //terminação do quarto "for"
                }                                                //terminação da quarta condição de valor da aposta

                if (apostaValor>100) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;                                                           //interação com o jogador
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    for (i=0;i<5;i++) {
                        cout << "Simbolos sorteados: ";
                        for (j=0;j<3;j++) {
                            s[j] = Simbolos[rand() % Simbolos.size()];
                            cout << s[j] << " ";
                        }
                        cout << endl; 
                        if (s[0]==s[1] && s[0]==s[2]) {                                   //se os tres simbolos forem iguais, isto acontece
                            Condicionador = true;
                            cout << "Que grande sorte! Voce conseguiu tres simbolos iguais! Seu premio e o dobro do que foi apostado!" << endl;      
                            cout << "Dinheiro ganho = " << apostaValor * 2 << endl;                                         
                            Dinheiro = Dinheiro + (apostaValor * 2);
                        } else if (s[0]==s[1] && s[0]!=s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        } else if (s[0]!=s[1] && s[0]==s[2]) {                            //se pelo menos dois simbolos forem iguais
                            Condicionador = true;
                            cout << "Parece que voce conseguiu dois simbolos iguais! Seu premio e o valor apostado mais metade dele mesmo!" << endl;
                            cout << "Dinheiro ganho = " << apostaValor + (apostaValor * 0.5) << endl;
                            Dinheiro = Dinheiro + (apostaValor + (apostaValor * 0.5));
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
                            cout << "Que ma sorte! Parece que voce nao conseguiu nem um simbolo igual se quer. Na proxima com certeza voce consegue!" << endl;
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
                                break;
                            }
                            cout << endl;
                        }
                    }                                               //terminação do quinto "for"
                }                                                //terminação da quinta condição de valor da aposta

                if (apostaValor==0) {                     //condição de desistência
                    cout << "Voce escolheu desistir do jogo. Voltando ao menu principal." << endl;
                    Contador +=1;
                    break;
                }

            } while (apostaValor!=0);                         //condição da função "do"
            cout << endl;
        break;                       //final case 2

        case 3: 
            if (Dinheiro<15) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;                //Caso o jogador não tenha dinheiro para pagar a entrada
                break;
            }
            Dinheiro -= 15;
            apostaValor = 0; vencedor = -1; vencedorCorrida = false; 
            srand(time(NULL));
            cout << "-15 reais." << endl;
            cout << "Boa noite " << Nome << "! Esta e uma corrida de cavalos. Aqui voce apostara no cavalo que voce acha que vai ganhar." << endl;
            cout << "Caso seu cavalo ganhe, teu dinheiro apostado sera dobrado. Senao, voce so perdera seu dinheiro mesmo." << endl;
            cout << endl << "Qual vai ser o seu cavalo? (1, 2, 3 ou 4)";
            cin >> escolhaCavalo;
            cout << endl << "Quanto sera apostado nele?";
            cin >> apostaValor;
            if (apostaValor>Dinheiro) {
                do {
                    cout << "O senhor nao possui esse dinheiro para apostar." << endl;
                    cout << "Quanto sera apostado nele?";
                    cin >> apostaValor;
                } while (apostaValor>0 );
            } else {
                Dinheiro -= apostaValor;
            }

            cout << endl << "Apostas feitas, vamos dar inicio a corrida. 3, 2, 1. **BANG**" << endl;
            cout << "APROVEITEM O ESPETACULO!" << endl;
            srand(time(0)); 

            while (!vencedorCorrida) {
                for (i=0; i<LINHAS; i++) {
                    if (progresso[i]<COLUNAS) {
                        if (rand() % 2 == 0) {
                            corridaCavalo[i][progresso[i]] = true;                //preguiça de explicar isso
                            progresso[i]++;
                        }
                    }
                    if (progresso[i] == COLUNAS) {
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
            } else {
                cout << "Bom, nao da para esperar que va ganhar todas ne?" << endl;
            }
            break;                                                                   //final case 3

        case 7: 
            if (Dinheiro<50) {
                cout << "Desculpa, mas voce nao tem dinheiro para poder realizar essa acao." << endl;
                break;
            }
            Dinheiro -= 50;
            cout << "-50 reais." << endl;
            cout << "Bem vindo a Roleta Russa! Nesse jogo, o programa ira gerar um numero aleatorio de 1 a 6 e voce tem que escolher entre atirar em si mesmo ou engatilhar a arma e atirar" << endl;
            cout << "Voce comeca com 3 vidas, cada vez q tu atirar em si mesmo e for verdadeira, voce perde uma vida.";
            cout << " Explicacoes a parte, vamos comecar." << endl;
            cout << endl << "Voce escolhe puxar o gatilho ou engatilhar a arma (A ou B).";
            cout << endl << "Caso deseja sair, digite 'C' para voltar, sem devolucao do valor de entrada. ";
            cin >> atirarArmar;
            if (atirarArmar=='C') {
                cout << "Retornando ao menu principal." << endl;             //opção de desistência
                break;
            }
            srand(time(NULL));
            for (j=0;j<3;j++) {
                girarTambor = rand() % 6;
                revolver[girarTambor] = true;
                for (i=0;i<6;i++) {
                    cout << endl <<"Voce escolhe atirar direto ou engatilhar (A ou B)? ";                 //opção de atirar ou engatilhar antes de atirar
                    cin >> atirarArmar;
                    cout << endl;
                    if (atirarArmar=='A' || atirarArmar=='a') {                               //opção de atirar no seco
                        if (revolver[i]==true) {
                            cout << "Ouch! Voce perdeu uma vida!" << endl;
                            VidaUsuario--;
                            cout << "Vida restante do jogador: " << VidaUsuario << endl;
                            i = i*0 + 6;
                            revolver[girarTambor] = false;
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                        } else {
                            cout << "Ok, voce sobreviveu, minha vez." << endl;
                        }
                    }
                    if (atirarArmar=='B' || atirarArmar=='b') {                               //opção de engatilhar antes de atirar
                        if (revolver[i+1]==true) {
                            cout << "OUCH! Nao deu muita sorte nessa ein!" << endl;
                            VidaUsuario--;
                            cout << "Vida restante do jogador: " << VidaUsuario << endl;
                            i = i*0 + 6;
                            revolver[girarTambor] = false;
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                        } else {
                            cout << "Sortudo maldito! Minha vez." << endl;
                        }
                    }

                    escolhaBot = rand() % 2;                                  //randomização de escolha do bot
                    if (escolhaBot==0) {
                        cout << endl << "**APERTA O GATILHO**" << endl;
                        if (revolver[i+1]==true) {
                            cout << "**BANG** AI CACETE, sorte sua!" << endl;
                            VidaBot--; 
                            cout << "Vida restante da casa: " << VidaBot << endl;
                            i = i*0 + 6;                                              //Caso ele escolha atirar
                            revolver[girarTambor] = false;
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                        } else {
                            cout << "Ufa! sua vez." << endl;
                        }
                    } else if (escolhaBot==1) {
                        cout << endl << "**ENGATILHA O REVOLVER**" << endl;
                        if (revolver[i+2]==true) {
                            cout << "**BANG** AAAAAAH! CARALHO!" << endl;
                            VidaBot--;
                            cout << "Vida restante da casa: " << VidaBot << endl;
                            i = i*0 + 6;                                             //Caso ele escolha engatilhar
                            revolver[girarTambor] = false;
                            cout << "Coloquei a bala aleatoriamente e girei o tambor." << endl;
                        } else {
                            cout << "Meu cu chegou a passar nem wi-fi kkkkkk" << endl;
                        }
                    }
                    
                    if (VidaUsuario==0) {
                        cout << "Que pena, voce morreu, perdeste 25 reais" << endl;
                        Dinheiro = Dinheiro - 25;                                        //se o jogador perde
                    } else if (VidaBot==0) {
                        cout << "Droga! Perdi para um palerma como voce. Parabens, voce triplicou seu valor de entrada" << endl;
                        Dinheiro = Dinheiro + (Dinheiro * 3);                           //se o jogador ganhar
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
            break;
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