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

int	main(int argc, char **argv)
{
	WebServ	webserv;

	if (argc != 2)
	{
		std::cout << "Error: need only one configuration file" << std::endl;
		return (1);
	}
	if (webserv.ConfigFile(argv[1]) == 1)
		return (1);
}
