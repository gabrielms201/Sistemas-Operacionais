# Lab02a-Processos Gerais
> 1 - Rode o programa anterior para valores grandes de n. As
mensagens sempre estar ̃ao ordenadas pelo valor de i?

Sim, rodando o programa utilizando o **stderr** como streaming de saída o "i" fica em ordem. Utilizamos para n = 10000. Nosso output pode ser visto em [stderr_test.txt](stderr_test.txt)


> 2 O que acontece se o programa anterior escreve-se as mensagens
para sys.stdout, usando print, ao invés de para sys.stderr

Não, rodando o programa utilizando o **stdout** como streaming de saída o "i" **não** fica totalmente em ordem todas as vezes. Utilizamos para n = 10000. 
Nosso output pode ser visto em [stdout_test.txt](stdout_test.txt) (**últimas linhas da execução**).

Por conta do buffer, podemos ter problemas na hora de imprimir esses dados, já que diferente da stream do **stderr**, a **stdout** é bufferizada. Uma maneira de evitar isso é chamando o método **fflush()** para resolver o problema.
