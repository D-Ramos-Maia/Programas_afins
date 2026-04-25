#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char tab_facil[10][10];
char tab_med[20][20];
char tab_dif[30][30];

int mina_1[2], mina_2[2], mina_3[2]; //posicao 0 = linha, posicao 1 = coluna
int nav_2x1_1[3], nav_2x1_2[3], nav_4x1[5]; //posicao 0 = linha, posicao 1 a 4 = colunas
int submar_1[4], submar_2[4], submar_3[4]; //posicao 0 = coluna, posicao 1 a 3 = linha
bool ok_1 = false; //Variavel de controle, serve para verificar se as locs 1 estao oks.
bool ok_2 = false; //Variavel de controle, serve para verificar se as locs 2 estao oks.
bool ok_3 = false; //Variavel de controle, serve para verificar se as locs 3 estao oks.

//Funcao que carrega do tabuleiro
void tabuleiro(int tam_tabuleiro){

    //Carrega tabuleiro facil
    if(tam_tabuleiro == 1){

        for(int i = 0; i < 10; i++){

            for(int j = 0; j < 10; j++){

                tab_facil[i][j] = 'x';
            };
        };
    }
    //Carrega tabuleiro medio
    else if(tam_tabuleiro == 2){

        for(int i = 0; i < 20; i++){

            for(int j = 0; j < 20; j++){

                tab_med[i][j] = 'x';
            };
        };
    }
    //Carrega tabuleiro dificil
    else if(tam_tabuleiro == 3){

        for(int i = 0; i < 30; i++){

            for(int j = 0; j < 30; j++){

                tab_dif[i][j] = 'x';
            };
        };
    };
};

//Imprime tabuleiro
void impri_tabuleiro(int q_tabuleiro){

    //Imprime tabuleiro facil
    if(q_tabuleiro == 1){

        for(int i = 0; i < 10; i++){

            for(int j = 0; j < 10; j++){

                printf("%c ", tab_facil[i][j]);
            };

            printf("\n");
        };
    }
    //Imprime tabuleiro medio
    else if(q_tabuleiro == 2){

        for(int i = 0; i < 20; i++){

            for(int j = 0; j < 20; j++){

                printf("%c ", tab_med[i][j]);
            };
            printf("\n");
        };
    }
    //Imprime tabuleiro dificil
    else if(q_tabuleiro == 3){

        for(int i = 0; i < 30; i++){

            for(int j = 0; j < 30; j++){

                printf("%c ", tab_dif[i][j]);
            };

            printf("\n");
        };
    };

};

//Vai atribuir locs aleatorias aos elementos nina, navio e submmarino 1.
void locs_1(int l_1){

    //Loc da mina
    mina_1[0] = rand() % l_1;
    mina_1[1] = rand() % l_1;

    //Loc do navio
    nav_2x1_1[0] = rand() % l_1;
    nav_2x1_1[1] = rand() % l_1;

    if (nav_2x1_1[1] == 0){

        nav_2x1_1[2] = 1;
    }
    else if (nav_2x1_1[1] == l_1 - 1){

        nav_2x1_1[1] = l_1 - 2;
        nav_2x1_1[2] = l_1 - 1;
    }
    else {

        int ale = rand() % 2;

        if (ale == 1){

            nav_2x1_1[2] = nav_2x1_1[1] + 1;
        }
        else {

            nav_2x1_1[2] = nav_2x1_1[1];
            nav_2x1_1[1] = nav_2x1_1[1] - 1;
        }
    }

    //loc do submarino
    submar_1[0] = rand() % l_1;
    submar_1[1] = rand() % l_1;

    if (submar_1[1] == l_1 - 1){

        submar_1[1] = submar_1[1] - 2;
        submar_1[2] = submar_1[1] + 1;
        submar_1[3] = submar_1[2] + 1;
    }
    else if (submar_1[1] == l_1 - 2){

        submar_1[1] = submar_1[1] - 1;
        submar_1[2] = submar_1[1] + 1;
        submar_1[3] = submar_1[2] + 1;
    }
    else{

        submar_1[2] = submar_1[1] + 1;
        submar_1[3] = submar_1[2] + 1;
    }

}

