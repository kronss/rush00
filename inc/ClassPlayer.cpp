/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPlayer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:34:46 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 13:36:23 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPlayer.hpp"
#include "ClassShot.hpp"
#include <iostream>

Player::Player()
{
	setX(1);
	setX(1);
	setColor(255);
	setCh(1)
}

Player::Player(Player const &n)
{
	*this = n;
}

Player::~Player() {}

Player & Player::operator=(Player const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setColor(r._color);
	setCh(r._ch);
	return (*this);
}

int	Player::moveUp(int map[][N])
{
	if (getY() != 0 && map[getY() - 1][getX()] != -1)
	{
		map[getY()][getX()] = '*';
		_cord_y -= 1;
		return 1;
	}
	return 0;
}

int	Player::moveDown(int map[][N])
{
	if (getY() != N - 1 && map[getY() + 1][getX()] != -1)
	{
		map[getY()][getX()] = '*';
		_cord_y += 1;
		return 1;
	}
	return 0;
}

int	Player::moveLeft(int map[][N])
{
	if (getX() != 0 && map[getY()][getX() - 1] != -1)
	{
		map[getY()][getX()] = '*';
		_cord_x -= 1;
		return 1;
	}
	return 0;
}

int	Player::moveRight(int map[][N])
{
	if (getX() != 0 && map[getY()][getX() + 1] != -1)
	{
		map[getY()][getX()] = '*';
		_cord_x += 1;
		return 1;
	}
	return 0;
}

void	Player::shoting()
{
	Unit* shot = new Shot(getX, getY, getColor);
	shot.moveRight(map[][N]);
}
