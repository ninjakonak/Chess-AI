#include "../../include/PieceInclude/Queen.h"

Queen::Queen() {

}

Queen::Queen(char color, sf::Vector2i tile){
	this->color = color;
	this->coordinates = tile;
}

std::vector<sf::Vector2i> Queen::Diagonals(std::string notation, sf::Vector2i selectedTile) {
	std::vector<sf::Vector2i> moves;

	bool minusDown = false;
	bool minusUp = false;
	bool plusDown = false;
	bool plusUp = false;

	for (int x = selectedTile.x - 1; x >= 0; x--) {
		sf::Vector2i minusDownPos = sf::Vector2i(x, selectedTile.y + selectedTile.x - x);
		sf::Vector2i minusUpPos = sf::Vector2i(x, selectedTile.y - (selectedTile.x - x));

		if (minusDownPos.y <= 7 && !minusDown) {

			if (this->findSquareValue(notation, minusDownPos)[0] != this->color && this->findSquareValue(notation, minusDownPos)[0] != '0') {


				moves.push_back(minusDownPos);
				minusDown = true;
			}
			else if (this->findSquareValue(notation, minusDownPos)[0] == this->color && this->findSquareValue(notation, minusDownPos)[0] != '0') {

				minusDown = true;
			}
			else {
				moves.push_back(minusDownPos);
			}
		}

		if (minusUpPos.y >= 0 && !minusUp) {
			if (this->findSquareValue(notation, minusUpPos)[0] != this->color && this->findSquareValue(notation, minusUpPos)[0] != '0') {

				moves.push_back(minusUpPos);
				minusUp = true;
			}
			else if (this->findSquareValue(notation, minusUpPos)[0] == this->color && this->findSquareValue(notation, minusUpPos)[0] != '0') {
				minusUp = true;
			}
			else {
				moves.push_back(minusUpPos);
			}
		}
	}

	for (int x = selectedTile.x + 1; x <= 7; x++) {
		sf::Vector2i plusDownPos = sf::Vector2i(x, selectedTile.y + x - selectedTile.x);
		sf::Vector2i plusUpPos = sf::Vector2i(x, selectedTile.y - (x - selectedTile.x));

		if (plusDownPos.y <= 7 && !plusDown) {

			if (this->findSquareValue(notation, plusDownPos)[0] != this->color && this->findSquareValue(notation, plusDownPos)[0] != '0') {


				moves.push_back(plusDownPos);
				plusDown = true;
			}
			else if (this->findSquareValue(notation, plusDownPos)[0] == this->color && this->findSquareValue(notation, plusDownPos)[0] != '0') {

				plusDown = true;
			}
			else {
				moves.push_back(plusDownPos);
			}
		}

		if (plusUpPos.y >= 0 && !plusUp) {
			if (this->findSquareValue(notation, plusUpPos)[0] != this->color && this->findSquareValue(notation, plusUpPos)[0] != '0') {

				moves.push_back(plusUpPos);
				plusUp = true;
			}
			else if (this->findSquareValue(notation, plusUpPos)[0] == this->color && this->findSquareValue(notation, plusUpPos)[0] != '0') {
				plusUp = true;
			}
			else {
				moves.push_back(plusUpPos);
			}
		}

	}

	return moves;
}

std::vector<sf::Vector2i> Queen::Lines(std::string notation, sf::Vector2i selectedTile) {
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

std::vector<sf::Vector2i> Queen::legalMoves(std::string notation, sf::Vector2i selectedTile){

	std::vector<sf::Vector2i> lines = this->Lines(notation, selectedTile);

	std::vector<sf::Vector2i> diagonals = this->Diagonals(notation, selectedTile);

	lines.insert(lines.end(), diagonals.begin(), diagonals.end());

	return lines;
}
