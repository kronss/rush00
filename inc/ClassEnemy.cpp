/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassEnemy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:42:40 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 13:36:57 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPlayer.hpp"
#include <iostream>

Enemy::Enemy()
{
	setCh(2);
}

Enemy::Enemy(Enemy const &n)
{
	*this = n;
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=(Enemy const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setColor(r._color);
	setCh(r._ch);
	return (*this);
}

int	Enemy::moveLeft(int map[][N])
{
	if (getX() != 0)//&& (getX() - 1) != 0)
	{
		map[getY()][getX()] = '*';
		_cord_x -= 1;
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