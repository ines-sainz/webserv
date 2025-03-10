/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Locations.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:35:36 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/07 10:35:38 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../WebServ.hpp"

class Locations
{
	private:
		std::string							path;
		int									allowed_methods[3] = {0, 0, 0};
		int									autoindex = 0;
		std::map<std::string, std::string>	content;

	public:
		Locations( void );
		~Locations();
};

Locations::Locations( void )
{
}

Locations::~Locations()
{
}

