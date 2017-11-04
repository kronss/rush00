/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassShot.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatushe <nmatushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:10:32 by nmatushe          #+#    #+#             */
/*   Updated: 2017/11/04 15:05:15 by nmatushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSSHOT_HPP
# define CLASSSHOT_HPP

#include "ClassUnit.hpp"
#include "ClassEnemy.hpp"
#include <ncurses.h>

Class Shot: public Unit  
{
	public:
		Shot();
		Shot(Shot const &n);
		Shot(int const x, int const y, int const color);
		~Shot();

		Shot & operator=(Shot const & r);

		int  moveRight(int map[gYMap][gXMap]);
		int		checkColision(Enemy &en);
}

#endif