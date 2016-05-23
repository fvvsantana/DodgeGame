//esse arquivo declara as funções e structs relativas à fisica do jogo em SDL

#ifndef SDL_PHYSICS_H
    #define SDL_PHYSICS_H

    #include <SDL.h>
    #include "bool.h"

    //struct de direções do comando:
    typedef struct ctrl{
        bool left, right, up, down;
    } Ctrl;

    //struct de controle de objetos: (handlingX, handlingY, freqCtrl); "handling == dirigibilidade"
    typedef struct hand {
        int hX, hY, fC;
    } Hand;

    // recebe os parametros: (velocidadeX, velocidadeY, aceleraçãoX, aceleraçãoY, freqAcel)
    typedef struct var{
        int vX, vY, aX, aY, fA;
    } Var;

    //recebe o caminho do objeto: (X inicial, Y inicial, X final, Y final)
    typedef struct rota{
        int x1, y1, x2, y2;
    } Rota;

    //detecta colisão entre retangulo e parede, e inverte valor da velocidade: (flavio)
    void collRectWall(SDL_Rect* rect, Var* varObj, const int* SCREEN_WIDTH, const int* SCREEN_HEIGHT);
    //atualiza a posição do objeto de acordo com a velocidade: (flavio)
    void velObj(int *pX, int *pY, int *vX, int *vY);
    //atualiza a velocidade do personagem de acordo com a aceleração e com a freqAcel: (flavio)
    void acelObj(Var* varObj);
    //(usa static) atualiza a velocidade de acordo com os comandos contidos na struct Ctrl e com a freqCtrl: (flavio)
    void doTheCtrl1(Ctrl* ctrlObj, Var* varObj, Hand* handObj);
    //(usa static) atualiza a velocidade de acordo com os comandos contidos na struct Ctrl e com a freqCtrl: (flavio)
    void doTheCtrl2(Ctrl* ctrlObj, Var* varObj, Hand* handObj);
    //pega os comandos para o objeto:
    void ctrlObj(SDL_Event* event, Ctrl* ctrlObj);
    //verifica se duas circunferências se intersectam: (flavio)
    bool coll2Circles(SDL_Rect* rect1, SDL_Rect* rect2);
    //verifica se o inimigo bateu na parede e inverte sua velocidade perpendicularmente: (flavio)
    void collEnemyWall(SDL_Rect* rect, Rota* rotaObj, Var* varObj);
#endif