//Vai atribuir locs aleatorias aos elementos nina, navio e submmarino 2.
void locs_2(int l_2){

    //Loc da mina
    mina_2[0] = rand() % l_2;
    mina_2[1] = rand() % l_2;

    //Loc do navio
    nav_2x1_2[0] = rand() % l_2;
    nav_2x1_2[1] = rand() % l_2;

    if (nav_2x1_2[1] == 0){

        nav_2x1_2[2] = 1;
    }
    else if (nav_2x1_2[1] == l_2 - 1){

        nav_2x1_2[1] = l_2 - 2;
        nav_2x1_2[2] = l_2 - 1;
    }
    else {

        int ale = rand() % 2;

        if (ale == 1){

            nav_2x1_2[2] = nav_2x1_2[1] + 1;
        }
        else {

            nav_2x1_2[2] = nav_2x1_2[1];
            nav_2x1_2[1] = nav_2x1_2[1] - 1;
        }
    }

    //loc do submarino
    submar_2[0] = rand() % l_2;
    submar_2[1] = rand() % l_2;

    if (submar_2[1] == l_2 - 1){

        submar_2[1] = submar_2[1] - 2;
        submar_2[2] = submar_2[1] + 1;
        submar_2[3] = submar_2[2] + 1;
    }
    else if (submar_2[1] == l_2 - 2){

        submar_2[1] = submar_2[1] - 1;
        submar_2[2] = submar_2[1] + 1;
        submar_2[3] = submar_2[2] + 1;
    }
    else{

        submar_2[2] = submar_2[1] + 1;
        submar_2[3] = submar_2[2] + 1;
    }

}

//Vai atribuir locs aleatorias aos elementos nina, navio e submmarino 2.
void locs_3(int l_3){

    //Loc da mina
    mina_3[0] = rand() % l_3;
    mina_3[1] = rand() % l_3;

    //Loc do navio
    nav_4x1[0] = rand() % l_3;
    nav_4x1[1] = rand() % l_3;

    int ale = rand() % 2;

    if (nav_4x1[1] == 0){

        nav_4x1[2] = 1;
        nav_4x1[3] = 2;
        nav_4x1[4] = 3;
    }
    else if(nav_4x1[1] == 1){

        if(ale == 0){

            nav_4x1[0] = 0;
            nav_4x1[2] = 1;
            nav_4x1[3] = 2;
            nav_4x1[4] = 3;
        }
        else{

            nav_4x1[1] = 2;
            nav_4x1[2] = 3;
            nav_4x1[3] = 4;
        }
    }
    else if (nav_4x1[1] == l_3 - 1){

        nav_4x1[3] = l_3 - 1;
        nav_4x1[2] = nav_4x1[3] - 1;
        nav_4x1[1] = nav_4x1[2] - 1;
    }
    else if (nav_4x1[1] == l_3 - 2){

        if (ale == 0){

            nav_4x1[3] = l_3 - 1;
            nav_4x1[2] = nav_4x1[3] - 1;
            nav_4x1[1] = nav_4x1[2] - 1;
        }
        else {

            nav_4x1[3] = l_3 - 2;
            nav_4x1[2] = nav_4x1[3] - 1;
            nav_4x1[1] = nav_4x1[2] - 1;
        }
    }
    else{

        if (ale == 0){

            nav_4x1[3] = nav_4x1[1];
            nav_4x1[2] = nav_4x1[3] - 1;
            nav_4x1[1] = nav_4x1[2] - 1;
        }
        else {

            nav_4x1[2] = nav_4x1[1] + 1;
            nav_4x1[3] = nav_4x1[2] + 1;
        }
    }

    //loc do submarino
    submar_3[0] = rand() % l_3;
    submar_3[1] = rand() % l_3;

    if (submar_3[1] == l_3 - 1){

        submar_3[1] = submar_3[1] - 2;
        submar_3[2] = submar_3[1] + 1;
        submar_3[3] = submar_3[2] + 1;
    }
    else if (submar_3[1] == l_3 - 2){

        submar_3[1] = submar_3[1] - 1;
        submar_3[2] = submar_3[1] + 1;
        submar_3[3] = submar_3[2] + 1;
    }
    else{

        submar_3[2] = submar_3[1] + 1;
        submar_3[3] = submar_3[2] + 1;
    }

}

