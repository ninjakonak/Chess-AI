#pragma once

#ifndef QUEEN_H
#define QUEEN_H

#include"Piece.h"

class Queen :public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile);

	std::vector<sf::Vector2i> Diagonals(std::string notation, sf::Vector2i selectedTile);

	std::vector<sf::Vector2i> Lines(std::string notation, sf::Vector2i selectedTile);

	
	
};


#endif
