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
		std::string							listen_ip;
		std::string							server_name; // oprtional
		std::string							root;
		std::string							index;
		int									allowed_methods[3]; //GET POST DELETE
		int									autoindex;
		unsigned long						client_max_size;
		std::map<int, std::string>			error_pages;
		Locations							*locations;

	public:
		int	num_locations;

		int	setLocation(std::vector<std::string> locations);
		int	setCgi();
		int	setClientMaxSize(std::vector<std::string> variable);
		int	setErrorPage(std::vector<std::string> variable);
		int	setAllowMethods(std::vector<std::string> variable);
		int	setIndex(std::vector<std::string> variable);
		int	setRoot(std::vector<std::string> variable);
		int	setServerName(std::vector<std::string> variable);
		int	setListen(std::vector<std::string> variable);
		int	setVariable(std::vector<std::string> variable);
		Server( void );
		~Server();
};
