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
    int i = 0;
    std::vector<Pokemon> mao_jogador1;
    std::vector<Pokemon> mao_jogador2;

    // O computador 'distribui as cartas', gerando 6 cartas pokemon aleatórias para cada jogador.
    g_DistribuirCartas("jogador1", "jogador2", &mao_jogador1, &mao_jogador2);
    tstring vencedorturnoanterior = mao_jogador1[0].get_jogador();

    Jogo jogo = Jogo(false, mao_jogador1.size());

    // Enquanto os jogadores tiverem pelo menos um Pokemon não desmaiado, continuar jogando.
    while(jogo.continuarjogando(mao_jogador1, mao_jogador2))
    {
        int carta1;
        int caracteristica1;
        int carta2;

        do{
            tcout << "Rodada " << i+1 << ", jogador1 digite o número da carta [de 1 a 6]: " << std::endl;
            tcin >> carta1;
            if(!mao_jogador1[carta1-1].podejogar())
                tcout << "Carta " << carta1 << " é um Pokemon desmaiado. Escolha um Pokemon ativo." << std::endl;
        }while(!mao_jogador1[carta1-1].podejogar());

        tcout << vencedorturnoanterior <<  ", digite a característica [de 1 a 4]: " << std::endl;
        tcin >> caracteristica1;

        do{
            tcout << "Jogador2, digite o número da carta [de 1 a 6]: " << std::endl;
            tcin >> carta2;
            if(!mao_jogador2[carta2-1].podejogar())
                tcout << "Carta " << carta2 << " é um Pokemon desmaiado. Escolha um Pokemon ativo." << std::endl;
        }while(!mao_jogador2[carta2-1].podejogar());

        Pokemonrodada rodada = Pokemonrodada(
            mao_jogador1[carta1-1], 
            mao_jogador2[carta2-1],
            traduzir_caracteristica(caracteristica1)
        );

        rodada.jogar();

        jogo.get_rodadas().push_back(rodada);
        // O vencedor do turno anterior seleciona a característica.
        // Exceções:
        // 1. Na primeira rodada o jogador1 escolhe
        // 2. Em caso de empate o jogador1 escolhe
        vencedorturnoanterior = rodada.empate() ? vencedorturnoanterior : rodada.get_vencedor().get_jogador();

        i++;
    }

    if(jogo.tem_vencedor(mao_jogador1, mao_jogador2))
        tcout << "Vencedor: " << jogo.get_vencedor(mao_jogador1, mao_jogador2) << std::endl;
    else
        tcout << "Não houve vencedor (empate)" << std::endl;

    return 0;
}
