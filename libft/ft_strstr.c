/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reasaw <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:59:00 by reasaw            #+#    #+#             */
/*   Updated: 2016/09/23 11:50:57 by reasaw           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (to_find[len])
		len++;
	if (len == 0)
		return (str);
	while (str[i])
	{
		while (to_find[pos] == str[i + pos])
		{
			if (pos == len - 1)
				return (str + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
