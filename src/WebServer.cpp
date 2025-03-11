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

void	split_line(std::vector<std::string> *splitted_line)
{
	std::string	compare = " \t";
}

int	WebServ::ConfigFile(char *file_name)
{
	std::ifstream				server_fd;
	std::vector<std::string>	server_file;
	std::vector<std::string>	splitted_line;
	std::string					lines;
	int							is_server = 0;


	server_fd.open(file_name, std::ios::in);
	if (!server_fd.is_open())
	{
		std::cout << "Error: Can't open file" << std::endl;
		return (1);
	}
	while (std::getline(server_fd, lines))
	{
		split_line(&splitted_line, &is_server);
		first_splitted = splitted_line.back();
		server_file.push_back(lines);
	}	

}

// int	WebServ::ConfigFile(char *file_name)
// {
// 	std::ifstream				server_fd;
// 	std::vector<std::string>	server_file;
// 	std::string					lines;
// 	std::string					substring;
// 	std::string					to_compare = "server {";
// 	int							is_server = 0;

// 	server_fd.open(file_name, std::ios::in);
// 	while (std::getline(server_fd, lines))
// 	{
// 		if (is_server == 0)
// 		{
// 			for (size_t i = 0; i < lines.length(); i++)
// 			{
// 				if (to_compare.find(lines[i]) == std::string::npos)
// 					return (1);
// 				if (lines[i] == ' ')
// 					continue ;
// 				else
// 				{
// 					substring = lines.substr(i, 6);
// 					if (substring == "server")
// 						is_server == 1;
// 					std::cout << substring << std::endl;
// 				}
// 			}
// 		}
// 		if (lines == "}")
// 			is_server = 0;
// 		server_file.push_back(lines);
// 	}
// 	return (0);
// }

WebServ::WebServ( void )
{
	//int	num_servers = 1;

	//this->server = new Server[num_servers];
}

WebServ::~WebServ()
{
	delete[] this->server;
}

