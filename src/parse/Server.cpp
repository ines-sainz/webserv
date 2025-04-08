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

int	Server::setClientMaxSize(std::vector<std::string> variable)
{
	if (variable.size() != 2 || this->client_max_size != 0)
	{
		std::cout << "Error: error setting client max size" << std::endl;
		return (1);
	}
	std::string	size = variable.back();
	unsigned long	i = 0;
	while (size[i])
	{
		if ((i != size.length() - 1 && isdigit(size[i]) == 0) || i > 10)
		{
			std::cout << "Error: error with client max size numbers" << std::endl;
			return (1);
		}
		i++;
	}
	if (size[size.length() - 1] != 'K' && size[size.length() - 1] != 'M' && size[size.length() - 1] != 'G')
	{
		std::cout << "Error: error with client max size units" << std::endl;
		return (1);
	}
	unsigned long	number = atol(size.c_str());
	if (size[size.length() - 1] != 'K')
		number *= 1024;
	else if (size[size.length() - 1] != 'M')
		number *= 1024 *1024;
	else if (size[size.length() - 1] != 'G')
		number *= 1024 * 1024 * 1024;
	this->client_max_size = number;
	std::cout << "DB: max_size=" << this->client_max_size << " " << size[size.length() - 1] << std::endl;
	return (0);
}

int	Server::setErrorPage(std::vector<std::string> variable)
{
	if (variable.size() != 3)
	{
		std::cout << "Error: error setting error pages" << std::endl;
		return (1);
	}
	std::vector<std::string>::iterator	it = variable.begin();
	it++;
	if ((*it).length() > 3)
	{
		std::cout << "Error: error with error page number" << std::endl;
		return (1);
	}
	int	number = atoi((*it).c_str());
	if (number < 100 || number >= 600)
	{
		std::cout << "Error: error with error page number" << std::endl;
		return (1);
	}
	it++;
	this->error_pages[number] = *it;
	std::cout << "DB: error page " << number << " file " << *it << std::endl;
	return (0);
}

int	Server::setAllowMethods(std::vector<std::string> variable)
{
	if (variable.size() <= 1)
	{
		std::cout << "Error: error setting allowed methods" << std::endl;
		return (1);
	}
	std::vector<std::string>::iterator it = variable.begin();
	it++;
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
	std::cout << "DB: methods get=" << allowed_methods[0] << " post=" << allowed_methods[1] << " delete=" << allowed_methods[2] << std::endl;
	return (0);
}

int	Server::setIndex(std::vector<std::string> variable)
{
	if (variable.size() != 2 || this->index != "")
	{
		std::cout << "Error: error setting index" << std::endl;
		return (1);
	}
	this->index = variable.back();
	std::cout << "DB: index=" << index << std::endl;
	return (0);
}

int	Server::setRoot(std::vector<std::string> variable)
{
	if (variable.size() != 2 || this->root != "")
	{
		std::cout << "Error: error setting root" << std::endl;
		return (1);
	}
	this->root = variable.back();
	std::cout << "DB: root=" << root << std::endl;
	return (0);
}

int	Server::setServerName(std::vector<std::string> variable)
{
	if (variable.size() != 2 || this->server_name != "")
	{
		std::cout << "Error: error setting server name" << std::endl;
		return (1);
	}
	this->server_name = variable.back();
	std::cout << "DB: server name=" << server_name << std::endl;
	return (0);
}

int	Server::setListen(std::vector<std::string> variable)
{
	if (variable.size() != 2 || this->server_name != "")
	{
		std::cout << "Error: error setting listen ports and ip" << std::endl;
		return (1);
	}
	const unsigned long i = variable.back().find(':');
	if (i != std::string::npos)
	{
		this->listen_ip = variable.back().substr(0, i);
		if (this->listen_ip.size() > 15)
		{
			std::cout << "Error: problem setting ip" << std::endl;
			return (1);
		}
		int j = 0;
		int	dot = 0;
		int	num = 0;
		int	ip_num = 0;
		char *ip_char = (char *)listen_ip.c_str();
		if ((listen_ip[0] && isdigit(listen_ip[0]) != 0))
			num++;
		else
		{
			std::cout << "Error: ip not correct" << std::endl;
			return (1);
		}
		while (listen_ip[j])
		{
			if (listen_ip[j] == '.')
			{
				if (isdigit(listen_ip[j + 1]) != 0)
					num++;
				dot++;
			}
			else
			{
				if (listen_ip[j] >= '0' && listen_ip[j] <= '9')
				{
					ip_num = atoi(&ip_char[j]);
					if (ip_num > 255)
					{
						std::cout << "Error: ip not correct" << std::endl;
						return (1);
					}
				}
				else
				{
					std::cout << "Error: ip not correct" << std::endl;
					return (1);
				}
			}
			j++;
		}
		if (dot != 3 || num != 4)
		{
			std::cout << "Error: ip not correct" << " dot " << dot << " num " << num << std::endl;
			return (1);
		}
		std::cout << "DB: ip=" << this->listen_ip << std::endl;
		const_cast<unsigned long&>(i) = i + 1;
	}
	else
		const_cast<unsigned long&>(i) = 0;
	std::string port = variable.back().substr(i);
	if (port.length() > 4)
	{
		std::cout << "Error: error setting port" << std::endl;
		return (1);
	}
	this->listen_port = atoi(port.c_str());
	if (this->listen_port > 9999 || this->listen_port == 0)
	{
		std::cout << "Error: error setting port" << std::endl;
		return (1);
	}
	std::cout << "DB: port=" << this->listen_port << std::endl;
	return (0);
}

int	Server::setVariable(std::vector<std::string> variable)
{
	if (*variable.begin() == "listen")
		return (setListen(variable));
	else if (*variable.begin() == "server_name")
		return (setServerName(variable));
	else if (*variable.begin() == "root")
		return (setRoot(variable));
	else if (*variable.begin() == "index")
		return (setIndex(variable));
	else if (*variable.begin() == "allow_methods")
		return (setAllowMethods(variable));
	else if (*variable.begin() == "error_page")
		return (setErrorPage(variable));
	else if (*variable.begin() == "client_max_size")
		return (setClientMaxSize(variable));
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
	listen_ip = "";
	listen_port = 0;
	server_name = "";
	this->allowed_methods[0] = 0;
	this->allowed_methods[1] = 0;
	this->allowed_methods[2] = 0;
	this->autoindex = 0;
	root = "";
	this->client_max_size = 0;
	(void)error_pages;
	index = "";
	//this->locations = new Locations[this->num_locations];
}

Server::~Server()
{
	delete[] this->locations;
}
