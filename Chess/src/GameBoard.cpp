#include "../include/GameBoard.h"

GameBoard::GameBoard() {
	
}



GameBoard::GameBoard(sf::RenderWindow* window, int boardWidth, int boardHeight) {
	this->window = window;
	
	this->height = boardHeight;
	this->width = boardWidth;

	this->InitVariables();
	
}

GameBoard::~GameBoard() {
	
}
void GameBoard::InitVariables() {
	this->TileSize = this->height / 8;

	this->InitTile();
	
	
	this->pieceWidth = 48;
	this->pieceHeight = 48;
	this->selected = false;
	this->turnCounter = 0;

	this->pieceTexture.setSize(sf::Vector2f(this->pieceWidth, this->pieceHeight));

	this->PieceMover = PieceMove(this->notation, &this->turnCounter);

	
	
}

void GameBoard::InitTile() {
	this->tile.setSize(sf::Vector2f(this->TileSize,this->TileSize));
}


void GameBoard::InitTextures(sf::Texture blackPawn, sf::Texture blackKnight,
	sf::Texture blackBishop, sf::Texture blackRook,
	sf::Texture blackQueen, sf::Texture blackKing,
	sf::Texture whitePawn, sf::Texture whiteKnight,
	sf::Texture whiteBishop, sf::Texture whiteRook,
	sf::Texture whiteQueen, sf::Texture whiteKing) {

	this->blackPawnTexture = blackPawn;
	this->blackBishopTexture = blackBishop;
	this->blackKingTexture = blackKing;
	this->blackKnightTexture = blackKnight;
	this->blackQueenTexture = blackQueen;
	this->blackRookTexture = blackRook;

	this->whitePawnTexture = whitePawn;
	this->whiteBishopTexture = whiteBishop;
	this->whiteKingTexture = whiteKing;
	this->whiteKnightTexture = whiteKnight;
	this->whiteQueenTexture = whiteQueen;
	this->whiteRookTexture = whiteRook;

	if (!this->whitePawnTexture.loadFromFile("assets/white_pawn.png")) {
		std::cout << "error";
	}

	if (!this->whiteBishopTexture.loadFromFile("assets/white_bishop.png")) {
		std::cout << "error";
	}

	if (!this->whiteKnightTexture.loadFromFile("assets/white_knight.png")) {
		std::cout << "error";
	}

	if (!this->whiteRookTexture.loadFromFile("assets/white_rook.png")) {
		std::cout << "error";
	}

	if (!this->whiteQueenTexture.loadFromFile("assets/white_queen.png")) {
		std::cout << "error";
	}

	if (!this->whiteKingTexture.loadFromFile("assets/white_king.png")) {
		std::cout << "error";
	}



	if (!this->blackPawnTexture.loadFromFile("assets/black_pawn.png")) {
		std::cout << "error";
	}

	if (!this->blackBishopTexture.loadFromFile("assets/black_bishop.png")) {
		std::cout << "error";
	}

	if (!this->blackKnightTexture.loadFromFile("assets/black_knight.png")) {
		std::cout << "error";
	}

	if (!this->blackRookTexture.loadFromFile("assets/black_rook.png")) {
		std::cout << "error";
	}

	if (!this->blackQueenTexture.loadFromFile("assets/black_queen.png")) {
		std::cout << "error";
	}

	if (!this->blackKingTexture.loadFromFile("assets/black_king.png")) {
		std::cout << "error";
	}

	this->whitePawnSprite.setTexture(this->whitePawnTexture);
	this->whiteKnightSprite.setTexture(this->whiteKnightTexture);
	this->whiteBishopSprite.setTexture(this->whiteBishopTexture);
	this->whiteRookSprite.setTexture(this->whiteRookTexture);
	this->whiteQueenSprite.setTexture(this->whiteQueenTexture);
	this->whiteKingSprite.setTexture(this->whiteKingTexture);

	this->blackPawnSprite.setTexture(this->blackPawnTexture);
	this->blackKnightSprite.setTexture(this->blackKnightTexture);
	this->blackBishopSprite.setTexture(this->blackBishopTexture);
	this->blackRookSprite.setTexture(this->blackRookTexture);
	this->blackQueenSprite.setTexture(this->blackQueenTexture);
	this->blackKingSprite.setTexture(this->blackKingTexture);

}

void GameBoard::DrawBoard() {
	sf::Color color;
	sf::Vector3i rgb;
	for (int y = 0; y < this->height / this->TileSize; y++) {
		for (int x = 0; x < this->width / this->TileSize; x++) {
			if ((x + y) % 2 == 0) {
				rgb = sf::Vector3i(238, 203, 141);
			}
			else {
				rgb = sf::Vector3i(202, 107, 58);
			}
			this->tile.setPosition(x*this->TileSize,y*this->TileSize);

			if (x == this->selectedTile.x && y == this->selectedTile.y && selected) {
				rgb = sf::Vector3i(255,255,255) - rgb/2;


			}
			
			if (this->selected) {
				for (auto& e : this->legalMoves) {
					if (e == sf::Vector2i(x, y)) {
						rgb = sf::Vector3i(255, 255, 255) - rgb / 2;
					}
				}
			}
			

			color = sf::Color(rgb.x, rgb.y, rgb.z);
			this->tile.setFillColor(color);
			this->window->draw(this->tile);
		}
	}

	this->DrawPieces();
}

