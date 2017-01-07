/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vportell <vportell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:08:14 by vportell          #+#    #+#             */
/*   Updated: 2016/11/04 15:40:36 by vportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if ((int)start + (int)len > i || (int)len < 0)
		return (NULL);
	if (len == 0)
		return ("");
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start - 1;
	while (s[++i] && i < (int)start + (int)len)
		sub[i - start] = s[i];
	sub[i - start] = '\0';
	return (sub);
}
