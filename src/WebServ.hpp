/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServ.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roallamos <roallamos@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:24:32 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/27 12:55:00 by roallamos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdlib.h>
# include <iostream>
# include <fstream>
# include <vector>
# include <map>
# include <arpa/inet.h>
# include <fcntl.h>
# include <unistd.h>

class	Server;
class	Client;

class WebServ
{
	private:
		std::map<int, std::string>	std_error_pages;
		std::vector<std::string>	server_file;
		int							num_servers;
		int							num_locations;
		Server						*server;
		int							num_clients;
		Client						*client;

	public:
		void	setStdErrorPages( void );
		int		openAndStoreFile( char *file_name );
		int		ConfigFile( char *file_name );
		void	webServlisten();
		WebServ( void );
		~WebServ();
};

void	splitLine(std::vector<std::string> *splitted, std::string to_split, std::string str);
