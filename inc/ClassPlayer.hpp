/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPlayer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:24:17 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 16:26:09 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPLAYER_HPP
# define CLASSPLAYER_HPP

#include "main.hpp"

class Shot;

class GameManeger;

extern  GameManeger gameManeger;


class Player : public Unit 
{
	public:
		Player();
		Player(int const x, int const y, int const color);
		Player(Player const &n);
		~Player();

		Player & operator=(Player const & r);

		int  moveUp(int map[gYMap][gXMap]);
		int  moveDown(int map[gYMap][gXMap]);
		int  moveLeft(int map[gYMap][gXMap]);
		int  moveRight(int map[gYMap][gXMap]);

		void	shooting(int map[gYMap][gXMap]);
};

#endif
