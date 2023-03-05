#include "../../include/PieceInclude/Piece.h"

void Piece::SetColor(char color) {
	this->color = color;
}

void Piece::SetCoordinates(sf::Vector2i tile) {
	this->coordinates = tile;
}

void Piece::CheckMoved() {

	if (this->movedOnce == true) {
		this->movedMore = true;
	}

	if (this->movedOnce == false) {
		this->movedOnce = true;
	}
}

void Piece::Init(char color, sf::Vector2i position, int* turnCounter) {
	this->SetColor(color);
	this->SetCoordinates(position);
	this->movedOnce = false;
	this->movedMore = false;

	this->turnCounter = turnCounter;
	
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