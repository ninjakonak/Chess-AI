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
			this->bishop.Init(this->notation.at(i), sf::Vector2i(xPos, yPos));
			this->bishops.push_back(this->bishop);
		}

		if (this->notation.at(i + 1) == 'r') {
			this->rook.Init(this->notation.at(i), sf::Vector2i(xPos, yPos));
			this->rooks.push_back(this->rook);
		}

		if (this->notation.at(i + 1) == 'n') {
			this->knight.Init(this->notation.at(i), sf::Vector2i(xPos, yPos));
			this->knights.push_back(this->knight);
		}

		if (this->notation.at(i + 1) == 'p') {
			this->pawn.Init(this->notation.at(i), sf::Vector2i(xPos, yPos));
			this->pawns.push_back(this->pawn);
		}

		if (this->notation.at(i + 1) == 'q') {
			this->queen.Init(this->notation.at(i), sf::Vector2i(xPos, yPos));
			this->queens.push_back(this->queen);
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
		for (auto& piece : this->pawns) {
			if (selectedTile == piece.coordinates) {
				moves = piece.legalMoves(notation, selectedTile);
			}
		}
	}
	if (piece[1] == 'n') {
		for (auto& piece : this->knights) {
			if (selectedTile == piece.coordinates) {
				moves = piece.legalMoves(notation, selectedTile);
			}
		}
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

	if (piece[1] == 'q') {
		for (auto& piece : this->queens) {
			if (selectedTile == piece.coordinates) {
				moves = piece.legalMoves(notation, selectedTile);
			}
		}
	}

	return moves;
}

void PieceMove::UpdatePieces(sf::Vector2i selectedTile, sf::Vector2i targetTile, char piece) {

	if (piece == 'p') {
		for (auto& piece : this->pawns) {
			if (selectedTile == piece.coordinates) {
				piece.SetCoordinates(targetTile);
				piece.CheckMoved();
			}
		}
	}

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

	if (piece == 'n') {
		for (auto& piece : this->knights) {
			if (selectedTile == piece.coordinates) {
				piece.SetCoordinates(targetTile);
			}
		}
	}

	if (piece == 'q') {
		for (auto& piece : this->queens) {
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