/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Requests.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:36:00 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/07 10:36:02 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../WebServ.hpp"

class Requests
{
	private:
		std::string	method;
		std::string	path;
		std::string	user_agent;
		std::string	host;
		std::string	accept;
		std::string	connection;

		std::string	content_type; // optional
		std::string	content_lenght; //optional

	public:
		Requests( void );
		~Requests();
};

Requests::Requests( void )
{
}

Requests::~Requests()
{
}

