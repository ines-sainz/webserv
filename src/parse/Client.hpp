/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:25:00 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/07 11:25:02 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "../WebServ.hpp"
# include "Requests.hpp"

class Client
{
	private:
		int			num_requests;
		Requests	*requests;

	public:
		Client( void );
		~Client();
};
