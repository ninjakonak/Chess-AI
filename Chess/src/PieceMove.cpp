#include "../include/PieceMove.h"

PieceMove::PieceMove() {

}

PieceMove::PieceMove(std::string notation, int* turnCounter) {
	this->notation = notation;

	this->turnCounter = turnCounter;

	this->InitPieces();
}

void PieceMove::InitPieces() {

	int xPos = 0;
	int yPos = 0;

	for (int i = 0; i < notation.length(); i += 3) {


		xPos = (i / 3) % 8;
		yPos = (i / 24);

		if (this->notation.at(i + 1) == 'b') {
			this->bishop.Init(this->notation.at(i), sf::Vector2i(xPos, yPos), this->turnCounter);
			this->bishops.push_back(this->bishop);
		}

		if (this->notation.at(i + 1) == 'r') {
			this->rook.Init(this->notation.at(i), sf::Vector2i(xPos, yPos), this->turnCounter);
			this->rooks.push_back(this->rook);
		}

		if (this->notation.at(i + 1) == 'n') {
			this->knight.Init(this->notation.at(i), sf::Vector2i(xPos, yPos), this->turnCounter);
			this->knights.push_back(this->knight);
		}

		if (this->notation.at(i + 1) == 'p') {
			this->pawn.Init(this->notation.at(i), sf::Vector2i(xPos, yPos), this->turnCounter);
			this->pawns.push_back(this->pawn);
		}

		if (this->notation.at(i + 1) == 'q') {
			this->queen.Init(this->notation.at(i), sf::Vector2i(xPos, yPos), this->turnCounter);
			this->queens.push_back(this->queen);
		}

		if (this->notation.at(i + 1) == 'k') {
			this->king.Init(this->notation.at(i), sf::Vector2i(xPos, yPos), this->turnCounter);
			this->kings.push_back(this->king);
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
				moves = piece.legalMoves(notation, selectedTile, this->pawns);
				
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

	if (piece[1] == 'k') {
		for (auto& piece : this->kings) {
			if (selectedTile == piece.coordinates) {
				moves = piece.legalMoves(notation, selectedTile, this->rooks);

				char color = piece.color;
				
				std::vector<sf::Vector2i> checkMoves = this->GetMoves(color, notation);

				for (auto& move : checkMoves) {
					
				}
			}
		}
	}
	
	return moves;
}

void PieceMove::UpdatePieces(sf::Vector2i selectedTile, sf::Vector2i targetTile, char piece) {
	
	if (piece == 'p') {
		for (auto& piece : this->pawns) {
			if (selectedTile == piece.coordinates) {

				if (abs(targetTile.y - piece.coordinates.y) == 2) {
					piece.SetFirstMove(*this->turnCounter);
				}


				piece.SetCoordinates(targetTile);
				if (!piece.movedMore) {
					piece.CheckMoved();
				}
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

				if (!piece.movedMore) {
					piece.CheckMoved();
				}
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

	if (piece == 'k') {
		for (auto& piece : this->kings) {
			if (selectedTile == piece.coordinates) {
				piece.SetCoordinates(targetTile);

				if (!piece.movedMore) {
					piece.CheckMoved();
				}
			}
		}
	}
}

std::string PieceMove::NewNotation(std::string notation, sf::Vector2i selectedTile, sf::Vector2i targetTile, std::string selectedPieceValue, bool change) {
	
	int xPos = 0;
	int yPos = 0;

	bool enPassant;

	std::string newNotation = "";
	if (change) {
		this->UpdatePieces(selectedTile, targetTile, selectedPieceValue[1]);
	}
	enPassant = false;


	if (selectedPieceValue[1] == 'p' && selectedTile.x != targetTile.x && (std::string("") + FindSquareVal(targetTile.x, targetTile.y, notation) == "00")) {
		enPassant = true;
	}
	

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

		else if (enPassant && xPos == targetTile.x && yPos == selectedTile.y) {
			newNotation += '0';
			newNotation += '0';
			newNotation += ',';
		}

		else {
			if (xPos == targetTile.x && yPos == selectedTile.y) {
			}
			if (change) {
				newNotation += notation.at(i);
				newNotation += notation.at(i + 1);
				newNotation += notation.at(i + 2);
			}
			else {
				newNotation += this->notation.at(i);
				newNotation += this->notation.at(i + 1);
				newNotation += this->notation.at(i + 2);
			}
		}

	}

	/*
	std::cout << "\n \n \n \n";
	std::cout << "\n/////////////////////////////////////";
	
	for (int x = 0; x < newNotation.length(); x++) {

		if (x % 24 == 0) {
			std::cout << "\n";
		}

		std::cout << newNotation.at(x);
		
	}
	std::cout << "\n///////////////////////////////////// \n";
	std::cout << "turn:" << *this->turnCounter << "\n";
	std::cout << "\n \n \n \n";
	*/

	return newNotation;
}

void PieceMove::ChangeNotation(std::string notation) {
	this->notation = notation;
}

std::vector<sf::Vector2i> PieceMove::GetMoves(char color, std::string notation)
{
	std::vector<sf::Vector2i> moves;

	if (color == 'W') {
		color = 'B';
	}
	else {
		color = 'W';
	}

	for (auto& e : this->bishops) {
		if (e.color == color && this->FindSquareVal(e.coordinates.x, e.coordinates.y, notation) == std::string("") + color + "b") {
			for (auto& move : (e.legalMoves(notation, e.coordinates))) {
				moves.push_back(move);
			}
		}
	}

	for (auto& e : this->kings) {
		if (e.color == color && this->FindSquareVal(e.coordinates.x, e.coordinates.y, notation) == std::string("") + color + "k") {
			for (auto& move : (e.legalMoves(notation, e.coordinates, this->rooks))) {
				moves.push_back(move);
			}
		}
	}

	for (auto& e : this->queens) {
		if (e.color == color && this->FindSquareVal(e.coordinates.x, e.coordinates.y, notation) == std::string("") + color + "q") {
			for (auto& move : (e.legalMoves(notation, e.coordinates))) {
				moves.push_back(move);
			}
		}
	}

	for (auto& e : this->rooks) {
		if (e.color == color && this->FindSquareVal(e.coordinates.x, e.coordinates.y, notation) == std::string("") + color + "r") {
			for (auto& move : (e.legalMoves(notation, e.coordinates))) {
				moves.push_back(move);
			}
		}
	}

	for (auto& e : this->pawns) {
		if (e.color == color && this->FindSquareVal(e.coordinates.x, e.coordinates.y, notation) == std::string("") + color + "p") {
			for (auto& move : (e.legalMoves(notation, e.coordinates, this->pawns))) {
				moves.push_back(move);
			}
		}
	}

	for (auto& e : this->knights) {
		if (e.color == color && this->FindSquareVal(e.coordinates.x, e.coordinates.y, notation) == std::string("") + color + "n") {
			for (auto& move : (e.legalMoves(notation, e.coordinates))) {
				moves.push_back(move);
			}
		}
	}
	return moves;
}

std::string PieceMove::FindSquareVal(int x, int y, std::string notation) {

	int xPos = 0;
	int yPos = 0;

	char notationSquare;

	char color = '0';
	char name = '0';

	for (int i = 0; i < notation.length(); i++) {

		notationSquare = notation.at(i);
		
		

		if (notationSquare == ',') {
			xPos += 1;
		}

		if (xPos == 8) {
			xPos = 0;
			yPos += 1;
		}
		if (xPos == x && yPos == y && (notationSquare == 'B' || notationSquare == 'W')) {
			color = notationSquare;
		}

		if (xPos == x && yPos == y && (notationSquare == 'r' || notationSquare == 'b' || notationSquare == 'p' || notationSquare == '0' || notationSquare == 'q' || notationSquare == 'k' || notationSquare == 'n')) {
			name = notationSquare;
		}

		
	}
	std::string square = std::string() + color + name;
	
	return square;

}