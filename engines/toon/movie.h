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
* $URL$
* $Id$
*
*/

#ifndef TOON_MOVIE_H
#define TOON_MOVIE_H

#include "toon/toon.h"
#include "graphics/video/smk_decoder.h"

namespace Toon {

class ToonstruckSmackerDecoder : public Graphics::SmackerDecoder {
public:
	ToonstruckSmackerDecoder(Audio::Mixer *mixer, Audio::Mixer::SoundType soundType = Audio::Mixer::kSFXSoundType);
	void handleAudioTrack(const byte &track, const uint32 &chunkSize, const uint32 &unpackedSize);
	bool loadFile(const Common::String &filename, int forcedflags) ;
};

class Movie {
public:
	Movie(ToonEngine *vm, ToonstruckSmackerDecoder *decoder);
	~Movie(void);

	void init() const;
	void play(Common::String video, int32 flags = 0);

protected:
	bool playVideo();
	ToonEngine *_vm;
	Audio::Mixer *_mixer;
	ToonstruckSmackerDecoder *_decoder;
};

} // End of namespace Toon

#endif
