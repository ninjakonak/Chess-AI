#include "../../include/PieceInclude/Pawn.h"



std::vector<sf::Vector2i> Pawn::legalMoves(std::string notation, sf::Vector2i selectedTile, std::vector<Pawn> pawns) {
	std::vector<sf::Vector2i> moves;
	int yColor;
	if (this->color == 'W') {
		yColor = -1;
	}
	else {
		yColor = 1;
	}

	
	std::string leftCross = findSquareValue(notation, sf::Vector2i(selectedTile.x - 1, selectedTile.y + yColor));
	std::string rightCross = findSquareValue(notation, sf::Vector2i(selectedTile.x + 1, selectedTile.y + yColor));

	if (findSquareValue(notation, sf::Vector2i(selectedTile.x, selectedTile.y + yColor)) == "00") {
		moves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y + yColor));
	}

	if (!movedOnce && 
		findSquareValue(notation, sf::Vector2i(selectedTile.x, selectedTile.y + yColor * 2)) == "00" &&
		findSquareValue(notation, sf::Vector2i(selectedTile.x, selectedTile.y + yColor)) == "00") {
		moves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y + yColor * 2));
	}

	if (leftCross[0] != this->color && leftCross[0] != '0') {
		moves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y + yColor));
	}
	if (rightCross[0] != this->color && rightCross[0] != '0') {
		moves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y + yColor));
	}


	

	for (auto& pawn : pawns) {
		if (pawn.CheckEnPassant(pawns) && pawn.coordinates.y == this->coordinates.y && (pawn.coordinates.x == this->coordinates.x + 1 || pawn.coordinates.x == this->coordinates.x - 1)) {
			moves.push_back(sf::Vector2i(pawn.coordinates.x, pawn.coordinates.y + yColor));
		}
	}

	return moves;
}

void Pawn::SetFirstMove(int firstMove) {
	this->firstMove = firstMove;
}

bool Pawn::CheckEnPassant(std::vector<Pawn> pawns) {
	int moveDecrement;
	for (auto& pawn : pawns) {
		if (pawn.color == 'W') {
			moveDecrement = -1;
		}
		else {
			moveDecrement = 0;
		}
		

		if (this->firstMove == *this->turnCounter + moveDecrement && pawn.color != this->color && firstMove != -1) {
			return true;
		}
	}
	
	return false;
}