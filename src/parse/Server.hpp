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
		int									listen_port;
		int									listen_ip;
		std::string							server_name; // oprtional
		int									allowed_methods[3]; //GET POST DELETE
		int									autoindex;
		std::string							root;
		std::map<int, std::string>			error_pages;
		std::string							index;
		int									num_locations;
		Locations							*locations;

	public:
		int	setCgi();
		int	setLocation();
		int	setErrorPage();
		int	setAllowMethods();
		int	setIndex();
		int	setRoot();
		int	setServerName();
		int	setListen();
		int	setVariable(std::vector<std::string> variable);
		Server( void );
		~Server();
};
