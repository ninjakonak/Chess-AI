#include "../include/PieceMove.h"

PieceMove::PieceMove() {
	
}

PieceMove::PieceMove(std::string notation) {
	this->notation = notation;

	this->InitPieces();
}

void PieceMove::InitPieces() {

	int xPos = 0;
	int yPos = 0;

	for (int i = 0; i < notation.length(); i += 3) {


		xPos = (i / 3) % 8;
		yPos = (i / 24);

		if (this->notation.at(i + 1) == 'b') {
			this->bishop.SetColor(this->notation.at(i));
			this->bishop.SetCoordinates(sf::Vector2i(xPos, yPos));
			this->bishops.push_back(this->bishop);
		}

		if (this->notation.at(i + 1) == 'r') {
			this->rook.SetColor(this->notation.at(i));
			this->rook.SetCoordinates(sf::Vector2i(xPos, yPos));
			this->rooks.push_back(this->rook);
		}
	}

	
}

std::vector<sf::Vector2i> PieceMove::legalMoves(sf::Vector2i selectedTile, std::string notation, std::string piece) {

	char color = 0;
	std::vector<sf::Vector2i> moves;

	if (piece[0] == 'W') {
		color = -1;
	}
	else {
		color = 1;
	}

	if (piece[1] == 'p') {
		moves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y + color));
		
		if ((selectedTile.y == 6 && color == -1) || (selectedTile.y == 1 && color == 1)) {
			moves.push_back(sf::Vector2i(selectedTile.x, selectedTile.y + color * 2));
		}
	}
	if (piece[1] == 'n') {
		moves.push_back(sf::Vector2i(selectedTile.x - 2, selectedTile.y + color));
		moves.push_back(sf::Vector2i(selectedTile.x + 2, selectedTile.y + color));
		moves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y + color * 2));
		moves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y + color * 2));

		moves.push_back(sf::Vector2i(selectedTile.x - 2, selectedTile.y + -color));
		moves.push_back(sf::Vector2i(selectedTile.x + 2, selectedTile.y + -color));
		moves.push_back(sf::Vector2i(selectedTile.x + 1, selectedTile.y + -color * 2));
		moves.push_back(sf::Vector2i(selectedTile.x - 1, selectedTile.y + -color * 2));
	}

	if (piece[1] == 'b') {
		//moves = this->bishop.legalMoves(notation, selectedTile);
		for (auto& piece : this->bishops) {
			if (selectedTile == piece.coordinates) {
				moves = piece.legalMoves(notation, selectedTile);
			}
		}
	}
	
	if (piece[1] == 'r') {
		for (auto& piece : this->rooks) {
			if (selectedTile == piece.coordinates) {
				moves = piece.legalMoves(notation, selectedTile);
			}
		}
	}

	return moves;
}

void PieceMove::UpdatePieces(sf::Vector2i selectedTile, sf::Vector2i targetTile, char piece) {
	if (piece == 'b') {
		for (auto& piece : this->bishops) {
			if (selectedTile == piece.coordinates) {
				piece.SetCoordinates(targetTile);
			}
		}
	}

	if (piece == 'r') {
		for (auto& piece : this->rooks) {
			if (selectedTile == piece.coordinates) {
				piece.SetCoordinates(targetTile);
			}
		}
	}
}

std::string PieceMove::NewNotation(std::string notation, sf::Vector2i selectedTile, sf::Vector2i targetTile, std::string selectedPieceValue) {
	int xPos = 0;
	int yPos = 0;

	std::string newNotation = "";

	this->UpdatePieces(selectedTile, targetTile, selectedPieceValue[1]);

	for (int i = 0; i < notation.length(); i += 3) {


		xPos = (i / 3) % 8;
		yPos = (i / 24);

		if (xPos == targetTile.x && yPos == targetTile.y) {
			newNotation += selectedPieceValue[0];
			newNotation += selectedPieceValue[1];
			newNotation += ',';

			
		}

		else if (xPos == selectedTile.x && yPos == selectedTile.y) {
			newNotation += '0';
			newNotation += '0';
			newNotation += ',';
		}
		else {
			newNotation += this->notation.at(i);
			newNotation += this->notation.at(i + 1);
			newNotation += this->notation.at(i + 2);
		}

	}

	return newNotation;
}

void PieceMove::ChangeNotation(std::string notation) {
	this->notation = notation;
}

std::vector<sf::Vector2i> PieceMove::GetMoves(char color, std::string notation)
{
	std::vector<sf::Vector2i> moves;

	if (color == 'W') {
		std::cout << "a";
		color = 'B';
	}
	else {
		color = 'W';
	}

	for (auto& e : this->bishops) {
		if (e.color == color) {
			for (auto& move : (e.legalMoves(notation, e.coordinates))) {
				moves.push_back(move);
			}
		}
	}
	return moves;
}