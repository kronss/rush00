/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassShot.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:10:32 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 16:19:18 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSSHOT_HPP
# define CLASSSHOT_HPP

#include "main.hpp"

class Enemy;

class Shot: public Unit
{
	public:
		Shot();
		Shot(Shot const &n);
		Shot(int const x, int const y, int const color, int const fl);
		~Shot();

		Shot & operator=(Shot const & r);

		int     moveRight(int map[gYMap][gXMap]);
		int		checkColision(Enemy &en);
};

#endif