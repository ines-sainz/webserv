# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 09:04:16 by isainz-r          #+#    #+#              #
#    Updated: 2025/03/04 09:04:18 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

PARSE_DIR	= src/parse

SRCS		= src/main.cpp \
			src/WebServer.cpp \
			src/split.cpp \
			$(PARSE_DIR)/Client.cpp \
			$(PARSE_DIR)/Locations.cpp \
			$(PARSE_DIR)/Requests.cpp \
			$(PARSE_DIR)/Server.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -I . -c $< -o $@

all: $(NAME)

r: fclean all
	./$(NAME) files/webserv.config

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all r
