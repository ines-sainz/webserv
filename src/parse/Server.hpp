/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:30:27 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/05 19:30:30 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../WebServ.hpp"
# include "Locations.hpp"

class Server
{
	private:
		int									listen;
		std::string							server_name; // oprtional
		int									allowed_methods[3] = {0, 0, 0}; //GET POST DELETE
		int									autoindex = 0;
		std::string							root;
		std::map<int, std::string>			error_pages;
		std::string							index;
		int									num_locations;
		Locations							*locations;

	public:
		Server( void );
		~Server();
};
