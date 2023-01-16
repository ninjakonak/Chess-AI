#include "../../include/PieceInclude/Rook.h"


Rook::Rook() {

}

Rook::Rook(char color, sf::Vector2i tile) {
	this->coordinates = tile;
	this->color = color;
}

std::vector<sf::Vector2i> Rook::legalMoves(std::string notation, sf::Vector2i selectedTile) {
	std::vector<sf::Vector2i> moves;

	sf::Vector2i leftHorizontalMove;
	sf::Vector2i rightHorizontalMove;
	sf::Vector2i upVerticalMove;
	sf::Vector2i downVerticalMove;


	bool leftHorizontal;
	bool rightHorizontal;
	bool upVertical;
	bool downVertical;

	

	for (int x = selectedTile.x - 1; x >= 0; x--) {
		
		sf::Vector2i leftHorizontalMove = sf::Vector2i(x, selectedTile.y);

		if (findSquareValue(notation, leftHorizontalMove)[0] != '0' && findSquareValue(notation, leftHorizontalMove)[0] != this->color) {
			moves.push_back(leftHorizontalMove);
			break;
		}
		else if (findSquareValue(notation, leftHorizontalMove)[0] == this->color) {
			break;
		}
		else {
			moves.push_back(leftHorizontalMove);
		}

	}

	for (int x = selectedTile.x + 1; x <= 7; x++) {
		sf::Vector2i rightHorizontalMove = sf::Vector2i(x, selectedTile.y);

		if (findSquareValue(notation, rightHorizontalMove)[0] != '0' && findSquareValue(notation, rightHorizontalMove)[0] != this->color) {
			moves.push_back(rightHorizontalMove);
			break;
		}
		else if (findSquareValue(notation, rightHorizontalMove)[0] == this->color) {
			break;
		}
		else {
			moves.push_back(rightHorizontalMove);
		}
	}

	for (int y = selectedTile.y - 1; y >= 0; y--) {

		sf::Vector2i upVerticalMove = sf::Vector2i(selectedTile.x, y);

		if (findSquareValue(notation, upVerticalMove)[0] != '0' && findSquareValue(notation, upVerticalMove)[0] != this->color) {
			moves.push_back(upVerticalMove);
			break;
		}
		else if (findSquareValue(notation, upVerticalMove)[0] == this->color) {
			break;
		}
		else {
			moves.push_back(upVerticalMove);
		}

	}

	for (int y = selectedTile.y + 1; y <= 7; y++) {

		sf::Vector2i downVerticalMove = sf::Vector2i(selectedTile.x, y);

		if (findSquareValue(notation, downVerticalMove)[0] != '0' && findSquareValue(notation, downVerticalMove)[0] != this->color) {
			moves.push_back(downVerticalMove);
			break;
		}
		else if (findSquareValue(notation, downVerticalMove)[0] == this->color) {
			break;
		}
		else {
			moves.push_back(downVerticalMove);
		}

	}

	return moves;
}
