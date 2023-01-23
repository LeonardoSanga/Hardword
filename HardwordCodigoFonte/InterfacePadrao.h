#pragma once

#include <SFML/Graphics.hpp>

enum Estado { NenhumEstado, Finalizar, Reiniciar, Menu, Sair };

/*
   Classe básica abstrata InterfacePadrao: serve como uma interface genérica para servir de base para as demais interfaces no programa
*/

class InterfacePadrao
{
public:
	InterfacePadrao(sf::IntRect limites) : limites(limites), habilitado(true) {};

	virtual ~InterfacePadrao() = default;

	virtual void atualiza(const float tempoDelta) = 0;

	virtual void desenha(sf::RenderWindow& janela) = 0;

	virtual void lidaComMousePressionado(const sf::Vector2i& posicaoDoMouse, bool botaoEsquerdo) {};

	virtual void lidaComMouseMovido(const sf::Vector2i& posicaoDoMouse) {};

	virtual void lidaComTeclaPressionada(const sf::Keyboard::Key tecla) {};

	void setHabilitado(bool habilitado) { habilitado = habilitado; };

	bool getHabilitado() const { return habilitado; }

	virtual Estado getEstado() const { return Estado::NenhumEstado; };

protected:
	sf::IntRect limites;

	bool habilitado;
};

