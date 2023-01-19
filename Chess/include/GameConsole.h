#pragma once
#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H

#include"GameBoard.h"

class GameConsole
{
public:
	const bool Running() const;

	void Update();
	void Render();

	GameConsole();
	~GameConsole();

private:

	void InitVariables();

	sf::Texture blackPawnTexture;
	sf::Texture blackQueenTexture;
	sf::Texture blackKnightTexture;
	sf::Texture blackKingTexture;
	sf::Texture blackBishopTexture;
	sf::Texture blackRookTexture;

	sf::Texture whiteKingTexture;
	sf::Texture whitePawnTexture;
	sf::Texture whiteQueenTexture;
	sf::Texture whiteRookTexture;
	sf::Texture whiteBishopTexture;
	sf::Texture whiteKnightTexture;

	GameBoard board;

	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	sf::Event e;

	void PollEvents();

	int boardWidth;
	int boardHeight;

	void CreateWindow();

};

#endif