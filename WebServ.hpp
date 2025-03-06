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
# include <vector>
# include <map>

class	Server;

class WebServ
{
	private:
		Server	*server[];

	public:
		WebServ( void );
		~WebServ();
};

WebServ::WebServ( void )
{
}

WebServ::~WebServ()
{
}


int	ConfigFile();
