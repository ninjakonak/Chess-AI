#include "../../include/PieceInclude/Bishop.h"



std::vector<sf::Vector2i> Bishop::legalMoves(std::string notation, sf::Vector2i selectedTile) {
	std::vector<sf::Vector2i> moves;

	bool minusDown = false;
	bool minusUp = false;
	bool plusDown = false;
	bool plusUp = false;

	for (int x = selectedTile.x - 1; x >= 0; x--) {
		sf::Vector2i minusDownPos = sf::Vector2i(x, selectedTile.y + selectedTile.x - x);
		sf::Vector2i minusUpPos = sf::Vector2i(x, selectedTile.y - (selectedTile.x - x));
		
		if (minusDownPos.y <= 7 &&! minusDown) {

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
