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

#include "titanic/star_control/fvector.h"
#include "titanic/star_control/dvector.h"
#include "titanic/star_control/fpose.h"
#include "common/algorithm.h"
#include "common/textconsole.h"

namespace Titanic {

FVector::FVector(const DVector &src) : _x(src._x), _y(src._y), _z(src._z) {
}

FVector FVector::fn1() const {
	return FVector(
		(ABS(_x - _y) < 0.00001 && ABS(_y - _z) < 0.00001 &&
			ABS(_x - _z) < 0.00001) ? -_y : _y,
		_z,
		_x
	);
}

FVector FVector::crossProduct(const FVector &src) const {
	return FVector(
		src._z * _y - _z * src._y,
		src._x * _z - _x * src._z,
		src._y * _x - _y * src._x
	);
}

float FVector::normalize() {
	float hyp = sqrt(_x * _x + _y * _y + _z * _z);
	assert(hyp);

	_x *= 1.0 / hyp;
	_y *= 1.0 / hyp;
	_z *= 1.0 / hyp;
	return hyp;
}

const FVector *FVector::addAndNormalize(FVector &dest, const FVector &v1, const FVector &v2) {
	FVector tempVector(v1._x + v2._x, v1._y + v2._y, v1._z + v2._z);
	tempVector.normalize();

	dest = tempVector;
	return &dest;
}

float FVector::getDistance(const FVector &src) const {
	float xd = src._x - _x;
	float yd = src._y - _y;
	float zd = src._z - _z;

	return sqrt(xd * xd + yd * yd + zd * zd);
}

FVector FVector::fn5(const FPose &pose) const {
	FVector v;
	v._x = pose._row2._x * _y + pose._row3._x * _z + pose._row1._x * _x + pose._vector._x;
	v._y = pose._row2._y * _y + pose._row3._y * _z + pose._row1._y * _x + pose._vector._y;
	v._z = pose._row3._z * _z + pose._row2._z * _y + pose._row1._z * _x + pose._vector._z;
	return v;
}

} // End of namespace Titanic
