#include "Fase.h"
#include "Jogo.h"

Fase::Fase(Jogo *jooj) :
        Ent() {
    pJogo = jooj;
}

Fase::~Fase() {
}

void Fase::executar() {

}

__attribute__((unused)) void Fase::gerenciar_colisoes() {

}

__attribute__((unused)) void Fase::reiniciar() {

}

