#include "Jogo.h"
#include "MenuPrincipal.h"
using namespace Controladoras;

Jogo* Jogo::CriarJogo() {
    if(not jogoUnico) {
        jogoUnico = new Jogo();
    }
    
    return jogoUnico;
}

Jogo::Jogo()
{
    srand(time(NULL));
    
    pilha.colocarEstado(reinterpret_cast<Estado*>(new MenuPrincipal(this)));

}

Jogo::~Jogo() {
}

void Jogo::executar() {

    float dT;
    Clock clock;

    while (GG.getAberto())
    {
        dT = clock.restart().asSeconds();
        if(dT > 1.0f / 20.0f)
            dT = 1.0f / 20.0f;

        GG.setDt(dT);

        GG.limpar();
        GG.leEventos();

        if( not pilha.executar() )
            GG.getJanela()->close();

        GG.getJanela()->display();
    }
}

Jogo* Jogo::jogoUnico = NULL;