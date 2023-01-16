#include "../../include/PieceInclude/Piece.h"

void Piece::SetColor(char color) {
	this->color = color;
}

void Piece::SetCoordinates(sf::Vector2i tile) {
	this->coordinates = tile;
}

std::string Piece::findSquareValue(std::string notation, sf::Vector2i tile) {

	sf::Vector2i pos = sf::Vector2i(0,0);
	
	
	for (int i = 0; i < notation.length(); i += 3) {
		pos.x = (i / 3) % 8;
		pos.y = (i / 24);
		
		if (pos == tile) {
			return std::string("") + notation.at(i) + notation.at(i + 1);
		}
	}
	return "00";
}