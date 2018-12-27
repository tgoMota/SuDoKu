#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

void le_arquivo(char *nome, int mat[][9]){
    FILE *arq = fopen(nome,"r");
    if(arq == NULL){
        printf("Erro de leitura\n");
        system("pause");
        exit(1);
    }

    int i,j;
    for(i=0; i< 9; i++)
        for(j=0; j< 9; j++)
            fscanf(arq,"%d",&mat[i][j]);

    fclose(arq);
}

/*             0     1    2     3   4      5      6      7         8  */
typedef enum{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,   /* nome das cores */
LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;
/*  9         10         11        12        13         14    15 */

static int __BACKGROUND = 1/*BLACK*/;/*pode ser o numero ou o nome da cor*/
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (__BACKGROUND << 4));
}

void tituloSudoku(){
    printf("\n\n");
    textcolor(4, 0);
    printf("================================================================================\n");
    printf("||");
    textcolor(14,0);
    printf("    **********   ***     ***   ****       ********   *    *   ***     ***   ");
    textcolor(4, 0);
    printf("||\n");
    printf("||");
    textcolor(14,0);
    printf("    **           ***     ***   **   *     *      *   *  *     ***     ***   ");
    textcolor(4, 0);
    printf("||\n");
    printf("||");
    textcolor(14,0);
    printf("    **********   ***     ***   **     *   *      *   **       ***     ***   ");
    textcolor(4,0);
    printf("||\n");
    printf("||");
    textcolor(14,0);
    printf("            **   ***     ***   **   *     *      *   *  *     ***     ***   ");
    textcolor(4,0);
    printf("||\n");
    printf("||");
    textcolor(14,0);
    printf("    **********   ***********   ****       ********   *    *   ***********   ");
    textcolor(4,0);
    printf("||\n");
    printf("================================================================================\n");
    textcolor(15,0);
}

void menu(){
    esconderCursor();
    char tecla;
    int opcao = 1;
    while(tecla != '\n'){

            if(tecla == 's' || tecla == 80) //DownArrow
                opcao++;
            if(tecla == 'w' || tecla == 72) //UpArrow
                opcao--;

        tituloSudoku();
        textcolor(9,0);
        if(opcao == 1){
            setlocale(LC_ALL, "Portuguese");
            printf(" ->    INSTRUÇÕES\n");
            printf("    INICIAR JOGO\n");
            printf("    CRÉDITOS\n");
            printf("    SAIR\n");
            textcolor(4,0);
            printf("===============================================================================\n");
            textcolor(9,0);
            setlocale(LC_ALL, NULL);
            tecla = getch();
            if(tecla == 13) //enter
                instrucoes();
            system("cls");

        }

        if(opcao == 2){
            setlocale(LC_ALL, "Portuguese");
            printf("    INSTRUÇÕES\n");
            printf(" ->    INICIAR JOGO\n");
            printf("    CRÉDITOS\n");
            printf("    SAIR\n");
            textcolor(4,0);
            printf("===============================================================================\n");
            textcolor(9,0);
            setlocale(LC_ALL, NULL);
            tecla = getch();
            system("cls");
            if(tecla == 13) //enter
                iniciar();

        }

        if(opcao == 3){
            setlocale(LC_ALL, "Portuguese");
            printf("    INSTRUÇÕES\n");
            printf("    INICIAR JOGO\n");
            printf(" ->   CRÉDITOS\n");
            printf("    SAIR\n");
            textcolor(4,0);
            printf("===============================================================================\n");
            textcolor(9,0);
            setlocale(LC_ALL, NULL);
            tecla = getch();
            if(tecla == 13)
                creditos();
            system("cls");
        }

        if(opcao == 4){
            setlocale(LC_ALL, "Portuguese");
            printf("    INSTRUÇÕES\n");
            printf("    INICIAR JOGO\n");
            printf("    CRÉDITOS\n");
            printf(" ->   SAIR\n");
            textcolor(4,0);
            printf("===============================================================================\n");
            textcolor(9,0);
            setlocale(LC_ALL, NULL);
            tecla = getch();
            if(tecla == 13)
                exit(1);
            system("cls");
        }

        if(opcao > 4){
            system("cls");
            menu();
        }

        if(opcao < 1){
            system("cls"); //limpar tela
            opcao = 5;
        }

    } //fim while
}

void esconderCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void restaurarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


void instrucoes(){
    system("cls");
    char tecla;
    int opcao = 1;
    while(tecla != '\n'){
        tituloSudoku();
        setlocale(LC_ALL, "Portuguese");
        textcolor(2,0);
        printf("                       I N S T R U Ç Õ E S\n");
        textcolor(4,0);
        printf("================================================================================\n");
        textcolor(9,0);
        printf("||      O Sudoku é um passatempo, pra ser jogado por apenas                    ||\n");
        printf("||      uma pessoa,que envolve raciocínio e lógica. A ideia                    ||\n");
        printf("||      do jogo é bem simples: complete todas as 81 celulas                    ||\n");
        printf("||      usando numeros de 1 a 9,sem repetir os numeros numa                    ||\n");
        printf("||      mesma linha, coluna ou grade (3x3).                                    ||\n");
        printf("||      Para mover o cursor, utilize as setas do teclado ou                    ||\n");
        printf("||      ,até mesmo, as teclas 'w' 'a' 's' 'd'.                                 ||\n");
        printf("||      Para modificar o valor, pressione ENTER na posição.                    ||\n");
        textcolor(4,0);
        printf("================================================================================\n");
        textcolor(2,0);
        printf("                       Deseja voltar ao menu?\n");
        textcolor(4,0);
        printf("================================================================================\n");
        textcolor(9,0);
        setlocale(LC_ALL, NULL);
        if(opcao == 1){
            printf("   -> SIM\n");
            printf("   SAIR DO JOGO\n");
            tecla = getch();
            system("cls");
            if(tecla == 13)
                menu();
        }
        if(opcao == 2){
            printf("   SIM\n");
            printf("   -> SAIR DO JOGO\n");
            tecla = getch();
            if(tecla == 13)
                exit(1);
            system("cls");
        }

        if(tecla == 's' || tecla == 80) //DownArrow
                opcao++;
        if(tecla == 'w' || tecla == 72) //UpArrow
                opcao--;
        if(opcao > 2)
            opcao = 1;
        if(opcao < 1)
            opcao = 2;

    } //fim while
}

void creditos(){
    system("cls");
    char tecla;
    int opcao = 1;
    while(tecla != '\n'){
        tituloSudoku();
        setlocale(LC_ALL, "Portuguese");
        textcolor(2,0);
        printf("                              C R É D I T O S\n");
        textcolor(4,0);
        printf("================================================================================\n");
        textcolor(9,0);
        printf("||      Thiago Mota Carvalho                                                   ||\n");
        printf("||                 Graduando em Ciência da Computação - UFU                    ||\n");
        printf("||                                     2018                                    ||\n");
        printf("||      email: tgomota1@gmail.com                                              ||\n");
        textcolor(4,0);
        printf("================================================================================\n");
        textcolor(2,0);
        printf("                       Deseja voltar ao menu?\n");
        textcolor(4,0);
        printf("================================================================================\n");
        textcolor(9,0);
        setlocale(LC_ALL, NULL);
        if(opcao == 1){
            printf("   -> SIM\n");
            printf("   SAIR DO JOGO\n");
            tecla = getch();
            system("cls");
            if(tecla == 13)
                menu();
        }
        if(opcao == 2){
            printf("   SIM\n");
            printf("   -> SAIR DO JOGO\n");
            tecla = getch();
            if(tecla == 13)
                exit(0);
            system("cls");
        }

        if(tecla == 's' || tecla == 80) //DownArrow
                opcao++;
        if(tecla == 'w' || tecla == 72) //UpArrow
                opcao--;
        if(opcao > 2)
            opcao = 1;
        if(opcao < 1)
            opcao = 2;
    }
}

