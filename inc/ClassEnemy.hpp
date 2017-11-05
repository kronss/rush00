/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassEnemy.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:39:44 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 16:20:04 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSENEMY_HPP
# define CLASSENEMY_HPP

#include "main.hpp"

class Player;

class Enemy: public Unit  
{
	public:
		Enemy();
		Enemy(int const x, int const y, int const color, int const fl);
		Enemy(Enemy const &n);
		~Enemy();

		Enemy & operator=(Enemy const & r);

		int  	moveLeft(int map[gYMap][gXMap]);
		int		checkColision(Player &pl);
};

#endif