/**
    Jogo.cpp
    Purpose: classe do jogo

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "Jogo.hpp"
#include "Pokemon.hpp"
#include "Pokemonrodada.hpp"
#include "Pokemoncardgenerator.hpp"
#include "Exceptions.hpp"

namespace BLL {

Jogo::Jogo()
    : m_rodadas(0U)
{}

Jogo::Jogo(const bool computadorjoga)
    : m_computadorjoga(computadorjoga)
{
    BLL::g_GerarRodadas("jogador1", this->m_computadorjoga ? "computador" : "jogador2", &(this->m_rodadas));
}

std::vector<Pokemonrodada>& Jogo::get_rodadas()
{return this->m_rodadas;}

const bool Jogo::get_computadorjoga() const
{return this->m_computadorjoga;}

void Jogo::set_rodadas(const std::vector<Pokemonrodada>& rodadas)
{this->m_rodadas = rodadas;}

void Jogo::set_computadorjoga(const bool computadorjoga)
{this->m_computadorjoga = computadorjoga;}

bool Jogo::tem_vencedor() const
{
    int count = std::count_if(this->m_rodadas.begin(), this->m_rodadas.end(), [](Pokemonrodada pkr){return pkr.get_vencedor().get_status() == Status::Ativo;});

    return count == 1;
}

BLL::tstring Jogo::get_vencedor() const
{
    auto vencedor = std::find_if(this->m_rodadas.begin(), this->m_rodadas.end(), [](Pokemonrodada pkr){return pkr.get_vencedor().get_status() == Status::Ativo;});

    if(vencedor == std::end(this->m_rodadas))
        return "";

    return vencedor->get_vencedor().get_jogador();
}

Jogo::~Jogo()
{}

} /* namespace BLL */
