/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:25:15 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/12 15:41:32 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

/* ************************** */
/*     PARSING CONSTANTS     */
/* ************************** */
# define BUFFER_SIZE 64

/* ************************** */
/*      ELEMENT TYPES        */
/* ************************** */
# define TYPE_ERROR -1
# define TYPE_EMPTY 0
# define TYPE_TEXTURE 1
# define TYPE_COLOR 2
# define TYPE_MAP 3

/* ************************** */
/*      PARSING STATES       */
/* ************************** */
# define STATE_TEXTURE 0
# define STATE_MAP 1
# define STATE_COLOR 2
# define STATE_ERROR 3

/* ************************** */
/*     PLAYER MOVEMENT       */
/* ************************** */
# define MOVE_SPEED 0.1
# define SPRINT_SPEED 0.25
# define ROT_SPEED 0.1

#endif