void mostraQuadro(int mat[][9], int copia[][9], int *celulas){
    tituloSudoku();
    printf("\n\n");
    *celulas = 0; //contar celulas vazias
    for(int i = 0; i<9 ; ++i){
            printf("                  ");
        for(int j = 0; j < 9 ; ++j){
            printf("|");
            if(copia[i][j] != 0){
                textcolor(15,1);
                printf(" %d ", copia[i][j]);
                textcolor(15,0);
            }
            else
                printf(" %d ", mat[i][j]);
            if(mat[i][j] == 0)
                (*celulas)++;
        }
        printf("|");
        printf("\n");
    }
}

int conferirJogo(int mat[][9], int celulas){
    if(celulas != 0)
        return -1; //ainda restam celulas vazias
    int linha = 0, coluna = 0, numero = 1;
    while(numero < 10){ //teste de linhas e colunas
        for(int i = 0; i<9 ; ++i){
            for(int j = 0; j < 9 ; ++j){
                if(mat[i][j] == numero){
                    linha++;
                    if(linha == 2)
                        return 0; //repetiu na linha
                }
                if(mat[j][i] == numero){
                    coluna++;
                    if(coluna == 2)
                        return 0; //repetiu na coluna
                }
            }
            linha = 0;
            coluna = 0;
        }
        numero++;
    }
    numero = 1; //passou no teste de linhas e colunas

    int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0 , H = 0, I = 0;
    while(numero < 10){ //teste em grades 3x3  // A D E
        for(int i = 0; i < 3 ; ++i){          //  B E F
            for(int j = 0; j < 3 ; ++j){     //   C F I
                /* Primeira Coluna de Grades (1/3) */
                if(mat[i][j] == numero) // A
                    ++A;
                if(mat[i+3][j] == numero) // B
                    ++B;
                if(mat[i+6][j] == numero) // C
                    ++C;

                /* Segunda Coluna de Grades (2/3) */
                if(mat[i][j+3] == numero) // D
                    ++D;
                if(mat[i+3][j+3] == numero) // E
                    ++E;
                if(mat[i+6][j+3] == numero) // F
                    ++F;

                /* Terceira Coluna de Grades (3/3) */
                if(mat[i][j+6] == numero) // G
                    ++G;
                if(mat[i+3][j+6] == numero) // H
                    ++H;
                if(mat[i+6][j+6] == numero) // I
                    ++I;

                if(A == 2 || B == 2 || C == 2 || D == 2 || E == 2 || F == 2 || G == 2 || H == 2 || I == 2)
                    return 0; // houve repeticao em alguma grade
            }
        }
        A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0 , H = 0, I = 0;
        ++numero;
    }
    return 1; //passou em todos os testes, o jogador venceu o desafio proposto
}

void informacaoCelulas(int celulas){
    esconderCursor();
    gotoxy(73,14);
    textcolor(1,0);
    printf("|======================|\n");
    gotoxy(73,15);
    printf("|");
    textcolor(15,4);
    printf("    Celulas vagas: %d ", celulas);
    textcolor(1,0);
    printf("|\n");
    gotoxy(73,16);
    printf("|======================|\n");
    textcolor(15,0);
}

void observacoes(){
    esconderCursor();
    gotoxy(73,19);
    printf("               Obs.\n");
    gotoxy(73,20);
    printf("A qualquer momento, voce pode digitar\n");
    gotoxy(73,21);
    printf("'c' para conferir seu jogo ou 'ESC' se\n");
    gotoxy(73,22);
    printf("desejar retornar ao menu.\n");
}

