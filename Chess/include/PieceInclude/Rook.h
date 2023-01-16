#pragma once

#ifndef ROOK_H
#define ROOK_H

#include"Piece.h"

class Rook :public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile);

	Rook();
	Rook(char color, sf::Vector2i tile);
};


#endif
