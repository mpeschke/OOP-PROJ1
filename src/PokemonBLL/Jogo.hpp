/**
    Jogo.cpp
    Purpose: classe do jogo

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include "stdafx.h"
#include "Pokemonrodada.hpp"
#include <string>
#include <vector>
#include <list>

namespace BLL {

class Jogo {
protected:
    Jogo();
public:
    Jogo(const bool computadorjoga, const unsigned int numero_cartas_pras_rodadas);
protected:
    std::vector<Pokemonrodada> m_rodadas;
    bool m_computadorjoga;
    unsigned int m_numero_cartas_pras_rodadas;
public:
    std::vector<Pokemonrodada>& get_rodadas();
    const bool get_computadorjoga() const;
    void set_rodadas(const std::vector<Pokemonrodada>& rodadas);
    void set_computadorjoga(const bool computadorjoga);
    bool tem_vencedor(const std::vector<Pokemon>& maojogador1, const std::vector<Pokemon>& maojogador2) const;
    BLL::tstring get_vencedor(const std::vector<Pokemon>& maojogador1, const std::vector<Pokemon>& maojogador2) const;
public:
    bool continuarjogando(const std::vector<Pokemon>& maojogador1, const std::vector<Pokemon>& maojogador2) const;
public:
    virtual ~Jogo();
};

} /* namespace BLL */
