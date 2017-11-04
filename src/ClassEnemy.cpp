/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassEnemy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:42:40 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 15:04:52 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPlayer.hpp"
#include <iostream>

Enemy::Enemy() {}

Enemy::Enemy(Enemy const &n)
{
	*this = n;
}

Enemy::Enemy(int const x, int const y, int const color)
{
	_cord_x = x;
	_cord_y = y;
	_color = color;
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=(Enemy const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setColor(r._color);
	return (*this);
}

int	Enemy::moveLeft(int map[gYMap][gXMap])
{
	if (getX() != 0)//&& (getX() - 1) != 0)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x -= 1;
		map[getY()][getX()] = ENEMY_1;
		return 1;
	}
	return 0;
}

int	Enemy::checkColision(Player &pl);
{
	if (this.getX() == pl.getX() && this.getY() == pl.getY())
	{
		return 1;
	}
	return 0;
}