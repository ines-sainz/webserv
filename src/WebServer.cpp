/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:52:13 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/07 10:52:15 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServ.hpp"
#include "parse/Server.hpp"
#include "parse/Client.hpp"

int	WebServ::openAndStoreFile(char *file_name)
{
	std::ifstream				server_fd;
	std::string					lines;

	this->num_servers = 0;
	server_fd.open(file_name, std::ios::in);
	if (!server_fd.is_open())
	{
		std::cout << "Error: Can't open file" << std::endl;
		return (1);
	}
	while (std::getline(server_fd, lines))
	{
		if (lines == "server {")
			num_servers++;
		if (lines != "")
			this->server_file.push_back(lines);
	}
	if (this->num_servers == 0)
	{
		std::cout << "Error: There isn't a server in the file" << std::endl;
		return (1);
	}
	std::cout << "DB: severs " << num_servers << std::endl;
	return (0);
}

int	WebServ::ConfigFile(char *file_name)
{
	int num_locations = 0; /////////////////////////////////////////////////////////////borrar
	if (openAndStoreFile(file_name) == 1)
		return (1);
	std::vector<std::string>::iterator it = server_file.begin();
	int	is_server = 0;
	int	is_location = 0;
	this->server = new Server[num_servers];
	int i = -1;
	std::vector<std::string> variable;
	std::vector<std::string>::iterator it2 = variable.begin();
	while (it != this->server_file.end())
	{
		splitLine(&variable, *it, " \t");
		it2 = variable.begin();
		if (*variable.begin() == "server")
		{
			if (is_server == 1 || *it != "server {")
			{
				std::cout << "Error: servers not well separated" << std::endl;
				return (1);
			}
			is_server = 1;
			i++;
		}
		else if (is_server == 0)
		{
			std::cout << "Error: information out of the servers" << std::endl;
			return (1);
		}
		if (*variable.begin() == "location") //correct this
		{
			if (is_location == 1)
			{
				std::cout << "Error: Location not well written" << std::endl;
				return (1);
			}
			num_locations++;
			is_location = 1;
		}
		if (*variable.begin() == "}")
		{
			if (is_location == 1)
				is_location = 0;
			else if (is_server == 1)
			{
				std::cout << "DB: locations " << num_locations << std::endl;
				is_server = 0;
				num_locations = 0;
			}
		}
		if (server[i].setVariable(variable) == 1)
		{
			std::cout << "Error setting variables" << std::endl;
			return (1);
		}
		it++;
		variable.clear();
	}
	if (is_server == 1)
	{
		std::cout << "Error: servers not well separated" << std::endl;
		return (1);
	}
	return (0);
}

// int	WebServ::ConfigFile(char *file_name)
// {
// 	std::ifstream				server_fd;
// 	std::vector<std::string>	server_file;
// 	std::string					lines;
// 	std::string					substring;
// 	std::string					to_compare = "server {";
// 	int							is_server = 0;

// 	server_fd.open(file_name, std::ios::in);
// 	while (std::getline(server_fd, lines))
// 	{
// 		if (is_server == 0)
// 		{
// 			for (size_t i = 0; i < lines.length(); i++)
// 			{
// 				if (to_compare.find(lines[i]) == std::string::npos)
// 					return (1);
// 				if (lines[i] == ' ')
// 					continue ;
// 				else
// 				{
// 					substring = lines.substr(i, 6);
// 					if (substring == "server")
// 						is_server == 1;
// 					std::cout << substring << std::endl;
// 				}
// 			}
// 		}
// 		if (lines == "}")
// 			is_server = 0;
// 		server_file.push_back(lines);
// 	}
// 	return (0);
// }

WebServ::WebServ( void )
{
	(void)this->num_clients;
	(void)this->num_servers;
	(void)this->client;
	(void)this->server;
	//int	num_servers = 0;

	//this->server = new Server[num_servers];
	//this->client = new Client[num_clients];
}

WebServ::~WebServ()
{
	//delete[] this->server;
	//delete[] this->client;
}

