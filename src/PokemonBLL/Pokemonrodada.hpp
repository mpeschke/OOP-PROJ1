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
    Pokemonrodada(const Pokemon& pokemon1, const Pokemon& pokemon2, const Caracteristica caracteristica_escolhida);
protected:
    Pokemon m_pokemon1;
    Pokemon m_pokemon2;
    Pokemon m_vencedor;
    bool m_jogado;
    Caracteristica m_caracteristica_escolhida;
public:
    const Pokemon& get_vencedor() const;
    bool get_jogado() const;
    Caracteristica get_caracteristica_escolhida() const;

    void set_vencedor(const Pokemon& pokemon);
    void set_jogado(const bool jogado);
    void set_caracteristica_escolhida(const Caracteristica caracteristica);
public:
    void jogar();
public:
    virtual ~Pokemonrodada();
};

} /* namespace BLL */
