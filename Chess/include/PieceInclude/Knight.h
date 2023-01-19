#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H

#include"Piece.h"

class Knight:public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile);

	Knight();
	Knight(char color, sf::Vector2i tile);
};


#endif
