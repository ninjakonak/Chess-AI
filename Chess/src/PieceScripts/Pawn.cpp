#include "../../include/PieceInclude/Pawn.h"

Pawn::Pawn() {

}

Pawn::Pawn(char color, sf::Vector2i tile) {
	this->color = color;
	this->coordinates = tile;
	
}

std::vector<sf::Vector2i> Pawn::legalMoves(std::string notation, sf::Vector2i selectedTile) {
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

	return moves;
}