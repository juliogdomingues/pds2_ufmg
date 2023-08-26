Neste VPL, vocês vão trabalhar com uma classe Vetor, que é uma versão simplificada do vector de c++ . Uma diferença significativa é que os índices de um Vetor podem ser definidos como qualquer intervalo de números inteiros. Por exemplo, a instrução

Vetor<int> v(-10, 10);

Cria um arranjo com *21* elementos, cujos índices variam de -10 até 10. O programador pode acessar os elementos deste arranjo através de dois métodos atribuir() e valor(). Por exemplo:

Vetor<int> v(-10, 10);
for (int i = -10; i <= 10; i++) {
  v.atribuir(i, i * i);
  cout << a.valor(i) << endl;
}

O que nós faremos neste VPL é alterar aspectos deste código, utilizando técnicas de programação defensiva/tratamento de exceções para tornar o código mais robusto à erros de entrada de dados dos usuários. Antes de mais nada, abra os arquivos na sua IDE de programação e entenda todo o funcionamento do programa. Atente-se, principalmente, a quais são as pré-condições de cada método da classe Vetor.

O código passado para vocês está correto. Entretanto, mesmo um software correto pode apresentar um comportamento indeterminado/inesperado diante de uma má operação do usuário. Um software robusto precisa antever estes episódios e tratá-los de alguma forma, mesmo que seja abortando o programa e explicando claramente ao usuário o que aconteceu. Para ilustrar como lidar com este tipo de erro, nós vamos adicionar ao código do VPL o tratamento de algumas exceções.

A função main já está implementada. Ela capta (catch) corretamente três tripos de exceções: ExcecaoIntervaloVazio, ExcecaoIndiceNaoInicializado, e ExcecaoIndiceInvalido.

O que você tem que fazer neste VPL é garantir que os métodos da classe Arranjo lancem (throw) estas exceções de acordo com suas pré-condições.
