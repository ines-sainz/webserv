/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:30:27 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/05 19:30:30 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WebServ.hpp"
#include "Server.hpp"
#include "Locations.hpp"

int	Server::setCgi()
{
	return (0);
}

int	Server::setLocation(std::vector<std::string> locations)
{
	(void)locations;
	return (0);
}

int	Server::setErrorPage()
{
	return (0);
}

int	Server::setAllowMethods(std::vector<std::string> variable)
{
	if (variable.size() == 1)
	{
		std::cout << "Error: error setting allowed methods" << std::endl;
		return (1);
	}
	std::vector<std::string>::iterator it = variable.begin();
	while (it != variable.end())
	{
		if (*it == "GET")
		{
			this->allowed_methods[0] = 1;
		}
		else if (*it == "POST")
		{
			this->allowed_methods[1] = 1;
		}
		else if (*it == "DELETE")
		{
			this->allowed_methods[2] = 1;
		}
		else
		{
			std::cout << "Error: wrong allowed methods" << std::endl;
			return (1);
		}
		it++;
	}
	return (0);
}

int	Server::setIndex(std::vector<std::string> variable)
{
	if (variable.size() != 2 || variable.back() != "")
	{
		std::cout << "Error: error setting index" << std::endl;
		return (1);
	}
	this->index = variable.back();
	return (0);
}

int	Server::setRoot()
{
	return (0);
}

int	Server::setServerName(std::vector<std::string> variable)
{
	if (variable.size() != 2 || variable.back() != "")
	{
		std::cout << "Error: error setting server name" << std::endl;
		return (1);
	}
	this->server_name = variable.back();
	return (0);
}

int	Server::setListen()
{
	return (0);
}

int	Server::setVariable(std::vector<std::string> variable)
{
	if (*variable.begin() == "listen")
		return(setListen());
	else if (*variable.begin() == "server_name")
		return (setServerName(variable));
	else if (*variable.begin() == "root")
		return (setRoot());
	else if (*variable.begin() == "index")
		return (setIndex(variable));
	else if (*variable.begin() == "allow_methods")
		return (setAllowMethods(variable));
	else if (*variable.begin() == "error_page")
		return (setErrorPage());
	else if (*variable.begin() == "location")
		return (0);
	else if (*variable.begin() == "server" || *variable.begin() == "}")
		return (0);
	else
	{
		std::cout << "DB: " << *variable.begin() << std::endl;
		return (1);
	}
	return (0);
}

Server::Server( void )
{
	listen_ip = 0;
	listen_port = 0;
	server_name = "";
	this->allowed_methods[0] = 0;
	this->allowed_methods[1] = 0;
	this->allowed_methods[2] = 0;
	this->autoindex = 0;
	root = "";
	(void)error_pages;
	index = 1;
	//this->locations = new Locations[this->num_locations];
}

Server::~Server()
{
	delete[] this->locations;
}
