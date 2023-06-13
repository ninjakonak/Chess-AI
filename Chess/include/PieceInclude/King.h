#pragma once
#ifndef KING_H
#define KING_H
 
#include"Piece.h"
#include"Rook.h"
class King :public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile, std::vector<Rook> rooks, std::vector<sf::Vector2i> opponentMoves);

	
};

#endif