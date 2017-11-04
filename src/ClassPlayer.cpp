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

#include "main.hpp"

Player::Player()
: Unit(1, 1, 1)
{

}

Player::Player(Player const &n)
{
	*this = n;
}

Player::Player(int const x, int const y, int const color)
{
	_cord_x = x;
	_cord_y = y;
	_id = color;
}

Player::~Player() {}

Player & Player::operator=(Player const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setId(r._id);
	return (*this);
}

int	Player::moveUp(int map[gYMap][gXMap])
{
	if (getY() != 0)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_y -= 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

int	Player::moveDown(int map[gYMap][gXMap])
{
	if (getY() != gYMap - 1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_y += 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

int	Player::moveLeft(int map[gYMap][gXMap])
{
	if (getX() != 0)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x -= 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

int	Player::moveRight(int map[gYMap][gXMap])
{
	if (getX() != gXMap - 1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x += 1;
		map[getY()][getX()] = PLAYER;
		return 1;
	}
	return 0;
}

void	Player::shooting(int map[gYMap][gXMap])
{
	Shot* shot = new Shot(getX(), getY(), getId());
	shot->moveRight(map);
}
