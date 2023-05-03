>>> Necessário compilar usando g++ main.cpp funcoes.cpp -o prog e em seguida executar usando ./prog <<<
>>> Esse programa só funciona com a existência de Remédios.txt <<<

Sobre as funções:

void adicionarArquivoNoMapa()
Essa função lê um arquivo chamado "Remedios.txt" e adiciona cada medicamento e seu preço correspondente a um mapa (map), onde o nome do medicamento é a chave (key) e o preço é o valor (value).
Usando um loop "while" e usa a função "getline()" para ler o nome do medicamento e o preço correspondente.
O preço é lido como uma string ("precoString") e, em seguida, é convertido em um valor double usando a função "stod()". O nome do medicamento e o preço são então adicionados ao mapa "medicamentos"
------------------------------------------------------
void imprimirArquivo()
Essa função imprime os valores armazenados no mapa "medicamentos". O mapa contém pares chave-valor, onde a chave é uma string que representa o nome do medicamento e o valor é um número double que representa o preço.
------------------------------------------------------
void verificarRemedio()
Essa função em C++ verifica se um medicamento especificado pelo usuário está presente no arquivo "Remedios.txt". 
Percorre cada linha do arquivo usando um loop "while" e a função "getline()" para ler o nome do medicamento.
Antes de entrar no loop, a função solicita que o usuário digite o nome do medicamento que deseja verificar e armazena a entrada do usuário na variável "nomeRemedio".
Dentro do loop, a função "compare()" é usada para comparar o nome do medicamento lido do arquivo com o nome do medicamento especificado pelo usuário. Se os nomes forem iguais a função imprime uma mensagem indicando que o medicamento está em estoque e incrementa o contador "c".
Após o loop, se o contador "c" for igual a zero, isso significa que o medicamento especificado pelo usuário não está presente no arquivo e a função imprime uma mensagem indicando que o medicamento não está em estoque.
------------------------------------------------------
void selecionarRemedio()
Essa função permite que o usuário selecione um medicamento e a quantidade desejada para adicionar ao carrinho de compras. A função usa as variáveis "itemCarrinho" e "qntd" para armazenar o nome do medicamento e a quantidade desejada, respectivamente.
Antes de entrar no loop "for", a função solicita que o usuário digite o nome do medicamento que deseja adicionar ao carrinho e a quantidade desejada, armazenando as entradas do usuário nas variáveis "itemCarrinho" e "qntd".
Dentro do loop "for", a função percorre cada par chave-valor no mapa "medicamentos". Se o nome do medicamento (i.first) for igual ao nome especificado pelo usuário (itemCarrinho), a função adiciona o nome do medicamento como uma chave no mapa "carrinhoMap" e atualiza o valor do preço (carrinhoMap[i.first].valor) e o número de itens no carrinho (carrinhoMap[i.first].contador) para o valor do preço (i.second) do mapa "medicamentos" e a quantidade especificada pelo usuário (qntd), respectivamente.
------------------------------------------------------
void calculoCompra()
Essa função é responsável por calcular o valor total da compra, com base nas informações armazenadas no mapa "carrinhoMap".
Dentro da função, a variável "valorTotal" é inicializada como zero. Em seguida, um loop "for" é usado para percorrer cada par chave-valor no mapa "carrinhoMap". Para cada item no carrinho, o valor total é atualizado adicionando o valor do item (carrinhoMap[i.first].valor) multiplicado pela quantidade de itens (carrinhoMap[i.first].contador).
------------------------------------------------------
void apagar()
Essa função é responsável por permitir que o usuário remova um item do carrinho de compras.
Dentro da função, a variável "deletar" é usada para armazenar o nome do medicamento que o usuário deseja remover do carrinho. Em seguida, um loop "for" é usado para percorrer cada par chave-valor no mapa "carrinhoMap". Para cada item no carrinho, o nome do medicamento é comparado com a string armazenada em "deletar". Se houver uma correspondência, o item é removido do carrinho usando a função "erase()" e o loop é interrompido com a declaração "break".
------------------------------------------------------
void imprimirArquivoGerente()
Mesma funcionalidade do imprimirArquivo.
------------------------------------------------------
void adicionarMedicamento()
Essa função é responsável por permitir que o usuário adicione um novo medicamento e seu respectivo preço no mapa "medicamentos".
Dentro da função, a variável "string" é usada para armazenar o nome do medicamento inserido pelo usuário, enquanto a variável "valor" é usada para armazenar o preço do medicamento. Depois que o usuário inserir o nome e o preço do medicamento, o novo medicamento é adicionado ao mapa "medicamentos" .
------------------------------------------------------
void atualizarPreco()
Essa função em C++ é responsável por permitir que o usuário atualize o preço de um medicamento existente no mapa "medicamentos".

A função pede que o usuário entre com o nome do medicamento a ser atualizado e o novo valor dele. Depois que o usuário inserir o nome e o novo preço do medicamento, a função usa um loop "for" para percorrer o mapa "medicamentos". Para cada par chave-valor no mapa, a função verifica se a chave (nome do medicamento) é igual à string inserida pelo usuário. Se as chaves forem iguais, o valor correspondente no mapa é atualizado para o novo preço inserido pelo usuário
------------------------------------------------------
void excluirMedicamento()
Essa função exclui um medicamento do mapa de medicamentos. Ela solicita que o usuário digite o nome do medicamento que deseja excluir e, em seguida, percorre a lista de medicamentos para verificar se o nome do medicamento digitado corresponde a algum dos medicamentos da lista. Se for encontrado um medicamento com o nome fornecido, ele é excluído da lista usando a função "erase".
------------------------------------------------------
void salvarMapNoArquivo()
Essa função salva o conteúdo do mapa "medicamentos" em no arquivo "Remedios.txt". Primeiro, ela abre o arquivo em modo de escrita, e em seguida, percorre cada elemento do mapa, escrevendo a chave (nome do medicamento) e valor (preço) em linhas separadas no arquivo.










