/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:16:16 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/04 11:16:18 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServ.hpp"
#include "parse/Client.hpp"
#include "parse/Locations.hpp"
#include "parse/Server.hpp"
#include "parse/Requests.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: need only one configuration file" << std::endl;
		return (1);
	}

	WebServ	webserv;
	if (webserv.ConfigFile(argv[1]) == 1)
	{
		std::cout << "DB: config file error" << std::endl;
		return (1);
	}
	webserv.setStdErrorPages();
	std::cout << "DB: everything is ok" << std::endl;
	return (0);
}
