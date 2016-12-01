/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 10:52:24 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 10:55:55 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char	*first_output;
	char	*second_output;
	int		counter;

	first_output = dest;
	second_output = src;
	counter = 0;
	while (*first_output)
		first_output++;
	while (*second_output && counter < nb)
	{
		*first_output = *second_output;
		first_output++;
		second_output++;
		counter++;
	}
	*first_output = '\0';
	return (dest);
}
