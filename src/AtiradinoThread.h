#pragma once

#include "stdafx.h"
#include "Atiradino.h"
#include "PThread.h"

using namespace GerenciadoresEntidades;

namespace Inimigos {
    class AtiradinoThread : public Atiradino, public PThread {
    public:
        explicit AtiradinoThread(Plataforma *p);

        ~AtiradinoThread();

        void executar();

        void atirar();

    private:
        void funcaoThread();

        static float tempoAtirar;
        bool threadFechada;

    };
}