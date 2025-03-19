/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:44 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/19 15:16:46 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServ.hpp"

int	countWords(std::string to_split, std::string str)
{
	int i = 0;
	int j = 0;

	while (to_split[i])
	{
		if (str.find(to_split[i]) != std::string::npos && to_split[i + 1] != '\0')
			i++;
		if (str.find(to_split[i]) == std::string::npos && (str.find(to_split[i + 1]) != std::string::npos || to_split[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j + 1);
}

std::string splitting(std::string to_split, std::string str, int *iter)
{
	int	j = 0;

	while (str.find(to_split[*iter]) != std::string::npos && to_split[*iter])
		(*iter)++;
	j = *iter;
	while (str.find(to_split[*iter]) == std::string::npos && to_split[*iter])
		(*iter)++;
	return (to_split.substr(j, *iter - j));
}

void	splitLine(std::vector<std::string> *splitted, std::string to_split, std::string str)
{
	int	iter = 0;
	int	count_words;
	int	i = 0;
	std::string	line;

	if (to_split.empty())
		return ;
	count_words = countWords(to_split, str);
	while (i < count_words - 1)
	{
		line = splitting(to_split, str, &iter);
		splitted->push_back(line);
		i++;
	}
}
