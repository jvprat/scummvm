/* ScummVM - Scumm Interpreter
 * Copyright (C) 2002-2005 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 */

#include "common/stdafx.h"
#include "common/util.h"

namespace Graphics {

void drawLine(int x0, int y0, int x1, int y1, int color, void (*plotProc)(int, int, int, void *), void *data) {
	// Bresenham's line algorithm, as described by Wikipedia
	bool steep = ABS(y1 - y0) > ABS(x1 - x0);

	if (steep) {
		SWAP(x0, y0);
		SWAP(x1, y1);
	}

	int delta_x = ABS(x1 - x0);
	int delta_y = ABS(y1 - y0);
	int err = 0;
	int delta_err = delta_y;
	int x = x0;
	int y = y0;

	int x_step = (x0 < x1) ? 1 : -1;
	int y_step = (y0 < y1) ? 1 : -1;

	if (steep)
		(*plotProc)(y, x, color, data);
	else
		(*plotProc)(x, y, color, data);

	while (x != x1) {
		x += x_step;
		err += delta_err;
		if (2 * err > delta_x) {
			y += y_step;
			err -= delta_x;
		}
		if (steep)
			(*plotProc)(y, x, color, data);
		else
			(*plotProc)(x, y, color, data);
	}
}

}	// End of namespace Graphics
