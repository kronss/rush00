/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPlayer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:24:17 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 12:11:50 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPLAYER_HPP
# define CLASSPLAYER_HPP

#include "ClassUnit.hpp"
#include <ncurses.h>

Class Player: public Unit  
{
	public:
		Player();
		Player(Player const &n);
		~Player();

		Player & operator=(Player const & r);

		int  moveUp(int map[][N]);
		int  moveDown(int map[][N]);
		int  moveLeft(int map[][N]);
		int  moveRight(int map[][N]);

		void	shooting();
}

#endif