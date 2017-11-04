/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassShot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:13:35 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 16:06:03 by nmatushe         ###   ########.fr       */
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
}

Shot::~Shot() {}

Shot & Shot::operator=(Shot const & r)
{
	setX(r._cord_x);
	setY(r._cord_y);
	setId(r._id);
	return (*this);
}

int	Shot::moveRight(int map[gYMap][gXMap])
{
	if (getX() != 0 && map[getY()][getX() + 1] != -1)
	{
		map[getY()][getX()] = DEFAULT;
		_cord_x += 1;
		map[getY()][getX()] = PLAYERS_BULET;
		return 1;
	}
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