void iniciar(){
    printf("\n\n");
    printf("                 ---------------------------------\n");
    printf("                      Iniciando o jogo.  \n");
    printf("                 ---------------------------------\n");
    Sleep(500);
    system("cls");
    printf("\n\n");
    printf("                 ---------------------------------\n");
    printf("                      Iniciando o jogo.. \n");
    printf("                 ---------------------------------\n");
    Sleep(500);
    system("cls");
    printf("\n\n");
    printf("                 ---------------------------------\n");
    printf("                      Iniciando o jogo...\n");
    printf("                 ---------------------------------\n");
    Sleep(500);
    system("cls");

    printf("\n\n\n                     O jogo foi criado, voce sera capaz de resolver? HAHAHAHA'");
    printf("\n                                       BOA SORTE!\n\n\n");
    printf("                           Pressione qualquer tecla para continuar...");
    char q = getch();
    system("cls");
    int num, xa, ya, xb, yb, celulas, option2;
    char a;
    int mat[9][9], copia[9][9];
    le_arquivo("sudoku.txt", mat);
    le_arquivo("sudoku.txt", copia); //mantem uma matriz similar a original para comparacao
    int x = 21, y = 12;
    char tecla;

        mostraQuadro(mat, copia, &celulas);
        while(1){
                informacaoCelulas(celulas);
                observacoes();
                gotoxy(x, y); // x = coluna // y = linha
                restaurarCursor();
                tecla = getch();
                if(tecla == 72 || tecla == 'w') //cima
                    --y;
                if(tecla == 75 || tecla == 'a') //direita
                    x -= 4;
                if(tecla == 77 || tecla == 'd') //esquerda
                    x += 4;
                if(tecla == 80 || tecla == 's') //baixo
                    ++y;

                if(x < 21)
                    x = 53;
                if(x > 53)
                    x = 21;
                if(y < 12)
                    y = 20;
                if(y > 20)
                    y = 12;

                if(tecla == 13) { //enter
                    xa = (x-21)/4;
                    ya = y-12;
                    gotoxy(21, 22);
                        if(copia[ya][xa] == 0){
                            printf("\n\n     Digite o numero a ser colocado nessa posicao: ");
                            while(1){
                                scanf("%d", &num);
                                mat[ya][xa] = num;
                                if(num < 1 || num > 9)
                                    printf("Numero invalido, digite outro: ");
                                else
                                    break;
                            }
                            system("cls");
                            mostraQuadro(mat, copia, &celulas);
                            gotoxy(21, 12);
                        }
                        else
                            printf("Posicao ja ocupada originalmente, selecione outra!\n");

                }
                if(tecla == 27){ // ESC
                    esconderCursor();
                    gotoxy(21, 22);
                    option2 = 1;
                    while(1){
                        if(tecla == 80 || tecla == 's')
                            option2 = 2;

                        if(tecla == 72 || tecla == 'w')
                            option2 = 1;

                        system("cls");
                        mostraQuadro(mat, copia, &celulas);
                        informacaoCelulas(celulas);
                        observacoes();
                        printf("   Deseja voltar ao menu?\n");
                        if(option2 == 1){
                            printf("      -> SIM\n");
                            printf("      NAO\n");
                            tecla = getch();
                            if(tecla == 13){
                                system("cls");
                                menu();
                            }
                        }
                        if(option2 == 2){
                            printf("      SIM\n");
                            printf("      -> NAO\n");
                            tecla = getch();
                            if(tecla == 13){
                                system("cls");
                                mostraQuadro(mat, copia, &celulas);
                                break;
                            }
                        }
                    }

                }
                if(tecla == 'c'){
                    system("cls");
                    esconderCursor();
                    if(conferirJogo(mat, celulas) == 1){
                        printf("\n\n\n");
                        printf("-----------------------------------------------------------------------------\n");
                        printf("             Parabens! Voce venceu o desafio!\n");
                        printf("\n               Pressione qualquer tecla para voltar ao menu...\n");
                        printf("-----------------------------------------------------------------------------\n");
                        q = getch();
                        system("cls");
                        menu();
                    }
                    else{
                        printf("\n\n\n");
                        printf("-----------------------------------------------------------------------------\n");
                        printf("       Seu quadro ainda nao está correto, continue tentando!\n");
                        printf("\n                           Pressione qualquer tecla para continuar...\n");
                        printf("-----------------------------------------------------------------------------\n");
                        q = getch();
                        system("cls");
                        mostraQuadro(mat, copia, &celulas);
                    }
                }
        }
}

void gotoxy(int x, int y) { //mudar coordenadas do cursor
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main(){
    menu();

    return 0;
}
