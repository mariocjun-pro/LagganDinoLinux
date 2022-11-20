#include "Menu.h"

using namespace Controladoras;

Menu::Menu(Jogo *jogo) :
        pJogo(jogo), fundo(1, pJogo->getGerenciador()) {
    lido = false;
    pontos = 0;
    ranking = false;
    lendoTexto = false;
    texto.resize(5);
    pGG = pJogo->getGerenciador();

    pressionar = false;

    fundo.setTamanho(Vector2f(1280.0f, 960.0f));
    fundo.setTextura("../arquivos/texturas/bg-menu/friends.png");
    fundo.setPosicao(pGG->getVisao()->getCenter());

    selecionado = 0;

    fonte.loadFromFile("../arquivos/texturas/fontes-strings/Pixel.TTF");
    int i;
    for (i = 0; i < 5; i++) {
        texto[i].setFont(fonte);
        texto[i].setCharacterSize(50);
        texto[i].setOutlineThickness(0.5);
        texto[i].setFillColor(Color::Black);
    }

    texto[0].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 400);
    texto[1].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 300);
    texto[2].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 200);
    texto[3].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 100);
    texto[4].setPosition(pGG->getVisao()->getCenter().x, pGG->getVisao()->getCenter().y - 000);


    leitura.setFont(fonte);
    leitura.setCharacterSize(50);
    leitura.setOutlineThickness(0.5);
    leitura.setFillColor(Color::Black);
    leitura.setPosition(pGG->getVisao()->getCenter().x - 600.0f, pGG->getVisao()->getCenter().y - 300.0f);

    texto[0].setString("Um Jogador");
    texto[1].setString("Dois Jogadores");
    texto[2].setString("Ranking");
    texto[3].setString("Carregar");
    texto[4].setString("Sair");

    totalT = 0;
}

Menu::~Menu() {

}

void Menu::executar() {
}

void Menu::leEntradas() {
    if (pressionar == false) {
        totalT += pGG->getDt();
    }
    if (totalT >= 0.2f) {
        totalT -= 0.2f;
        pressionar = true;
    }
    if (pressionar) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            selecionado--;
            if (selecionado < 0)
                selecionado = 4;
            pressionar = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            selecionado++;
            if (selecionado >= 5)
                selecionado = 0;
            pressionar = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            opcao = selecionado;
        }
    }


}

void Menu::posicionarTexto() {
    // posiciona as opcoes do menu
    auto get_center = pGG->getVisao()->getCenter();
    texto[0].setPosition(get_center.x - 500, get_center.y - 200);
    texto[1].setPosition(get_center.x - 500, get_center.y - 100);
    texto[2].setPosition(get_center.x - 500, get_center.y + 000);
    texto[3].setPosition(get_center.x - 500, get_center.y + 100);
    texto[4].setPosition(get_center.x - 500, get_center.y + 200);
}

void Menu::carregar(string nome) {
    ifstream leitor("../arquivos/save/Fase" + nome + ".dino", ios::in);
    int fase;
    int dois;
    leitor >> fase;
    leitor >> dois;


    if (fase == 0) {
        FabricaMontanha fab(pJogo);
        fab.setCarregar(true);
        fab.setDoisJogadores(dois);

        pJogo->colocarEstado(reinterpret_cast<Estado *>(fab.criar()));
    } else if (fase == 1) {
        FabricaFloresta fab(pJogo);
        fab.setCarregar(true);
        fab.setDoisJogadores(dois);

        pJogo->colocarEstado(reinterpret_cast<Estado *>(fab.criar()));
    }

    leitor.close();

}

void Menu::limparEstados() {
    int k;
    k = pJogo->pilhaTam();
    while (k != 1) {
        pJogo->tirarEstado();
        k--;
    }
}

void Menu::exibeRanking() {
    string saux;
    int aux;
    int i, k;
    if (ranking) {
        if (not lido) {
            rank.clear();
            ifstream leitor("../arquivos/save/Ranking.dino", ios::in);
            while (leitor >> saux >> aux) {
                rank.emplace_back(saux, aux);
            }
            lido = true;
            textoRank.resize(rank.size());

            auto pgg_x = pGG->getVisao()->getCenter().x + 100;
            auto pgg_y = pGG->getVisao()->getCenter().y - 400;

            for (i = 0; i < static_cast<int>(rank.size()); i++) {
                textoRank[i].setFont(fonte);
                textoRank[i].setCharacterSize(40);
                textoRank[i].setOutlineThickness(0.5);
                textoRank[i].setFillColor(Color::Black);
                textoRank[i].setPosition(pgg_x,pgg_y + static_cast<float>(i) * 50.0f);
                textoRank[i].setString(rank[i].first + " " + to_string(rank[i].second));
            }

            rank.clear();
        }

        for (i = 0; i < textoRank.size(); i++) {
            pGG->getJanela()->draw(textoRank[i]);
        }
    }
}

void Menu::leTexto() {
    if (lendoTexto) {
        pGG->setLeitura(true);
        pressionar = false;
        Text aux;
        aux.setFont(fonte);
        aux.setCharacterSize(50);
        aux.setOutlineThickness(0.5);
        aux.setFillColor(Color::Black);
        aux.setPosition(pGG->getVisao()->getCenter().x - 600.0f, pGG->getVisao()->getCenter().y - 400.0f);
        aux.setString("Digite seu nome");


        sleitura = pGG->getEntrada();
        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            lendoTexto = false;
            totalT = 0.0f;
            if (sleitura != "") {
                salvaPontuacao();
            }
        }

        leitura.setString(sleitura);
        pGG->getJanela()->draw(aux);
        pGG->getJanela()->draw(leitura);

    } else {
        pGG->setLeitura(false);
    }
}

void Menu::salvaPontuacao() {
    ifstream leitor;
    ofstream gravador;
    int aux;
    string saux;

    vector<int> v;
    map<int, string> ranking;

    leitor.open("../arquivos/save/Ranking.dino", ios::in);

    ranking.insert(pair<int, string>(pontos, sleitura));
    v.push_back(pontos);

    while (leitor >> saux >> aux) {
        v.push_back(aux);
        ranking.insert(pair<int, string>(aux, saux));
    }

    std::sort(v.begin(), v.end());
    leitor.close();

    gravador.open("../arquivos/save/Ranking.dino", ios::out | ios::trunc);

    for (int i = v.size() - 1; i >= 0; i--) {
        gravador << ranking.at(v.at(i));
        gravador << ' ';
        gravador << v[i];
        gravador << endl;
    }

    gravador.close();
    lido = false;
}

void Menu::setLendoTexto(const bool l) {
    lendoTexto = l;
    leitura.setFont(fonte);
    leitura.setCharacterSize(50);
    leitura.setOutlineThickness(0.5);
    leitura.setFillColor(Color::Black);
    leitura.setPosition(pGG->getVisao()->getCenter().x - 600.0f, pGG->getVisao()->getCenter().y - 300.0f);
}