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