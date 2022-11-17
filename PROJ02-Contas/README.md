# Para compilar o programa, execute:
```
make
```
ou
```
g++ program.cpp -std=c++11 -pthread -o programa
```
para executar, basta rodar:
```
./programa
```

# Comprovando que os resultados propostos foram alcançados
Para comprovar há o modo teste no código.
O teste tem um conceito simples: 
Ele vai realizar transações, e verificar se o saldo de cad aconta é o esperado.
Esse teste vai rodar até que aconteça alguma condição de corrida. Se não parar, e por que não temos condição de corrida.
Comentar o mutex do código fará o teste detectar uma race condition. Caso o contrário, não acontecerá.

Também, é possível validar que está tudo OK fora do modo teste. Para isso bastar rodar o programa normalmente, e verificar que a conta "a1" (from) enviou tudo para a conta "a2" (to). (resultado é impresso na tela)

Como rodar o modo teste:
```
./programa -test
```

# Explicação

Foi resolvido o problema de concorrência atráves de um mutex global, que é travado ao entrar numa região crítica. Com isso, as demais threads aguardarâo a liberação do mutex para continuar a execução.
