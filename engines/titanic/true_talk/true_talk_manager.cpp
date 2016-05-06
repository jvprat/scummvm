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

#include "titanic/true_talk/true_talk_manager.h"
#include "titanic/core/tree_item.h"
#include "titanic/npcs/true_talk_npc.h"
#include "titanic/game_manager.h"

#define MKTAG_BE(a3,a2,a1,a0) ((uint32)((a3) | ((a2) << 8) | ((a1) << 16) | ((a0) << 24)))

namespace Titanic {

int CTrueTalkManager::_v1;
int CTrueTalkManager::_v2;
int CTrueTalkManager::_v3;
bool CTrueTalkManager::_v4;
bool CTrueTalkManager::_v5;
int CTrueTalkManager::_v6;
int CTrueTalkManager::_v7;
bool CTrueTalkManager::_v8;
int CTrueTalkManager::_v9;
bool CTrueTalkManager::_v10;
int CTrueTalkManager::_v11[41];
CTrueTalkNPC *CTrueTalkManager::_currentNPC;

CTrueTalkManager::CTrueTalkManager(CGameManager *owner) : 
		_gameManager(owner), _scripts(&_titleEngine), _currentCharId(0),
		_dialogueFile(nullptr), _field14(0) {
}

CTrueTalkManager::~CTrueTalkManager() {
	clear();
}

void CTrueTalkManager::save(SimpleFile *file) const {
	saveStatics(file);

	saveNPC(file, 101);
	saveNPC(file, 103);
	saveNPC(file, 104);
	saveNPC(file, 105);
	saveNPC(file, 111);
	saveNPC(file, 100);
	saveNPC(file, 112);
	saveNPC(file, 107);
	file->writeNumber(0);
}

void CTrueTalkManager::load(SimpleFile *file) {
	loadStatics(file);

	// Iterate through loading characters
	int charId = file->readNumber();
	while (charId) {
		loadNPC(file, charId);

		int ident1 = file->readNumber();
		int ident2 = file->readNumber();

		if (ident1 != MKTAG_BE('U', 'R', 'A', 'H')) {
			while (ident2 != MKTAG_BE('A', 'K', 'E', 'R')) {
				ident1 = ident2;
				ident2 = file->readNumber();

				if (!ident1)
					break;
			}
		}

		// Get start of next character
		charId = file->readNumber();
	}
}

void CTrueTalkManager::loadStatics(SimpleFile *file) {
	int count = file->readNumber();
	_v1 = file->readNumber();
	_v2 = file->readNumber();
	_v3 = file->readNumber();
	_v4 = file->readNumber() != 0;
	_v5 = file->readNumber() != 0;
	_v6 = file->readNumber();
	_v7 = file->readNumber();
	_v8 = file->readNumber() != 0;
	_v9 = file->readNumber();
	_v10 = file->readNumber() != 0;

	for (int idx = count; count > 10; --idx)
		file->readNumber();

	int count2 = file->readNumber();
	for (int idx = 0; idx < count2; ++idx) {
		int v = file->readNumber();
		if (idx < 41)
			_v11[idx] = v;
	}
}

void CTrueTalkManager::saveStatics(SimpleFile *file) {
	file->writeNumber(10);
	file->writeNumber(_v1);
	file->writeNumber(_v2);
	file->writeNumber(_v3);
	file->writeNumber(_v4 ? 1 : 0);
	file->writeNumber(_v5 ? 1 : 0);
	file->writeNumber(_v6);
	file->writeNumber(_v7);
	file->writeNumber(_v8 ? 1 : 0);
	file->writeNumber(_v9);
	file->writeNumber(_v10 ? 1 : 0);

	file->writeNumber(41);
	for (int idx = 0; idx < 41; ++idx)
		file->writeNumber(_v11[idx]);
}

void CTrueTalkManager::clear() {
	delete _dialogueFile;
	_dialogueFile = nullptr;
	_currentCharId = 0;
}

void CTrueTalkManager::setFlags(int index, int val) {
	switch (index) {
	case 1:
		if (val >= 1 && val <= 3)
			_v3 = val;
		break;

	case 2:
		_v4 = !val;
		break;

	case 3:
		_v5 = val != 0;
		break;

	case 4:
		if (val >= 0 && val <= 3)
			_v6 = val;
		break;

	case 5:
		_v7 = val;
		break;

	case 6:
		_v8 = val != 0;
		break;

	default:
		if (index < 41)
			_v11[index] = val;
		break;
	}
}

void CTrueTalkManager::loadNPC(SimpleFile *file, int charId) {
	TTNamedScript *script = _scripts.getNamedScript(charId);
	if (script)
		script->load(file);
}

void CTrueTalkManager::saveNPC(SimpleFile *file, int charId) const {
	TTNamedScript *script = _scripts.getNamedScript(charId);
	if (script) {
		script->save(file);
		file->writeNumber(MKTAG_BE('U', 'R', 'A', 'H'));
		file->writeNumber(MKTAG_BE('A', 'K', 'E', 'R'));
	}
}

void CTrueTalkManager::preLoad() {
	warning("TODO: CTrueTalkManager::preLoad");
}

void CTrueTalkManager::update1() {
	//warning("CTrueTalkManager::update1");
}

void CTrueTalkManager::update2() {
	//warning("CTrueTalkManager::update2");
}

void CTrueTalkManager::start(CTrueTalkNPC *npc, int val2, int val3) {
	TTNamedScript *npcScript = getNpcScript(npc);
	TTRoomScript *roomScript = getRoomScript();
	
	_titleEngine.reset();
	uint charId = npcScript->charId();
	loadAssets(npc, charId);

	_currentNPC = npc;
	warning("TODO: CTrueTalkManager::start");
	_currentNPC = nullptr;

	//TODO: More
}

TTNamedScript *CTrueTalkManager::getTalker(const CString &name) const {
	if (name.contains("Doorbot"))
		return _scripts.getNamedScript(104);
	else if (name.contains("DeskBot"))
		return _scripts.getNamedScript(103);
	else if (name.contains("LiftBot"))
		return _scripts.getNamedScript(105);
	else if (name.contains("Parrot"))
		return _scripts.getNamedScript(107);
	else if (name.contains("BarBot"))
		return _scripts.getNamedScript(100);
	else if (name.contains("ChatterBot"))
		return _scripts.getNamedScript(102);
	else if (name.contains("BellBot"))
		return _scripts.getNamedScript(101);
	else if (name.contains("MaitreD"))
		return _scripts.getNamedScript(112);
	else if (name.contains("Succubus") || name.contains("Sub"))
		return _scripts.getNamedScript(111);

	return nullptr;
}

TTNamedScript *CTrueTalkManager::getNpcScript(CTrueTalkNPC *npc) const {
	CString npcName = npc->getName();
	TTNamedScript *script = getTalker(npcName);

	if (!script) {
		// Fall back on the default NPC script
		script = _scripts.getNamedScript(101);
	}

	return script;
}

TTRoomScript *CTrueTalkManager::getRoomScript() const {
	CRoomItem *room = _gameManager->getRoom();
	TTRoomScript *script = nullptr;
	if (room) {
		int scriptId = room->getScriptId();
		if (scriptId)
			script = _scripts.getRoomScript(scriptId);
	}

	if (!script) {
		// Fall back on the default Room script
		script = _scripts.getRoomScript(110);
	}

	return script;
}

void CTrueTalkManager::loadAssets(CTrueTalkNPC *npc, int charId) {
	// If assets for the character are already loaded, simply exit
	if (_currentCharId == charId)
		return;

	// Clear any previously loaded data
	clear();

	// Signal the NPC to get the asset details
	CTrueTalkGetAssetDetailsMsg detailsMsg;
	detailsMsg.execute(npc);

	if (!detailsMsg._filename.empty()) {
		_dialogueFile = new CDialogueFile(detailsMsg._filename, 20);
		_field14 = detailsMsg._numValue + 1;
	}
}

} // End of namespace Titanic
