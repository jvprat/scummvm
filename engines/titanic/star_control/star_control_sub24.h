/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TITANIC_STAR_CONTROL_SUB24_H
#define TITANIC_STAR_CONTROL_SUB24_H

#include "titanic/star_control/star_control_sub23.h"

namespace Titanic {

class CStarControlSub24 : public CStarControlSub23 {
public:
	virtual ~CStarControlSub24() {}

	virtual void proc3(const FMatrix &m1, const FMatrix &m2);
	virtual void proc4(FVector &v1, FVector &v2, FMatrix &m);
	virtual int proc5(CErrorCode &errorCode, FVector &v, FMatrix &m);
};

} // End of namespace Titanic

#endif /* TITANIC_STAR_CONTROL_SUB24_H */
