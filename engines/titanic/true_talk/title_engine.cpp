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

#include "titanic/true_talk/title_engine.h"

namespace Titanic {

CTitleEngine::CTitleEngine() : _script(nullptr), _sub(nullptr) {
}

CTitleEngine::~CTitleEngine() {
	delete _script;
	delete _sub;
}

void CTitleEngine::setup(int val1, int val2) {

}


/*------------------------------------------------------------------------*/

STtitleEngine::STtitleEngine(): CTitleEngine(), _field58(0) {
}

STtitleEngine::~STtitleEngine() {
	delete _stream;
}

void STtitleEngine::reset() {
	_field58 = 0;
	_array.clear();
}

void STtitleEngine::setup(int val1, int val2) {
	CTitleEngine::setup(val1, 3);
}

int STtitleEngine::proc2(int val1, int val2) {
	// TODO
	return 0;
}

void STtitleEngine::dump(int val1, int val2) {
	// TODO
}

void STtitleEngine::open(const CString &name) {
	_stream = _resources.getResource(Common::WinResourceID("Text"),
		name);
}

void STtitleEngine::close() {
	delete _stream;
	_stream = nullptr;
}

} // End of namespace Titanic
