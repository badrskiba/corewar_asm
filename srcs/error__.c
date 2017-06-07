/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error__.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagaizi <mtagaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:37:16 by mtagaizi          #+#    #+#             */
/*   Updated: 2017/05/23 16:32:40 by mtagaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int	error__(int er)
{
	if (er == 1)
		ft_printf("Erreur lors de la lecture du ficher\n");
	else if (er == 42)
		ft_printf("Erreur lors de la creation du fichier .cor\n");
	else if (er == -1)
		ft_printf("Usage: ./asm [-a] <sourcefile.s>\n\t-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output\n");
	else if (er == -2)
		ft_printf("Erreur lors de la creation du fichier .cor\n");
	return (-1);
}
