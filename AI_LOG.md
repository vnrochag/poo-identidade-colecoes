# Rastreabilidade de IA

Se não utilizou IA, declare explicitamente. Caso tenha utilizado, preencha para cada incremento:

| Pedido ao agente | Sugestão aceita/rejeitada | Minha justificativa técnica | Como conferi |
|---|---|---|---|
| Implementar a inserção do catálogo em C++ sem sobrescrever uma chave existente. | Aceita | Usei `emplace`, que permite inserir somente se a chave ainda não existir. O `second` do resultado informa se uma nova entrada foi criada. | Executei `make test ETAPA=01` e o teste C++ passou. |
| Implementar a inserção do catálogo em Python sem sobrescrever uma chave existente. | Aceita | Verifiquei primeiro se a chave já existe no `dict`. Assim, a segunda medição com a mesma tag é recusada e a primeira é preservada. | Executei `make test ETAPA=01` e o teste Python passou. |
| Implementar a busca em C++ sem criar uma entrada quando a chave não existe. | Aceita | Usei `find` e comparei com `end()`. Quando encontra, retorno o endereço do `second`; quando não encontra, retorno `nullptr`. | Executei `make test ETAPA=01` e `make run`. |
| Implementar a busca em Python sem criar uma entrada quando a chave não existe. | Aceita | Usei `get`, que retorna o item ou `None` sem adicionar uma nova chave ao `dict`. | Executei `make test ETAPA=01` e `make run`. |
| Preencher as previsões e evidências da Etapa 01. | Aceita | Registrei o comportamento de identidade, igualdade, duplicata e preservação da primeira medição com base nos resultados observados. | Comparei as explicações com a saída de `make run` e com os testes da Etapa 01. |
| Implementar a remoção do catálogo em C++ sem alterar outras partes. | Aceita | Usei `erase`, que retorna a quantidade de entradas removidas. Assim, retorno verdadeiro quando a chave existia e falso quando não existia. | Executei `make test ETAPA=02` e o teste C++ passou. |
| Implementar a remoção do catálogo em Python sem alterar outras partes. | Aceita | Verifiquei se a chave existia antes de usar `del`. Assim, a remoção retorna verdadeiro somente quando uma entrada é removida. | Executei `make test ETAPA=02` e o teste Python passou. |
| Implementar `ultimas` em C++ mantendo a ordem e as repetições. | Aceita | Retornei um novo `vector` com as últimas leituras, sem modificar o histórico original. O limite zero retorna uma coleção vazia. | Executei `make test ETAPA=02` e o teste C++ passou. |
| Implementar `ultimas` em Python mantendo a ordem e as repetições. | Aceita | Retornei uma nova lista usando fatiamento, mantendo o histórico original. O limite negativo continua sendo rejeitado com `ValueError`. | Executei `make test ETAPA=02` e o teste Python passou. |
| Preencher as previsões e evidências da Etapa 02. | Aceita | Registrei o comportamento da remoção, das consultas do histórico, da independência da coleção retornada e da retenção dos dados em memória. | Comparei as explicações com `make test ETAPA=02` e com o comportamento implementado em C++ e Python. |
