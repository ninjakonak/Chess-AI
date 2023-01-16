#pragma once
#ifndef PIECEMOVE_H
#define PIECEMOVE_H

#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

#include"PieceInclude/Bishop.h"
#include"PieceInclude/Rook.h"

#include<iostream>

class PieceMove
{

public:
	PieceMove();
	PieceMove(std::string notation);

	std::vector<sf::Vector2i> legalMoves(sf::Vector2i selectedTile, std::string notation, std::string piece);

	std::string NewNotation(std::string notation, sf::Vector2i selectedTile, sf::Vector2i targetTile, std::string selectedPieceValue);
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

	void InitPieces();
	void UpdatePieces(sf::Vector2i selectedTile, sf::Vector2i targetTile, char piece);

};

#endif