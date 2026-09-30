# Rastreabilidade de IA

Se não utilizou IA, declare explicitamente. Caso tenha utilizado, preencha para cada incremento:

| Pedido ao agente | Sugestão aceita/rejeitada | Minha justificativa técnica | Como conferi |
|---|---|---|---|
| Implementar a inserção do catálogo em C++ sem sobrescrever uma chave existente. | Aceita | Usei `emplace`, que permite inserir somente se a chave ainda não existir. O `second` do resultado informa se uma nova entrada foi criada. | Executei `make test ETAPA=01` e o teste C++ passou. |
| Implementar a inserção do catálogo em Python sem sobrescrever uma chave existente. | Aceita | Verifiquei primeiro se a chave já existe no `dict`. Assim, a segunda medição com a mesma tag é recusada e a primeira é preservada. | Executei `make test ETAPA=01` e o teste Python passou. |
| Implementar a busca em C++ sem criar uma entrada quando a chave não existe. | Aceita | Usei `find` e comparei com `end()`. Quando encontra, retorno o endereço do `second`; quando não encontra, retorno `nullptr`. | Executei `make test ETAPA=01` e `make run`. |
| Implementar a busca em Python sem criar uma entrada quando a chave não existe. | Aceita | Usei `get`, que retorna o item ou `None` sem adicionar uma nova chave ao `dict`. | Executei `make test ETAPA=01` e `make run`. |
| Preencher as previsões e evidências da Etapa 01. | Aceita | Registrei o comportamento de identidade, igualdade, duplicata e preservação da primeira medição com base nos resultados observados. | Comparei as explicações com a saída de `make run` e com os testes da Etapa 01. |