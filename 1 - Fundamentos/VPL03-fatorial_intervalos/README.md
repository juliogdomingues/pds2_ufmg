O objetivo desse VPL é praticar a escrita de funções em C++. Serão feitas duas funções: uma que calcula o fatorial,  outra que conta a quantidade de inteiros em um intervalo. Para terminar esse VPL, você deverá completar o código dessas duas funções dentro do arquivo Main.cpp.

A função fatorial recebe um número inteiro. Caso esse número seja negativo, o valor 1 deve ser retornado:


fatorial(3) == 6

fatorial(2) == 2


fatorial(1) == 1

fatorial(0) == 1

fatorial(-1) == 1

A função intervalo conta a quantidade de inteiros entre dois números de ponto flutuante. A contagem é inclusiva. Isso é, caso o número de ponto flutuante também seja um inteiro, ele deve ser contado. Exemplos:


intervalo(3.0, 5.0) == 3

intervalo(2.01, 2.9) == 0


intervalo(0.999, 1.001) == 1

Dica:
Lembre-se que para testar localmente, você pode usar o seguinte comado: ./executavel < in.txt, onde o arquivo in.txt possui os dados que serão utilizados como entrada.
Não altere a função main: ela contém um switch para escolher o caso de teste que será usado.
