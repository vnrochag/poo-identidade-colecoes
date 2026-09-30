# Previsões, evidências e decisões

Preencha antes e depois da execução. Explique com suas palavras; resultados de testes sozinhos não respondem às perguntas.

## Etapa 01 — reconhecer e cadastrar (até 300 palavras)

| Situação | Minha previsão antes de executar | Evidência observada e explicação |
|---|---|---|
| Duas instâncias com LT-101: identidade e igualdade | `a` e `b` devem ser instâncias diferentes, mas devem ser consideradas iguais porque possuem a mesma tag. O `alias` deve ser a mesma instância de `a`. | O resultado foi `Mesma instancia: false`, `Alias: true` e `Iguais: true`. Isso mostra que `a` e `b` são objetos diferentes, mas possuem a mesma identificação, enquanto `alias` aponta para a mesma instância de `a`. |
| Inserir 12% e depois 99% com a mesma tag | A segunda medição não deve substituir a primeira. O cadastro deve continuar com a medição de 12%. | O resultado foi `Primeira: true`, `Duplicada: false` e `Preservada: 12 %`. A primeira medição foi cadastrada, a segunda foi recusada e o valor original foi mantido. O mesmo comportamento apareceu em C++ e Python. |
| Buscar outra instância da mesma tag | Mesmo sendo outra instância, a busca deve encontrar o cadastro que já existe para a mesma tag. | A busca usa a identificação do sensor como chave, permitindo localizar o cadastro pela mesma tag mesmo usando outra instância. |
| Buscar chave ausente e consultar leitura zero | Se a chave não existir, a busca deve indicar que não encontrou o cadastro. Uma consulta de zero leituras deve retornar uma coleção vazia sem alterar o histórico. | A implementação de `buscar` consulta a chave sem criar uma nova entrada e retorna ausência quando ela não existe. A consulta de zero leituras ainda será verificada na etapa do histórico. |

1. De onde vêm os dois `second` do C++? Por que o `map` precisa de ordem e o `dict` precisa de hash e igualdade?
Os dois `second` aparecem em situações diferentes. No `std::map`, `first` é a chave e `second` é o valor armazenado. Já no resultado de `emplace`, `second` é um booleano que informa se uma nova entrada foi inserida. O `map` usa a ordem das chaves para organizar os elementos, enquanto o `dict` do Python usa hash e igualdade para encontrar as chaves.

2. Qual comportamento mudaria se cada tentativa sobrescrevesse o cadastro? Em que requisito essa alternativa seria adequada?
Se cada tentativa sobrescrevesse o cadastro, a medição de 12% seria perdida quando fosse cadastrada a de 99%. Isso não atende ao requisito de não substituir uma medição já registrada. Essa alternativa seria adequada quando a intenção fosse manter somente a medição mais recente de cada sensor.

3. Por que um conjunto de tags não substitui o catálogo de medições? Hashes diferentes para objetos iguais seriam aceitáveis?
Um conjunto de tags não substitui o catálogo porque ele guardaria apenas as tags, sem a medição associada a cada sensor. O catálogo precisa relacionar a tag com seu cadastro e sua medição. Hashes diferentes para objetos que são considerados iguais não seriam aceitáveis, porque objetos iguais precisam ser encontrados pela mesma chave.

## Etapa 02 — remover, consultar e pensar na memória (até 350 palavras)

| Situação | Minha previsão | Evidência C++ e Python |
|---|---|---|
| Remover chave existente duas vezes | A primeira remoção deve retornar verdadeiro e a segunda deve retornar falso. A chave removida não deve continuar no catálogo. | `make test ETAPA=02` passou em C++ e Python. A primeira remoção retorna sucesso e a segunda retorna ausência. |
| Consultar 0, 2 e 100 últimas leituras de [12, 12, 15] | O limite 0 deve retornar vazio. O limite 2 deve retornar [12, 15] e o limite 100 deve retornar as três leituras, mantendo a ordem e as repetições. | `make test ETAPA=02` passou em C++ e Python. As consultas retornam as leituras corretas sem alterar o histórico original. |
| Limpar a coleção devolvida e consultar novamente | Alterar a coleção devolvida não deve alterar o histórico original. | Os testes da etapa 02 passaram. Em Python é criada uma nova lista e em C++ é criado um novo `vector`. |
| Remover cadastro e consultar histórico independente | Remover o cadastro não deve apagar as leituras que já estão no histórico. | `make test ETAPA=02` passou em C++ e Python. O catálogo e o histórico são estruturas separadas, então remover o cadastro não apaga o histórico. |


1. Descreva seu algoritmo para `ultimas`, sobretudo o caso zero. Cite a decisão de fronteira que precisou adaptar em cada linguagem.
No C++, se o limite for zero ou o histórico estiver vazio, retorno uma coleção vazia. Se o limite for menor que a quantidade de leituras, começo nas últimas posições e mantenho a ordem original. Em Python, também trato o limite zero e uso uma nova lista com fatiamento. Python ainda precisa rejeitar limite negativo com ValueError, enquanto C++ recebe std::size_t.


2. A consulta limita a memória do histórico? Para apenas exibir os últimos dez valores, quando bastaria esta consulta e quando seria necessário descartar dados antigos? O que se perde ao descartar?
Não. A consulta apenas escolhe quais leituras serão retornadas e mantém todas no histórico. Para apenas exibir os últimos dez, ultimas(10) seria suficiente. Para guardar somente dez, seria necessário alterar o registro para descartar as mais antigas. Nesse caso, perderíamos parte do histórico.


3. Compare posse e referências: se o chamador ainda tem uma medição Python, apagar a entrada do catálogo a destrói? E um ponteiro C++ para uma entrada removida pode continuar sendo usado?
Não. Em Python, apagar a entrada do catálogo não destrói uma medição que ainda possui outra referência. Em C++, um ponteiro para uma entrada removida do map fica inválido e não pode continuar sendo usado.


4. Escolha uma alternativa rejeitada (eliminar repetições, retornar a coleção interna, ordenar por valor ou guardar apenas uma soma). Indique qual requisito ela violaria e um cenário em que seria útil.
Escolhi eliminar repetições. Isso violaria o requisito de preservar todas as ocorrências, porque duas leituras iguais podem representar momentos diferentes. Poderia ser útil em uma situação em que fosse necessário saber apenas quais valores diferentes apareceram.

## Evidências da entrega

- Comando local, resultado e commit testado:
- URL da execução de Actions desse commit:
- Um diagnóstico de falha encontrado e como o corrigiu:
- Limite observado dos testes: o que ainda exige inspeção/explicação?
