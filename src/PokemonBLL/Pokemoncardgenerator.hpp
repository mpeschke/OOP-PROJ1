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

const PokemonMonstro g_CharmanderSt = {
    "Charmander",
    4000U,
    7000U,
    35U,
    25000U,
    Tipo::Fire
};

const PokemonMonstro g_HoOhSt = {
    "Ho-Oh",
    10000U,
    6000U,
    40U,
    40000U,
    Tipo::Fire
};

const PokemonMonstro g_VulpixSt = {
    "Vulpix",
    3000U,
    5000U,
    50U,
    20000U,
    Tipo::Fire
};

const PokemonMonstro g_MagmarSt = {
    "Magmar",
    5000U,
    4000U,
    25U,
    50000U,
    Tipo::Fire
};

const PokemonMonstro g_PikachuSt = {
    "Pikachu",
    7000U,
    8000U,
    40U,
    20000U,
    Tipo::Electric
};

const PokemonMonstro g_AmpharosSt = {
    "Ampharos",
    9000U,
    10000U,
    35U,
    50000U,
    Tipo::Electric
};

const PokemonMonstro g_DedenneSt = {
    "Dedenne",
    4000U,
    4000U,
    50U,
    35000U,
    Tipo::Electric
};

const PokemonMonstro g_JolteonSt = {
    "Jolteon",
    5000U,
    5000U,
    50U,
    45000U,
    Tipo::Electric
};

const PokemonMonstro g_BayleefSt = {
    "Bayleef",
    9000U,
    6000U,
    20U,
    50000U,
    Tipo::Grass
};

const PokemonMonstro g_TreeckoSt = {
    "Treecko",
    6000U,
    6000U,
    35U,
    35000U,
    Tipo::Grass
};

const PokemonMonstro g_ShayminSt = {
    "Shaymin",
    3000U,
    7000U,
    50U,
    45000U,
    Tipo::Grass
};

const PokemonMonstro g_BulbasaurSt = {
    "Bulbasaur",
    7000U,
    2000U,
    50U,
    10000U,
    Tipo::Grass
};

const PokemonMonstro g_TotodileSt = {
    "Totodile",
    7000U,
    3000U,
    30U,
    40000U,
    Tipo::Water
};

const PokemonMonstro g_SquirtleSt = {
    "Squirtle",
    6000U,
    5000U,
    40U,
    30000U,
    Tipo::Water
};

const PokemonMonstro g_LaprasSt = {
    "Lapras",
    10000U,
    5000U,
    50U,
    40000U,
    Tipo::Water
};

const PokemonMonstro g_MarilSt = {
    "Maril",
    3000U,
    5000U,
    40U,
    40000U,
    Tipo::Water
};

void g_DistribuirCartas(const BLL::tstring jogador1, const BLL::tstring jogador2, std::vector<Pokemon>* cartasjogador1, std::vector<Pokemon>* cartasjogador2);
} /* namespace BLL */
