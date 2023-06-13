#include "../../include/PieceInclude/King.h"



std::vector<sf::Vector2i> King::legalMoves(std::string notation, sf::Vector2i selectedTile, std::vector<Rook> rooks, std::vector<sf::Vector2i> opponentMoves) {

	
	std::vector<sf::Vector2i> tempMoves;
	std::vector<sf::Vector2i> moves;

	tempMoves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y + 1));
	tempMoves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y + 1));
	tempMoves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y));
	tempMoves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y));
	tempMoves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y + 1));
	tempMoves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y));
	tempMoves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y - 1));
	tempMoves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y - 1));
	tempMoves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y - 1));

	for (auto& move : tempMoves) {
		if (findSquareValue(notation, sf::Vector2i(move.x, move.y))[0] != this->color) {
			moves.push_back(move);
		}
	}

	bool rightRookMoved = false;
	bool leftRookMoved = false;

	bool castleQueen = true;
	bool castleKing = true;
	
	for (auto& rook : rooks) {
		if (rook.coordinates.x > this->coordinates.x && rook.movedOnce && rook.color == this->color) {
			rightRookMoved = true;
		}

		if (rook.coordinates.x < this->coordinates.x && rook.movedOnce && rook.color == this->color) {
			leftRookMoved = true;
		}
	}

	if (findSquareValue(notation, sf::Vector2i(this->coordinates.x + 1, this->coordinates.y)) == "00" &&
		findSquareValue(notation, sf::Vector2i(this->coordinates.x + 2, this->coordinates.y)) == "00" && !
		rightRookMoved && 
		this->movedOnce == false) {

		for (auto& move : opponentMoves) {
			if ((move.x == this->coordinates.x + 1 && move.y == this->coordinates.y) || (move.x == this->coordinates.x + 2 && move.y == this->coordinates.y)) {
				castleKing = false;
				std::cout << move.x << "," << move.y << "\n";
			}
		}
	}
	else {
		castleKing = false;
	}

	if (findSquareValue(notation, sf::Vector2i(this->coordinates.x - 1, this->coordinates.y)) == "00" &&
		findSquareValue(notation, sf::Vector2i(this->coordinates.x - 2, this->coordinates.y)) == "00" &&
		findSquareValue(notation, sf::Vector2i(this->coordinates.x - 3, this->coordinates.y)) == "00" && !
		leftRookMoved &&
		this->movedOnce == false) {

		for (auto& move : opponentMoves) {
			if ((move.x == this->coordinates.x - 1 && move.y == this->coordinates.y) || (move.x == this->coordinates.x - 2 && move.y == this->coordinates.y) || (move.x == this->coordinates.x - 3 && move.y == this->coordinates.y)) {
				castleQueen = false;
			}
		}

	}
	else {
		castleQueen = false;
	}

	if (castleQueen) {
		moves.push_back(sf::Vector2i(this->coordinates.x - 2, this->coordinates.y));
	}
	if (castleKing) {
		moves.push_back(sf::Vector2i(this->coordinates.x + 2, this->coordinates.y));
	}

	return moves;

}