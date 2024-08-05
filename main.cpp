#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;
#define tamanho 4

int main() {

    int row1, col1;
    int row2, col2;
    int choice;

    cout << "---- Bem vindo ao jogo da memoria! ----\n\n   (1) Jogar!\n   (2) Sair!\n";
    cout << "\nEscolha uma opcao: ";
    cin >> choice;
    system("cls");

   srand(time(0));

    int matriz[tamanho][tamanho];
    int numeros[8];
    int escolha = rand() % 3;

    // INICIALIZANDO O VETOR DE 1 A 8
    for (int i = 0; i < 8; i++) {
        numeros[i] = i + 1;
    }


    // EMBARALHAMENTO DOS NUMEROS
    for (int i = 8 - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    // PREENCHIMENTO DA MATRIZ PRINCIPAL COM OS NUMEROS
    int index = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = numeros[index++];
        }
    }

    // MATRIZ TRANSPOSTA
    int MatrizZERO[tamanho][tamanho];

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            MatrizZERO[i][j] = matriz[i][j];
        }
    }
    if (escolha == 0 && choice != 2) {
    cout << "\n";
    for (int j=0; j<4; j++) {
            cout << " " << "  ";
        for(int i=0; i<4; i++) {
            cout << MatrizZERO[i][j] << "  ";
        }
        cout << endl;
    }
}

    // MATRIZ INVERTIDA POR LINHA
    int MatrizUM[tamanho][tamanho];

    for (int j = 0; j < tamanho; j++) {
        for (int i = 0; i < tamanho; i++) {
            MatrizUM[i][j] = MatrizZERO[tamanho - i - 1][j];
        }
    }

    if (escolha == 1 && choice != 2) {
    cout << "\n";
    for (int i=0; i<4; i++) {
            cout << " " << "  ";
        for(int j=0; j<4; j++) {
            cout << MatrizUM[i][j] << "  ";
        }
        cout << endl;
    }
}

    // MATRIZ INVERTIDA POR COLUNA
    int MatrizDOIS[tamanho][tamanho];

    for (int j = 0; j < tamanho; j++) {
        for (int i = 0; i < tamanho; i++) {
            MatrizDOIS[i][j] = MatrizZERO[i][tamanho - j - 1];
        }
    }

    if (escolha == 2 && choice != 2) {
    cout << "\n";
    for (int i=0; i<4; i++) {
            cout << " " << "  ";
        for(int j=0; j<4; j++) {
            cout << MatrizDOIS[i][j] << "  ";
        }
        cout << endl;
    }
}
    Sleep(1100);
    system("cls");

    /// MATRIZ DE REFERENCIA
    char enfeite[4][4] =
{
    {'*', '*', '*', '*'},
    {'*', '*', '*', '*'},
    {'*', '*', '*', '*'},
    {'*', '*', '*', '*'}
};

        cout << endl;
        cout << "          0  1  2  3  < coluna\n";
        for (int i=0; i < 4; i++) {
            cout << "       " << i << "  ";
            for (int j=0; j < 4; j++) {
               cout << enfeite[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << "linha  ^";
        cout << "\n\n";

    bool revealed[4][4] = {false};
    int matches = 0;
    int attempts = 0;
    bool gameover = false;

    if (choice == 2) {
        system("cls");
    }

    /// INICIA O JOGO
    if (escolha == 0 && choice != 2) {
    while (!gameover) {

        // PEDE A LINHA E A COLUNA
        cout << "Digite a linha e a coluna, respectivamente: ";
        cin >> row1 >> col1;

            if (revealed[row1][col1] == true) {
                cout << "Esta carta ja foi!\n";
                system("pause");
                cout << endl;
            } else {
                cout << "carta: " << MatrizZERO[row1][col1] << "\n\n";
            }

            if (row1 > 3 || row1 < 0 || col1 > 3 || col1 < 0) {
                cout << "Numeros invalidos!! Digite de 0 a 3 para linha e de 0 a 3 para a coluna.\n";
                system("pause");
                cout << endl;
            }

        // PEDE A LINHA E A COLUNA
        cout << "Digite a linha e a coluna, respectivamente: ";
        cin >> row2 >> col2;

            if (row2 == row1 && col2 == col1) {
                cout << "Numeros invalidos!!\n";
                system("pause");
                cout << endl;
            } else if (revealed[row2][col2] == true) {
                cout << "Esta carta ja foi!\n";
                system("pause");
                cout << endl;
            } else {
                cout << "carta: " << MatrizZERO[row2][col2] << "\n\n";
            }


            if (row2 > 3 || row2 < 0 || col2 > 3 || col2 < 0) {
                cout << "Numeros invalidos!! Digite de 0 a 3 para linha e de 0 a 3 para a coluna.\n";
                system("pause");
                cout << endl;
            }

            // CONFERE SE ACERTOU OU NÃO
        if (MatrizZERO[row1][col1] == MatrizZERO[row2][col2] && (row2 == row1 && col2 == col1)) {
            cout << "JOGADA NOK." << endl;
        } else if (MatrizZERO[row1][col1] == MatrizZERO[row2][col2]) {
            cout << "JOGADA OK!" << endl;
            revealed[row1][col1] = true;
            revealed[row2][col2] = true;
            matches++;
        } else {
            cout << "JOGADA NOK." << endl;
        }


        // DESENHA A MATRIZ ATUALIZADA
        cout << endl;
        cout << "           0  1  2  3  < coluna\n\n";
        for (int i = 0; i < 4; i++) {
                cout << "       " << i << "  ";
            for (int j = 0; j < 4; j++) {
                if (revealed[i][j]) {
                    cout << " " << MatrizZERO[i][j] << " ";
                } else {
                    cout << " * ";
                }
            }
            cout << endl;
        }
        cout << "linha  ^";
        cout << "\n\n";

        attempts++;

        cout << endl << "Tentativas: " << attempts << endl;
        cout << endl << "Pares encontrados: " << matches << endl;
        cout << endl;

        /// VERIFICA SE ULTRAPASSOU O LIMITE
        if(attempts > 24) {
            gameover = true;
            system("cls");
        }
        /// VERIFICA OS PARES
        if(matches == 8) {
            gameover = true;
            system("cls");
        }
    }
}

        if (escolha == 1 && choice != 2) {
    while (!gameover) {

        // PEDE A LINHA E A COLUNA
        cout << "Digite a linha e a coluna, respectivamente: ";
        cin >> row1 >> col1;

            if (revealed[row1][col1] == true) {
                cout << "Esta carta ja foi!\n";
                system("pause");
                cout << endl;
            } else {
                cout << "carta: " << MatrizUM[row1][col1] << "\n\n";
            }

            if (row1 > 3 || row1 < 0 || col1 > 3 || col1 < 0) {
                cout << "Numeros invalidos!! Digite de 0 a 3 para linha e de 0 a 3 para a coluna.\n";
                system("pause");
                cout << endl;
            }

        // PEDE A LINHA E A COLUNA
        cout << "Digite a linha e a coluna, respectivamente: ";
        cin >> row2 >> col2;

            if (row2 == row1 && col2 == col1) {
                cout << "Numeros invalidos!!\n";
                system("pause");
                cout << endl;
            } else if (revealed[row2][col2] == true) {
                cout << "Esta carta ja foi!\n";
                system("pause");
                cout << endl;
            } else {
                cout << "carta: " << MatrizUM[row2][col2] << "\n\n";
            }


            if (row2 > 3 || row2 < 0 || col2 > 3 || col2 < 0) {
                cout << "Numeros invalidos!! Digite de 0 a 3 para linha e de 0 a 3 para a coluna.\n";
                system("pause");
                cout << endl;
            }

            // CONFERE SE ACERTOU OU NÃO
        if (MatrizUM[row1][col1] == MatrizUM[row2][col2] && (row2 == row1 && col2 == col1)) {
            cout << "JOGADA NOK." << endl;
        } else if (MatrizUM[row1][col1] == MatrizUM[row2][col2]) {
            cout << "JOGADA OK!" << endl;
            revealed[row1][col1] = true;
            revealed[row2][col2] = true;
            matches++;
        } else {
            cout << "JOGADA NOK." << endl;
        }

        attempts++;

        cout << endl << "Tentativas: " << attempts << endl;
        cout << endl << "Pares encontrados: " << matches << endl;
        cout << endl;

        // DESENHA A MATRIZ ATUALIZADA
        cout << endl;
        cout << "           0  1  2  3  < coluna\n\n";
        for (int i = 0; i < 4; i++) {
                cout << "       " << i << "  ";
            for (int j = 0; j < 4; j++) {
                if (revealed[i][j]) {
                    cout << " " << MatrizUM[i][j] << " ";
                } else {
                    cout << " * ";
                }
            }
            cout << endl;
        }
        cout << "linha  ^";
        cout << "\n\n";

        /// VERIFICA SE ULTRAPASSOU O LIMITE
        if(attempts > 24) {
            gameover = true;
            system("cls");
        }
        /// VERIFICA OS PARES
        if(matches == 8) {
            gameover = true;
            system("cls");
        }
    }
}

        if (escolha == 2 && choice != 2) {
    while (!gameover) {

        // PEDE A LINHA E A COLUNA
        cout << "Digite a linha e a coluna, respectivamente: ";
        cin >> row1 >> col1;

            if (revealed[row1][col1] == true) {
                cout << "Esta carta ja foi!\n";
                system("pause");
                cout << endl;
            } else {
                cout << "carta: " << MatrizDOIS[row1][col1] << "\n\n";
            }

            if (row1 > 3 || row1 < 0 || col1 > 3 || col1 < 0) {
                cout << "Numeros invalidos!! Digite de 0 a 3 para linha e de 0 a 3 para a coluna.\n";
                system("pause");
                cout << endl;
            }

        // PEDE A LINHA E A COLUNA
        cout << "Digite a linha e a coluna, respectivamente: ";
        cin >> row2 >> col2;

            if (row2 == row1 && col2 == col1) {
                cout << "Numeros invalidos!!\n";
                system("pause");
                cout << endl;
            } else if (revealed[row2][col2] == true) {
                cout << "Esta carta ja foi!\n";
                system("pause");
                cout << endl;
            } else {
                cout << "carta: " << MatrizDOIS[row2][col2] << "\n\n";
            }


            if (row2 > 3 || row2 < 0 || col2 > 3 || col2 < 0) {
                cout << "Numeros invalidos!! Digite de 0 a 3 para linha e de 0 a 3 para a coluna.\n";
                system("pause");
                cout << endl;
            }

            // CONFERE SE ACERTOU OU NÃO
        if (MatrizDOIS[row1][col1] == MatrizDOIS[row2][col2] && (row2 == row1 && col2 == col1)) {
            cout << "JOGADA NOK." << endl;
        } else if (MatrizDOIS[row1][col1] == MatrizDOIS[row2][col2]) {
            cout << "JOGADA OK!" << endl;
            revealed[row1][col1] = true;
            revealed[row2][col2] = true;
            matches++;
        } else {
            cout << "JOGADA NOK." << endl;
        }

        attempts++;

        cout << endl << "Tentativas: " << attempts << endl;
        cout << endl << "Pares encontrados: " << matches << endl;
        cout << endl;

        // DESENHA A MATRIZ ATUALIZADA
        cout << endl;
        cout << "           0  1  2  3  < coluna\n\n";
        for (int i = 0; i < 4; i++) {
                cout << "       " << i << "  ";
            for (int j = 0; j < 4; j++) {
                if (revealed[i][j]) {
                    cout << " " << MatrizDOIS[i][j] << " ";
                } else {
                    cout << " * ";
                }
            }
            cout << endl;
        }
        cout << "linha  ^";
        cout << "\n\n";

        /// VERIFICA SE ULTRAPASSOU O LIMITE
        if(attempts > 24) {
            gameover = true;
            system("cls");
        }
        /// VERIFICA OS PARES
        if(matches == 8) {
            gameover = true;
            system("cls");
        }
    }
}

    if (matches == 8) {
        cout << "\nGOOD JOB! voce encontrou os " << matches << " pares em " << attempts << " tentativas!" << endl;
    }
    if (attempts > 24) {
        cout << "\nGAME OVER! voce ultrapassou o limite de tentativas: " << attempts << endl;
    }



    return 0;
}
