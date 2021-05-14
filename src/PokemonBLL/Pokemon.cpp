/**
    Pokemon.hpp
    Purpose: Pokemon superclass

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "Pokemon.hpp"
#include "Exceptions.hpp"

namespace BLL {

Pokemon::Pokemon()
    : m_status(Status::Ativo), m_caracteristica_rodada(Caracteristica::Indefinido)
{}

Pokemon::Pokemon(const PokemonMonstro& monstro, const Status status, const BLL::tstring jogador, const Caracteristica caracteristica_rodada)
    : m_monstro(monstro), m_status(status), m_jogador(jogador), m_caracteristica_rodada(caracteristica_rodada)
{}

// O cálculo aqui considera também a vantagem do Tipo.
Pokemon& Pokemon::getvencedorrodada(Pokemon& adversario)
{
    float valoradversario = 0.0f;
    float valor = 0.0f;

    switch(this->get_caracteristica_rodada())
    {
        case Caracteristica::Ataque:
            valoradversario = (float)adversario.get_ataque();
            valor = (float)this->get_ataque();
            break;
        case Caracteristica::Defesa:
            valoradversario = (float)adversario.get_defesa();
            valor = (float)this->get_defesa();
            break;
        case Caracteristica::Agilidade:
            valoradversario = (float)adversario.get_agilidade();
            valor = (float)this->get_agilidade();
            break;
        case Caracteristica::HP:
            valoradversario = (float)adversario.get_hp();
            valor = (float)this->get_hp();
            break;
        default:
            return *this;
    };

    valor = valor * (this->temvantagem(adversario) ? 1.5f : 1.0f);
    valoradversario = valoradversario * (adversario.temvantagem(*this) ? 1.5f : 1.0f);

    if(valor > valoradversario)
    {
        this->set_status(Status::Ativo);
        adversario.set_status(Status::Desmaiado);
        return *this;
    }
    else if(valor < valoradversario)
    {
        this->set_status(Status::Desmaiado);
        adversario.set_status(Status::Ativo);
        return adversario;
    }

    this->set_status(Status::Desmaiado);
    adversario.set_status(Status::Desmaiado);
    return *this;
}

float Pokemon::getadversariopontos(const Pokemon& adversario) const
{
    switch(this->get_caracteristica_rodada())
    {
        case Caracteristica::Ataque:
            return (float)adversario.get_ataque();
            break;
        case Caracteristica::Defesa:
            return (float)adversario.get_defesa();
            break;
        case Caracteristica::Agilidade:
            return (float)adversario.get_agilidade();
            break;
        case Caracteristica::HP:
            return (float)adversario.get_hp();
            break;
        default:
            return false;
    };
}

// Checa-se aqui se a vantagem existe para o tipo de Pokemon.
bool Pokemon::temvantagem(const Pokemon& adversario)
{
    switch(this->get_tipo())
    {
        case Tipo::Electric:
            if(adversario.get_tipo() == Tipo::Water)
                return true;
            break;
        case Tipo::Water:
            if(adversario.get_tipo() == Tipo::Fire)
                return true;
            break;
        case Tipo::Fire:
            if(adversario.get_tipo() == Tipo::Grass)
                return true;
            break;
        case Tipo::Grass:
            if(adversario.get_tipo() == Tipo::Electric)
                return true;
            break;
        default:
            return false;
    };

    return false;
}

Pokemon::~Pokemon()
{}

const Caracteristica Pokemon::get_caracteristica_rodada() const
{return this->m_caracteristica_rodada;}

const BLL::tstring& Pokemon::get_jogador() const
{return this->m_jogador;}

const PokemonMonstro& Pokemon::get_monstro() const
{return this->m_monstro;}

const unsigned int Pokemon::get_ataque() const
{return this->m_monstro.m_ataque;}

const unsigned int Pokemon::get_defesa() const
{return this->m_monstro.m_defesa;}

const unsigned int Pokemon::get_agilidade() const
{return this->m_monstro.m_agilidade;}

const unsigned int Pokemon::get_hp() const
{return this->m_monstro.m_hp;}

const Status Pokemon::get_status() const
{return this->m_status;}

const Tipo Pokemon::get_tipo() const
{return this->m_monstro.m_tipo;}


void Pokemon::set_caracteristica_rodada(const Caracteristica& caracteristica)
{this->m_caracteristica_rodada = caracteristica;}

void Pokemon::set_jogador(const BLL::tstring& jogador)
{this->m_jogador = jogador;}

void Pokemon::set_ataque(const unsigned int ataque)
{this->m_monstro.m_ataque = ataque;}

void Pokemon::set_defesa(const unsigned int defesa)
{this->m_monstro.m_defesa = defesa;}

void Pokemon::set_agilidade(const unsigned int agilidade)
{this->m_monstro.m_agilidade = agilidade;}

void Pokemon::set_hp(const unsigned int hp)
{this->m_monstro.m_hp = hp;}

void Pokemon::set_status(const Status status)
{this->m_status = status;}

void Pokemon::set_tipo(const Tipo tipo)
{this->m_monstro.m_tipo = tipo;}

bool Pokemon::podejogar() const
{return this->m_status == Status::Ativo;}

} /* namespace BLL */
