
#include "Span.hpp"
#include <vector>

int main(void)
{
	std::cout << "===== TESTE BASICO =====" << std::endl;

	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== TESTE LIMITE CHEIO =====" << std::endl;

	try
	{
		Span sp = Span(3);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);

		std::cout << "Tentando adicionar mais um numero..." << std::endl;
		sp.addNumber(40);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== TESTE COM POUCOS NUMEROS =====" << std::endl;

	try
	{
		Span sp = Span(5);

		sp.addNumber(42);

		std::cout << "Tentando calcular shortestSpan com apenas 1 numero..." << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro esperado: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== TESTE COM NUMEROS NEGATIVOS =====" << std::endl;

	try
	{
		Span sp = Span(5);

		sp.addNumber(-10);
		sp.addNumber(5);
		sp.addNumber(20);
		sp.addNumber(-30);
		sp.addNumber(0);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== TESTE COM MUITOS NUMEROS =====" << std::endl;

	try
	{
		Span sp = Span(10000);

        std::vector<int> valores;

        for (int i = 0; i < 10000; i++)
            valores.push_back(i);

        sp.addNumber(valores.begin(), valores.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	return (0);
}