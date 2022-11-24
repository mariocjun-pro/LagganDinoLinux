# se a pasta existe, apaga e cria novamente
printf "Verificando se a pasta build existe...\n"
if [ -d "build" ]; then
    printf "existe, apagando...\n"
    rm -rf build
fi

printf "criando a pasta build...\n"
mkdir build

printf "OK, pasta criada, entrando na pasta build...\n"
cd build || exit

printf "compilando o programa...\n"
cmake .. && make

printf "Jogo rodando...\n"
./LagganDino