#pragma once
#ifndef PAWN_H
#define PAWN_H

#include"Piece.h"

class Pawn :public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile);

	Pawn();
	Pawn(char color, sf::Vector2i tile);
};


#endif
