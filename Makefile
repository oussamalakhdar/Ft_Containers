# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 11:39:27 by olakhdar          #+#    #+#              #
#    Updated: 2023/02/03 19:10:51 by olakhdar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	c++ main.cpp vector.cpp -o containers

clean:
	rm containers