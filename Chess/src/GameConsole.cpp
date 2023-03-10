#include "../include/GameConsole.h"


GameConsole::GameConsole() {
	this->window = nullptr;
	this->InitVariables();
}

GameConsole::~GameConsole() {
	delete this->window;
	delete this->board;
}

void GameConsole::InitVariables() {
	this->boardHeight = 800;
	this->boardWidth = 800;
	this->CreateWindow();
	this->board = new GameBoard(this->window, this->boardWidth, this->boardHeight);
	this->board->InitTextures(this->whitePawnTexture, this->whiteKnightTexture,
							 this->whiteBishopTexture, this->whiteRookTexture,
							 this->whiteQueenTexture, this->whiteKingTexture,
							 this->blackPawnTexture, this->blackKnightTexture,
							 this->blackBishopTexture, this->blackRookTexture,
							 this->blackQueenTexture, this->blackKingTexture);
}



void GameConsole::CreateWindow() {
	this->videoMode.height = this->boardHeight;
	this->videoMode.width = this->boardWidth;
	this->window = new sf::RenderWindow(this->videoMode, "Chess", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void GameConsole::PollEvents() {
	while (this->window->pollEvent(this->e)) {
		switch (this->e.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

void GameConsole::Update() {
	this->PollEvents();
	this->board->Update();
}

void GameConsole::Render() {
	this->window->clear();
	this->board->DrawBoard();
	this->window->display();
}

const bool GameConsole::Running() const {
	return this->window->isOpen();
}