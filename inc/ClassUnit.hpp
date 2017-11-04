/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassUnit.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:06:20 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 13:35:56 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

#ifndef CLASSUNIT_HPP
# define CLASSUNIT_HPP

int const N = ?;

Class Unit 
{
	protected:
		int		_cord_y;
		int		_cord_x;
		int		_color;
		int 	_ch;
	public:
		Unit();
		Unit(Unit const &n);
		~Unit();

		Unit & operator=(Unit const & r);

		void	setX(int x);
		void	setY(int y);
		void	setColor(int color);
		void	setCh(int c);
		int		getX();
		int		getY();
		int		getColor();
		int		getCh();

		void	putCharByCord();
}

#endif