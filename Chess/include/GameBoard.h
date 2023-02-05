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

	void InitTextures(sf::Texture blackPawn, sf::Texture blackKnight, 
					  sf::Texture blackBishop, sf::Texture blackRook,
					  sf::Texture blackQueen, sf::Texture blackKing,
					  sf::Texture whitePawn, sf::Texture whiteKnight,
					  sf::Texture whiteBishop, sf::Texture whiteRook,
					  sf::Texture whiteQueen, sf::Texture whiteKing);

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
	
	sf::Sprite blackPawnSprite;
	sf::Texture blackPawnTexture;

	sf::Sprite blackKnightSprite;
	sf::Texture blackKnightTexture;

	sf::Sprite blackBishopSprite;
	sf::Texture blackBishopTexture;

	sf::Sprite blackRookSprite;
	sf::Texture blackRookTexture;

	sf::Sprite blackQueenSprite;
	sf::Texture blackQueenTexture;

	sf::Sprite blackKingSprite;
	sf::Texture blackKingTexture;

	sf::Sprite whitePawnSprite;
	sf::Texture whitePawnTexture;

	sf::Sprite whiteKnightSprite;
	sf::Texture whiteKnightTexture;

	sf::Sprite whiteBishopSprite;
	sf::Texture whiteBishopTexture;

	sf::Sprite whiteRookSprite;
	sf::Texture whiteRookTexture;

	sf::Sprite whiteQueenSprite;
	sf::Texture whiteQueenTexture;

	sf::Sprite whiteKingSprite;
	sf::Texture whiteKingTexture;

	int pieceWidth;
	int pieceHeight;

	bool mousePressed = false;
	bool selected;

	sf::Vector2i mousePosition;

	sf::Vector2i selectedTile;
	sf::Vector2i targetTile;

	void InitTile();

	void InitVariables();

	
	/*
	std::string notation = 
		"Br,Bn,Bb,Bq,Bk,Bb,Bn,Br,"
		"Bp,Bp,Bp,Bp,Bp,Bp,Bp,Bp,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"Wp,Wp,Wp,Wp,Wp,Wp,Wp,Wp,"
		"Wr,Wn,Wb,Wq,Wk,Wb,Wn,Wr,";

	*/

	std::string notation =
		"00,00,00,00,00,00,00,00,"
		"00,Bp,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"00,00,Bk,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,"
		"Wk,00,00,00,00,00,00,00,"
		"00,00,00,00,00,00,00,00,";
	
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
