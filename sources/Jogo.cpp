#include "Jogo.h"

Jogo::Jogo() : gerenciador_grafico() {
    Executar();
}

Jogo::~Jogo() {}

void Jogo::Executar() {
    Loop();
}

void Jogo::Loop() {
    gerenciador_grafico.loop();
}
