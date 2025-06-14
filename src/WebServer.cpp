/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roallamos <roallamos@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:52:13 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/27 12:57:58 by roallamos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServ.hpp"
#include "parse/Server.hpp"
#include "parse/Client.hpp"

void	WebServ::setStdErrorPages( void )
{
	this->std_error_pages[100] = "Continue";
	this->std_error_pages[200] = "OK";
	this->std_error_pages[201] = "Created";
	this->std_error_pages[204] = "No Content";
	this->std_error_pages[301] = "Moved Permanently";
	this->std_error_pages[302] = "Found";
	this->std_error_pages[303] = "See Other";
	this->std_error_pages[307] = "Temporary Redirect";
	this->std_error_pages[308] = "Permanent Redirect";
	this->std_error_pages[400] = "Bad Request";
	this->std_error_pages[403] = "Forbidden";
	this->std_error_pages[404] = "Not Found";
	this->std_error_pages[405] = "Method Not Allowed";
	this->std_error_pages[408] = "Request Timeout";
	this->std_error_pages[413] = "Content Too Large";
	this->std_error_pages[415] = "Unsupported Media Type";
	this->std_error_pages[418] = "I'm a teapot";
	this->std_error_pages[421] = "Misdirected Request";
	this->std_error_pages[429] = "Too Many Requests";
	this->std_error_pages[500] = "Internal Server Error";
	this->std_error_pages[501] = "Not Implemented";
	this->std_error_pages[505] = "HTTP Version Not Supported";
	// std::map<int, std::string>::iterator	it = this->std_error_pages.begin();
	// while (it != this->std_error_pages.end())
	// {
	// 	std::cout << "DB: " << it->first << " = " << it->second << std::endl;
	// 	it++;
	// }
}

int	WebServ::openAndStoreFile( char *file_name )
{
	std::ifstream	server_fd;
	std::string		lines;

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
	int num_locations = 0;
	if (openAndStoreFile(file_name) == 1)
		return (1);
	std::vector<std::string>::iterator	it = server_file.begin();
	int									is_server = 0;
	int 								i = -1;
	std::vector<std::string> 			variable;
	std::vector<std::string>::iterator	it2 = variable.begin();
	std::vector<std::string>			locations;
	std::vector<std::string>			locations_temp;

	this->server = new Server[num_servers];
	while (it != this->server_file.end())
	{
		splitLine(&variable, *it, "; \t");
		if (variable.size() == 0)
		{
			std::cout << "Error: line without information" << std::endl;
			return (1);
		}
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
			if (variable.size() != 3 || variable.back() != "{")
			{
				std::cout << "Error: Location not well written" << std::endl;
				return (1);
			}
			num_locations++;
			it2 = variable.begin();
			while (it2 != variable.end())
			{
				locations.push_back(*it2);
				it2++;
			}
			it++;
			while (it != this->server_file.end())
			{
				locations_temp.clear();
				splitLine(&locations_temp, *it, "; \t");
				if (locations_temp.size() == 0)
				{
					std::cout << "Error: line without information" << std::endl;
					return (1);
				}
				locations.push_back(*it);
				if (*locations_temp.begin() == "}")
					break ;
				it++;
			}
		}
		else if (num_locations > 0 && *variable.begin() != "}")
		{
			std::cout << "Error: information after or between locations" << std::endl;
			return (1);
		}
		if (*variable.begin() == "}")
		{
			if (is_server == 1 && *it == "}")
			{	
				std::cout << "DB: locations " << num_locations << std::endl;
				if (server[i].setLocation(locations) == 1)
				{
					std::cout << "Error: problem setting the location" << std::endl;
					return (1);
				}
				is_server = 0;
				num_locations = 0;
			}
			else
			{
				std::cout << "Error: cofig file not well written" << std::endl;
				return (1);
			}
			server[i].num_locations = this->num_locations;
			locations.clear();
		}
		if (server[i].setVariable(variable) == 1)
			return (1);
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

void	WebServ::webServlisten()
{
	this->server->startListen();
}

WebServ::WebServ( void )
{
	(void)this->num_clients;
	(void)this->num_servers;
	(void)this->client;
	(void)this->server;
	num_locations = 0;

	this->server = new Server[1];
	//this->client = new Client[num_clients];
}

WebServ::~WebServ()
{
	delete[] this->server;
	//delete[] this->client;
}

