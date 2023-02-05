#pragma once
#ifndef KING_H
#define KING_H

#include"Piece.h"

class King :public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile);

	King();
	King(char color, sf::Vector2i tile);
};

#endif