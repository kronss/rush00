/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPlayer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:34:46 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 16:17:01 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPlayer.hpp"

Player::Player()
{
	setX(1);
	setX(1);
	setColor(255);
}

Player::Player(Player const &n)
{
	*this = n;
}

Player::Player(int const x, int const y, int const color)
{
	_cord_x = x;
	_cord_y = y;
	_color = color;
}

Player::~Player() {}

Player & Player::operator=(Player const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setColor(r._color);
	return (*this);
}

int	Player::moveUp(int **map)
{
	if (getY() != 0 && map[getY() - 1][getX()] != -1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_y -= 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

int	Player::moveDown(int **map)
{
	if (getY() != gYMap - 1 && map[getY() + 1][getX()] != -1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_y += 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

int	Player::moveLeft(int **map)
{
	if (getX() != 0 && map[getY()][getX() - 1] != -1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x -= 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

int	Player::moveRight(int **map)
{
	if (getX() != 0 && map[getY()][getX() + 1] != -1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x += 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

void	Player::shooting(int **map)
{
	Shot* shot = new Shot(getX(), getY(), getColor());
	shot->moveRight(map);
}
