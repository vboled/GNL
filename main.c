/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 12:49:33 by gweasley          #+#    #+#             */
/*   Updated: 2019/10/13 12:49:35 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	main()
{
	int fd = open("test.TXT", O_RDONLY);
	char *line;
	while (1)
	{
		int res = get_next_line(fd, &line);
		printf("%d |", res);
		if (res != 1)
			return (0);
		printf("%s\n", line);
	}
	return (0);
}

