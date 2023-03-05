#pragma once
#ifndef PIECE_H
#define PIECE_H

#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

#include<iostream>
#include<algorithm>

class Piece
{
public:
	char color;

	sf::Vector2i coordinates;

	void SetColor(char color);
	void SetCoordinates(sf::Vector2i tile);
	void CheckMoved();
	void Init(char color, sf::Vector2i position, int* turnCounter);

	std::string findSquareValue(std::string notation, sf::Vector2i tile);

	bool movedOnce;
	bool movedMore;

	int* turnCounter;

	
};

#endif
