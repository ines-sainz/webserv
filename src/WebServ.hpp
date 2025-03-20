/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:24:32 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/05 19:24:34 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <fstream>
# include <vector>
# include <map>

class	Server;
class	Client;

class WebServ
{
	private:
		std::vector<std::string>	server_file;
		int		num_servers;
		int		num_locations;
		Server	*server;
		int		num_clients;
		Client	*client;

	public:
		int	openAndStoreFile(char *file_name);
		int	ConfigFile(char *file_name);

		WebServ( void );
		~WebServ();
};

void	splitLine(std::vector<std::string> *splitted, std::string to_split, std::string str);
