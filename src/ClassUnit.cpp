/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassUnit.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:16:26 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 16:18:39 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Unit::Unit() {}

Unit::Unit(Unit const & n)
{
	*this = n;
}

Unit::~Unit() {}

Unit & Unit::operator=(Unit const & r)
{
	_cord_y = r._cord_y;
	_cord_x = r._cord_x;
	_color = r._color;
	return (*this);
}

void	Unit::setX(int x)
{
	_cord_x = x;
}

void	Unit::setY(int y)
{
	_cord_y = y;
}

void	Unit::setColor(int color)
{
	_color = color;
}

int		Unit::getX()
{
	return _cord_x;
}

int		Unit::getY()
{
	return _cord_y;
}

int		Unit::getColor()
{
	return _color;
}
