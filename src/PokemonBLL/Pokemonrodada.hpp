/**
    Pokemonrodada.cpp
    Purpose: Representa a rodada de cartas de um jogo

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include "stdafx.h"
#include "Pokemon.hpp"
#include <string>
#include <vector>
#include <list>

namespace BLL {

class Pokemonrodada {
public:
    Pokemonrodada();
    Pokemonrodada(Pokemon& pokemon1, Pokemon& pokemon2, const Caracteristica caracteristica_escolhida);
protected:
    Pokemon* m_pokemon1;
    Pokemon* m_pokemon2;
    bool m_jogado;
    Caracteristica m_caracteristica_escolhida;
public:
    const Pokemon& get_vencedor() const;
    bool get_jogado() const;
    Caracteristica get_caracteristica_escolhida() const;

    void set_jogado(const bool jogado);
    void set_caracteristica_escolhida(const Caracteristica caracteristica);
public:
    void jogar();
    bool empate() const;
    bool jogador1_venceu() const;
    bool jogador2_venceu() const;
public:
    virtual ~Pokemonrodada();
};

} /* namespace BLL */
