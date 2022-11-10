#include "PilhaEstados.h"

using namespace Controladoras;

PilhaEstados::PilhaEstados() {
}

PilhaEstados::~PilhaEstados() {
}

void PilhaEstados::tirarEstado(bool excluir) {
    if(!estados.empty()) { 
        if(excluir)
            coletorLixo.push(estados.top());
        
        estados.pop();
    }
}

bool PilhaEstados::executar() {

    if(!coletorLixo.empty()) {
        delete coletorLixo.top();
        coletorLixo.pop();
    }
    
    if(!estados.empty()) {
        estados.top()->executar();
        return true;
    }
    else {
        return false;
    }
}
