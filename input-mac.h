/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-mac.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:11 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/24 22:05:10 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MAC
# define INPUT_MAC

enum	EVENTS
{
	EVENT_ON_KEYDOWN = 2,
	EVENT_ON_KEYUP = 3,
	EVENT_ON_MOUSEDOWN = 4,
	EVENT_ON_MOUSEUP = 5,
	EVENT_ON_MOUSEMOVE = 6,
	EVENT_ON_EXPOSE = 12,
	EVENT_ON_DESTROY = 17,
	EVENT_ON_RESIZE = 25
};

enum	KEYS
{
	KEY_ESC = 53
};

#endif