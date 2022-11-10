#include "Animadora.h"


GerenciadoresEntidades::Animadora::Animadora(Corpo_Grafico* corpo) {
    pCorpo = corpo;
    textura = NULL;
    
    inicializa(Vector2f(0, 0), Vector2u(0, 0), Vector2u(1, 1));
}

GerenciadoresEntidades::Animadora::~Animadora() {
    
}

void GerenciadoresEntidades::Animadora::inicializa(Vector2f margemErro, Vector2u quantidadeQuadros, Vector2u TotalDeQuadros) {
    qtdQuadros = quantidadeQuadros;
    tempoTroca = 0.3f;
    tempoTotal = 0;
    comeco = 0;
    quadrosAtuais.x = 0;
    quadrosAtuais.y = 0;
    margem = margemErro;
    
    if(pCorpo)
        textura = pCorpo->getTextura();
    
    quadro.width = textura->getSize().x / (float)(TotalDeQuadros.x);
    quadro.height = (textura->getSize().y / (float)(TotalDeQuadros.y));
}

void GerenciadoresEntidades::Animadora::atualizar(float dT, bool aDireita, unsigned int comecoP, unsigned int quantidadeQuadrosX, float troca, unsigned int linha) {
    quadrosAtuais.y = linha;
    qtdQuadros.x = quantidadeQuadrosX;
    tempoTotal += dT;
    tempoTroca = troca;
    if(comeco != comecoP) {
        comeco = comecoP;
        quadrosAtuais.x = comeco;
    }

    
    
    if(tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        (quadrosAtuais.x)++;
        
        if(quadrosAtuais.x >= (qtdQuadros.x + comeco)) {
            quadrosAtuais.x = comeco;
        }
    }
    
    if(aDireita) {
        quadro.left = quadrosAtuais.x * quadro.width;
        quadro.width = abs(quadro.width);
    }
    else {
        quadro.left = (quadrosAtuais.x + 1) * abs(quadro.width);
        quadro.width = -abs(quadro.width);
    }
    
    quadro.top = quadrosAtuais.y * quadro.height;
    
    Vector2f aux(quadro.width, quadro.height);
    quadro.width += margem.x;
    quadro.height += margem.y;
    
    pCorpo->getCorpo()->setTextureRect(quadro);
    
    quadro.width = aux.x;
    quadro.height = aux.y;
}

void GerenciadoresEntidades::Animadora::atualizarLinhasSequencial(float dT, bool aDireita, Vector2u quantidadeQuadros, unsigned int quadrosUltimaLinha, float troca) {
    qtdQuadros.x = quantidadeQuadros.x;
    qtdQuadros.y = quantidadeQuadros.y;
    tempoTotal += dT;
    tempoTroca = troca;

    
    if(tempoTotal >= tempoTroca) {
        tempoTotal -= tempoTroca;
        (quadrosAtuais.x)++;
        
        if(quadrosAtuais.x >= qtdQuadros.x) {
            quadrosAtuais.y++;
            quadrosAtuais.x = 0;
            if(quadrosAtuais.y >= (qtdQuadros.y - 1)) {
                quadrosAtuais.y = 0;
            }
        }
    }
    
    
    if(aDireita) {
        quadro.left = quadrosAtuais.x * quadro.width;
        quadro.width = abs(quadro.width);
    }
    else {
        quadro.left = (quadrosAtuais.x + 1) * abs(quadro.width);
        quadro.width = -abs(quadro.width);
    }
    
    quadro.top = quadrosAtuais.y * quadro.height;
    
    pCorpo->getCorpo()->setTextureRect(quadro);
}