//Vai executar os voids nescessarios para gerar as locs.
void c_locs(int c_tabuleiro){

    if(c_tabuleiro == 1){

        locs_1(10);
    }
    else if (c_tabuleiro == 2){

        locs_1(20);
        locs_2(20);
    }
    else if (c_tabuleiro == 3){

        locs_1(30);
        locs_2(30);
        locs_3(30);
    }
};

//Compara se alguma loc da dificuldade facil e verifica se são diferentes, se nao, os gera novamente
bool c_aleatorio_1 (){

    bool controle = true; //Variavel de controle
    int cont_diferenca = 0; //cantabiliza quando for diferente.

    //Verifica se a mina não conside com o navio
    if (mina_1[0] == nav_2x1_1[0]){

        for (int i = 1; i < 3; i++){

            if(mina_1[1] == nav_2x1_1[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o submarino
    if (mina_1[1] == submar_1[0]){

        for (int i = 1; i < 4; i++){

            if (mina_1[0] == submar_1[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio não conside com o submarino
    for (int i = 1; i < 4; i++){

        if (nav_2x1_1[0] == submar_1[i]){

            for (int j = 1; j < 3; j++){

                if (nav_2x1_1[j] == submar_1[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}

    //Se todos forem diferentes finalisa, se não, sorteira novamente as posicoes
    if (cont_diferenca == 3){

        ok_1 = true;
        return true;
    }
    else {

        return false;
    }

}

//Compara se alguma loc que aparecem na dificuldade facil e media e verifica se sao diferentes, se nao, os gera novamente
bool c_aleatorio_1_2(){

    bool controle = true; //Variavel de controle
    int cont_diferenca = 0; //cantabiliza quando for diferente.

    //Verifica se a mina 1 com a mina 2
    if (mina_1[0] == mina_2[0] && mina_1[1] == mina_2[1]){controle = false;}

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o navio
    if (mina_1[0] == nav_2x1_2[0]){

        for (int i = 1; i < 3; i++){

            if(mina_1[1] == nav_2x1_2[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o submarino
    if (mina_1[1] == submar_2[0]){

        for (int i = 1; i < 4; i++){

            if (mina_1[0] == submar_2[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio 1 nao conside com navio 2
    if (nav_2x1_1[0] == nav_2x1_2[0]){

        for(int i = 1; i < 3; i++){

            for(int j = 1; j < 3; j++){

                if (nav_2x1_1[i] == nav_2x1_2[j]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio não conside com o submarino
    for (int i = 1; i < 4; i++){

        if (nav_2x1_1[0] == submar_2[i]){

            for (int j = 1; j < 3; j++){

                if (nav_2x1_1[j] == submar_2[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verificar se o submarino 1 nao conside com o navio 2
    for (int i = 1; i < 4; i++){

        if (nav_2x1_2[0] == submar_1[i]){

            for (int j = 1; j < 3; j++){

                if (nav_2x1_2[j] == submar_1[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se os submarinos são diferentes
    if (submar_1[0] == submar_2[0]){

        for (int i = 1; i < 4; i++){

            for (int j = 1; j < 4; j++){

                if(submar_1[i] == submar_2[j]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}

    //Se todos forem diferentes finalisa, se não, sorteira novamente as posicoes
    if (cont_diferenca == 7){

        return true;
    }
    else {

        return false;
    }

}

//Compara se alguma loc da dificuldade media e verifica se sao diferentes, se nao, os gera novamente
bool c_aleatorio_2(int c_2){

    //Serve para carregar as posicoes de locs 1.
    while(true){

        if (ok_1 == true){ //Serve para conferir se as locs 1 já estaos oks, se tiverem nao precisam ser sorteadas

            break;
        }

        if (c_aleatorio_1()){ //Carrega as locs 1

            ok_1 = true;
            break;
        }
        else {

            locs_1(c_2);
        }

    }

    //Serve para carregar as posicoes de em comum entre locs 1 e 2.
    while(true){ //Carrega as loc em comum entre a dificuldade facil e media


        if (c_aleatorio_1_2()){ //Carrega as locs 1

            break;
        }

        else {

            locs_2(c_2);
        }

    }

    bool controle = true; //Variavel de controle
    int cont_diferenca = 0; //cantabiliza quando for diferente.

    //Verifica se a mina não conside com o navio
    if (mina_2[0] == nav_2x1_2[0]){

        for (int i = 1; i < 3; i++){

            if(mina_2[1] == nav_2x1_2[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o submarino
    if (mina_2[1] == submar_2[0]){

        for (int i = 1; i < 4; i++){

            if (mina_2[0] == submar_2[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio não conside com o submarino
    for (int i = 1; i < 4; i++){

        if (nav_2x1_2[0] == submar_2[i]){

            for (int j = 1; j < 3; j++){

                if (nav_2x1_2[j] == submar_2[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}

    //Se todos forem diferentes finalisa, se não, sorteira novamente as posicoes
    if (cont_diferenca == 3){

        ok_2 = true;
        return true;
    }
    else {

        return false;
    }

}

//Compara se alguma loc que aparecem na dificuldade facil e dificil e verifica se sao diferentes, se nao, os gera novamente
bool c_aleatorio_1_3(){

    bool controle = true; //Variavel de controle
    int cont_diferenca = 0; //cantabiliza quando for diferente.

    //Verifica se a mina 1 com a mina 3
    if (mina_1[0] == mina_3[0] && mina_1[1] == mina_3[1]){controle = false;}

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o navio
    if (mina_1[0] == nav_4x1[0]){

        for (int i = 1; i < 5; i++){

            if(mina_1[1] == nav_4x1[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o submarino
    if (mina_1[1] == submar_3[0]){

        for (int i = 1; i < 4; i++){

            if (mina_1[0] == submar_3[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio 1 nao conside com navio 3
    if (nav_2x1_1[0] == nav_4x1[0]){

        for(int i = 1; i < 3; i++){

            for(int j = 1; j < 5; j++){

                if (nav_2x1_1[i] == nav_4x1[j]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio não conside com o submarino
    for (int i = 1; i < 4; i++){

        if (nav_2x1_1[0] == submar_3[i]){

            for (int j = 1; j < 3; j++){

                if (nav_2x1_1[j] == submar_3[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verificar se o submarino 1 nao conside com o navio 3
    for (int i = 1; i < 4; i++){

        if (nav_4x1[0] == submar_1[i]){

            for (int j = 1; j < 3; j++){

                if (nav_4x1[j] == submar_1[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se os submarinos são diferentes
    if (submar_1[0] == submar_3[0]){

        for (int i = 1; i < 4; i++){

            for (int j = 1; j < 4; j++){

                if(submar_1[i] == submar_3[j]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}

    //Se todos forem diferentes finalisa, se não, sorteira novamente as posicoes
    if (cont_diferenca == 7){

        return true;
    }
    else {

        return false;
    }

}

//Compara se alguma loc que aparecem na dificuldade facil e media e verifica se sao diferentes, se nao, os gera novamente
bool c_aleatorio_2_3(){

    bool controle = true; //Variavel de controle
    int cont_diferenca = 0; //cantabiliza quando for diferente.

    //Verifica se a mina 1 com a mina 3
    if (mina_2[0] == mina_3[0] && mina_2[1] == mina_3[1]){controle = false;}

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o navio
    if (mina_2[0] == nav_4x1[0]){

        for (int i = 1; i < 5; i++){

            if(mina_2[1] == nav_4x1[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o submarino
    if (mina_2[1] == submar_3[0]){

        for (int i = 1; i < 4; i++){

            if (mina_2[0] == submar_3[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio 1 nao conside com navio 3
    if (nav_2x1_2[0] == nav_4x1[0]){

        for(int i = 1; i < 3; i++){

            for(int j = 1; j < 5; j++){

                if (nav_2x1_2[i] == nav_4x1[j]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio não conside com o submarino
    for (int i = 1; i < 4; i++){

        if (nav_2x1_2[0] == submar_3[i]){

            for (int j = 1; j < 3; j++){

                if (nav_2x1_2[j] == submar_3[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verificar se o submarino 1 nao conside com o navio 3
    for (int i = 1; i < 4; i++){

        if (nav_4x1[0] == submar_2[i]){

            for (int j = 1; j < 3; j++){

                if (nav_4x1[j] == submar_2[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se os submarinos são diferentes
    if (submar_2[0] == submar_3[0]){

        for (int i = 1; i < 4; i++){

            for (int j = 1; j < 4; j++){

                if(submar_2[i] == submar_3[j]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}

    //Se todos forem diferentes finalisa, se não, sorteira novamente as posicoes
    if (cont_diferenca == 7){

        return true;
    }
    else {

        return false;
    }

}

//Compara se alguma loc da dificuldade dificil e verifica se sao diferentes, se nao, os gera novamente
bool c_aleatorio_3(){

    //Serve para carregar as posicoes de locs 1 e 2.
    while(true){

        if (ok_2 == true){ //Serve para conferir se as locs 1 já estaos oks, se tiverem nao precisam ser sorteadas

            break;
        }

        if (c_aleatorio_2(30)){ //Carrega as locs 1 e 2

            ok_2 = true;
            break;
        }
        else {

            locs_2(30); //Sorteia novamente se tiver considencias
        }

    }

    //Serve para carregar as posicoes de em comum entre locs 1 e 3.
    while(true){ //Carrega as loc em comum entre a dificuldade facil e media


        if (c_aleatorio_1_3()){ //Carrega as locs 1

            break;
        }
        else {

            locs_3(30);
        }
    }

    //Serve para carregar as posicoes de em comum entre locs 2 e 3.
    while(true){ //Carrega as loc em comum entre a dificuldade facil e media


        if (c_aleatorio_2_3()){ //Carrega as locs 1

            break;
        }
        else{

            locs_3(30);
        }
    }

    bool controle = true; //Variavel de controle
    int cont_diferenca = 0; //cantabiliza quando for diferente.

    //Verifica se a mina não conside com o navio
    if (mina_3[0] == nav_4x1[0]){

        for (int i = 1; i < 5; i++){

            if(mina_3[1] == nav_4x1[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se a mina não conside com o submarino
    if (mina_3[1] == submar_3[0]){

        for (int i = 1; i < 4; i++){

            if (mina_3[0] == submar_3[i]){
                controle = false;
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}
    controle = true;

    //Verifica se o navio não conside com o submarino
    for (int i = 1; i < 4; i++){

        if (nav_4x1[0] == submar_3[i]){

            for (int j = 1; j < 3; j++){

                if (nav_4x1[j] == submar_3[0]){

                    controle = false;
                }
            }
        }
    }

    //Implementa se for diferente
    if (controle){cont_diferenca++;}

    //Se todos forem diferentes finalisa, se não, sorteira novamente as posicoes
    if (cont_diferenca == 3){

        ok_3 = true;
        return true;
    }
    else {

        return false;
    }

}

//Seta as condicoes iniciais
bool iniciar_tabuleiro(int q_tabuleiro){

    tabuleiro(q_tabuleiro); //Inicia o tabuleiro
    c_locs(q_tabuleiro); //Faz o primeiro sorteio

    if (q_tabuleiro == 1){

        while (true){

            if (c_aleatorio_1()){break;}
            locs_1(10);//Faz um novo sorteio
        }
        return true;
    }
    else if (q_tabuleiro == 2){

        while (true){

            if (c_aleatorio_2(20)){break;}

            if (!ok_1){locs_1(20);} //Faz um novo sorteio das locs 1 caso elas ainda não tenha sido sorteada
            locs_2(20);//Faz um novo sorteio
        }
        return true;
    }
    else if (q_tabuleiro == 3){

        while (true){

            if (c_aleatorio_3()){break;}

            if (!ok_1){locs_1(30);} //Faz um novo sorteio das locs 1 caso elas ainda não tenha sido sorteada
            if (!ok_2){locs_2(30);} //Faz um novo sorteio das locs 1 caso elas ainda não tenha sido sorteada
            locs_3(30);

        }
        return true;
    }
    else {

        return false;
    }

}

//Verifica se uma loc fornecida e uma loc que conside com algum objeto da loc 1
int veri_loc_1 (int linha, int coluna){

    //Verifica se e igual a loc da mina
    if (linha == mina_1[0] && coluna == mina_1[1]){return 0;}

    //Verifica se e igual a loc do navio
    if (linha == nav_2x1_1[0]){

        for (int i = 1; i < 3; i++){

            if (coluna == nav_2x1_1[i]){

                return 1;
            }
        }
    }

    //Verifica se e igual a loc do submarino
    if (coluna == submar_1[0]){

        for (int i = 1; i < 4; i++){

            if (linha == submar_1[i]){

                return 2;
            }
        }
    }

    //Caso nao ache nada retorna 3.
    return 3;
}

//Verifica se uma loc fornecida e uma loc que conside com algum objeto da loc 2
int veri_loc_2 (int linha, int coluna){

    //Verifica se e igual a loc da mina
    if (linha == mina_2[0] && coluna == mina_2[1]){return 0;}

    //Verifica se e igual a loc do navio
    if (linha == nav_2x1_2[0]){

        for (int i = 1; i < 3; i++){

            if (coluna == nav_2x1_2[i]){

                return 1;
            }
        }
    }

    //Verifica se e igual a loc do submarino
    if (coluna == submar_2[0]){

        for (int i = 1; i < 4; i++){

            if (linha == submar_2[i]){

                return 2;
            }
        }
    }

    //Caso nao ache nada retorna 3.
    return 3;
}

//Verifica se uma loc fornecida e uma loc que conside com algum objeto da loc 3
int veri_loc_3 (int linha, int coluna){

    //Verifica se e igual a loc da mina
    if (linha == mina_3[0] && coluna == mina_3[1]){return 0;}

    //Verifica se e igual a loc do navio
    if (linha == nav_4x1[0]){

        for (int i = 1; i < 5; i++){

            if (coluna == nav_4x1[i]){

                return 1;
            }
        }
    }

    //Verifica se e igual a loc do submarino
    if (coluna == submar_3[0]){

        for (int i = 1; i < 4; i++){

            if (linha == submar_3[i]){

                return 2;
            }
        }
    }

    //Caso nao ache nada retorna 3.
    return 3;
}

//A funcao que consulta se uma loc fornecida conside com a loc de uma mina/navio/submarino
int veri_loc (int linha, int coluna){

    int var_controle; //Uma variavel de controle, que vai receber e retornar valores

    //Verifica se conside com alguma loc 1
    if (ok_1){

        var_controle = veri_loc_1(linha, coluna);

        //se Var_controle for diferente de 4, entao a posicao conside
        if (var_controle != 3){

            return var_controle;
        }
    }

    //Verifica se conside com alguma loc 2
    if (ok_2){

        var_controle = veri_loc_2(linha, coluna);

        //se Var_controle for diferente de 4, entao a posicao conside
        if (var_controle != 3) {

            return var_controle;
        }
    }

    //Verifica se conside com alguma loc 3
    if (ok_3){

        var_controle = veri_loc_3(linha, coluna);

        //se Var_controle for diferente de 4, entao a posicao conside
        if (var_controle != 3) {

            return var_controle;
        }
    }

    return 3;
}

//Funcao principal
int main (){

    int set_dificuldade, q_vitoria; //Seletor de dificuldade e a variavel que define qual é fator de vitoria respectivamente
    int fator_vitoria = 0; //Registra a quantidades de acertos e garante a vitoria

    printf("Informe a dificuldade (1 - Facil, 2 - Medio, 3 - Dificil): ");
        scanf("%d", &set_dificuldade);

    if(set_dificuldade == 1){

        q_vitoria = 6;
    }
    else if (set_dificuldade == 2){

        q_vitoria = 12;
    }
    else if (set_dificuldade == 3){

        q_vitoria = 20;
    }

    srand(time(NULL)); //Iniciar a semente aleatortia

    //Inicia o tabuleiro a comeca a executar o jogo
    if (iniciar_tabuleiro(set_dificuldade)){

        printf("Iniciando jogo \n\n");

        while (true) {
            int receber, linha, coluna;

            impri_tabuleiro(set_dificuldade);

            printf("\nInforme as posicoes (Linha[Entre 1 e %d], coluna[Entre 1 e %d]): ", set_dificuldade * 10, set_dificuldade * 10);
            // O espaço antes de %d ignora espaços/enters acumulados
            if (scanf(" %d, %d", &linha, &coluna) != 2) {
                printf("Entrada invalida! Use o formato: linha, coluna\n");
                while (getchar() != '\n'); // Limpa o lixo do teclado
                continue;
            }

            // --- PROTEÇÃO 1: Evitar que o programa quebre se digitar coordenadas fora do mapa ---
            int limite = (set_dificuldade == 1) ? 10 : (set_dificuldade == 2) ? 20 : 30; // Ajuste conforme seu tamanho
            if (linha < 1 || linha > limite || coluna < 1 || coluna > limite) {
                printf("Coordenada fora do tabuleiro! Tente novamente.\n");
                continue;
            }

            // --- PROTEÇÃO 2: Verificar se o jogador ja atirou aqui
            char *posicao_atual; // Ponteiro para facilitar a checagem independente do tabuleiro
            if (set_dificuldade == 1) posicao_atual = &tab_facil[linha - 1][coluna - 1];
            else if (set_dificuldade == 2) posicao_atual = &tab_med[linha -1][coluna - 1];
            else posicao_atual = &tab_dif[linha -1][coluna -1];

            if (*posicao_atual != 'x') {
                printf("Voce ja atirou aqui! Escolha outro lugar.\n");
                continue;
            }

            receber = veri_loc(linha, coluna);

            // Altera a matriz e so conta vitoria se for algo novo
            if (receber == 0) {
                *posicao_atual = 'M';
                fator_vitoria++;
            }
            else if (receber == 1) {
                *posicao_atual = 'N';
                fator_vitoria++;
            }
            else if (receber == 2) {
                *posicao_atual = 'S';
                fator_vitoria++;
            }
            else {
                *posicao_atual = '0'; // Errou (Agua)
            }

            if (fator_vitoria == q_vitoria) {
                impri_tabuleiro(set_dificuldade);
                printf("\nParabens!!! Voce venceu!!!!\n");
                break;
            }
        }
    }
    else {

        printf("Dificuldade invalida");
        return 0;
    }

}
