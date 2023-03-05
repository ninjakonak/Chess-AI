#pragma once
#ifndef PAWN_H
#define PAWN_H

#include"Piece.h"

class Pawn :public Piece
{
public:

	std::vector<sf::Vector2i> legalMoves(std::string notation, sf::Vector2i selectedTile, std::vector<Pawn> pawns);
	bool CheckEnPassant(std::vector<Pawn> pawns);

	void SetFirstMove(int firstMove);

	int firstMove = -1;

	
};


#endif
