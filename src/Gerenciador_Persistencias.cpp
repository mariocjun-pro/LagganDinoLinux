#include "Gerenciador_Persistencias.h"

/*
 * 1 - Andino
 * 2 - Tard
 * 3 - Atiradino
 * 4 - Espinho
 * 5 - ChefeDino
 * 6 - Galho
 * 7 - Vita
 * 8 - Pedra
 * 9 - AtiradinoThread
 */

Gerenciador_Persistencias::Gerenciador_Persistencias() {
    doisJogadores = 0;
    pontosTotais = 0;
    string nome = "Sem nome";
}

Gerenciador_Persistencias::~Gerenciador_Persistencias() {
}

void Gerenciador_Persistencias::criarArquivos() {
    ofstream arquivo;
    string aux;

    arq[0] = ("../arquivos/save/" + ("Jogador" + nome)) + ".dino";
    arquivo.open(arq[0], ios::out | ios::trunc);
    arquivo.close();

    arq[1] = ("../arquivos/save/" + ("Objetos" + nome)) + ".dino";
    arquivo.open(arq[1], ios::out | ios::trunc);
    arquivo.close();

    arq[2] = ("../arquivos/save/" + ("Fase" + nome)) + ".dino";
    arquivo.open(arq[2], ios::out | ios::trunc);
    arquivo.close();

    aux = "../arquivos/save/Salvos.dino";
    arquivo.open(aux, ios::app);
    arquivo << nome << endl;
    arquivo.close();
}

void Gerenciador_Persistencias::gravar(pair<Entidade *, int> p) {
    switch (p.second) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
            gravarObjetos(p.first, p.second);
            break;
        case 2:
        case 7:
            gravarJogadores(reinterpret_cast<Jogador *>(p.first), p.second);
            break;
        default:
            break;
    }

}

void Gerenciador_Persistencias::gravarObjetos(Entidade *ent, int id) {
    ofstream gravador(arq[1], ios::app);
    Inimigo *inim;

    try {
        if (!gravador) {
            throw 10;
        }

        gravador << id << ' ';

        if (ent->getPlataforma())
            gravador << ent->getPlataforma()->getIdPlataforma() << ' ';
        else
            gravador << -1 << ' ';

        gravador << ent->getPosicao().x << ' ' << ent->getPosicao().y << ' ';

        if (id == 1 || id == 3 || id == 5) {
            inim = reinterpret_cast<Inimigo *>(ent);
            gravador << inim->getVidas() << ' ';
        }

        gravador << endl;
    }
    catch (int e) {
        cerr << "Erro ao abrir o arquivo";
    }
    gravador.close();
}

void Gerenciador_Persistencias::gravarJogadores(Jogador *j, int id) {
    ofstream gravador(arq[0], ios::app);

    if (!gravador) {
        cerr << "erro ao abrir o arquivo";
        return;
    }
    if (id == 2)
        doisJogadores = 1;

    pontosTotais += j->getPontos();

    gravador << id << ' ';
    gravador << j->getPontos() << ' ';
    gravador << j->getVidas() << ' ';
    gravador << j->getPosicao().x << ' ' << j->getPosicao().y << ' ';
    gravador << endl;
    gravador.close();
}

void Gerenciador_Persistencias::gravarFase(const unsigned int id) {
    ofstream gravador(arq[2], ios::app);

    gravador << id << endl;
    gravador << doisJogadores << endl;
    gravador << pontosTotais << endl;
    gravador.close();
}