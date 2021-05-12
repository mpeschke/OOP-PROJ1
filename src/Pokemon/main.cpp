/**
    main.cpp

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "stdafx.h"

#ifndef WIN32
#define _tmain main
#else
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

using namespace BLL;

Caracteristica traduzir_caracteristica(const int i)
{
    switch(i)
    {
        case 1:
            return Caracteristica::Ataque;
            break;
        case 2:
            return Caracteristica::Defesa;
            break;
        case 3:
            return Caracteristica::Agilidade;
            break;
        case 4:
            return Caracteristica::HP;
            break;
        default:
            return Caracteristica::Indefinido;
    };
}

int _tmain(int argc, ::TCHAR* argv[])
{
    Jogo jogo = Jogo(false);

    for(int i = 0; i < 1; i++)
    {
        tcout << "Rodada " << i+1 << ", jogador1, digite o número da carta [de 1 a 6]: " << std::endl;
        int carta1;
        tcin >> carta1;
        tcout << "Digite a característica [de 1 a 4]: " << std::endl;
        int caracteristica1;
        tcin >> caracteristica1;
        tcout << "Jogador2, digite o número da carta [de 1 a 6]: " << std::endl;
        int carta2;
        tcin >> carta2;

        jogo.get_rodadas()[i].set_caracteristica_escolhida(traduzir_caracteristica(caracteristica1));
    }

    return 0;
}
