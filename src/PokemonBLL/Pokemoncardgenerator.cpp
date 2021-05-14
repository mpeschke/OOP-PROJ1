/**
    Pokemoncardgenerator.hpp
    Purpose: Geração de cartas embaralhadas.

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "Pokemoncardgenerator.hpp"
#include "Exceptions.hpp"
#include <random>

namespace BLL {

static const Pokemon g_Charmander(g_CharmanderSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_HoOh(g_HoOhSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Vulpix(g_VulpixSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Magmar(g_MagmarSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Pikachu(g_PikachuSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Ampharos(g_AmpharosSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Dedenne(g_DedenneSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Jolteon(g_JolteonSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Bayleef(g_BayleefSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Treecko(g_TreeckoSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Shaymin(g_ShayminSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Bulbasaur(g_BulbasaurSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Totodile(g_TotodileSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Squirtle(g_SquirtleSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Lapras(g_LaprasSt, Status::Ativo, "", Caracteristica::Indefinido);
static const Pokemon g_Maril(g_MarilSt, Status::Ativo, "", Caracteristica::Indefinido);

static const std::vector<Pokemon> g_Monstros{
    g_Charmander,
    g_HoOh,
    g_Vulpix,
    g_Magmar,
    g_Pikachu,
    g_Ampharos,
    g_Dedenne,
    g_Jolteon,
    g_Bayleef,
    g_Treecko,
    g_Shaymin,
    g_Bulbasaur,
    g_Totodile,
    g_Squirtle,
    g_Lapras,
    g_Maril
};

// Usando aqui o gerador de números pseudo-aleatórios baseado no Mersenne Twister (https://en.wikipedia.org/wiki/Mersenne_Twister).
// Notar que o algoritmo REALMENTE simula uma distribuição manual de cartas, com as cartas
// sendo 'retiradas do topo' do baralho. Com a diferença que se passam as cartas primeiro para
// um jogador, depois para outro.
void g_DistribuirCartas(const BLL::tstring jogador1, const BLL::tstring jogador2, std::vector<Pokemon>* cartasjogador1, std::vector<Pokemon>* cartasjogador2)
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);

    for(int i = 0; i < 6; i++)
    {
        cartasjogador1->push_back(g_Monstros[v[i]]);
        cartasjogador1->at(i).set_jogador(jogador1);
        cartasjogador2->push_back(g_Monstros[v[i+6]]);
        cartasjogador2->at(i).set_jogador(jogador2);
    }
}

} /* namespace BLL */