void GameBoard::CheckEvents() {
	
	int xPosition = 0;
	int yPosition = 0;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (!this->mousePressed) {
			this->mousePosition = sf::Mouse::getPosition(*this->window);
			this->mousePressed = true;

			xPosition = (this->mousePosition.x - (this->mousePosition.x % this->TileSize)) / this->TileSize;
			yPosition = (this->mousePosition.y - (this->mousePosition.y % this->TileSize)) / this->TileSize;

			

			if (this->selected && this->selectedTile == sf::Vector2i(xPosition, yPosition)) {
				this->selected = false;
			}

			else if (selected) {
				
				
				this->targetSquareValue = this->FindSquareValue(this->selectedTile.x, this->selectedTile.y);
				if (this->targetSquareValue == "00" && this->selectedPieceValue == "00") {
					this->selectedTile = sf::Vector2i(xPosition, yPosition);
				}
				else if ((this->selectedPieceValue[0] == 'B' && this->Turn == 1) || (this->selectedPieceValue[0] == 'W' && this->Turn == 0)) {

					

					this->targetTile.x = xPosition;
					this->targetTile.y = yPosition;

					for (auto& e : this->legalMoves) {
						if (e.x == targetTile.x && e.y == targetTile.y) {
							
							

							std::string tempNotation = this->PieceMover.NewNotation(this->notation, this->selectedTile, this->targetTile, this->selectedPieceValue, false);

							std::string notation = this->notation;

							this->notation = tempNotation;

							
							

							
							
							char color;
							char oppositeColor;

							if (this->Turn == 0) {
								color = 'W';
								oppositeColor = 'B';
							}
							else {
								color = 'B';
								oppositeColor = 'W';
							}

							

							std::vector<sf::Vector2i> moves = this->PieceMover.ExtractMoveCoordinates(this->PieceMover.GetMoves(color, tempNotation, false));
							std::vector<sf::Vector2i> possibleMoves = this->PieceMover.ExtractMoveCoordinates(this->PieceMover.GetMoves(oppositeColor, this->notation, false));
							std::vector<sf::Vector2i> strictMoves = std::vector<sf::Vector2i>();

							
							
							bool changeNotation = true;

							for (auto& e : moves) {
								if(this->FindSquareValue(e.x, e.y) == std::string("") + color + "k"){
									changeNotation = false;
								}
							}

							
							
							
							if (changeNotation) {
								this->notation = this->PieceMover.NewNotation(this->notation, this->selectedTile, this->targetTile, this->selectedPieceValue, true);
								

								/*
								std::cout << "\n \n \n \n";
								std::cout << "\n/////////////////////////////////////";

								for (int x = 0; x < this->notation.length(); x++) {

								if (x % 24 == 0) {
								std::cout << "\n";
								}

								std::cout << this->notation.at(x);

								}
								std::cout << "\n///////////////////////////////////// \n";
								//std::cout << "turn:" << *this->turnCounter << "\n";
								std::cout << "\n \n \n \n";
								*/


								this->PieceMover.ChangeNotation(this->notation);

								
								

								this->Turn ++;
								this->Turn %= 2;
								
								if (this->Turn == 0) {
									this->turnCounter++;
								}

								this->selected = false;
							}
							else {
								this->notation = notation;
							}
						}
					}

					

					
				}
			}

			else {
				this->selected = true;

				this->selectedTile = sf::Vector2i(xPosition, yPosition);
				this->selectedPieceValue = this->FindSquareValue(this->selectedTile.x, this->selectedTile.y);
				
				this->legalMoves = this->PieceMover.legalMoves(this->selectedTile, this->notation, this->selectedPieceValue);
				
				
			}

			
			

		}
	}
	else {
		this->mousePressed = false;
	}
}

void GameBoard::Update() {
	this->CheckEvents();
}

std::string GameBoard::FindSquareValue(int x, int y) {

	int xPos = 0;
	int yPos = 0;

	char notationSquare;

	char color = '0';
	char name = '0';

	for (int i = 0; i < this->notation.length(); i++) {

		notationSquare = this->notation.at(i);
		
		

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




void GameBoard::DrawPieces() {

	int xPos = 0;
	int yPos = 0;

	char notationSquare;
	
	
	

	for (int i = 0; i < this->notation.length(); i += 3) {

		char color = this->notation.at(i);
		char piece = this->notation.at(i + 1);

		xPos = (i / 3) % 8;
		yPos = (i / 24);

		
		

		if (color == 'W') {

			if (piece == 'p') {
				this->whitePawnSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->whitePawnSprite);
			}
			if (piece == 'n') {
				this->whiteKnightSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->whiteKnightSprite);
			}
			if (piece == 'b') {
				this->whiteBishopSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->whiteBishopSprite);
			}
			if (piece == 'r') {
				this->whiteRookSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->whiteRookSprite);
			}
			if (piece == 'q') {
				this->whiteQueenSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->whiteQueenSprite);
			}
			if (piece == 'k') {
				this->whiteKingSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->whiteKingSprite);
			}
		}

		if (color == 'B') {

			if (piece == 'p') {
				this->blackPawnSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->blackPawnSprite);
			}
			if (piece == 'n') {
				this->blackKnightSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->blackKnightSprite);
			}
			if (piece == 'b') {
				this->blackBishopSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->blackBishopSprite);
			}
			if (piece == 'r') {
				this->blackRookSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->blackRookSprite);
			}
			if (piece == 'q') {
				this->blackQueenSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->blackQueenSprite);
			}
			if (piece == 'k') {
				this->blackKingSprite.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
				this->window->draw(this->blackKingSprite);
			}
		}
		
	}
	

}