/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassEnemy.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:39:44 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 15:05:13 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSENEMY_HPP
# define CLASSENEMY_HPP

#include "ClassUnit.hpp"
#include <ncurses.h>

class Enemy: public Unit  
{
	public:
		Enemy();
		Enemy(int const x, int const y, int const color);
		Enemy(Enemy const &n);
		~Enemy();

		Enemy & operator=(Enemy const & r);

		int  	moveLeft(int map[gYMap][gXMap]);
		int		checkColision(Player &pl);
};

#endif