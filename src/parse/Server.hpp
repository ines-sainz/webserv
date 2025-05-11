/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roallamos <roallamos@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:30:27 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/27 12:41:11 by roallamos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../WebServ.hpp"
# include "Locations.hpp"

class Server
{
	private:
		int									listen_port;
		int									server_fd;// sustituit por vector
		int 								new_socket;// sustituit por vector
		struct sockaddr_in 					address;
		char 								buffer[1024];
		socklen_t 							addrlen;
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
		int	setSocket(void);
		int	startListen(void);
		Server( void );
		~Server();
};
