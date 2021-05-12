/**
    test_pokemonbll.hpp
    Purpose: Unit Tests for the PokemonBLL class.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once
#include <boost/test/included/unit_test.hpp>
#include "stdafx.h"

/*
## 1. Nome da classe é Onibus

## 2. Deve haver um método inicial que instancie a classe Onibus

## 3. A classe Onibus deve inicializar com o número de pontos, a capacidade para pessoas sentadas e a capacidade para pessoas em pé
*/
BOOST_AUTO_TEST_SUITE(suite_onibus_inicializacao)

BOOST_AUTO_TEST_CASE(test_onibus_inicializa_sucesso)
{
    BOOST_TEST_MESSAGE( "TEST CENÁRIO 2. Deve haver um método inicial que instancie a classe Onibus" );
    BOOST_TEST ( true );
}

BOOST_AUTO_TEST_SUITE_END()
