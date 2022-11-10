#include "stdafx.h"
#include "Jogo.h"

using namespace Controladoras;

int main (void) 
{
    Jogo* jogo;
    jogo = Jogo::CriarJogo();
    
    jogo->executar();
    return 0;
}