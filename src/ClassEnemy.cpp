/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassEnemy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:42:40 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/05 09:34:21 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


Enemy::Enemy() 
{
	
}

Enemy::Enemy(Enemy const &n)
{
	*this = n;
}

Enemy::Enemy(int const x, int const y, int const color)
{
	_cord_x = x;
	_cord_y = y;
	_id = color;
	_isDead = false;
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=(Enemy const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setId(r._id);
	setIsDead(false);
	return (*this);
}

int	Enemy::moveLeft(int map[gYMap][gXMap])
{
	if (_isDead == true) return 0;



	if (getX() != 0)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x -= 1;
		map[getY()][getX()] = ENEMY_1;
		return 1;
	}
	else
	{
		map[getY()][getX()] = DEFAULT;
		_isDead = true;
	}

	return 0;
}

int	Enemy::checkColision(Player & player)
{
	if (getY() == player.getY())
		if (getX() == player.getX())
			return 1;
	return 0;
}





















