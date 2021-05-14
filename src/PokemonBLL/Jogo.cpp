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
    : m_rodadas(0U), m_numero_cartas_pras_rodadas(0U)
{}

Jogo::Jogo(const bool computadorjoga, const unsigned int numero_cartas_pras_rodadas)
    : m_computadorjoga(computadorjoga), m_numero_cartas_pras_rodadas(numero_cartas_pras_rodadas)
{}

std::vector<Pokemonrodada>& Jogo::get_rodadas()
{return this->m_rodadas;}

const bool Jogo::get_computadorjoga() const
{return this->m_computadorjoga;}

void Jogo::set_rodadas(const std::vector<Pokemonrodada>& rodadas)
{this->m_rodadas = rodadas;}

void Jogo::set_computadorjoga(const bool computadorjoga)
{this->m_computadorjoga = computadorjoga;}

// Usando stl count_if, com um predicado, para validar a regra fornecida no enunciado:
// "Vence o jogador que ainda tem (pelo menos) 1 pokemon ativo." Isso induz que,
// se o adversário ainda tem um pokemon ativo, ele ainda pode jogar.
// Conclusão: um dos jogadores tem que ter pelo menos 1 ativo, e o outro jogador nenhum.
bool Jogo::tem_vencedor(const std::vector<Pokemon>& maojogador1, const std::vector<Pokemon>& maojogador2) const
{
    bool jogador1venceu = (
        (std::count_if(maojogador1.begin(), maojogador1.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) >= 1U) &&
        (std::count_if(maojogador2.begin(), maojogador2.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) == 0U)
    );

    bool jogador2venceu = (
        (std::count_if(maojogador2.begin(), maojogador2.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) >= 1U) &&
        (std::count_if(maojogador1.begin(), maojogador1.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) == 0U)
    );

    return jogador1venceu || jogador2venceu;
}

// A lógica aqui é semelhante à da função Jogo::tem_vencedor.
BLL::tstring Jogo::get_vencedor(const std::vector<Pokemon>& maojogador1, const std::vector<Pokemon>& maojogador2) const
{
    bool jogador1venceu = (
        (std::count_if(maojogador1.begin(), maojogador1.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) >= 1U) &&
        (std::count_if(maojogador2.begin(), maojogador2.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) == 0U)
    );

    bool jogador2venceu = (
        (std::count_if(maojogador2.begin(), maojogador2.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) >= 1U) &&
        (std::count_if(maojogador1.begin(), maojogador1.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) == 0U)
    );

    if(jogador1venceu && !jogador2venceu)
        return maojogador1[0].get_jogador();
    else if(jogador2venceu && !jogador1venceu)
        return maojogador2[0].get_jogador();
    
    return "";
}

// A lógica aqui é semelhante à da função Jogo::tem_vencedor.
bool Jogo::continuarjogando(const std::vector<Pokemon>& maojogador1, const std::vector<Pokemon>& maojogador2) const
{
    // Se um dos jogadores não tem nenhum pokemon ativo, o jogo está finalizado.
    return !(
        (std::count_if(maojogador1.begin(), maojogador1.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) == 0U) ||
        (std::count_if(maojogador2.begin(), maojogador2.end(),[](Pokemon pk){return pk.get_status() == Status::Ativo;}) == 0U)
    );
}

Jogo::~Jogo()
{}

} /* namespace BLL */
