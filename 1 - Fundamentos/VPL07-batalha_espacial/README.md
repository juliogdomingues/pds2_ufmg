Neste exercício você deverá fazer dois TADs para um jogo de batalha espacial. Utilizando Structs, você deve criar os seguintes TADs: Ponto2D e Nave. Cada TAD deve seguir as especificações abaixo:

Ponto2D tem dois membros: (i) x, do tipo double, e (ii) y, do tipo double.
• Essa classe deve possuir um construtor que recebe x e y, ambos do tipo double, e inicializa os membros correspondentes com os valores recebidos.
• Também deve possuir um construtor default, que inicializa x e y com zero.

A classe deve possuir o seguinte método:
double calcular_distancia(Ponto2D ponto): calcula a distância euclidiana para outro ponto no plano.

Nave tem três membros: (i) posicao do tipo Ponto2D, (ii) forca do tipo double, e (iii) energia do tipo double.

• Toda instância deve começar com o valor de energia igual a 100, independente do construtor utilizado.
• A classe deve possuir um construtor que recebe posicao e forca e inicializa os membros correspondentes com os valores recebidos. Caso o parâmetro forca não seja informado, ele deve ter um valor padrão 1. 
• A classe também deve possuir um construtor default, que inicializa posicao com seu construtor padrão, forca com 1, e energia com 100.

Você deve implementar os seguintes métodos nesse TAD:
void mover(double dx, double dy): atualiza a posição da nave nos eixos x e y somando valores dx e dy, respectivamente.

double calcular_distancia(Nave nave): calcula e retorna a distância euclidiana para outra nave qualquer passada como parâmetro.

int determinar_indice_nave_mais_proxima(Nave naves[], int n): recebe um array de naves e um parâmetro que informa a quantidade de elementos nesse array. Determina qual a nave mais próxima e retorna o índice que essa nave ocupa no array.
Assuma que duas naves não ocupam o mesmo espaço, então se achar uma nave com distância igual a zero, essa nave é você mesmo, e não a nave mais próxima.

void atacar(Nave naves[], int n): ataca a nave mais próxima.
A nave que sofre o ataque tem o seu valor de energia reduzido por uma quantidade de dano. O valor do dano a ser reduzido é dado pela seguinte equação:
 dano = \frac{forca \times 100}{distancia} , onde distancia é distância para a nave, e forca é a força da nave que faz o ataque.
O máximo de dano (limite) que uma nave pode fazer em outra é 30. 
Se após um ataque, a nave atacada tiver energia menor/igual a 50 deve ser impressa a mensagem "Energia baixa!".

void imprimir_status(): imprime a situação atual da nave no seguinte formato "x y energia".


OBS1: Nesse exercício você não precisa implementar a função main! O objetivo é simular o caso em que você está implementando um TAD que será utilizado por outra pessoa (que conhece apenas o contrato). Dessa forma, a leitura dos dados de entrada e jogadas já estão implementadas, e você deve apenas implementar os TADs (Ponto2D e Nave). Você é livre para implementar quaisquer outros métodos auxiliares nos TADs que julgar necessário.

OBS2: Deve-se conseguir criar variáveis do tipo Ponto2D e Nave sem passar nenhum valor para o construtor. Para isso, você pode criar um construtor default ou utilizar valores padrões no construtor com parâmetros mencionado acima (veja o último link nas referências abaixo). Lembre-se que uma TAD pode ter vários construtores diferentes.

Pergunta frequente: Por que não preciso retornar nada na função atacar? Como a função main vai saber que alterei os valores de energia das naves?
Resposta: Lembre-se de que quando recebemos arrays como parâmetros de funções (por exemplo, na função atacar), eles são uma referência do array original*, e não uma cópia. Por isso, se em algum momento da função nós alterarmos os valores de um elemento do array, todos os lugares que têm acesso ao array verão a mudança. E é por isso que não precisamos retornar nada na função atacar. Quando a função alterar os valores de energia das naves, a função main verá essa mudança imediatamente, pois também tem acesso ao array sendo alterado.
* Essa não é a terminologia mais correta, mas a explicação completa só pode ser entendida depois da aula de ponteiros.

Para ilustrar, abaixo é apresentado um exemplo de entrada/saída:

input=
3
-1.0 0.0 1.0
0.0 0.0 1.0
1.0 0.0 1.0
s
a 0
s

output =
-1.00 0.00 100.00
0.00 0.00 100.00
1.00 0.00 100.00
-1.00 0.00 100.00
0.00 0.00 70.00
1.00 0.00 100.00

Nesse caso, o comando 's' é usado para imprimir o status atual de todas as naves, e o comando 'a' faz um ataque considerando a nave informada.

Atenção: Lembre-se de fazer a correta modularização utilizando os arquivos .hpp e .cpp.

Dica:
Você pode copiar o arquivo main.cpp aqui para testar localmente e ver como todo o setup inicial é feito (entrada/saída, jogadas, etc).

Referências:
https://www.cplusplus.com/doc/tutorial/dynamic/
https://www.cplusplus.com/doc/tutorial/structures/
https://en.cppreference.com/w/cpp/language/default_arguments
