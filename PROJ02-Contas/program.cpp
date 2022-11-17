// Gabriel Augusto Ribeiro Gomes	           32134762
// Paulo Henrique Braga Cechinel	           32151128
// Ricardo Gabriel Marques dos Santos Ruiz  31234908

#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>

std::mutex g_mtx;
#define MAX_THREADS 100

class Account
{
public:
	Account(unsigned int accountNumber, unsigned long long balance)
		: _accountNumber(accountNumber), _balance(balance)
	{
	}
	// Verifica se o objeto consegue pagar com base no valor inserido
	bool CanPay(unsigned int ammount)
	{
		// verifica se o quanto quer transferir é maior que o saldo
		if (ammount > _balance)
		{
			std::cout << "WARNING: AccountNumber: "
				<< _accountNumber << std::endl << "Cant afford to pay: " << ammount << std::endl << "Current Balance: " << _balance << std::endl;
			return false;
		}
		return true;
	}
	unsigned long long WithdrawMoney(unsigned int ammount)
	{
		_balance -= ammount;
		return _balance;
	}

	bool To(Account* destination, unsigned int ammount)
	{
		// Critical Region
		g_mtx.lock();
		if (!CanPay(ammount))
		{
			// Leaving
			g_mtx.unlock();
			return false;
		}

		destination->From(this, ammount);
		WithdrawMoney(ammount);
		std::cout << "[To]::Account [" << _accountNumber << "]" << " sending R$: " << ammount << " to " << destination->GetAccountNumber() << std::endl;
		// Leaving
		g_mtx.unlock();
		return true;

	}

	void ShowInfo()
	{
		std::cout << "AccountNumber: " << _accountNumber << std::endl << "\t->Balance: " << _balance << std::endl;
	}

	unsigned int GetAccountNumber() { return _accountNumber; }

	unsigned int GetBalance() { return _balance; }
private:
	// privado: essa funcao não é segura para thread
	bool From(Account* sender, unsigned int ammount)
	{
		_balance += ammount;
		std::cout << "[From]::Account [" << _accountNumber << "]" << " receiving R$: " << ammount << " from " << sender->GetAccountNumber() << std::endl;
		return true;
	}
	unsigned long long _balance;
	unsigned int _accountNumber;
};

bool test()
{
	Account a1 = Account(1, 500);
	Account a2 = Account(2, 300);
	unsigned int account1ExepectedBalance = 275;
	unsigned int account2ExepectedBalance = 525;
	
	// 4 envios da conta 1 para a conta 2:
	std::thread t1(&Account::To, &a1, &a2, 100);
	std::thread t2(&Account::To, &a1, &a2, 50);
	std::thread t3(&Account::To, &a1, &a2, 50);
	std::thread t4(&Account::To, &a1, &a2, 25);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	if (a1.GetBalance() != account1ExepectedBalance || a2.GetBalance() != account2ExepectedBalance)
	{
		std::cout << "TEST FAILED: " << std::endl;
		std::cout << "A1: Expected Balance: " << account1ExepectedBalance  << "|| Actual Balance : " << a1.GetBalance() << std::endl;
		std::cout << "A2: Expected Balance: " << account2ExepectedBalance << "|| Actual Balance : " << a1.GetBalance() << std::endl;
	}
	
	return a1.GetBalance() == account1ExepectedBalance && a2.GetBalance() == account2ExepectedBalance;
}

void run()
{
	std::vector<Account*> accounts;
	Account a1 = Account(1, 1000);
	Account a2 = Account(2, 100);
	std::vector<std::thread> pool;

	// adiciona o endereco das contas no vetor de enderecos 
	accounts.push_back(&a1);
	accounts.push_back(&a2);

	std::cout << "Balance before transactions: " << std::endl;

	// Exibir informacao da conta para cada conta
	for (Account* account : accounts)
	{
		account->ShowInfo();
		std::cout << std::endl;
	}
	std::cout << "<----------->" << std::endl;

	int threadCount = 100;
	for (int i = 0; i < threadCount; i++)
	{
		if (i > MAX_THREADS)
		{
			break;
		}
		// Adiciona a thread no pool

		// Enviar 100 reais da conta a1 a conta 2
		pool.push_back(std::thread(&Account::To, &a1, &a2, 10));
		std::cout << "[Thread Init] sending " << 10 << " from " << a1.GetAccountNumber() << " to " << a2.GetAccountNumber() << std::endl;
	}

	// Para cada thread na pool, fazer a thread principal aguardar pelas outras
	for (auto& thread : pool)
	{
		thread.join();
	}

	std::cout << "<----------->" << std::endl;
	std::cout << std::endl << "Balance after transactions: " << std::endl;

	// Exibir informacao da conta para cada conta
	for (Account* account : accounts)
	{
		account->ShowInfo();
		std::cout << std::endl;
	}
	std::cout << "<----------->" << std::endl;
}

int main(int argc, char* argv[])
{
	// Modo de teste.
	// Caso rode o programa com o prefixo test, ele vai rodar até encontrar um problema de race condition
	// Se não encontrar, vai rodar infinitamente
	// Remover o mutex do código forçará a condicao de corrida
	if (argc == 2 && strcmp(argv[1], "-test") == 0) // se argv[1] == "teste"
	{
		bool shouldStop = false;
		while (!shouldStop)
		{
			// deve continuar até o teste falhar (not test)
			shouldStop = !test();
		}
		std::cout << "RACE CONDITION!!!!";
		return 1;
	}
	else
	{
		run();
	}

}



