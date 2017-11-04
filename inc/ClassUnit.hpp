/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassUnit.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:06:20 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 15:05:20 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSUNIT_HPP
# define CLASSUNIT_HPP

#include "Window.hpp"



extern int const gYMap;
extern int const gXMap;


class Unit 
{
	protected:
		int		_cord_y;
		int		_cord_x;
		int		_color;
	public:
		Unit();
		Unit(Unit const &n);
		~Unit();

		Unit & operator=(Unit const & r);

		void	setX(int x);
		void	setY(int y);
		void	setColor(int color);
		int		getX();
		int		getY();
		int		getColor();
};

#endif