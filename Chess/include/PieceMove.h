#pragma once
#ifndef PIECEMOVE_H
#define PIECEMOVE_H

#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

#include"PieceInclude/Bishop.h"
#include"PieceInclude/Rook.h"
#include"PieceInclude/Knight.h"
#include"PieceInclude/Pawn.h"
#include"PieceInclude/Queen.h"
#include"PieceInclude/King.h"

#include<iostream>

class PieceMove
{

public:
	PieceMove();
	PieceMove(std::string notation);

	std::vector<sf::Vector2i> legalMoves(sf::Vector2i selectedTile, std::string notation, std::string piece);

	std::string NewNotation(std::string notation, sf::Vector2i selectedTile, sf::Vector2i targetTile, std::string selectedPieceValue, bool change);
	void ChangeNotation(std::string notation);
	
	std::vector<sf::Vector2i> GetMoves(char color, std::string notation);

private:
	
	sf::Vector2i selectedTile;

	std::string notation;

	std::string piece;

	Bishop bishop;
	std::vector<Bishop> bishops;

	Rook rook;
	std::vector<Rook> rooks;

	Knight knight;
	std::vector<Knight> knights;

	Pawn pawn;
	std::vector<Pawn> pawns;

	Queen queen;
	std::vector<Queen> queens;

	King king;
	std::vector<King> kings;

	void InitPieces();
	void UpdatePieces(sf::Vector2i selectedTile, sf::Vector2i targetTile, char piece);

	std::string FindSquareVal(int x, int y, std::string notation);

};

#endif