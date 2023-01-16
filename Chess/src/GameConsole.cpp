#include "../include/GameConsole.h"


GameConsole::GameConsole() {
	this->window = nullptr;
	this->InitVariables();
}

GameConsole::~GameConsole() {
	delete this->window;
}

void GameConsole::InitVariables() {
	this->boardHeight = 800;
	this->boardWidth = 800;
	this->CreateWindow();
	this->board = GameBoard(this->window, this->boardWidth, this->boardHeight);
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
	this->board.Update();
}

void GameConsole::Render() {
	this->window->clear();
	this->board.DrawBoard();
	this->window->display();
}

const bool GameConsole::Running() const {
	return this->window->isOpen();
}