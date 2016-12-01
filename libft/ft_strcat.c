/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 10:48:02 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 10:52:01 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *first_output;
	char *second_output;

	first_output = dest;
	second_output = src;
	while (*first_output)
		first_output++;
	while (*second_output)
	{
		*first_output = *second_output;
		first_output++;
		second_output++;
	}
	*first_output = '\0';
	return (dest);
}
