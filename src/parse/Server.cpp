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

int	Server::setLocation()
{
	return (0);
}

int	Server::setErrorPage()
{
	return (0);
}

int	Server::setAllowMethods()
{
	return (0);
}

int	Server::setIndex()
{
	return (0);
}

int	Server::setRoot()
{
	return (0);
}

int	Server::setServerName()
{
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
		return (setServerName());
	else if (*variable.begin() == "root")
		return (setRoot());
	else if (*variable.begin() == "index")
		return (setIndex());
	else if (*variable.begin() == "allow_methods")
		return (setAllowMethods());
	else if (*variable.begin() == "error_page")
		return (setErrorPage());
	else if (*variable.begin() == "location")
		return (setLocation());
	else if (*variable.begin() == "cgi_ext" || *variable.begin() == "cgi_pass" || *variable.begin() == "upload_store")
		return (setCgi());
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
	num_locations = 0;
	//this->locations = new Locations[this->num_locations];
}

Server::~Server()
{
	delete[] this->locations;
}
