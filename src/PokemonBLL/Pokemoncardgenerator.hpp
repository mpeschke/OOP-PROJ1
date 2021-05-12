/**
    Pokemoncardgenerator.hpp
    Purpose: Geração de cartas embaralhadas.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include "stdafx.h"
#include "Pokemon.hpp"
#include "Pokemonrodada.hpp"
#include <string>
#include <vector>
#include <list>

namespace BLL {

void g_GerarRodadas(const BLL::tstring jogador1, const BLL::tstring jogador2, std::vector<Pokemonrodada>* rodadas);
} /* namespace BLL */
