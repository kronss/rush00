/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassUnit.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:06:20 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 15:36:57 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSUNIT_HPP
# define CLASSUNIT_HPP

#include "main.hpp"


extern int const gYMap;
extern int const gXMap;


class Unit 
{
	protected:
		int		_cord_y;
		int		_cord_x;
		int		_id;
		bool	_fl;
	public:
		Unit();
		Unit(int y, int x, int id, int _fl);
		Unit(Unit const &n);
		virtual ~Unit();

		Unit & operator=(Unit const & r);

		void	setX(int x);
		void	setY(int y);
		void	setId(int color);
		void	setFl(int fl);

		int		getX();
		int		getY();
		int		getId();
		int		getFl();
};

#endif