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

#ifndef COMMON_ACTION_H
#define COMMON_ACTION_H

#include "common/scummsys.h"

#ifdef ENABLE_KEYMAPPER

#include "common/events.h"
#include "common/func.h"
#include "common/list.h"
#include "common/str.h"

namespace Common {

struct HardwareKey;
class Keymap;

#define ACTION_ID_SIZE (4)

struct KeyActionEntry {
	const KeyState ks;
	const char *id;
	const char *description;
};

struct Action {
	/** unique id used for saving/loading to config */
	char id[ACTION_ID_SIZE];
	/** Human readable description */
	String description;

	/** Events to be sent when mapped key is pressed */
	List<Event> events;
	int priority;
	int group;
	int flags;

private:
	/** Hardware key that is mapped to this Action */
	const HardwareKey *_hwKey;
	Keymap *_boss;

public:
	Action(Keymap *boss, const char *id, String des = "",
		   int pri = 0, int flg = 0 );

	void addEvent(const Event &evt) {
		events.push_back(evt);
	}

	void addEvent(const EventType evtType) {
		Event evt;

		evt.type = evtType;
		events.push_back(evt);
	}

	void addKeyEvent(const KeyState &ks) {
		Event evt;

		evt.type = EVENT_KEYDOWN;
		evt.kbd = ks;
		addEvent(evt);
	}

	void addLeftClickEvent() {
		addEvent(EVENT_LBUTTONDOWN);
	}

	void addMiddleClickEvent() {
		addEvent(EVENT_MBUTTONDOWN);
	}

	void addRightClickEvent() {
		addEvent(EVENT_RBUTTONDOWN);
	}

	Keymap *getParent() {
		return _boss;
	}

	void mapKey(const HardwareKey *key);
	const HardwareKey *getMappedKey() const;

};

struct ActionPriorityComp : public BinaryFunction<Action, Action, bool> {
	bool operator()(const Action *x, const Action *y) const {
		return x->priority > y->priority;
	}
	bool operator()(const Action &x, const Action &y) const {
		return x.priority > y.priority;
	}
};

} // End of namespace Common

#endif // #ifdef ENABLE_KEYMAPPER

#endif // #ifndef COMMON_ACTION_H
