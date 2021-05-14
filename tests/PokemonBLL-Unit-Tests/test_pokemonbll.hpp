/**
    test_pokemonbll.hpp
    Purpose: Unit Tests para o jogo Pokemon.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once
#include <boost/test/included/unit_test.hpp>
#include "stdafx.h"

BOOST_AUTO_TEST_SUITE(suite_pokemon)

BOOST_AUTO_TEST_CASE(test_pokemon_vantagem_electric_over_water)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO VANTAGEM. Electric sobre Water." );
    Pokemon jogadorelectric = Pokemon(BLL::g_PikachuSt, Status::Ativo, "", Caracteristica::Agilidade);
    Pokemon jogadorwater = Pokemon(BLL::g_TotodileSt, Status::Ativo, "", Caracteristica::Agilidade);
    BOOST_TEST ( jogadorelectric.temvantagem(jogadorwater) );
}

BOOST_AUTO_TEST_CASE(test_pokemon_vantagem_water_over_fire)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO VANTAGEM. Water sobre Fire." );
    Pokemon jogadorwater = Pokemon(BLL::g_TotodileSt, Status::Ativo, "", Caracteristica::Agilidade);
    Pokemon jogadorfire = Pokemon(BLL::g_CharmanderSt, Status::Ativo, "", Caracteristica::Agilidade);
    BOOST_TEST ( jogadorwater.temvantagem(jogadorfire) );
}

BOOST_AUTO_TEST_CASE(test_pokemon_vantagem_fire_over_grass)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO VANTAGEM. Fire sobre Grass." );
    Pokemon jogadorfire = Pokemon(BLL::g_CharmanderSt, Status::Ativo, "", Caracteristica::Agilidade);
    Pokemon jogadorgrass = Pokemon(BLL::g_BayleefSt, Status::Ativo, "", Caracteristica::Agilidade);
    BOOST_TEST ( jogadorfire.temvantagem(jogadorgrass) );
}

BOOST_AUTO_TEST_CASE(test_pokemon_vantagem_grass_over_electric)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO VANTAGEM. Grass sobre Electric." );
    Pokemon jogadorgrass = Pokemon(BLL::g_BayleefSt, Status::Ativo, "", Caracteristica::Agilidade);
    Pokemon jogadorelectric = Pokemon(BLL::g_PikachuSt, Status::Ativo, "", Caracteristica::Agilidade);
    BOOST_TEST ( jogadorgrass.temvantagem(jogadorelectric) );
}

BOOST_AUTO_TEST_SUITE_END()
