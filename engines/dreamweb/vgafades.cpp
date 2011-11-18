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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "dreamweb/dreamweb.h"

namespace DreamGen {

uint8 *DreamGenContext::mainPalette() {
	return segRef(data.word(kBuffers)).ptr(kMaingamepal, 256*3);
}

uint8 *DreamGenContext::startPalette() {
	return segRef(data.word(kBuffers)).ptr(kStartpal, 256*3);
}

uint8 *DreamGenContext::endPalette() {
	return segRef(data.word(kBuffers)).ptr(kEndpal, 256*3);
}

void DreamGenContext::clearstartpal() {
	memset(startPalette(), 0, 256*3);
}

void DreamGenContext::clearendpal() {
	memset(endPalette(), 0, 256*3);
}

void DreamGenContext::paltostartpal() {
	memcpy(startPalette(), mainPalette(), 256*3);
}

void DreamGenContext::endpaltostart() {
	memcpy(startPalette(), endPalette(), 256*3);
}

void DreamGenContext::startpaltoend() {
	memcpy(endPalette(), startPalette(), 256*3);
}

void DreamGenContext::paltoendpal() {
	memcpy(endPalette(), mainPalette(), 256*3);
}

void DreamGenContext::fadecalculation() {
	if (data.byte(kFadecount) == 0) {
		data.byte(kFadedirection) = 0;
		return;
	}

	uint8 *startPal = startPalette();
	const uint8 *endPal = endPalette();
	for (size_t i = 0; i < 256 * 3; ++i, ++si, ++di) {
		uint8 s = startPal[i];
		uint8 e = endPal[i];
		if (s == e)
			continue;
		else if (s > e)
			--startPal[i];
		else {
			if (data.byte(kFadecount) <= e)
				++startPal[i];
		}
	}
	--data.byte(kFadecount);
}

void DreamGenContext::fadeupyellows() {
	paltoendpal();
	memset(endPalette() + 231*3, 0, 8*3);
	memset(endPalette() + 246*3, 0, 1*3);
	data.byte(kFadedirection) = 1;
	data.byte(kFadecount) = 63;
	data.byte(kColourpos) = 0;
	data.byte(kNumtofade) = 128;
	hangon(128);
}

void DreamGenContext::fadeupmonfirst() {
	paltostartpal();
	paltoendpal();
	memset(startPalette() + 231*3, 0, 8*3);
	memset(startPalette() + 246*3, 0, 1*3);
	data.byte(kFadedirection) = 1;
	data.byte(kFadecount) = 63;
	data.byte(kColourpos) = 0;
	data.byte(kNumtofade) = 128;
	hangon(64);
	al = 26;
	playchannel1();
	hangon(64);
}

} /*namespace dreamgen */

