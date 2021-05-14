/**
    Pokemon.hpp
    Purpose: Pokemon superclass

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <list>

namespace BLL {

enum Caracteristica
{
    Indefinido,
    Ataque,
    Defesa,
    Agilidade,
    HP
};

enum Tipo
{
    NaoDefinido,
    Fire,
    Electric,
    Grass,
    Water
};

enum Status
{
    Ativo,
    Desmaiado
};

struct PokemonMonstro
{
    BLL::tstring m_pokemon;
    unsigned int m_ataque;
    unsigned int m_defesa;
    unsigned int m_agilidade;
    unsigned int m_hp;
    Tipo m_tipo;
};

class Pokemon {
public:
    Pokemon();
    Pokemon(const PokemonMonstro& monstro, const Status status, const BLL::tstring jogador, const Caracteristica caracteristica_rodada);
protected:
    Caracteristica m_caracteristica_rodada;
    BLL::tstring m_jogador;
    PokemonMonstro m_monstro;
    Status m_status;
public:
    const Caracteristica get_caracteristica_rodada() const;
    const BLL::tstring& get_jogador() const;
    const PokemonMonstro& get_monstro() const;
    const unsigned int get_ataque() const;
    const unsigned int get_defesa() const;
    const unsigned int get_agilidade() const;
    const unsigned int get_hp() const;
    const Status get_status() const;
    const Tipo get_tipo() const;

    void set_caracteristica_rodada(const Caracteristica& caracteristica);
    void set_jogador(const BLL::tstring& jogador);
    void set_ataque(const unsigned int ataque);
    void set_defesa(const unsigned int defesa);
    void set_agilidade(const unsigned int agilidade);
    void set_hp(const unsigned int hp);
    void set_status(const Status status);
    void set_tipo(const Tipo tipo);
public:
    Pokemon& getvencedorrodada(Pokemon& adversario);
    bool temvantagem(const Pokemon& adversario);
    float getadversariopontos(const Pokemon& adversario) const;
    bool podejogar() const;
public:
    virtual ~Pokemon();
};

} /* namespace BLL */
