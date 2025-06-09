#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main() {
    int OP,i,j,NumerosSorteados[6],NumerosEscolhidos[6],Contador; //variável de opção e opção 2, variável para função (for), vetor tipo Int para armazenar números
    char Nome[30], s[3], R[3]; //vetor tipo Char para colocar seu nome, variável para armazenar resposta
    float Dinheiro, apostaValor; //variável que representa o dinheiro inicial do jogador
    bool Condicionador = false;   //pra aplicar uma condição de verdade ou falso  
    OP=0; Dinheiro=100; Contador=0;
    vector<char> Simbolos = {'@','#','$','&','*','%'};

    cout << "Antes de jogar, por favor digite seu nome: ";
    cin >> Nome;
    cout << "Ola " << Nome << "! Bem vindo a Diversao Virtual! Voce tem 100 reais para comecar sua diversao." << endl;

    do {
       cout << "========= Diversao Virtual =========" << endl;  
       cout << "1. MegaSena (RS20 para jogar)" << endl;
       cout << "2. Alavanca da Sorte (RS10 de entrada para jogar)" << endl;
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
            Condicionador = false;
            Dinheiro -= 20;
            cout << "-20 reais." << endl;
            cout << "Boa noite " << Nome << "! Vou gerar 6 numeros diferentes e se voce tem que acertar pelo menos um deles." << endl;
            srand(time(NULL));
            for (i=0;i<6;i++) {
                NumerosSorteados[i] = rand()%60+1;
            }
            cout << "Geracao aleatoria feita! Agora escreva os numeros. " << endl;
            for (i=0;i<6;i++) {
                cout << "Escreva o " << i+1 << "o numero: ";
                cin >> NumerosEscolhidos[i];
            } 
            cout << endl;
            for (i=0;i<6;i++) {
                cout << i+1 << "o numero sorteado: " << NumerosSorteados[i] << " / " << i+1 << "o numero escolhido: " << NumerosEscolhidos[i] << endl;
                if (NumerosSorteados[i]==NumerosEscolhidos[i]) {
                    Condicionador = true;
                    cout << endl << "Parabens, voce acertou o numero sorteado, na sua respectiva casa! +100 reais" << endl;
                    cout << endl;
                    Dinheiro = Dinheiro + 100;
                } else {
                    for (j=0;j<6;j++) {
                    if (NumerosSorteados[i]==NumerosEscolhidos[j]) {                     
                        Condicionador = true;
                        cout << endl <<"Parabens, voce acertou o numero sorteado, mas nao foi na respectiva casa. +30 reais" << endl;
                        cout << endl;
                        Dinheiro = Dinheiro + 30; 
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
                cout << "Digite 0 para desistir (sem retorno do valor de entrada)." << endl;
                cout << "=====================================" << endl;
                cout << "Qual vai ser o valor da sua aposta? ";
                cin >> apostaValor; 
                if (apostaValor>=1 && apostaValor<=10) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
                    cout << "Certo, voce apostou " << apostaValor << " reais, agora voce vai poder puxar a alavanca e esperar o resultado. Vou puxa-la por ti." << endl;
                    cout << endl;
                    for (i=0;i<1;i++) {
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
                        }
                        if (Condicionador==false) {                                       //se nem um for igual
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
                            cout << "Vamos para a segunda tentativa do senhor?";
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
                                cout << "Vamos para a " << i+2 << "a tentativa do senhor?";
                            } else {
                                cout << "Vamos para a " << i+1 <<"a tentativa do senhor?";
                            }
                            cin >> R;
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
                        if (i==2 || i==1 || i==0) {                                                     //pergunta para não começar instantaneamente a segunda/terceira/quarta tentativa
                            if (i==0) {
                                cout << "Vamos para a " << i+2 << "a tentativa do senhor?";
                            } else {
                                cout << "Vamos para a " << i+1 <<"a tentativa do senhor?";
                            }
                            cin >> R;
                            cout << endl;
                        }
                    }                                               //terminação do quarto "for"
                }                                                //terminação da quarta condição de valor da aposta

                if (apostaValor>100) {
                    srand(static_cast<unsigned>(time(0)));
                    Dinheiro -= apostaValor;
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
                                cout << "Vamos para a " << i+2 << "a tentativa do senhor?";
                            } else {
                                cout << "Vamos para a " << i+1 <<"a tentativa do senhor?";
                            }
                            cin >> R;
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
        break;                       //final case 2

        case 3: 
            

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