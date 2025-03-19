/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Locations.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:34:54 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/07 10:34:56 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Locations.hpp"

Locations::Locations( void )
{
	this->autoindex = 0;
	this->allowed_methods[0] = 0;
	this->allowed_methods[1] = 0;
	this->allowed_methods[2] = 0;
}

Locations::~Locations()
{
}
