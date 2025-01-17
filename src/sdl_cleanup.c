/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbespalk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:07:58 by vbespalk          #+#    #+#             */
/*   Updated: 2019/05/08 18:08:00 by vbespalk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cleanup_sdl_window(SDL_Window **win)
{
	if (*win)
		SDL_DestroyWindow(*win);
	*win = NULL;
}

void	cleanup_sdl_texture(SDL_Texture **tex)
{
	if (*tex)
		SDL_DestroyTexture(*tex);
	*tex = NULL;
}

void	cleanup_sdl_surface(SDL_Surface **surf)
{
	if (*surf)
		SDL_FreeSurface(*surf);
	*surf = NULL;
}

void	cleanup_sdl_render(SDL_Renderer **rend)
{
	if (*rend)
		SDL_DestroyRenderer(*rend);
	*rend = NULL;
}

void	cleanup_mix_chunk(Mix_Chunk **sound)
{
	if (*sound)
		Mix_FreeChunk(*sound);
	*sound = NULL;
}

void	cleanup_mix_music(Mix_Music **sound)
{
	if (*sound)
		Mix_FreeMusic(*sound);
	*sound = NULL;
}

void	cleanup_ttf_font(TTF_Font **font)
{
	if (*font)
		TTF_CloseFont(*font);
	*font = NULL;
}

void	on_sdl_close(char *fmt, ...)
{
	va_list	args_ptr;

	if (fmt == NULL)
		SDL_Quit();
	va_start(args_ptr, fmt);
	while (*fmt)
	{
		if (*fmt == 's')
			cleanup_sdl_surface(va_arg(args_ptr, SDL_Surface **));
		else if (*fmt == 't')
			cleanup_sdl_texture(va_arg(args_ptr, SDL_Texture **));
		else if (*fmt == 'r')
			cleanup_sdl_render(va_arg(args_ptr, SDL_Renderer **));
		else if (*fmt == 'w')
			cleanup_sdl_window(va_arg(args_ptr, SDL_Window **));
		else if (*fmt == 'c')
			cleanup_mix_chunk(va_arg(args_ptr, Mix_Chunk **));
		else if (*fmt == 'm')
			cleanup_mix_music(va_arg(args_ptr, Mix_Music **));
		else if (*fmt == 'f')
			cleanup_ttf_font(va_arg(args_ptr, TTF_Font **));
		fmt++;
	}
	va_end(args_ptr);
}
