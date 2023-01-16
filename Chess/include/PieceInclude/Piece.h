#pragma once
#ifndef PIECE_H
#define PIECE_H

#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

#include<iostream>

class Piece
{
public:
	char color;

	sf::Vector2i coordinates;

	void SetColor(char color);
	void SetCoordinates(sf::Vector2i tile);

	std::string findSquareValue(std::string notation, sf::Vector2i tile);

	bool movedOnce;
};

#endif
