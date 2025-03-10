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

int	ConfigFile(char *file_name);

WebServ::WebServ( void )
{
	//int	num_servers = 1;

	//this->server = new Server[num_servers];
}

WebServ::~WebServ()
{
	delete[] this->server;
}

