#include "../../include/PieceInclude/Knight.h"

Knight::Knight() {

}

Knight::Knight(char color, sf::Vector2i tile) {
	this->coordinates = tile;
	this->color = color;
}

std::vector<sf::Vector2i> Knight::legalMoves(std::string notation, sf::Vector2i selectedTile) {

	std::vector<sf::Vector2i> temporaryMoves;
	std::vector<sf::Vector2i> moves;

	temporaryMoves.push_back(sf::Vector2i(selectedTile.x - 2, selectedTile.y - 1));
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x + 2, selectedTile.y - 1));
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y + 2));
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y + 2));
	   
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x - 2, selectedTile.y + 1));
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x + 2, selectedTile.y + 1));
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y - 2));
	temporaryMoves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y - 2));

	
	for (auto& move : temporaryMoves) {
		if (this->findSquareValue(notation, move)[0] != this->color) {
			moves.push_back(move);
		}
	}
	
	temporaryMoves = moves;
	moves.clear();
	
	for (auto& move : temporaryMoves) {
		
		if (move.x <= 7 && move.y <= 7 && move.x >= 0 && move.y >= 0) {
			moves.push_back(move);
		}
	}
	
	

	return moves;

}