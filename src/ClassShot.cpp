/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassShot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:13:35 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/05 10:06:20 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Shot::Shot() {}

Shot::Shot(Shot const &n)
{
	*this = n;
}

Shot::Shot(int const x, int const y, int const color)
{
	_cord_x = x;
	_cord_y = y;
	_id = color;
	_fl = false;
}

Shot::~Shot() {}

Shot & Shot::operator=(Shot const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setId(r._id);
	setFl(false);
	return (*this);
}

int	Shot::moveRight(int map[gYMap][gXMap])
{
	if (getX() != gXMap - 1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x += 1;
		map[getY()][getX()] = PLAYERS_BULET;   
		return 1;
	}
	else
		map[getY()][getX()] = DEFAULT;
	return 0;
}

int	Shot::checkColision(Enemy &en)
{
	if (this->getX() == en.getX() && this->getY() == en.getY())
	{
		return 1;
	}
	return 0;
}
