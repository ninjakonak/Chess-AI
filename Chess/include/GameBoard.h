#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

#include<iostream>
#include"PieceMove.h"

class GameBoard
{
public:
	
	void DrawBoard();
	void Update();

	GameBoard(sf::RenderWindow* window, int boardWidth, int boardHeight);
	GameBoard();
	~GameBoard();

private:
	sf::RenderWindow* window;

	int height;
	int width;

	int TileSize;

	sf::RectangleShape tile;

	sf::RectangleShape pieceTexture;

	int pieceWidth;
	int pieceHeight;

	bool mousePressed = false;
	bool selected;

	sf::Vector2i mousePosition;

	sf::Vector2i selectedTile;
	sf::Vector2i targetTile;

	void InitTile();

	void InitVariables();

	

	std::string notation = 
		"Br,Bn,Bb,Bq,Bk,Bb,Bn,Br,"
		"Bp,Bp,Bp,Bp,Bp,Bp,Bp,Bp,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"Wp,Wp,Wp,Wp,Wp,Wp,Wp,Wp,"
		"Wr,Wn,Wb,Wq,Wk,Wb,Wn,Wr,";
	
	char Turn = 0;
	
	void CheckEvents();

	std::string selectedPieceValue = "";
	std::string targetSquareValue = "";

	void UpdateNotation();

	std::string FindSquareValue(int x, int y);

	void DrawPieces();

	PieceMove PieceMover;
	std::vector<sf::Vector2i> legalMoves;
};

#endif
