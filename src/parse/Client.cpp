/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:24:55 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/07 11:24:57 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../WebServ.hpp"
#include "Client.hpp"
#include "Requests.hpp"

Client::Client( void )
{
	num_requests = 0;
	this->requests = new Requests[this->num_requests];
}

Client::~Client()
{
	delete[] this->requests;
}
