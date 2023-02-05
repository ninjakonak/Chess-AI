#include "../../include/PieceInclude/King.h"

King::King() {

}

King::King(char color, sf::Vector2i tile) {
	this->coordinates = tile;
	this->color = color;
}

std::vector<sf::Vector2i> King::legalMoves(std::string notation, sf::Vector2i selectedTile) {

	
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

	return moves;

}