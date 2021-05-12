/**
    Pokemonrodada.cpp
    Purpose: Representa a rodada de cartas de um jogo

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "Pokemonrodada.hpp"
#include "Exceptions.hpp"

namespace BLL {

Pokemonrodada::Pokemonrodada()
    : m_jogado(false), m_caracteristica_escolhida(Caracteristica::Indefinido)
{}

Pokemonrodada::Pokemonrodada(const Pokemon& pokemon1, const Pokemon& pokemon2, const Caracteristica caracteristica_escolhida)
    : m_pokemon1(pokemon1), m_pokemon2(pokemon2), m_jogado(false), m_caracteristica_escolhida(caracteristica_escolhida)
{
    this->m_pokemon1.set_caracteristica_rodada(this->m_caracteristica_escolhida);
    this->m_pokemon2.set_caracteristica_rodada(this->m_caracteristica_escolhida);
}

const Pokemon& Pokemonrodada::get_vencedor() const
{return this->m_vencedor;}

bool Pokemonrodada::get_jogado() const
{return this->m_jogado;}

Caracteristica Pokemonrodada::get_caracteristica_escolhida() const
{return this->m_caracteristica_escolhida;}

void Pokemonrodada::set_vencedor(const Pokemon& pokemon)
{this->m_vencedor = pokemon;}

void Pokemonrodada::set_jogado(const bool jogado)
{this->m_jogado = jogado;}

void Pokemonrodada::set_caracteristica_escolhida(const Caracteristica caracteristica)
{this->m_caracteristica_escolhida = caracteristica;}

void Pokemonrodada::jogar()
{
    this->m_vencedor = this->m_pokemon1.getvencedorrodada(this->m_pokemon2);
    this->set_jogado(true);
}

Pokemonrodada::~Pokemonrodada()
{}

} /* namespace BLL */
