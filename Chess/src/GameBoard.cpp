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

	this->pieceTexture.setSize(sf::Vector2f(this->pieceWidth, this->pieceHeight));

	this->PieceMover = PieceMove(this->notation);

	
	
}

void GameBoard::InitTile() {
	this->tile.setSize(sf::Vector2f(this->TileSize,this->TileSize));
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
							
							

							std::string tempNotation = this->PieceMover.NewNotation(this->notation, this->selectedTile, this->targetTile, this->selectedPieceValue);
							
							
							
							char color;

							if (this->Turn == 0) {
								color = 'W';
							}
							else {
								color = 'B';
							}

							std::vector<sf::Vector2i> moves = this->PieceMover.GetMoves(color, tempNotation);

							
							bool changeNotation = true;

							for (auto& e : moves) {
								if(this->FindSquareValue(e.x, e.y) == std::string("") + color + "k"){
									changeNotation = false;
								}

								
							}
							if (changeNotation) {
								this->notation = this->PieceMover.NewNotation(this->notation, this->selectedTile, this->targetTile, this->selectedPieceValue);
								this->PieceMover.ChangeNotation(this->notation);




								this->Turn++;
								this->Turn %= 2;
								this->selected = false;
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
	
	
	

	for (int y = 0; y < this->notation.length(); y++) {

		notationSquare = this->notation.at(y);

		if (notationSquare == ',') {
			xPos += 1;
		}

		if (xPos == 8) {
			xPos = 0;
			yPos += 1;
		}

		if(notationSquare == 'B'){
			this->pieceTexture.setFillColor(sf::Color::Black);
			this->pieceTexture.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
		}

		if (notationSquare == 'W') {
			this->pieceTexture.setFillColor(sf::Color::White);
			this->pieceTexture.setPosition(xPos * this->TileSize + this->pieceWidth / 2, yPos * this->TileSize + this->pieceHeight / 2);
		}

		this->window->draw(this->pieceTexture);
	}
	

}