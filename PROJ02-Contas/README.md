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
Ele vai realizar transações, e verificar se o saldo de cada conta é o esperado.
Esse teste vai rodar até que aconteça alguma condição de corrida. Se não parar, e por que não temos condição de corrida.
Comentar o mutex do código fará o teste detectar uma race condition. Caso o contrário, não acontecerá.

Também, é possível validar que está tudo OK fora do modo teste. Para isso bastar rodar o programa normalmente, e verificar que a conta "a1" (from) enviou tudo para a conta "a2" (to). (resultado é impresso na tela)

Como rodar o modo teste:
```
./programa -test
```

Execução normal:
```
Balance before transactions: 
AccountNumber: 1
    ->Balance: 1000

AccountNumber: 2
    ->Balance: 100

<----------->
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[Thread Init] sending 10 from 1 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[From]::Account [2] receiving R$: 10 from 1
[Thread Init] sending 10 from 1 to 2
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[Thread Init] sending 10 from 1 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[Thread Init] sending 10 from 1 to 2
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
[From]::Account [2] receiving R$: 10 from 1
[To]::Account [1] sending R$: 10 to 2
<----------->

Balance after transactions: 
AccountNumber: 1
    ->Balance: 0

AccountNumber: 2
    ->Balance: 1100

<----------->

```

# Explicação

Foi resolvido o problema de concorrência atráves de um mutex global, que é travado ao entrar numa região crítica. Com isso, as demais threads aguardarâo a liberação do mutex para continuar a execução.
