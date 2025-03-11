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
		int		num_servers = 0;
		Server	*server;
		Client	*clients;

	public:
		int	ConfigFile(char *file_name);

		WebServ( void );
		~WebServ();
};

