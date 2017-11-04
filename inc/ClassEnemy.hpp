/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassEnemy.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:39:44 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 13:35:34 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSENEMY_HPP
# define CLASSENEMY_HPP

#include "ClassUnit.hpp"
#include <ncurses.h>

Class Enemy: public Unit  
{
	public:
		Enemy();
		Enemy(Enemy const &n);
		~Enemy();

		Enemy & operator=(Enemy const & r);

		int  	moveLeft(int map[][N]);
		int		checkColision(Player &pl);
}

#endif