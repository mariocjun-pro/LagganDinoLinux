#ifndef GAME_PILHAESTADOS_H
#define GAME_PILHAESTADOS_H

#include "stdafx.h"
#include "Estado.h"

using namespace Estados;

namespace Controladoras {
    class PilhaEstados {
    public:
        PilhaEstados();

        ~PilhaEstados();

        void tirarEstado(bool excluir = true);

        void colocarEstado(Estado *est) { estados.push(est); }

        bool executar();

    private:
        stack<Estado *> estados;
        stack<Estado *> coletorLixo;
    };
}
#endif //GAME_PILHAESTADOS_H
