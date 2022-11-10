#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Corpo_Grafico.h"

using namespace Auxiliares;
using namespace Abstratas;
using namespace GerenciadoresEntidades;


namespace Auxiliares {
    class Plataforma : public Entidade {
    public:
        Plataforma(Vector2f tam = Vector2f(100.0f, 100.0f));
        ~Plataforma();

        void executar() {corpo.atualizaAnimacao(0.1, true, 0, 0, 0, 0);}

        //Sets e Gets
        void setTextura(string tex) { corpo.setTextura(tex); }

        const int getIdPlataforma() const { return idPlataforma; }
        
        static void setContIdPlat(const int cont) { contIdPlataforma = cont; }

        static int contIdPlataforma;
    private:
        int idPlataforma;
    };
}
