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
    : m_jogado(false), m_caracteristica_escolhida(Caracteristica::Indefinido), m_pokemon1(NULL), m_pokemon2(NULL)
{}

Pokemonrodada::Pokemonrodada(Pokemon& pokemon1, Pokemon& pokemon2, const Caracteristica caracteristica_escolhida)
    : m_pokemon1(&pokemon1), m_pokemon2(&pokemon2), m_jogado(false), m_caracteristica_escolhida(caracteristica_escolhida)
{
    this->m_pokemon1->set_caracteristica_rodada(this->m_caracteristica_escolhida);
    this->m_pokemon2->set_caracteristica_rodada(this->m_caracteristica_escolhida);
}

const Pokemon& Pokemonrodada::get_vencedor() const
{
    if(this->empate())
        throw CExcecao("Não houve vencedor");
    return this->m_pokemon1->get_status() == Status::Ativo ? *(this->m_pokemon1) : *(this->m_pokemon2);
}

bool Pokemonrodada::get_jogado() const
{return this->m_jogado;}

Caracteristica Pokemonrodada::get_caracteristica_escolhida() const
{return this->m_caracteristica_escolhida;}

void Pokemonrodada::set_jogado(const bool jogado)
{this->m_jogado = jogado;}

void Pokemonrodada::set_caracteristica_escolhida(const Caracteristica caracteristica)
{this->m_caracteristica_escolhida = caracteristica;}

void Pokemonrodada::jogar()
{
    this->m_pokemon1->getvencedorrodada(*(this->m_pokemon2));
    this->set_jogado(true);
}

bool Pokemonrodada::empate() const
{return this->m_pokemon1->get_status() == Status::Desmaiado && this->m_pokemon2->get_status() == Status::Desmaiado;}

bool Pokemonrodada::jogador1_venceu() const
{return this->m_pokemon1->get_status() == Status::Ativo;}

bool Pokemonrodada::jogador2_venceu() const
{return this->m_pokemon2->get_status() == Status::Ativo;}

Pokemonrodada::~Pokemonrodada()
{}

} /* namespace BLL */
