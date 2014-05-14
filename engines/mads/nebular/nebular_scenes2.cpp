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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/scummsys.h"
#include "mads/mads.h"
#include "mads/scene.h"
#include "mads/nebular/nebular_scenes.h"
#include "mads/nebular/nebular_scenes2.h"

namespace MADS {

namespace Nebular {

void Scene2xx::setAAName() {
	int idx = (_scene->_nextSceneId == 216) ? 4 : 2;
	_game._aaName = Resources::formatAAName(idx);
}

void Scene2xx::setPlayerSpritesPrefix() {
	_vm->_sound->command(5);
	Common::String oldName = _game._player._spritesPrefix;

	switch(_scene->_nextSceneId) {
	case 213:
	case 216:
		_game._player._spritesPrefix = "";
		break;
	default:
		if (_globals[kSexOfRex] != SEX_MALE) {
			_game._player._spritesPrefix = "ROX";
		} else {
			_game._player._spritesPrefix = "RXM";
		}
		break;
	}

	_game._player._scalingVelocity = (_scene->_nextSceneId <= 212);

	if (oldName != _game._player._spritesPrefix)
		_game._player._spritesChanged = true;

	if ((_scene->_nextSceneId == 203 || _scene->_nextSceneId == 204) && _globals[kRhotundaStatus])
		_game._player._loadsFirst = false;

	_vm->_palette->setEntry(16, 10, 63, 63);
	_vm->_palette->setEntry(17, 10, 45, 45);
}

void Scene2xx::sceneEntrySound() {
	if (_vm->_musicFlag) {
		switch (_scene->_nextSceneId) {
		case 201:
			if ((_globals[kTeleporterCommand] == 2) || (_globals[kTeleporterCommand] == 4) || (_globals[kMeteorologistStatus] != 1))
				_vm->_sound->command(9);
			else
				_vm->_sound->command(17);
			break;
		case 202:
		case 203:
		case 204:
		case 205:
		case 208:
		case 209:
		case 212:
			_vm->_sound->command(9);
			break;
		case 206:
		case 211:
		case 215:
			_vm->_sound->command(10);
			break;
		case 207:
		case 214:
			_vm->_sound->command(11);
			break;
		case 210:
			if (_globals[kTwinklesStatus] == 0)
				_vm->_sound->command(15);
			else
				_vm->_sound->command(10);
			break;
		case 213:
			if (_globals[kMeteorologistWatch] == 0)
				_vm->_sound->command(1);
			else
				_vm->_sound->command(9);
				break;
		case 216:
			_vm->_sound->command(16);
			break;
		default:
			_vm->_sound->command(10);
			break;
		}
	} else
		_vm->_sound->command(2);
}

/*------------------------------------------------------------------------*/

void Scene201::setup() {
	setPlayerSpritesPrefix();
	setAAName();

	_scene->addActiveVocab(NOUN_15F);
	_scene->addActiveVocab(NOUN_BIRDS);
	_scene->addActiveVocab(VERB_WALKTO);
}

void Scene201::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('x', 0));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('x', 1));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('m', -1));
	_globals._spriteIndexes[4] = _scene->_sprites.addSprites(formAnimName('b', -1));
	_globals._spriteIndexes[5] = _scene->_sprites.addSprites("*SC002Z1");
	_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 6, 0, 1, 0);
	_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 15, 0, 0, 50);
	_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 4, 0, 0, 0);
	_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 6, 0, 0, 0);
	_scene->_sequences.setDepth(_globals._sequenceIndexes[4], 8);
	_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[4], Common::Point(185, 46));

	int idx = _scene->_dynamicHotspots.add(NOUN_BIRDS, 209, _globals._sequenceIndexes[4], Common::Rect(0, 0, 0, 0));
	_scene->_dynamicHotspots.setPosition(idx, Common::Point(186, 81), FACING_NORTH);

	if ((_scene->_priorSceneId == 202) || (_scene->_priorSceneId == -1)) {
		_game._player._playerPos = Common::Point(165, 152);
	} else {
		_game._player._playerPos = Common::Point(223, 149);
		_game._player._facing = FACING_SOUTH;
	}

	if (_globals[kTeleporterCommand]) {
		_game._player._visible = false;
		_game._player._stepEnabled = false;
		int sepChar = (_globals[kSexOfRex] == SEX_UNKNOWN) ? 't' : 'u';
		// Guess values. What is the default value used by the compiler?
		int suffixNum = -1;
		int abortTimers = -1;
		switch(_globals[kTeleporterCommand]) {
		case 1:
			suffixNum = 3;
			abortTimers = 76;
			_globals[kTeleporterUnderstood] = true;
			break;
		case 2:
			suffixNum = 1;
			abortTimers = 77;
			break;
		case 3:
			_game._player._visible = true;
			_game._player._stepEnabled = true;
			suffixNum = -1;
			break;
		case 4:
			suffixNum = 2;
			abortTimers = 78;
			break;
		}
		_globals[kTeleporterCommand] = 0;
		if (suffixNum >= 0)
			_scene->loadAnimation(formAnimName(sepChar, suffixNum), abortTimers);
	}

	if ((_scene->_priorSceneId == 202) && (_globals[kMeteorologistStatus] == 1) && !_scene->_roomChanged) {
		_globals._spriteIndexes[6] = _scene->_sprites.addSprites(formAnimName('a', 0));
		_globals._spriteIndexes[7] = _scene->_sprites.addSprites(formAnimName('a', 1));
		_game.loadQuoteSet(90, 91, 0);
		_game._player._stepEnabled = false;
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 7, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], -1, 12);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[6], SEQUENCE_TRIGGER_SPRITE, 12, 70);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 1);
		_pterodactylFlag = false;
		_game._player.walk(Common::Point(157, 143), FACING_NORTH);
		_vm->_palette->setEntry(252, 45, 63, 45);
		_vm->_palette->setEntry(253, 20, 45, 20);
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 2, 0, 120, _game.getQuote(90));
	} else
		_pterodactylFlag = true;

	if (_globals[kTeleporterUnderstood])
		_scene->_hotspots.activate(438, false);

	sceneEntrySound();
}

void Scene201::step() {
	if (_pterodactylFlag && (_vm->getRandomNumber(5000) == 9)) {
		_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 5, 1, 6, 0);
		int idx = _scene->_dynamicHotspots.add(351, 13, _globals._sequenceIndexes[5], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(270, 80), FACING_EAST);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[5], 8);
		_vm->_sound->command(14);
		_pterodactylFlag = false;
	}

	if (_game._trigger == 70) {
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 9, 1, 0, 0);
		_game._player._visible = false;
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], 12, 16);
		_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 9, 1, 0, 0);
		_vm->_sound->command(42);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 1);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[7], 1);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_SPRITE, 3, 81);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_EXPIRE, 0, 71);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[6], SEQUENCE_TRIGGER_EXPIRE, 0, 73);
	}

	if (_game._trigger == 81) {
		_scene->_kernelMessages.reset();
	}

	if (_game._trigger == 71) {
		_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 9, 0, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[7], -2, -2);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[7], 1);
	}

	if (_game._trigger == 73) {
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 9, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], 17, -2);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[6], SEQUENCE_TRIGGER_EXPIRE, 0, 74);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 1);
	}

	if (_game._trigger == 74) {
		_vm->_sound->command(40);

		_scene->_kernelMessages.add(Common::Point(125, 56), 0xFDFC, 32, 82, 180, _game.getQuote(91));
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 9, 0, 0, 0);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 1);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], -2, -2);
		_scene->_sequences.addTimer(180, 75);
	}

	if (_game._trigger == 75) {
		_globals[kMeteorologistEverSeen] = 0;
		_scene->_nextSceneId = 202;
	}

	if (_game._trigger == 76) {
		_game._player._stepEnabled = true;
		_game._player._visible = true;
		_game._player._priorTimer = _scene->_frameStartTime - _game._player._ticksAmount;
	}

	if (_game._trigger == 77) {
		_globals[kTeleporterCommand] = 1;
		_scene->_nextSceneId = _globals[kTeleporterDestination];
		_scene->_reloadSceneFlag = true;
	}

	if (_game._trigger == 78) {
		_vm->_sound->command(40);
		_vm->_dialogs->show(0x4E92);
		_scene->_reloadSceneFlag = true;
	}
}

void Scene201::actions() {
	if (_action._lookFlag == false) {
		if (_action.isAction(VERB_WALK_TOWARDS, 0x83))
			_scene->_nextSceneId = 202;
		else if ((_action.isAction(0x50, 0x156)) || (_action.isAction(0x188, 0x16C)) || (_action.isAction(0x188, 0x1B6))) {
			if (_game._trigger == 0) {
				_game._player._stepEnabled = false;
				_game._player._visible = false;
				int sepChar = (_globals[kSexOfRex] == SEX_UNKNOWN) ? 't' : 'u';
				_scene->loadAnimation(formAnimName(sepChar, 0), 1);
			} else if (_game._trigger == 1) {
				_scene->_nextSceneId = 213;
			}
		} else if (_action.isAction(VERB_LOOK, 0x1A6)) {
			_vm->_dialogs->show(0x4E85);
		} else if (_action.isAction(VERB_LOOK, 0x129)) {
			_vm->_dialogs->show(0x4E86);
		} else if (_action.isAction(VERB_LOOK, 0x16F)) {
			_vm->_dialogs->show(0x4E87);
		} else if (_action.isAction(VERB_LOOK, 0x142)) {
			_vm->_dialogs->show(0x4E88);
		} else if (_action.isAction(VERB_LOOK, 0x18F)) {
			_vm->_dialogs->show(0x4E89);
		} else if (_action.isAction(VERB_LOOK, 0x1B9)) {
			_vm->_dialogs->show(0x4E8A);
		} else if (_action.isAction(VERB_LOOK, 0x192)) {
			_vm->_dialogs->show(0x4E8B);
		} else if (_action.isAction(VERB_LOOK, 0x1BA)) {
			_vm->_dialogs->show(0x4E8C);
		} else if (_action.isAction(VERB_LOOK, 0x83)) {
			_vm->_dialogs->show(0x4E8E);
		} else if (_action.isAction(VERB_LOOK, 0x1B6)) {
			if (_globals[kMeteorologistEverSeen])
				_vm->_dialogs->show(0x4E90);
			else
				_vm->_dialogs->show(0x4E8D);
		} else if (_action.isAction(VERB_LOOK, 0x16C)) {
			_vm->_dialogs->show(0x4E91);
		} else
			return;
	} else {
		_vm->_dialogs->show(0x4E8F);
	}
	_action._inProgress = false;
}

void Scene201::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_pterodactylFlag);
}

/*------------------------------------------------------------------------*/

void Scene202::setup() {
	setPlayerSpritesPrefix();
	setAAName();

	_scene->addActiveVocab(NOUN_LADDER);
	_scene->addActiveVocab(VERB_CLIMB_DOWN);
	_scene->addActiveVocab(VERB_WALKTO);
	_scene->addActiveVocab(NOUN_BONE);
	_scene->addActiveVocab(NOUN_SKULL);
	_scene->addActiveVocab(NOUN_BROKEN_LADDER);
}

void Scene202::enter() {
	_game._player._beenVisible = true;
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('b', 0));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('b', 1));
	_globals._spriteIndexes[6] = _scene->_sprites.addSprites(formAnimName('b', 2));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('x', 0));
	_globals._spriteIndexes[5] = _scene->_sprites.addSprites(formAnimName('l', -1));
	if (_globals[kSexOfRex] != SEX_MALE) {
		_globals._spriteIndexes[7] = _scene->_sprites.addSprites("*ROXBD_2");
	} else {
		_globals._spriteIndexes[7] = _scene->_sprites.addSprites("*RXMBD_2");
	}
	_globals._spriteIndexes[8] = _scene->_sprites.addSprites(formAnimName('a', 0));
	_globals._spriteIndexes[9] = _scene->_sprites.addSprites(formAnimName('a', 1));
	_globals._spriteIndexes[11] = _scene->_sprites.addSprites(formAnimName('a', 2));

	_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 6, 0, 0, 0);
	_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 6, 0, 0, 0);
	_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(149, 113));
	_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 10);
	int idx = _scene->_dynamicHotspots.add(NOUN_BONE, VERB_WALKTO, _globals._sequenceIndexes[2], Common::Rect(0, 0, 0, 0));
	_scene->_dynamicHotspots.setPosition(idx, Common::Point(153, 97), FACING_SOUTH);

	if (!(_globals[kBone202Status] & 1)) {
		_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 6, 0, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[1], Common::Point(130, 108));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 10);
		idx = _scene->_dynamicHotspots.add(NOUN_BONE, VERB_WALKTO, _globals._sequenceIndexes[1], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(132, 97), FACING_SOUTH);
	}

	if (!(_globals[kBone202Status] & 2)) {
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 6, 0, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[6], Common::Point(166, 110));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 10);
		idx = _scene->_dynamicHotspots.add(NOUN_BONE, VERB_WALKTO, _globals._sequenceIndexes[6], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(165, 99), FACING_SOUTH);
	}

	if (_globals[kBone202Status])
		_scene->changeVariant(_globals[kBone202Status]);

	if (_scene->_priorSceneId == 201) {
		_game._player._playerPos = Common::Point(190, 91);
		_game._player._facing = FACING_SOUTH;
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(178, 152);
		_game._player._facing = FACING_NORTH;
	}

	if (_globals[kLadderBroken]) {
		_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 6, 0, 0, 0);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[5], 6);
		_scene->_hotspots.activate(NOUN_LADDER, false);
		idx = _scene->_dynamicHotspots.add(NOUN_BROKEN_LADDER, VERB_WALKTO, _globals._sequenceIndexes[5], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(246, 124), FACING_NORTH);
	}

	_game.loadQuoteSet(0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x62, 0x63, 0x64, 0x65, 0x66, 0x61, 0);
	_activeMsgFl = false;

	if (_scene->_priorSceneId == -2) {
		if (_waitingMeteoFl) {
			_globals._sequenceIndexes[9] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], false, 1);
			_game._player._visible = false;
		}
	} else {
		_waitingMeteoFl = false;
		_ladderTopFl = false;
	}

	_meteoClock1 = _meteoClock2 = _scene->_frameStartTime;

	if (_scene->_roomChanged)
		_game._objects.addToInventory(OBJ_BINOCULARS);

	if (_globals[kMeteorologistWatch]) {
		_game._player._visible = false;
		_game._player._stepEnabled = false;
		if (_globals[kMeteorologistWatch] == 2)
			_ladderTopFl = true;
		else
			_ladderTopFl = false;

		if (_globals[kMeteorologistWatch] < 1)
			_globals._sequenceIndexes[10] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], false, 6);
		else
			_globals._sequenceIndexes[10] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], false, 8);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[10], 1);

		if (_ladderTopFl) {
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[10], Common::Point(247, 82));
			_game._player._playerPos = Common::Point(246, 124);
			_game._player._facing = FACING_NORTH;
			_globals[kTeleporterUnderstood] = true;
		} else {
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[10], Common::Point(172, 123));
			_game._player._playerPos = Common::Point(171, 122);
			_game._player._facing = FACING_NORTH;
		}

		_scene->loadAnimation(formAnimName('M', -1), 71);
		_scene->_activeAnimation->setCurrentFrame(200);
	} else {
		_game._player._visible = false;
		_scene->_sequences.startCycle(_globals._sequenceIndexes[9], true, 1);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
		_game._player._playerPos = Common::Point(246, 124);
		_game._player._facing = FACING_NORTH;
	}

	_meteorologistSpecial = 0;
}

void Scene202::setRandomKernelMessage() {
	int vocabId = _vm->getRandomNumber(92, 96);
	_scene->_kernelMessages.reset();
	_game._triggerSetupMode = SEQUENCE_TRIGGER_DAEMON;
	_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 70, 120, _game.getQuote(vocabId));
	_activeMsgFl = true;
}

void Scene202::step() {
	if (!_activeMsgFl && (_game._player._playerPos == Common::Point(77, 105)) && (_game._player._facing == FACING_NORTH) && (_vm->getRandomNumber(999) == 0)) {
		_scene->_kernelMessages.reset();
		_activeMsgFl = false;
		if (_vm->getRandomNumber(4) == 0)
			setRandomKernelMessage();
	}

	if (_game._trigger == 70)
		_activeMsgFl = false;

	if (_game._trigger == 71) {
		_vm->_sound->command(3);
		_vm->_sound->command(9);
		_meteoClock1 = 900 + _scene->_frameStartTime;
		Common::Point msgPos;
		int msgFlag;
		if (!_ladderTopFl) {
			msgPos = Common::Point(0, 0);
			msgFlag = 2;
		} else {
			msgPos = Common::Point(248, 15);
			msgFlag = 0;
		}
		int msgIndex = _scene->_kernelMessages.add(msgPos, 0x1110, msgFlag | 32, 0, 120, _game.getQuote(102));
		_scene->_kernelMessages.setQuoted(msgIndex, 4, true);

		if (_globals[kMeteorologistWatch] == 1) {
			_action._activeAction._verbId = VERB_LOOK;
			_action._activeAction._objectNameId = 39;
			_action._activeAction._indirectObjectId = 438;
			_game._triggerSetupMode = SEQUENCE_TRIGGER_PARSER;
			_scene->_sequences.addTimer(120, 2);
			_meteorologistSpecial = -1;
		} else if (_globals[kMeteorologistWatch] == 2) {
			_scene->_sequences.addTimer(120, 90);
		}
		_globals[kMeteorologistWatch] = 0;
	}

	switch (_game._trigger) {
	case 90:
		_vm->_sound->command(41);
		_scene->_sequences.remove(_globals._sequenceIndexes[10]);
		_globals._sequenceIndexes[9] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[9], true, 6, 1, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[9], SEQUENCE_TRIGGER_EXPIRE, 0, 91);
		break;
	case 91:
		_globals._sequenceIndexes[9] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], true, 1);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
		_scene->_sequences.addTimer(60, 92);
		break;
	case 92: {
		_scene->_sequences.remove(_globals._sequenceIndexes[9]);
		_globals._sequenceIndexes[11] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[11], false, 6, 1, 0, 0);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[11], 1);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[11], SEQUENCE_TRIGGER_EXPIRE, 0, 93);
		_scene->_kernelMessages.reset();
		int msgIndex = _scene->_kernelMessages.add(Common::Point(0, -65), 0x1110, 32, 0, 60, _game.getQuote(98));
		_scene->_kernelMessages.setSeqIndex(msgIndex, _globals._sequenceIndexes[11]);
		}
		break;
	case 93: {
		_globals[kLadderBroken] = -1;
		_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 6, 0, 0, 0);
		_scene->_hotspots.activate(NOUN_LADDER, false);
		int idx = _scene->_dynamicHotspots.add(NOUN_BROKEN_LADDER, VERB_WALKTO, _globals._sequenceIndexes[5], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(246, 124), FACING_NORTH);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[11], _globals._sequenceIndexes[5]);
		_scene->_sequences.updateTimeout(-1, _globals._sequenceIndexes[11]);
		_game._player._stepEnabled = true;
		_game._player._visible = true;
		_ladderTopFl = false;
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(99));
		}
		break;
	default:
		break;
	}

	if (!_scene->_activeAnimation && (_globals[kMeteorologistStatus] != 2) && (_meteoClock2 <= _scene->_frameStartTime) && (_meteoClock1 <= _scene->_frameStartTime)) {
		int randVal = _vm->getRandomNumber(1, 500);
		int threshold = 1;
		if (_ladderTopFl)
			threshold += 25;
		if (!_globals[kMeteorologistEverSeen])
			threshold += 25;
		if (threshold >= randVal) {
			_vm->_sound->command(17);
			_scene->loadAnimation(formAnimName('M', -1), 71);
			_toStationFl = true;
			_toTeleportFl = false;
			_globals[kMeteorologistEverSeen] = true;
			_lastRoute = 0;
			_stationCounter = 0;
			_meteoClock2 = _scene->_frameStartTime + 2;
		}
	}

	if (!_scene->_activeAnimation)
		return;

	if (_waitingMeteoFl) {
		if (_scene->_activeAnimation->getCurrentFrame() >= 200) {
			if ((_globals[kMeteorologistWatch] == 2) || _globals[kLadderBroken]) {
				_scene->_nextSceneId = 213;
			} else {
				_vm->_dialogs->show(0x4EE9);
				_scene->_reloadSceneFlag = true;
			}
		}

		if ((_scene->_activeAnimation->getCurrentFrame() == 160) && (_meteoFrame != _scene->_activeAnimation->getCurrentFrame())) {
			Common::Point msgPos;
			int msgFlag;
			if (!_ladderTopFl) {
				msgPos = Common::Point(0, 0);
				msgFlag = 2;
			} else {
				msgPos = Common::Point(248, 15);
				msgFlag = 0;
			}
			int msgIndex = _scene->_kernelMessages.add(msgPos, 0x1110, msgFlag | 32, 0, 120, _game.getQuote(101));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
		}
	}

	if (_meteoClock2 + 7200 <= _scene->_frameStartTime) {
		_toTeleportFl = true;
	}

	if (_scene->_activeAnimation->getCurrentFrame() == _meteoFrame) {
		return;
	}

	_meteoFrame = _scene->_activeAnimation->getCurrentFrame();
	int randVal = _vm->getRandomNumber(1, 1000);
	int frameStep = -1;

	switch (_scene->_activeAnimation->getCurrentFrame()) {
	case 42:
	case 77:
	case 96:
		frameStep = subStep1(randVal);
		break;
	case 51:
	case 74:
		frameStep = subStep2(randVal);
		break;
	case 27:
	case 119:
	case 159:
		frameStep = subStep3(randVal);
		break;
	case 176:
		frameStep = subStep4(randVal);
		break;
	case 59:
		_lastRoute = 3;
		++_stationCounter;
		if (randVal <= 800)
			frameStep = 55;
		break;
	case 89:
		_lastRoute = 1;
		if (randVal <= 700)
			frameStep = 83;
		break;
	case 137:
		_lastRoute = 2;
		if (randVal <= 700)
			frameStep = 126;
		break;
	}

	if (frameStep < 0)
		return;

	int nextFrame = 1 + _scene->_activeAnimation->getCurrentFrame() - frameStep;
	if (nextFrame) {
		_scene->_activeAnimation->setCurrentFrame(nextFrame);
		_meteoFrame = nextFrame;
	}
}

int Scene202::subStep1(int randVal) {
	_stationCounter = 0;

	if ((randVal <= 100) || _toStationFl)
		return 42;

	if ((randVal <= 200) || _toTeleportFl)
		return 96;

	if ((randVal <= 300) && (_lastRoute != 1))
		return 77;

	return 76;
}

int Scene202::subStep2(int randVal) {
	_toStationFl = false;

	if ((randVal <= 150) && (_stationCounter < 5))
		return 51;

	if ((randVal <= 300) || _toTeleportFl)
		return 74;

	if (randVal <= 400)
		return 64;

	return 44;
}

int Scene202::subStep3(int randVal) {
	if ((randVal <= 100) || _toStationFl)
		return 27;

	if ((randVal <= 200) || _toTeleportFl)
		return 159;

	if ((randVal <= 300) && (_lastRoute != 2))
		return 119;

	return 110;
}

int Scene202::subStep4(int randVal) {
	if ((randVal <= 100) || _toTeleportFl)
		return 176;

	if (randVal <= 200)
		return 19;

	return 166;
}

void Scene202::preActions() {
	Player &player = _vm->_game->_player;

	if (player._readyToWalk)
		_scene->_kernelMessages.reset();

	if (!_ladderTopFl && (_action.isAction(0x4E, NOUN_LADDER) || !player._readyToWalk)) {
		if (_game._trigger == 0) {
			_vm->_sound->command(29);
			player._readyToWalk = false;
			_game._player._stepEnabled = false;
			_scene->_sequences.remove(_globals._sequenceIndexes[9]);
			_globals._sequenceIndexes[8] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[8], false, 6, 1, 0, 0);
			_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 1);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
		} else if (_game._trigger == 1) {
			_scene->_sequences.updateTimeout(-1, _globals._sequenceIndexes[8]);
			_scene->_dynamicHotspots.remove(_ladderHotspotId);
			_game._player._visible = true;
			player._readyToWalk = true;
			_game._player._stepEnabled = true;
			_ladderTopFl = false;
		}
	}

	if (_action.isAction(VERB_LOOK, 0x27) && (_action._activeAction._indirectObjectId > 0)) {
		if (!player._readyToWalk || _ladderTopFl)
			_game._player._needToWalk = false;
		else
			_game._player._needToWalk = true;

		if (!_ladderTopFl)
			_game._player.walk(Common::Point(171, 122), FACING_NORTH);
	}
}

void Scene202::actions() {
	if (_action._lookFlag == false) {
		if (_action.isAction(0x4E, NOUN_LADDER)) {
			_action._inProgress = false;
			return;
		} else if (_action.isAction(VERB_WALK_TOWARDS, 0x83)) {
			_scene->_nextSceneId = 203;
		} else if (_action.isAction(VERB_WALK_TOWARDS, 0x82)) {
			if (_globals[kMeteorologistStatus] != 2) {
				if (_scene->_activeAnimation)
					_globals[kMeteorologistStatus] = 1;
				else
					_globals[kMeteorologistStatus] = 0;
			}
			_scene->_nextSceneId = 201;
		} else if (_action.isAction(VERB_TAKE, 0x2C)) {
			if (_action._mainObjectSource == 4) {
				switch (_game._trigger) {
				case 0:
					if (_game._objects.isInInventory(OBJ_BONES)) {
						_vm->_dialogs->show(0x4EFB);
					} else {
						_game._player._stepEnabled = false;
						_game._player._visible = false;
						_globals._sequenceIndexes[7] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[6], false, 3, 2, 0, 0);
						_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[7]);
						_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_SPRITE, 6, 1);
						_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
					}
					break;
				case 1:
					if (_game._player._playerPos == Common::Point(132,97)) {
						_scene->_sequences.remove(_globals._sequenceIndexes[1]);
						_globals[kBone202Status] |= 1;
					} else {
						_scene->_sequences.remove(_globals._sequenceIndexes[6]);
						_globals[kBone202Status] |= 2;
					}
					break;
				case 2:
					if (_game._objects.isInInventory(OBJ_BONE)) {
						_game._objects.removeFromInventory(OBJ_BONE, 1);
						_game._objects.addToInventory(OBJ_BONES);
						_vm->_dialogs->showItem(OBJ_BONES, 0x4EFA, 0);
					} else {
						_game._objects.addToInventory(OBJ_BONE);
						_vm->_dialogs->showItem(OBJ_BONE, 0x4EFA, 0);
					}
					_scene->changeVariant(_globals[kBone202Status]);
					_game._player._stepEnabled = true;
					_game._player._visible = true;
					break;
				default:
					_action._inProgress = false;
					return;
				}
			}
		} else if ((_action.isAction(0x50, NOUN_LADDER)) && (_globals[kLadderBroken] == 0)) {
			switch (_game._trigger) {
			case 0:
				_vm->_sound->command(29);
				_meteoClock1 = _scene->_frameStartTime;
				_game._player._visible = false;
				_game._player._stepEnabled = false;

				_ladderHotspotId = _scene->_dynamicHotspots.add(NOUN_LADDER, 79, -1, Common::Rect(241, 68, 241 + 12, 68 + 54));
				_scene->_dynamicHotspots.setPosition(_ladderHotspotId, Common::Point(246, 124), FACING_NORTH);
				_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 6, 1, 0, 0);
				_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 1);
				_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
				break;
			case 1: {
				_globals._sequenceIndexes[9] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], true, 1);
				_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
				_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
				_scene->_sequences.updateTimeout(_globals._sequenceIndexes[8], _globals._sequenceIndexes[9]);
				_ladderTopFl = true;
				_game._player._stepEnabled = true;
				int msgIndex = _scene->_kernelMessages.add(Common::Point(248, 15), 0x1110, 32, 0, 60, _game.getQuote(97));
				_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
				}
				break;
			default:
				_action._inProgress = false;
				return;
			}
		} else if (((_action.isAction(VERB_LOOK, 0x27, 0x82)) || (_action.isAction(VERB_LOOK, 0x27, 0x1B6))) && (_globals[kSexOfRex] == SEX_MALE)) {
			if (!_ladderTopFl) {
				switch (_game._trigger) {
				case 0:
					_game._player._stepEnabled = false;
					_game._player._visible= false;
					_globals._sequenceIndexes[10] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[9], false, 6, 1, 0, 0);
					_scene->_sequences.setAnimRange(_globals._sequenceIndexes[10], 1, 6);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[10], Common::Point(172, 123));
					_scene->_sequences.setDepth(_globals._sequenceIndexes[10], 1);
					_scene->_sequences.updateTimeout(-1, _globals._sequenceIndexes[10]);
					_scene->_sequences.addSubEntry(_globals._sequenceIndexes[10], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
					break;
				case 1:
					_globals._sequenceIndexes[10] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], false, 6);
					_scene->_sequences.setDepth(_globals._sequenceIndexes[10], 1);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[10], Common::Point(172, 123));
					if (_scene->_activeAnimation) {
						_waitingMeteoFl = true;
						_globals[kMeteorologistWatch] = 1;
					} else {
						_scene->_sequences.addTimer(120, 2);
					}
					break;
				case 2:
					if (!_scene->_activeAnimation && !_meteorologistSpecial) {
						_vm->_dialogs->show(0x4EFE);
					}
					_scene->_sequences.remove(_globals._sequenceIndexes[10]);
					_globals._sequenceIndexes[10] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[9], false, 6, 1, 0, 0);
					_scene->_sequences.setDepth(_globals._sequenceIndexes[10], 1);
					_scene->_sequences.setAnimRange(_globals._sequenceIndexes[10], 1, 6);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[10], Common::Point(172, 123));
					_scene->_sequences.addSubEntry(_globals._sequenceIndexes[10], SEQUENCE_TRIGGER_EXPIRE, 0, 3);
					break;
				case 3:
					_scene->_sequences.updateTimeout(-1, _globals._sequenceIndexes[10]);
					_game._player._stepEnabled = true;
					_game._player._visible = true;
					break;
				default:
					_action._inProgress = false;
					return;
				}
			} else {
				switch (_game._trigger) {
				case 0:
					_toTeleportFl = true;
					_game._player._stepEnabled = false;
					_scene->_sequences.remove(_globals._sequenceIndexes[9]);
					_globals._sequenceIndexes[9] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[9], true, 6, 1, 0, 0);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
					_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
					_scene->_sequences.addSubEntry(_globals._sequenceIndexes[9], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
					break;
				case 1:
					_globals._sequenceIndexes[10] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], true, -2);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[10], Common::Point(247, 82));
					_scene->_sequences.setDepth(_globals._sequenceIndexes[10], 1);
					if (_scene->_activeAnimation) {
						if (_scene->_activeAnimation->getCurrentFrame() > 200) {
							_scene->_sequences.addTimer(120, 2);
						} else {
							_waitingMeteoFl = true;
							_globals[kMeteorologistWatch] = 2;
							if ((_scene->_activeAnimation->getCurrentFrame() >= 44) && (_scene->_activeAnimation->getCurrentFrame() <= 75)) {
								_scene->_kernelMessages.reset();
								int msgIndex = _scene->_kernelMessages.add(Common::Point(248, 15), 0x1110, 32, 0, 60, _game.getQuote(100));
								_scene->_kernelMessages.setQuoted(msgIndex, 4, false);
							} else {
								_action._inProgress = false;
								return;
							}
						}
					} else {
						_scene->_sequences.addTimer(120, 2);
					}
					break;
				case 2:
					if (!_scene->_activeAnimation)
						_vm->_dialogs->show(0x4EFE);
					_meteorologistSpecial = 0;
					_scene->_sequences.remove(_globals._sequenceIndexes[10]);
					_globals._sequenceIndexes[9] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[9], false, 6, 1, 0, 0);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
					_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
					_scene->_sequences.addSubEntry(_globals._sequenceIndexes[9], SEQUENCE_TRIGGER_EXPIRE, 0, 3);
					break;
				case 3:
					_globals._sequenceIndexes[9] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], true, 1);
					_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(247, 82));
					_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 1);
					_game._player._stepEnabled = true;
					break;
				default:
					_action._inProgress = false;
					return;
				}
			}
		} else if (_action.isAction(0x188, 0xAA)) {
			setRandomKernelMessage();
		} else if (_action.isAction(VERB_LOOK, 0x129)) {
			_vm->_dialogs->show(0x4EEA);
		} else if (_action.isAction(VERB_LOOK, 0x86)) {
			_vm->_dialogs->show(0x4EEB);
		} else if (_action.isAction(VERB_LOOK, 0x19C)) {
			_vm->_dialogs->show(0x4EEC);
		} else if (_action.isAction(VERB_LOOK, 0x82)) {
			if ((_globals[kMeteorologistStatus] == 0) || (_globals[kMeteorologistStatus] == 2)) {
				_vm->_dialogs->show(0x4EED);
			} else if (_globals[kMeteorologistStatus] == 1) {
				_vm->_dialogs->show(0x4EFC);
			} else {
				_action._inProgress = false;
				return;
			}
		} else if (_action.isAction(VERB_LOOK, 0x18E)) {
			_vm->_dialogs->show(0x4EEE);
		} else if (_action.isAction(VERB_LOOK, 0x164)) {
			_vm->_dialogs->show(0x4EEF);
		} else if (_action.isAction(VERB_LOOK, 0x175)) {
			_vm->_dialogs->show(0x4EF0);
		} else if (_action.isAction(VERB_LOOK, 0x174)) {
			_vm->_dialogs->show(0x4EF1);
		} else if (_action.isAction(VERB_LOOK, 0x142)) {
			_vm->_dialogs->show(0x4EF2);
		} else if (_action.isAction(VERB_LOOK, 0xAA)) {
			if ((_game._player._playerPos == Common::Point(77, 105)) && (_game._player._facing == FACING_NORTH))
				_vm->_dialogs->show(0x4EF4);
			else
				_vm->_dialogs->show(0x4EF3);
		} else if (_action.isAction(VERB_LOOK, 0x186)) {
			_vm->_dialogs->show(0x4EF5);
		} else if (_action.isAction(VERB_LOOK, 0x1B5)) {
			_vm->_dialogs->show(0x4EF6);
		} else if (_action.isAction(VERB_LOOK, 0x140)) {
			_vm->_dialogs->show(0x4EF7);
		} else if (_action.isAction(VERB_TAKE, 0x140)) {
			_vm->_dialogs->show(0x4EF8);
		} else if (_action.isAction(VERB_LOOK, 0x2D)) {
			if (_action._commandSource == 4)
				_vm->_dialogs->show(0x4EF9);
			else
				return;
		} else {
			return;
		}
	} else {
		_vm->_dialogs->show(0x4EFB);
	}
	_action._inProgress = false;
}

void Scene202::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_activeMsgFl);
	s.syncAsByte(_ladderTopFl);
	s.syncAsByte(_waitingMeteoFl);
	s.syncAsByte(_toStationFl);
	s.syncAsByte(_toTeleportFl);

	s.syncAsSint32LE(_ladderHotspotId);
	s.syncAsSint32LE(_lastRoute);
	s.syncAsSint32LE(_stationCounter);
	s.syncAsSint32LE(_meteoFrame);

	s.syncAsUint32LE(_meteoClock1);
	s.syncAsUint32LE(_meteoClock2);
	s.syncAsUint32LE(_startTime);

	s.syncAsSint32LE(_meteorologistSpecial);
}

/*****************************************************************************/

void Scene203::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(477);
}

void Scene203::enter() {
	if (_scene->_priorSceneId == 202) {
		_game._player._playerPos = Common::Point(187, 99);
		_game._player._facing = FACING_SOUTH;
	} else if (_scene->_priorSceneId == 209) {
		_game._player._playerPos = Common::Point(308, 117);
		_game._player._facing = FACING_WEST;
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(155, 152);
		_game._player._facing = FACING_NORTH;
	}

	_rhotundaEatFl = false;
	_rhotundaEat2Fl = false;

	if ((_globals[kRhotundaStatus] == 0) && (!_scene->_roomChanged)) {
		_rhotundaEatFl = true;
		_game._player.walk(Common::Point(158, 135), FACING_SOUTH);
		int idx = _scene->_dynamicHotspots.add(131, 396, 0, Common::Rect(0, 0, 320, 156));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(155, 152), FACING_SOUTH);
		_scene->_dynamicHotspots.setCursor(idx, CURSOR_GO_DOWN);
	}

	if (!_rhotundaEatFl) {
		_globals._spriteIndexes[0] = _scene->_sprites.addSprites(formAnimName('b', -1));
		if (_vm->getRandomNumber(1, 3) == 2) {
			_globals._spriteIndexes[15] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[0], false, 9, 1, 0, 0);
			int idx = _scene->_dynamicHotspots.add(477, 209, _globals._spriteIndexes[15], Common::Rect(0, 0, 0, 0));
			_scene->_dynamicHotspots.setPosition(idx, Common::Point(-2, 0), FACING_NONE);
			_vm->_sound->command(14);
		}
	}

	_game.loadQuoteSet(0x67, 0x68, 0x69, 0x6A, 0x5A, 0);

	if (_rhotundaEatFl) {
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(_vm->getRandomNumber(103, 106)));
	}

	sceneEntrySound();
}

void Scene203::step() {
	if (!_rhotundaEatFl)
		return;

	if ((_game._trigger == 0) && _rhotundaEat2Fl)
		return;

	if ((_game._player._playerPos != Common::Point(158, 136)) || (_game._player._facing != FACING_SOUTH))
		return;

	_rhotundaEat2Fl = true;

	if (_game._trigger == 0) {
		_game._player._visible = false;
		_game._player._stepEnabled = false;
		_vm->_palette->lock();
		_scene->_kernelMessages.reset();
		_scene->resetScene();
		_vm->_events->setCursor2(CURSOR_WAIT);
		_scene->loadAnimation(Resources::formatName(203, 'a', -1, EXT_AA, ""), 81);
	} else if (_game._trigger == 81) {
		_scene->_nextSceneId = 208;
		_scene->_reloadSceneFlag = true;
	}
}

void Scene203::preActions() {
	if (_rhotundaEatFl && !_action.isAction(VERB_WALK_TOWARDS, 0x83)) {
		_game._player.walk(Common::Point(158, 136), FACING_SOUTH);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_WALKTO, 0xF3))
		_game._player._walkOffScreenSceneId = 209;
}

void Scene203::actions() {
	if (_action._savedFields._lookFlag) {
		_vm->_dialogs->show(0x4F53);
	} else if (_action.isAction(VERB_WALK_TOWARDS, 0x83)) {
		_scene->_nextSceneId = 208;
	} else if (_action.isAction(VERB_WALK_TOWARDS, 0x82)) {
		_scene->_nextSceneId = 202;
	} else if (_action.isAction(VERB_LOOK, 0x142)) {
		_vm->_dialogs->show(0x4F4D);
	} else if (_action.isAction(VERB_LOOK, 0x4D)) {
		_vm->_dialogs->show(0x4F4E);
	} else if (_action.isAction(VERB_LOOK, 0x100)) {
		_vm->_dialogs->show(0x4F4F);
	} else if (_action.isAction(VERB_LOOK, 0x82)) {
		_vm->_dialogs->show(0x4F50);
	} else if (_action.isAction(VERB_LOOK, 0x1A6)) {
		_vm->_dialogs->show(0x4F51);
	} else if (_action.isAction(VERB_LOOK, 0x30)) {
		_vm->_dialogs->show(0x4F51);
	} else
		return;

	_action._inProgress = false;
}

void Scene203::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_rhotundaEat2Fl);
	s.syncAsByte(_rhotundaEatFl);
}

/*****************************************************************************/

void Scene205::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(VERB_WALKTO);
	_scene->addActiveVocab(NOUN_CHICKEN);
	_scene->addActiveVocab(NOUN_PIRANHA);
}

void Scene205::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('x', 0));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('x', 1));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('x', 2));
	_globals._spriteIndexes[5] = _scene->_sprites.addSprites(formAnimName('f', -1));
	_globals._spriteIndexes[4] = _scene->_sprites.addSprites(formAnimName('c', -1));
	_globals._spriteIndexes[6] = _scene->_sprites.addSprites(formAnimName('p', -1));

	if (_globals[kSexOfRex] == SEX_MALE)
		_globals._spriteIndexes[8] = _scene->_sprites.addSprites(formAnimName('a', 1));

	_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 10, 0, 0, 3);
	int idx = _scene->_dynamicHotspots.add(73, 13, _globals._sequenceIndexes[1], Common::Rect(0, 0, 0, 0));
	_scene->_dynamicHotspots.setPosition(idx, Common::Point(162, 120), FACING_NORTHEAST);

	_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 15, 0, 0, 0);
	idx = _scene->_dynamicHotspots.add(73, 13, _globals._sequenceIndexes[1], Common::Rect(0, 0, 0, 0));
	_scene->_dynamicHotspots.setPosition(idx, Common::Point(162, 120), FACING_NORTHEAST);

	_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 9, 0, 0, 0);
	_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 6, 0, 0, 0);
	_scene->_sequences.setDepth(_globals._sequenceIndexes[5], 11);

	if (!_game._visitedScenes._sceneRevisited) {
		_lastFishTime = _scene->_frameStartTime;
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 7, 1, 0, 0);
		idx = _scene->_dynamicHotspots.add(269, 13, _globals._sequenceIndexes[6], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(49, 86), FACING_NORTH);
	}

	if (_game._objects[12]._roomNumber == 205) {
		_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 7, 0, 0, 0);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[4], 11);
	} else {
		_scene->_hotspots.activate(450, false);
	}

	_beingKicked = false;
	_game.loadQuoteSet(0x6B, 0x70, 0x71, 0x72, 0x5A, 0x74, 0x75, 0x76, 0x77, 0x78, 0x73, 0x79, 0x7A, 0x7B, 0x7C,
		0x7D, 0x7E, 0x7F, 0x80, 0xAC, 0xAD, 0xAE, 0x6C, 0x6D, 0x6E, 0x6F, 0x2, 0);
	_dialog1.setup(0x2A, 0x5A, 0x78, 0x74, 0x75, 0x76, 0x77, 0);

	if (!_game._visitedScenes._sceneRevisited)
		_dialog1.set(0x5A, 0x74, 0x75, 0x77, 0);

	_vm->_palette->setEntry(250, 63, 50, 20);
	_vm->_palette->setEntry(251, 50, 40, 15);
	_vm->_palette->setEntry(252, 63, 63, 40);
	_vm->_palette->setEntry(253, 50, 50, 30);

	_chickenTime = _vm->_game->_scene._frameStartTime;

	if (_globals[kSexOfRex] == SEX_FEMALE)
		warning("sub71704(0x3, 0xC3, 0x108, 0x63, 0x86, 0xD, 2, 0xFDFC, 0x3C, 0x6C, 0x6C, 0x6D, 0x6D, 0x6E, 0x6E, 0x6F, 0x6C, 0);");

	if (_scene->_priorSceneId != -2)
		_game._player._playerPos = Common::Point(99, 152);

	if (_globals[kSexOfRex] != SEX_MALE) {
		_scene->loadAnimation(formAnimName('a', -1), 0);
		_scene->_activeAnimation->_resetFlag = false;
	} else {
		_beingKicked = true;
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 1, 0, 0);
		_game._player._visible = false;
		_game._player._stepEnabled = false;
		_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 2);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_SPRITE, 6, 73);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_SPRITE, 11, 74);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 0);
	}
	sceneEntrySound();
}

void Scene205::step() {
	if (_globals[kSexOfRex] == SEX_FEMALE) {
		warning("TODO: sub7178C()");

		if (_vm->_game->_scene._frameStartTime >= _chickenTime) {
			warning("TODO: if (sub717B2(100, 1 + sub7176C())) {");
			_vm->_sound->command(28);
			//	 }
			_chickenTime = _vm->_game->_scene._frameStartTime + 2;
		}
	}

	if (_vm->_game->_scene._frameStartTime - _lastFishTime > 1300) {
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(
			_globals._spriteIndexes[6], false, 5, 1, 0, 0);
		int idx = _scene->_dynamicHotspots.add(269, 13, _globals._sequenceIndexes[6],
			Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(49, 86), FACING_NORTH);
		_lastFishTime = _vm->_game->_scene._frameStartTime;
	}

	if (_game._trigger == 73)
		_scene->_kernelMessages.add(Common::Point(160, 68), 0xFBFA, 32, 0, 60, _game.getQuote(112));

	if (_game._trigger == 74) {
		_vm->_sound->command(26);
		_scene->_kernelMessages.add(Common::Point(106, 90), 0x1110, 32, 0, 60, _game.getQuote(113));
	}

	if (_game._trigger == 71) {
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 6, 0, 0, 0);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 2);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[8], -2, -2);
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(160, 68), 0xFBFA, 32, 72, 180, _game.getQuote(114));
	}

	if (_game._trigger == 72)
		_scene->_nextSceneId = 211;
}

void Scene205::handleWomanSpeech(int quote) {
	_kernelMessage = _scene->_kernelMessages.add(Common::Point(186, 27), 0xFBFA, 0, 0, 9999999, _game.getQuote(quote));
}

void Scene205::actions() {
	if (_game._screenObjects._inputMode == 1) {
		if (_kernelMessage >= 0)
			_scene->_kernelMessages.remove(_kernelMessage);
		_kernelMessage = -1;

		if (_game._trigger == 0) {
			_game._player._stepEnabled = false;
			_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 18, 1, 120, _game.getQuote(_action._activeAction._verbId));
		} else {
			if ((_game._trigger > 1) || (_action._activeAction._verbId != 0x76))
				_game._player._stepEnabled = true;

			switch (_action._activeAction._verbId) {
			case 0x5A:
				handleWomanSpeech(0x7A);
				_dialog1.write(0x78, true);
				_dialog1.write(0x5A, false);
				break;

			case 0x74:
				handleWomanSpeech(0x7C);
				_dialog1.write(0x74, false);
				_dialog1.write(0x76, true);
				break;

			case 0x75:
			case 0x78:
				handleWomanSpeech(0x7B);
				_dialog1.write(_action._activeAction._verbId, false);
				_vm->_dialogs->show(20501);
				break;

			case 0x76:
				if (_game._trigger == 1) {
					handleWomanSpeech(0x7D);
					_scene->_sequences.addTimer(120, 2);
				} else if (_game._trigger == 2) {
					handleWomanSpeech(0x7E);
					_dialog1.write(0x76, false);
					_globals[kChickenPermitted] = true;
				}
				break;

			case 0x77:
				_scene->_kernelMessages.add(Common::Point(186, 27), 0xFBFA, 0, 0, 120, _game.getQuote(0x7F));
				_scene->_userInterface.setup(kInputBuildingSentences);
				break;

			default:
				break;
			}

			if (_action._activeAction._verbId != 0x77)
				_dialog1.start();
		}
	} else if (_action._lookFlag)
		_vm->_dialogs->show(20502);
	else if (_action.isAction(VERB_LOOK, 0x27, 0x1C8))
		_vm->_dialogs->show(20518);
	else if (_action.isAction(VERB_TALKTO, 0x1DC)) {
		if (_game._trigger == 0) {
			_game._player._stepEnabled = false;
			_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 18, 1, 120, _game.getQuote(0x73));
		} else if (_game._trigger == 1) {
			_game._player._stepEnabled = true;
			handleWomanSpeech (0x79);
			_dialog1.write(0x5A, true);
			_dialog1.write(0x75, true);
			_dialog1.start();
		}
	} else if (_action.isAction(VERB_GIVE, 0x1DC) && _game._objects.isInInventory(_game._objects.getIdFromDesc(_action._activeAction._objectNameId))) {
		if (_game._trigger == 0) {
			_game._player._stepEnabled = false;
			int rndVal = _vm->getRandomNumber(0xAC, 0xAE);
			_scene->_kernelMessages.add(Common::Point(186, 27), 0xFBFA, 32, 1, 120, _game.getQuote(rndVal));
		} else if (_game._trigger == 1)
			_game._player._stepEnabled = true;
	} else if (_action.isAction(VERB_WALKTO, 0x1C8)) {
		if (_game._trigger == 0) {
			_game._player._visible   = false;
			_game._player._stepEnabled = false;
			_vm->_palette->lock();
			_scene->_kernelMessages.reset();
			warning("TODO: sub70402();");

			_globals._spriteIndexes[9] = _scene->_sprites.addSprites(formAnimName('a', 0));
			_vm->_palette->refreshSceneColors();
			_globals._sequenceIndexes[9] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[9], false, 6, 1, 0, 0);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[9], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[9], -1);
			_vm->_sound->command(27);
		} else if (_game._trigger == 1) {
			if (_scene->_activeAnimation != nullptr)
				warning("scene->_activeAnimation._spriteSetsCount = 0;");

			_vm->_dialogs->show(20516);
			_scene->_reloadSceneFlag = true;
		}
	} else {
		if (_action.isAction(0x1AD, 0x1C7))
			_scene->_nextSceneId = 210;

		if (_action.isAction(VERB_WALKTO, 0x86) || _action.isAction(VERB_WALKTO, 0x1C2)) {
			if (_game._objects.isInRoom(OBJ_CHICKEN)) {
				_scene->_kernelMessages.reset();
				_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(0x6B));
			}
		} else if (_action.isAction(VERB_TAKE, 0x1C2) && _globals[kChickenPermitted] && _game._objects.isInRoom(OBJ_CHICKEN)) {
			_game._objects.addToInventory(OBJ_CHICKEN);
			_scene->_sequences.remove(_globals._sequenceIndexes[4]);
			_scene->_hotspots.activate(0x1C2, false);
			_vm->_dialogs->showItem(OBJ_CHICKEN, 812);
		} else if (_action.isAction(VERB_TAKE, 0x1C2) && (!_globals[kChickenPermitted]))
			_scene->_kernelMessages.add(Common::Point(186, 27), 0xFBFA, 32, 0, 120, _game.getQuote(0x80));
		else if (_action.isAction(VERB_LOOK, 0x1DC))
			_vm->_dialogs->show(20503);
		else if (_action.isAction(VERB_LOOK, 0xAA))
			_vm->_dialogs->show(20504);
		else if (_action.isAction(VERB_LOOK, 0x49) && (_action._mainObjectSource == 4))
			_vm->_dialogs->show(20505);
		else if (_action.isAction(VERB_TAKE, 0x49) && (_action._mainObjectSource == 4))
			_vm->_dialogs->show(20506);
		else if (_action.isAction(VERB_LOOK, 0x1C2))
			_vm->_dialogs->show(20507);
		else if (_action.isAction(VERB_LOOK, 0x86))
			_vm->_dialogs->show(20508);
		else if (_action.isAction(VERB_TAKE, 0x86))
			_vm->_dialogs->show(20509);
		else if (_action.isAction(VERB_LOOK, 0x1C5))
			_vm->_dialogs->show(20510);
		else if (_action.isAction(VERB_LOOK, 0x1C8))
			_vm->_dialogs->show(20511);
		else if (_game._objects.isInInventory(_game._objects.getIdFromDesc(_action._activeAction._objectNameId))
			&& (   _action.isAction(VERB_GIVE, 0x1C5) || _action.isAction(VERB_THROW, 0x1C5)
			|| _action.isAction(VERB_GIVE, 0x10D) || _action.isAction(VERB_THROW, 0x10D)))
				_vm->_dialogs->show(20512);
		else if (_action.isAction(VERB_LOOK, 0x10D))
			_vm->_dialogs->show(20513);
		else if (_action.isAction(VERB_LOOK, 0x1C4))
			_vm->_dialogs->show(20514);
		else if (_action.isAction(VERB_TAKE, 0x1C4))
			_vm->_dialogs->show(20515);
		else if (_action.isAction(VERB_TAKE, 0x1DC))
			_vm->_dialogs->show(20517);
		else
			return;
	}

	_action._inProgress = false;
}

void Scene205::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsUint32LE(_lastFishTime);
	s.syncAsUint32LE(_chickenTime);
	s.syncAsByte(_beingKicked);
	s.syncAsSint16LE(_kernelMessage);

	_dialog1.synchronize(s);
}

/*****************************************************************************/

void Scene207::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(0x185);
	_scene->addActiveVocab(VERB_WALKTO);
	_scene->addActiveVocab(0x14D);
	_scene->addActiveVocab(VERB_WALKTO);
}

void Scene207::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('h', 0));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('h', 1));
	_globals._spriteIndexes[4] = _scene->_sprites.addSprites(formAnimName('c', -1));
	_globals._spriteIndexes[5] = _scene->_sprites.addSprites(formAnimName('e', 0));
	_globals._spriteIndexes[6] = _scene->_sprites.addSprites(formAnimName('e', 1));
	_globals._spriteIndexes[7] = _scene->_sprites.addSprites(formAnimName('g', 1));
	_globals._spriteIndexes[8] = _scene->_sprites.addSprites(formAnimName('g', 0));
	_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 7, 0, 0, 0);
	_scene->_sequences.setDepth(_globals._sequenceIndexes[5], 7);

	int var2;
	if (!_game._visitedScenes._sceneRevisited) {
		var2 = 1;
	} else {
		var2 = _vm->getRandomNumber(4) + 1;
	}

	if (var2 > 2)
		_vultureFl = false;
	else
		_vultureFl = true;

	_spiderFl = (var2 & 1);

	if (_vultureFl) {
		_globals._sequenceIndexes[1] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[1], false, 30, 0, 0, 400);
		_vultureTime = _game._player._priorTimer;
		_vultureHotspotId = _scene->_dynamicHotspots.add(389, 13, _globals._sequenceIndexes[1], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(_vultureHotspotId, Common::Point(254, 94), FACING_WEST);
	}

	if (_spiderFl) {
		_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 7, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], -1, -1);
		_spiderTime = _game._player._priorTimer;
		_spiderHotspotId = _scene->_dynamicHotspots.add(333, 13, _globals._sequenceIndexes[4], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(_spiderHotspotId, Common::Point(59, 132), FACING_SOUTH);
	}

	_eyeFl = false;
	if (_scene->_priorSceneId == 211) {
		_game._player._playerPos = Common::Point(13, 105);
		_game._player._facing = FACING_EAST;
	} else if (_scene->_priorSceneId == 214) {
		_game._player._playerPos = Common::Point(164, 117);
		_game._player._facing = FACING_SOUTH;
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(305, 131);
	}

	_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 10, 1, 0, 0);
	_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], 1, 22);
	_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 6);
	_scene->_sequences.addSubEntry(_globals._sequenceIndexes[6], SEQUENCE_TRIGGER_EXPIRE, 0, 70);
}

void Scene207::moveVulture() {
	_scene->_sequences.remove(_globals._sequenceIndexes[1]);
	_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 7, 1, 0, 0);
	_vm->_sound->command(43);
	_vultureFl = false;
	_vultureTime = _game._player._priorTimer;
	_scene->_dynamicHotspots.remove(_vultureHotspotId);
}

void Scene207::moveSpider() {
	_scene->_sequences.remove(_globals._sequenceIndexes[4]);
	_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 5, 1, 0, 0);
	_spiderFl = false;
	_spiderTime = _game._player._priorTimer;
	_scene->_dynamicHotspots.remove(_spiderHotspotId);
}

void Scene207::step() {
	if (!_vultureFl)
		moveVulture();

	if (_spiderFl)
		moveSpider();

	if (_game._trigger == 70) {
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 10, 0, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], 23, 34);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[6], 6);
	}

	if (_game._trigger == 71)
		_eyeFl = false;

	if (_eyeFl)
		return;

	if ((_game._player._playerPos.x >= 124) && (_game._player._playerPos.x <= 201)) {
		_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 10, 1, 0, 0);
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 1, 0, 0);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[7], 6);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 6);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_EXPIRE, 0, 71);
		_eyeFl = true;
	}
}

void Scene207::preActions() {
	if (_action.isAction(VERB_WALK_DOWN, 0x1AE))
		_game._player._walkOffScreenSceneId = 211;

	if (_action.isAction(VERB_WALK_TOWARDS, 0x1AB))
		_game._player._walkOffScreenSceneId = 208;

	if ((_action.isAction(VERB_WALKTO)) || (_action.isAction(VERB_LOOK))) {
		if (_action.isAction(0x185)) {
			_vultureTime = -9999;
		} else if (_action.isAction(0x14D)) {
			_spiderTime = -9999;
		}
	}
}

void Scene207::actions() {
	if (_action._savedFields._lookFlag) {
		_vm->_dialogs->show(0x50E7);
	} else if (_action.isAction(VERB_WALK_THROUGH, 0x70)) {
		_scene->_nextSceneId = 214;
	} else {
		if ((_game._player._playerPos.x > 150) && (_game._player._playerPos.x < 189) &&
		    (_game._player._playerPos.y > 111) && (_game._player._playerPos.y < 130)) {
			if ((_game._player._playerPos.x <= 162) && (_game._player._playerPos.x >= 181) &&
			    (_game._player._playerPos.y <= 115) && (_game._player._playerPos.y >= 126)) {
				_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 10, 2, 0, 0);
				_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 2, 0, 0);
				_scene->_sequences.setDepth(_globals._sequenceIndexes[7], 6);
				_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 6);
			}
		} else if (_eyeFl) {
			_scene->_sequences.remove(_globals._sequenceIndexes[7]);
			_scene->_sequences.remove(_globals._sequenceIndexes[8]);
			_eyeFl = false;
		}

		if (_action.isAction(VERB_LOOK, 0x69)) {
			_vm->_dialogs->show(0x50DD);
		} else if (_action.isAction(VERB_LOOK, 0x1AF)) {
			_vm->_dialogs->show(0x50DE);
		} else if (_action.isAction(VERB_LOOK, 0x141)) {
			_vm->_dialogs->show(0x50DF);
		} else if (_action.isAction(VERB_LOOK, 0x3E)) {
			_vm->_dialogs->show(0x50E0);
		} else if (_action.isAction(VERB_LOOK, 0x198)) {
			_vm->_dialogs->show(0x50E1);
		} else if (_action.isAction(VERB_LOOK, 0x1AE)) {
			_vm->_dialogs->show(0x50E2);
		} else if (_action.isAction(VERB_LOOK, 0xE8)) {
			_vm->_dialogs->show(0x50E3);
		} else if (_action.isAction(VERB_LOOK, 0x12)) {
			_vm->_dialogs->show(0x50E4);
		} else if (_action.isAction(VERB_LOOK, 0x1AC)) {
			_vm->_dialogs->show(0x50E5);
		} else if (_action.isAction(VERB_LOOK, 0x185)) {
			_vm->_dialogs->show(0x50E6);
		} else if (_action.isAction(VERB_TAKE, 0x141)) {
			_vm->_dialogs->show(0x50E8);
		} else if (_action.isAction(VERB_TAKE, 0x12)) {
			_vm->_dialogs->show(0x50E9);
		} else if (_action.isAction(VERB_LOOK, 0x14D)) {
			_vm->_dialogs->show(0x50EA);
		} else if (_action.isAction(VERB_TAKE, 0x14D)) {
			_vm->_dialogs->show(0x50EB);
		} else
			return;
	}

	_action._inProgress = false;
}

void Scene207::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_vultureFl);
	s.syncAsByte(_spiderFl);
	s.syncAsByte(_eyeFl);

	s.syncAsSint32LE(_spiderHotspotId);
	s.syncAsSint32LE(_vultureHotspotId);
	s.syncAsSint32LE(_spiderTime);
	s.syncAsSint32LE(_vultureTime);
}

/*****************************************************************************/

void Scene208::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(NOUN_HUGE_LEGS);
	_scene->addActiveVocab(NOUN_LEAF_COVERED_PIT);
	_scene->addActiveVocab(NOUN_PILE_OF_LEAVES);
	_scene->addActiveVocab(VERB_WALKTO);
}

void Scene208::updateTrap() {
	if (_globals[kRhotundaStatus] == 1) {
		_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 8, 0, 0, 24);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 5);
		int idx = _scene->_dynamicHotspots.add(NOUN_HUGE_LEGS, VERB_WALKTO, _globals._sequenceIndexes[1], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(100, 146), FACING_NORTH);
		_scene->_hotspots.activate(414, false);
		return;
	}

	switch (_globals[kLeavesStatus]) {
	case 0: {
		_globals._sequenceIndexes[2] = _scene->_sequences.startCycle(_globals._spriteIndexes[2], false, 1);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 15);
		int idx = _scene->_dynamicHotspots.add(NOUN_PILE_OF_LEAVES, VERB_WALKTO, _globals._sequenceIndexes[2], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(60, 152), FACING_NORTH);
		}
		break;
	case 2: {
		_scene->_sequences.setDepth(_globals._sequenceIndexes[3], 15);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 1);
		_scene->_hotspots.activate(NOUN_DEEP_PIT, false);
		int idx = _scene->_dynamicHotspots.add(NOUN_LEAF_COVERED_PIT, VERB_WALKTO, _globals._sequenceIndexes[2], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(100, 146), FACING_NORTH);
		_scene->_dynamicHotspots[idx]._articleNumber = PREP_ON;
		}
		break;
	}
}

void Scene208::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('a', 1));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('x', 0));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('x', 1));
	_globals._spriteIndexes[4] = _scene->_sprites.addSprites(formAnimName('x', 2));
	_globals._spriteIndexes[5] = _scene->_sprites.addSprites("*RXMBD_8");

	updateTrap();

	_rhotundaTurnFl = false;
	_boundingFl = false;
	_scene->_kernelMessages._talkFont = _vm->_font->getFont(FONT_INTERFACE);
	_scene->_textSpacing = 0;

	if (_scene->_priorSceneId == 207) {
		_game._player._playerPos = Common::Point(8, 122);
		_game._player._facing = FACING_EAST;
	} else if (_scene->_priorSceneId == 203) {
		_game._player._playerPos = Common::Point(142, 108);
		_game._player._facing = FACING_SOUTH;
	} else if (_scene->_priorSceneId == 209) {
		_game._player._playerPos = Common::Point(307, 123);
		_game._player._facing = FACING_WEST;
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(162, 149);
		_game._player._facing = FACING_NORTH;
	}

	_game.loadQuoteSet(0x81, 0x46, 0);

	if ((_scene->_priorSceneId == 207) && (_globals[kMonkeyStatus] == MONKEY_HAS_BINOCULARS)) {
		int msgIndex = _scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(129));
		_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
	}

	_vm->_palette->setEntry(16, 0, 0, 63);
	_vm->_palette->setEntry(17, 0, 0, 45);
	sceneEntrySound();
}

void Scene208::step() {
	if (_boundingFl && (_rhotundaTime <= _scene->_activeAnimation->getCurrentFrame())) {
		_rhotundaTime = _scene->_activeAnimation->getCurrentFrame();

		if (_rhotundaTime == 125)
			_scene->_sequences.remove(_globals._sequenceIndexes[4]);
	}

	if (!_rhotundaTurnFl)
		return;

	if ((_game._player._playerPos != Common::Point(20, 148)) || (_game._player._facing != FACING_EAST))
		return;

	if ((_game._trigger == 0) && _boundingFl)
		return;

	_boundingFl = true;

	switch (_game._trigger) {
	case 0:
		_scene->loadAnimation(formAnimName('A', -1), 81);
		_rhotundaTime = 0;
		break;
	case 81:
		_scene->_sequences.remove(_globals._spriteIndexes[15]);
		_globals[kRhotundaStatus] = 1;
		updateTrap();
		_scene->_sequences.addTimer(90, 82);
		break;
	case 82:
		_game._player._stepEnabled = true;
		break;
	}
}

void Scene208::preActions() {
	Player &player = _vm->_game->_player;

	if (_action.isAction(VERB_LOOK) && player._readyToWalk)
		player._needToWalk = true;

	if (_action.isAction(VERB_WALK_TOWARDS, 0x9B))
		player._walkOffScreenSceneId = 209;

	if (_action.isAction(VERB_WALK_TOWARDS, 0xF6))
		player._walkOffScreenSceneId = 207;
}

void Scene208::subAction(int mode) {

	switch (_game._trigger) {
	case 0: {
		_game._player._stepEnabled = false;
		_game._player._visible = false;
		_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 6, 1, 0, 0);
		_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[5]);

		int abortVal;
		if ((mode == 1) || (mode == 2))
			abortVal = 1;
		else
			abortVal = 2;

		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[5], SEQUENCE_TRIGGER_EXPIRE, 0, abortVal);
		}
		break;
	case 1: {
		int oldVal = _globals._sequenceIndexes[5];
		_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 12, 3, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[5], 3, 4);
		_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[5]);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[5], oldVal);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[5], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
		_vm->_sound->command(20);
		}
		break;
	case 2: {
		switch (mode) {
		case 1:
			_game._objects.addToInventory(OBJ_BIG_LEAVES);
			_scene->_sequences.remove(_globals._sequenceIndexes[2]);
			_globals[kLeavesStatus] = 1;
			break;
		case 2:
			_game._objects.setRoom(OBJ_BIG_LEAVES, 1);
			_globals[kLeavesStatus] = 2;
			updateTrap();
			break;
		case 3:
			_scene->_sequences.remove(_globals._sequenceIndexes[3]);
			_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 1);
			_game._objects.removeFromInventory(OBJ_TWINKIFRUIT, 1);
			_vm->_sound->command(34);
			break;
		case 4:
			_game._objects.removeFromInventory(OBJ_BURGER, 1);
			_vm->_sound->command(33);
			break;
		case 5:
			_game._objects.removeFromInventory(OBJ_DEAD_FISH, 1);
			_vm->_sound->command(33);
			break;
		}

		int oldVal = _globals._sequenceIndexes[5];
		_globals._sequenceIndexes[5] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[5], false, 6, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[5], 1, 3);
		_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[5]);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[5], oldVal);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[5], SEQUENCE_TRIGGER_EXPIRE, 0, 3);
		}
		break;
	case 3:
		_game._player._visible = true;
		_game._player._stepEnabled = true;
		break;
	}
}

void Scene208::actions() {
	if (_action.isAction(VERB_WALK_TOWARDS, 0x19F)) {
		if (_globals[kRhotundaStatus])
			_scene->_nextSceneId = 203;
		else if (_game._trigger == 0) {
			_game._player._stepEnabled = false;
			int msgIndex = _scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 1, 120, _game.getQuote(70));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
		} else if (_game._trigger == 1) {
			_scene->_nextSceneId = 203;
		}
	} else if (_action.isAction(VERB_WALK_TOWARDS, 0x83)) {
		_scene->_nextSceneId = 212;
	} else if (_action.isAction(VERB_TAKE, NOUN_PILE_OF_LEAVES) && (!_globals[kLeavesStatus] || _game._trigger)) {
		subAction(1);
		if (_game._player._stepEnabled)
			_vm->_dialogs->showItem(OBJ_BIG_LEAVES, 0x326, 0);
	} else if (_action.isAction(VERB_PUT, NOUN_BIG_LEAVES, NOUN_DEEP_PIT) && (_globals[kLeavesStatus] == 1 || _game._trigger)) {
		subAction(2);
	} else if (_action.isAction(VERB_PUT, NOUN_TWINKIFRUIT, NOUN_LEAF_COVERED_PIT)) {
		subAction(3);
		if (_game._player._stepEnabled) {
			_game._player._stepEnabled = false;
			_rhotundaTurnFl = true;
			_game._player.walk(Common::Point(20, 148), FACING_EAST);
		}
	} else if (_action.isAction(VERB_PUT, NOUN_BURGER, NOUN_LEAF_COVERED_PIT)) {
		subAction(4);
		if (_game._player._stepEnabled) {
			_vm->_dialogs->show(0x514C);
		}
	} else if (_action.isAction(VERB_PUT, NOUN_DEAD_FISH, NOUN_LEAF_COVERED_PIT)) {
		subAction(5);
		if (_game._player._stepEnabled) {
			_vm->_dialogs->show(0x514C);
		}
	} else if (_action.isAction(VERB_LOOK, 0x5D)) {
		_vm->_dialogs->show(0x5141);
	} else if (_action.isAction(VERB_LOOK, 0xF6)) {
		_vm->_dialogs->show(0x5142);
	} else if (_action.isAction(VERB_LOOK, 0x16F)) {
		_vm->_dialogs->show(0x5143);
	} else if (_action.isAction(VERB_LOOK, 0x129)) {
		_vm->_dialogs->show(0x5144);
	} else if (_action.isAction(VERB_LOOK, 0x1A1)) {
		_vm->_dialogs->show(0x5145);
	} else if (_action.isAction(VERB_TAKE, 0x1A1)) {
		_vm->_dialogs->show(0x5146);
	} else if (_action.isAction(VERB_LOOK, 0x9B)) {
		_vm->_dialogs->show(0x5147);
	} else if (_action.isAction(VERB_LOOK, NOUN_DEEP_PIT)) {
		_vm->_dialogs->show(0x5148);
	} else if (_action.isAction(VERB_LOOK, NOUN_PILE_OF_LEAVES)) {
		_vm->_dialogs->show(0x5149);
	} else if (_action.isAction(VERB_LOOK, NOUN_LEAF_COVERED_PIT)) {
		if (_game._difficulty == DIFFICULTY_EASY)
			_vm->_dialogs->show(0x514A);
		else
			_vm->_dialogs->show(0x514B);
	} else if (_action.isAction(VERB_LOOK, 0x174) || _action.isAction(VERB_LOOK, 0x175)) {
		_vm->_dialogs->show(0x514D);
	} else if (_action.isAction(VERB_TAKE, NOUN_LEAF_COVERED_PIT)) {
		_vm->_dialogs->show(0x514E);
	} else if (_action.isAction(VERB_LOOK, NOUN_HUGE_LEGS)) {
		_vm->_dialogs->show(0x514F);
	} else if (_action.isAction(VERB_TAKE, NOUN_HUGE_LEGS) || _action.isAction(VERB_PULL, NOUN_HUGE_LEGS)) {
		_vm->_dialogs->show(0x5150);
	} else if (_action._savedFields._lookFlag == 0) {
		return;
	} else if (_globals[kRhotundaStatus] == 1) {
		_vm->_dialogs->show(0x5153);
	} else if (_globals[kLeavesStatus] == 2) {
		_vm->_dialogs->show(0x5152);
	} else {
		_vm->_dialogs->show(0x5151);
	}

	_action._inProgress = false;
}

void Scene208::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_rhotundaTurnFl);
	s.syncAsByte(_boundingFl);

	s.syncAsSint32LE(_rhotundaTime);
}

/*****************************************************************************/

void Scene209::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(0x10F);
}

void Scene209::handlePause() {
	switch (_game._trigger) {
	case 124:
		if (++_pauseCounter <= _pauseCounterThreshold)
			_scene->_sequences.addTimer(60, 124);
		else
			_pauseMode = 0;
		break;
	}
}

void Scene209::initPauseCounterThreshold() {
	switch (_game._trigger) {
	case 226:
		_scene->_sequences.addTimer(1, 124);
		_pauseCounterThreshold = _vm->getRandomNumber(7,12);
		_pauseMode = 2;
		_pauseCounter = 0;
		break;
	}
}

void Scene209::handlePeek() {
	switch (_game._trigger) {
	case 133:
		_vm->_sound->command(18);
		_globals._sequenceIndexes[3] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 51, 52);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 134);
		break;

	case 134: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(60, 135);
		}
		break;

	case 135:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 7);
		_scene->_sequences.addTimer(10, 136);
		break;

	case 136:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.addTimer(50, 137);
		break;

	case 137:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 51, 52);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 138);
		break;

	case 138:
		_pauseMode = 1;
		_scene->_hotspots.activate(227, false);
		_playingAnimFl = false;
		break;
	}
}

void Scene209::handleVerticalMove() {
	switch (_game._trigger) {
	case 140:
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 8, 8, 0, 1);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 1, 5);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 141);
		break;

	case 141: {
		_vm->_sound->command(18);
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 5);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(60, 142);
		}
		break;

	case 142:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 1, 5);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 143);
		break;

	case 143:
		_pauseMode = 1;
		_playingAnimFl = false;
		_scene->_hotspots.activate(227, false);
		break;
	}
}

void Scene209::handleLookStay() {
	switch (_game._trigger) {
	case 145:
		_vm->_sound->command(18);
		_monkeyPosition = 2;
		_globals._sequenceIndexes[3] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 51, 52);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 146);
		break;

	case 146: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(15, 147);
		}
		break;

	case 147:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 7);
		_scene->_sequences.addTimer(8, 148);
		break;

	case 148:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);

		if (!_dodgeFl) {
			_scene->_sequences.addTimer(90, 149);
		} else {
			_scene->_sequences.addTimer(1, 149);
			_shouldDodgeFl = true;
		}
		break;

	case 149:
		_playingAnimFl = false;
		break;
	}
}

void Scene209::handleLookRight() {
	switch (_game._trigger) {
	case 151:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 8, 2, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 8, 14);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 152);
		break;

	case 152: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(60, 153);
		}
		break;

	case 153:
		_playingAnimFl = false;
		if (_dodgeFl)
			_shouldDodgeFl = true;
		break;
	}
}

void Scene209::handleBlink() {
	switch (_game._trigger) {
	case 155:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.addTimer(50, 156);
		break;

	case 156:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 7);
		_scene->_sequences.addTimer(10, 157);
		break;

	case 157:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.addTimer(50, 158);
		break;

	case 158:
		_playingAnimFl = false;
		if (_dodgeFl)
			_shouldDodgeFl = true;
		break;
	}
}

void Scene209::handleGetBinoculars() {
	switch (_game._trigger) {
	case 161:
		_vm->_sound->command(18);
		_monkeyPosition = 3;
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 8, 24);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_SPRITE, 20, 165);
		if (!_fallFl && !_dodgeFl) {
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 162);
		} else {
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 163);
		}
		break;

	case 162: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 8, 6, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 23, 25);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 163);
		}
		break;

	case 163: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 8, 0, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 23, 24);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(8, 164);
		}
		break;

	case 164:
		_playingAnimFl = false;
		if (_fallFl)
			_shouldFallFl = true;
		break;

	case 165:
		_vm->_sound->command(18);
		break;
	}
}

void Scene209::handleBinocularBlink() {
	switch (_game._trigger) {
	case 167: {
		int oldIdx = _globals._sequenceIndexes[3];
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 8, 2, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 23, 25);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 168);
		}
		break;

	case 168: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 8, 0, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 23, 24);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(30, 169);
		}
		break;

	case 169:
		_playingAnimFl = false;
		if (_fallFl)
			_shouldFallFl = true;
		break;
	}
}

void Scene209::handleBinocularScan() {
	switch (_game._trigger) {
	case 171: {
		int oldIdx = _globals._sequenceIndexes[3];
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 12, 2, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 43, 45);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 172);
		}
		break;

	case 172: {
		int oldIdx = _globals._sequenceIndexes[3];
		int randAction = _vm->getRandomNumber(1,2);
		switch (randAction) {
		case 1:
			_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 12, 2, 0, 0);
			break;
		case 2:
			_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 12, 4, 0, 0);
			break;
		}
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 23, 25);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 173);
		}
		break;

	case 173: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 12, 2, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 26, 30);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 174);
		}
		break;

	case 174: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 12, 0, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 23, 24);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addTimer(60, 175);
		}
		break;

	case 175:
		_playingAnimFl = false;
		if (_fallFl)
			_shouldFallFl = true;
		break;
	}
}

void Scene209::handleJumpInTree() {
	switch (_game._trigger) {
	case 178: {
		int oldIdx = 0;
		_monkeyPosition = 1;
		if (_removeMonkeyFl)
			_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		else
			oldIdx = _globals._sequenceIndexes[3];

		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 46, 49);
		if (!_removeMonkeyFl)
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);

		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 179);
		}
		break;

	case 179: {
		_vm->_sound->command(18);
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 53, 61);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 180);
		}
		break;

	case 180:
		_removeMonkeyFl = true;
		_pauseMode = 1;
		_playingAnimFl = false;
		_scene->_hotspots.activate(227, false);
		break;
	}
}

void Scene209::handleTongue() {
	switch (_game._trigger) {
	case 182: {
		int oldIdx = _globals._sequenceIndexes[3];
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 12, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 26, 30);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 183);
		}
		break;

	case 183: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 12, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 31, 33);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 184);
		}
		break;

	case 184: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 12, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 36, 37);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 185);
		}
		break;

	case 185: {
		_vm->_sound->command(18);
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[3], false, 6, 20, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 38, 39);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 186);
		}
		break;

	case 186: {
		int oldIdx = _globals._sequenceIndexes[3];
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 12, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 40, 41);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 178);
		_removeMonkeyFl = false;
		}
		break;
	}
}

void Scene209::handleStandFromPeek() {
	switch (_game._trigger) {
	case 189:
		_monkeyPosition = 4;
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 50);
		_scene->_sequences.addTimer(8, 190);
		break;

	case 190:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_scene->_sequences.addTimer(8, 191);
		break;

	case 191:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[6] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[6], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[6], 1, 5);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[6], SEQUENCE_TRIGGER_EXPIRE, 0, 192);
		break;

	case 192: {
		_vm->_sound->command(18);
		int oldIdx = _globals._sequenceIndexes[6];
		_globals._sequenceIndexes[5] = _scene->_sequences.startCycle(_globals._spriteIndexes[5], false, 1);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[5], oldIdx);
		_scene->_sequences.addTimer(8, 193);
		}
		break;

	case 193:
		_scene->_sequences.remove(_globals._sequenceIndexes[5]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 22);
		_scene->_sequences.addTimer(5, 194);
		break;

	case 194:
		_playingAnimFl = false;
		_counter = 0;
		break;
	}
}

void Scene209::handleStandBlink() {
	switch (_game._trigger) {
	case 246:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 22);
		_scene->_sequences.addTimer(10, 247);
		break;

	case 247:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 23);
		_scene->_sequences.addTimer(8, 248);
		break;

	case 248:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 22);
		_scene->_sequences.addTimer(10, 249);
		break;

	case 249:
		_playingAnimFl = false;
		break;
	}
}

void Scene209::handleJumpAndHide() {
	switch (_game._trigger) {
	case 196:
		_vm->_sound->command(18);
		_monkeyPosition = 1;
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[5] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[5], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[5], 1, 16);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[5], SEQUENCE_TRIGGER_EXPIRE, 0, 197);
		break;

	case 197:
		_pauseMode = 1;
		_scene->_hotspots.activate(227, false);
		_playingAnimFl = false;
		break;
	}
}

void Scene209::handleMonkeyEating() {
	switch (_game._trigger) {
	case 199:
		_vm->_sound->command(18);
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 10, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 1, 14);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 200);
		break;

	case 200: {
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[4], false, 10, 10, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 15, 16);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 201);
		}
		break;

	case 201: {
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 12);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addTimer(20, 202);
		}
		break;

	case 202:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 19);
		_scene->_sequences.addTimer(20, 203);
		break;

	case 203:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 17);
		_scene->_sequences.addTimer(20, 204);
		break;

	case 204:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[4], false, 10, 8, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 18, 19);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 205);
		break;

	case 205: {
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[4], false, 10, 8, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 20, 21);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 206);
		}
		break;

	case 206: {
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 10, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 22, 25);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		if (!_dodgeFl && !_fallFl)
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 207);
		else
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 209);
		}
		break;

	case 207: {
		_vm->_sound->command(18);
		 int msgIndex = _scene->_kernelMessages.add(Common::Point(180, 25), 0xFDFC, 0, 0, 90, _game.getQuote(130));
		 _scene->_kernelMessages.setQuoted(msgIndex, 4, true);

		 int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[4], false, 15, 4, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 26, 27);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 208);
		}
		break;

	case 208: {
		_scene->_kernelMessages.add(Common::Point(180, 39), 0xFDFC, 0, 0, 90, _game.getQuote(131));
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[4], false, 10, 4, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 28, 29);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 209);
		}
		break;

	case 209: {
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 22);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addTimer(1, 210);
		}
		break;

	case 210:
		_playingAnimFl = false;
		break;
	}
}

void Scene209::handleMonkeyFall() {
	switch (_game._trigger) {
	case 219: {
		_vm->_sound->command(25);
		_scene->_sprites.remove(_globals._spriteIndexes[7]);
		_scene->_sprites.remove(_globals._spriteIndexes[6]);
		_scene->_sprites.remove(_globals._spriteIndexes[5]);
		_scene->_sprites.remove(_globals._spriteIndexes[4]);

		_globals._spriteIndexes[8] = _scene->_sprites.addSprites(formAnimName('m', 4));
		_scene->_kernelMessages.add(Common::Point(180, 26), 0xFDFC, 0, 0, 90, _game.getQuote(151));
		_scene->_sequences.addTimer(40, 100);
		_scene->_hotspots.activate(227, false);
		int oldIdx = _globals._sequenceIndexes[3];
		_monkeyPosition = 1;
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[8], 1, 35);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 6);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 220);
		}
		break;

	case 220: {
		_vm->_sound->command(18);
		_scene->_kernelMessages.add(Common::Point(182, 109), 0xFDFC, 0, 0, 90, _game.getQuote(159));
		_scene->_hotspots.activate(227, false);
		int oldIdx = _globals._sequenceIndexes[3];
		_monkeyPosition = 1;
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[8], 36, 42);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[8], 6);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[3], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 221);
		}
		break;

	case 221: {
		_game._objects.setRoom(OBJ_BINOCULARS, 209);
		_binocularsDroppedFl = true;
		int oldIdx = _globals._sequenceIndexes[8];
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 1, 0, 0);
		_globals._sequenceIndexes[9] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], false, 1);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[9], oldIdx);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(201, 131));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 8);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[8], oldIdx);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[8], 43, 72);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 222);
		int idx = _scene->_dynamicHotspots.add(39, 13, _globals._sequenceIndexes[9], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(200, 133), FACING_NORTH);
		}
		break;

	case 222: {
		_scene->_kernelMessages.add(Common::Point(182, 109), 0xFDFC, 0, 0, 70, _game.getQuote(160));
		int oldIdx = _globals._sequenceIndexes[8];
		_globals._sequenceIndexes[8] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[8], false, 8, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[8], 73, 78);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[8], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[8], SEQUENCE_TRIGGER_EXPIRE, 0, 223);
		}
		break;

	case 223:
		_scene->loadAnimation(Resources::formatName(209, 'e', -1, EXT_AA, ""), 224);
		_vm->_sound->command(38);
		break;

	case 224:
		_playingAnimFl = false;
		_fallFl = false;
		_counter = 0;
		_pauseMode = 0;
		_vm->_dialogs->show(0x51AE);
		_game._player._stepEnabled = true;
		break;
	}
}

void Scene209::handleMonkey1() {
	switch (_game._trigger) {
	case 212:
		_scene->_sequences.remove(_globals._sequenceIndexes[4]);
		_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 9, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[4], 1, 13);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 213);
		break;

	case 213: {
		int oldIdx = _globals._sequenceIndexes[4];
		_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 7, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[7], 1, 22);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[7], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_EXPIRE, 0, 214);
		}
		break;

	case 214: {
		int oldIdx = _globals._sequenceIndexes[7];
		_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 7, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[7], 23, 26);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[7], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_EXPIRE, 0, 215);
		int msgIndex = _scene->_kernelMessages.add(Common::Point(170, 21), 0xFDFC, 0, 0, 90, _game.getQuote(156));
		_scene->_kernelMessages.setQuoted(msgIndex, 3, true);
		}
		break;

	case 215: {
		_vm->_sound->command(18);
		_scene->loadAnimation(Resources::formatName(209, 'a', -1, EXT_AA, ""), 251);
		int oldIdx = _globals._sequenceIndexes[7];
		_globals._sequenceIndexes[7] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[7], false, 7, 1, 0, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[7], 27, 35);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[7], oldIdx);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[7], SEQUENCE_TRIGGER_EXPIRE, 0, 216);
		}
		break;

	case 216: {
		int oldIdx = _globals._sequenceIndexes[7];
		_globals._sequenceIndexes[4] = _scene->_sequences.startCycle(_globals._spriteIndexes[4], false, 22);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[4], oldIdx);
		_scene->_sequences.addTimer(25, 217);
		}
		break;

	case 217:
		_pitchFl = false;
		_counter = 0;
		_pauseMode = 0;
		_scene->_sequences.addTimer(1, 196);
		break;
	}
}

void Scene209::handleMonkey2() {
	switch (_game._trigger) {
	case 251:
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 60, _game.getQuote(137));
		_vm->_sound->command(22);
		_globals._sequenceIndexes[12] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[12], false, 11, 1, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[12], Common::Point(111, 133));
		_scene->_sequences.setScale(_globals._sequenceIndexes[12], 79);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[12], 1, 6);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[12], SEQUENCE_TRIGGER_EXPIRE, 0, 252);
		_game._player._priorTimer = _scene->_frameStartTime - _game._player._ticksAmount;
		_game._player._visible = false;
		break;

	case 252: {
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(132));
		int oldIdx = _globals._sequenceIndexes[12];
		_globals._sequenceIndexes[12] = _scene->_sequences.startCycle(_globals._spriteIndexes[12], false, 7);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[12], Common::Point(111, 133));
		_scene->_sequences.setScale(_globals._sequenceIndexes[12], 79);
		_scene->_sequences.updateTimeout(_globals._sequenceIndexes[12], oldIdx);
		_scene->_sequences.addTimer(120, 253);
		}
		break;

	case 253:
		_scene->_sequences.remove(_globals._sequenceIndexes[12]);
		_game._player._priorTimer = _scene->_frameStartTime - _game._player._ticksAmount;
		_game._player._visible = true;
		_game._player._stepEnabled = true;
		break;
	}
}

void Scene209::handleDodge() {
	switch (_game._trigger) {
	case 241:
		_scene->_hotspots.activate(227, true);
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 7);
		_scene->_sequences.addTimer(6, 242);
		break;

	case 242:
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 5);
		_scene->_sequences.addTimer(25, 243);
		_vm->_sound->command(24);
		break;

	case 243:
		_vm->_sound->command(18);
		_scene->_sequences.remove(_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 6);
		_playingAnimFl = false;
		_pauseMode = 0;
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(180, 21), 0xFDFC, 0, 0, 90, _game.getQuote(155));
		if (!_shootMissedLastFl) {
			_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(135));
			_shootMissedLastFl = true;
		} else {
			_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(136));
		}
		break;
	}
}

void Scene209::enter() {
	_globals._spriteIndexes[12] = _scene->_sprites.addSprites(formAnimName('a', 1));
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('e', -1));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('a', 0));
	_globals._spriteIndexes[9] = _scene->_sprites.addSprites(formAnimName('b', 1));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('m', 0));
	_globals._spriteIndexes[4] = _scene->_sprites.addSprites(formAnimName('m', 1));
	_globals._spriteIndexes[5] = _scene->_sprites.addSprites(formAnimName('m', 3));
	_globals._spriteIndexes[6] = _scene->_sprites.addSprites(formAnimName('m', 6));
	_globals._spriteIndexes[7] = _scene->_sprites.addSprites(formAnimName('m', 8));

	_game.loadQuoteSet(0x82, 0x83, 0x84, 0x9C, 0x97, 0x95, 0x99, 0x9E, 0x98, 0x9B, 0xA0, 0x96, 0x9F,
		0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x91, 0x92, 0x93, 0x94, 0x89, 0x85, 0x8A, 0x86, 0x87, 0x88, 0);

	_vm->_palette->setEntry(252, 63, 44, 30);
	_vm->_palette->setEntry(253, 63, 20, 22);

	if (_game._objects.isInRoom(OBJ_PLANT_STALK)) {
		_globals._sequenceIndexes[1] = _scene->_sequences.startCycle(_globals._spriteIndexes[1], false, 1);
		int idx = _scene->_dynamicHotspots.add(271, 13, _globals._sequenceIndexes[1], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(263, 129), FACING_SOUTH);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 13);
	}

	if (_scene->_priorSceneId == 208) {
		_game._player._playerPos = Common::Point(11, 121);
		_game._player._facing = FACING_EAST;
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(28, 121);
		_game._player._facing = FACING_SOUTH;
	}

	if (_game._objects.isInRoom(OBJ_BINOCULARS)) {
		_globals._sequenceIndexes[9] = _scene->_sequences.startCycle(_globals._spriteIndexes[9], false, 1);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[9], Common::Point(201, 131));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[9], 8);
		int idx = _scene->_dynamicHotspots.add(39, 13, _globals._sequenceIndexes[9], Common::Rect(0, 0, 0, 0));
		_scene->_dynamicHotspots.setPosition(idx, Common::Point(200, 133), FACING_NORTH);
	}

	if (_scene->_roomChanged) {
		_game._objects.addToInventory(OBJ_POISON_DARTS);
		_game._objects.addToInventory(OBJ_BLOWGUN);
		_globals[kMonkeyStatus] = MONKEY_HAS_BINOCULARS;
	}

	_pitchFl = false;
	_fallFl = false;
	_dodgeFl = false;
	_playingAnimFl = false;
	_monkeyPosition = 1;
	_counter = 0;
	_pauseMode = 0;
	_forceFallFl = false;
	_shouldFallFl = false;
	_forceDodgeFl = false;
	_binocularsDroppedFl = false;
	_shouldDodgeFl = false;
	_startShootingInTimerFl = false;
	_dialogAbortVal = 5;
	_playingDialogFl = false;
	_shootMissedLastFl = false;
	_removeMonkeyFl = true;
	_shootReadyFl = false;

	_scene->_hotspots.activate(227, false);

	sceneEntrySound();
}

void Scene209::step() {
	if (!_playingAnimFl && !_pitchFl && !_fallFl && !_dodgeFl && (_pauseMode == 0) && (_globals[kMonkeyStatus] == MONKEY_HAS_BINOCULARS)) {
		int randAction = _vm->getRandomNumber(1,50);
		switch (randAction) {
		case 1:
			if ((_monkeyPosition == 1) && (_counter < 2)) {
				_scene->_sequences.addTimer(1, 133);
				_playingAnimFl = true;
				_scene->_hotspots.activate(227, true);
				++_counter;
			}
			break;

		case 2:
			if ((_monkeyPosition == 1) && (_counter < 2)) {
				_scene->_sequences.addTimer(1, 140);
				_scene->_hotspots.activate(227, true);
				_playingAnimFl = true;
				++_counter;
			}
			break;

		case 3:
			if (_monkeyPosition == 1) {
				_scene->_sequences.addTimer(1, 145);
				_scene->_hotspots.activate(227, true);
				_playingAnimFl = true;
				_counter = 0;
			}
			break;

		case 4:
			if ((_monkeyPosition == 2) && (_counter < 2)) {
				_scene->_sequences.addTimer(1, 151);
				_scene->_hotspots.activate(227, true);
				++_counter;
				_playingAnimFl = true;
			}
			break;

		case 5:
			if (_monkeyPosition == 2) {
				_scene->_sequences.addTimer(1, 161);
				_scene->_hotspots.activate(227, true);
				_counter = 0;
				_playingAnimFl = true;
			}
			break;

		case 6:
			if (_monkeyPosition == 2) {
				_scene->_sequences.addTimer(1, 189);
				_scene->_hotspots.activate(227, true);
				_counter = 0;
				_playingAnimFl = true;
			}
			break;
		case 7:
			if (_monkeyPosition == 3) {
				_scene->_hotspots.activate(227, true);
				_scene->_sequences.addTimer(1, 167);
				_playingAnimFl = true;
			}
			break;

		case 8:
			if (_monkeyPosition == 3) {
				_scene->_sequences.addTimer(1, 178);
				_playingAnimFl = true;
				_scene->_hotspots.activate(227, true);
				_counter = 0;
			}
			break;

		case 9:
			if ((_monkeyPosition == 3) && (_game._player._playerPos.x<120)) {
				_scene->_sequences.addTimer(1, 182);
				_scene->_hotspots.activate(227, true);
				_counter = 0;
				_playingAnimFl = true;
			}
			break;

		case 10:
			if (_monkeyPosition == 4) {
				_scene->_sequences.addTimer(1, 196);
				_scene->_hotspots.activate(227, true);
				_playingAnimFl = true;
				_counter = 0;
			}
			break;

		case 11:
			if ((_monkeyPosition == 4) && (_counter < 3)) {
				_scene->_sequences.addTimer(1, 199);
				_scene->_hotspots.activate(227, true);
				++_counter;
				_playingAnimFl = true;
			}
			break;

		case 30:
			if (_monkeyPosition == 4) {
				_scene->_sequences.addTimer(1, 246);
				_scene->_hotspots.activate(227, true);
				_counter = 0;
				_playingAnimFl = true;
			}
			break;

		default:
			if ((randAction >= 12) && (randAction <= 20) && (_monkeyPosition == 2) && (_counter < 5)) {
				_scene->_sequences.addTimer(1, 155);
				++_counter;
				_playingAnimFl = true;
			}

			if ((randAction >= 21) && (randAction <= 29) && (_monkeyPosition == 3) && (_counter < 3)) {
				_scene->_sequences.addTimer(1, 171);
				_playingAnimFl = true;
				++_counter;
			}
			break;
		}
	}

	if (!_dodgeFl && !_pitchFl && !_fallFl && (_pauseMode == 1))
		_scene->_sequences.addTimer(1, 226);

	if (!_dodgeFl && !_pitchFl && !_fallFl && (_pauseMode == 2))
		handlePause();

	if (!_dodgeFl && !_pitchFl && !_fallFl && (_pauseMode == 1))
		initPauseCounterThreshold();

	handlePeek();
	handleVerticalMove();
	handleLookStay();
	handleLookRight();
	handleBlink();
	handleGetBinoculars();
	handleStandFromPeek();
	handleDodge();
	handleBinocularBlink();
	handleBinocularScan();
	handleJumpInTree();
	handleTongue();
	handleMonkeyFall();
	handleJumpAndHide();
	handleMonkeyEating();
	handleMonkey1();
	handleStandBlink();
	handleMonkey2();

	if ((_monkeyPosition == 1) && !_playingAnimFl && _fallFl) {
		_scene->_sequences.addTimer(1, 145);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 2) && !_playingAnimFl && _fallFl) {
		_scene->_sequences.addTimer(1, 161);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 4) && !_playingAnimFl && _fallFl) {
		_scene->_sequences.addTimer(1, 196);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 3) && !_playingAnimFl && _fallFl && _forceFallFl) {
		_scene->_sequences.addTimer(1, 219);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 1) && !_playingAnimFl && _pitchFl) {
		_scene->_sequences.addTimer(1, 145);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 2) && !_playingAnimFl && _pitchFl) {
		_scene->_sequences.addTimer(1, 189);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 4) && !_playingAnimFl && _pitchFl) {
		_scene->_sequences.addTimer(1, 212);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 3) && !_playingAnimFl && _pitchFl) {
		_scene->_sequences.addTimer(1, 178);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 1) && !_playingAnimFl && _dodgeFl) {
		_scene->_sequences.addTimer(1, 145);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 4) && !_playingAnimFl && _dodgeFl) {
		_scene->_sequences.addTimer(1, 196);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 3) && !_playingAnimFl && _dodgeFl) {
		_scene->_sequences.addTimer(1, 178);
		_playingAnimFl = true;
	}

	if ((_monkeyPosition == 2) && !_playingAnimFl && _dodgeFl && _forceDodgeFl) {
		_scene->_sequences.addTimer(1, 241);
		_playingAnimFl = true;
	}

	if (_dodgeFl || _fallFl) { /* if want to dodge or fall */
		if (!_playingAnimFl && (_monkeyPosition == 2))
			_shouldDodgeFl = true;

		if (!_playingAnimFl && (_monkeyPosition == 3))
			_shouldFallFl = true;

		switch (_game._trigger) {
		case 228:
			_game._player._visible = false;
			_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 8, 1, 0, 0);
			_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 1, 7);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 228);
			break;

		case 229: {
			int oldIdx = _globals._sequenceIndexes[2];
			_globals._sequenceIndexes[2] = _scene->_sequences.startCycle(_globals._spriteIndexes[2], false, 7);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[2], oldIdx);
			_scene->_sequences.addTimer(35, 230);
			}
			break;

		case 230:
			_scene->_sequences.remove(_globals._sequenceIndexes[2]);
			_globals._sequenceIndexes[2] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[2], false, 8, 1, 0, 0);
			_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 1, 7);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 231);
			break;

		case 231: {
			int oldIdx = _globals._sequenceIndexes[2];
			_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 8, 1, 0, 0);
			_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 8, 10);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[2], oldIdx);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 232);
			_game._player._priorTimer = _scene->_frameStartTime - _game._player._ticksAmount;
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[2], -1);
			_game._player._visible = false;
			}
			break;

		case 232: {
			int oldIdx = _globals._sequenceIndexes[2];
			_globals._sequenceIndexes[2] = _scene->_sequences.startCycle(_globals._spriteIndexes[2], false, 10);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[2], oldIdx);
			_scene->_sequences.addTimer(2, 233);
			_scene->_kernelMessages.reset();
			if (_dodgeFl && (_monkeyPosition != 1) && (_monkeyPosition != 2))
				_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 34463, _game.getQuote(138));
			if (_fallFl && (_monkeyPosition != 3))
				_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 34463, _game.getQuote(138));
			}
			break;

		case 233:
			_shootReadyFl = true;
			break;

		case 234:
			_scene->_sequences.remove(_globals._sequenceIndexes[2]);
			_scene->_kernelMessages.reset();
			if (_action.isAction(VERB_HOSE_DOWN, NOUN_BLOWGUN, NOUN_MONKEY)) {
				_globals._sequenceIndexes[2] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[2], false, 7, 16, 0, 0);
				_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 11, 12);
				_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
				_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
				_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_SPRITE, 12, 239);
				_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 235);
			} else if (_action.isAction(VERB_SHOOT, NOUN_BLOWGUN, NOUN_MONKEY)) {
				_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 8, 1, 0, 0);
				_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 11, 12);
				_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
				_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
				_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 235);
				_vm->_sound->command(23);
			}
			break;

		case 235: {
			int oldIdx = _globals._sequenceIndexes[2];
			_globals._sequenceIndexes[2] = _scene->_sequences.startCycle(_globals._spriteIndexes[2], false, 13);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.updateTimeout(_globals._sequenceIndexes[2], oldIdx);
			_scene->_sequences.addTimer(12, 236);
			_forceFallFl = true;
			_forceDodgeFl = true;
			}
			break;

		case 236:
			_scene->_sequences.remove(_globals._sequenceIndexes[2]);
			_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 8, 1, 0, 0);
			_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 14, 16);
			_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(116, 131));
			_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 4);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 237);
			break;

		case 237:
			_game._player._visible = true;
			_game._player._priorTimer = _scene->_frameStartTime - _game._player._ticksAmount;
			_scene->_sequences.addTimer(1, 238);
			break;

		case 238:
			_scene->_sequences.remove(_globals._sequenceIndexes[2]);
			if (_dodgeFl)
				_game._player._stepEnabled = true;

			_startShootingInTimerFl = false;

			if (_fallFl) {
				_globals[kMonkeyStatus] = MONKEY_IS_GONE;
				_game._objects.setRoom(OBJ_POISON_DARTS, NOWHERE);
			}
			_dodgeFl = false;
			_fallFl = false;
			_forceFallFl = false;
			_forceDodgeFl = false;
			_shouldFallFl = false;
			_shouldDodgeFl = false;
			break;

		case 239:
			_vm->_sound->command(23);
			break;
		}
	}

	if (_game._trigger == 100)
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(134));

	if (_shootReadyFl && (_shouldFallFl || _shouldDodgeFl)) {
		_scene->_sequences.addTimer(4, 234);
		_shootReadyFl = false;
	}
}

void Scene209::preActions() {
	if (_action.isAction(VERB_WALK_TOWARDS, 0x84))
		_game._player._walkOffScreenSceneId = 208;

	if (_globals[kMonkeyStatus] == MONKEY_HAS_BINOCULARS) {
		if ((_action.isAction(VERB_SHOOT) || _action.isAction(VERB_HOSE_DOWN)) && _action.isTarget(NOUN_MONKEY)
			&& _action.isObject(NOUN_BLOWGUN) && _game._objects.isInInventory(OBJ_BLOWGUN) && _game._objects.isInInventory(OBJ_POISON_DARTS)) {
			_game._player._prepareWalkPos = Common::Point(111, 129);
			_game._player._prepareWalkFacing = FACING_NORTHEAST;
			_game._player._needToWalk = true;
			_game._player._readyToWalk = true;
		}

		if (_action.isAction(VERB_LOOK, NOUN_MONKEY) || _action.isAction(VERB_TALKTO, NOUN_MONKEY)) {
			_game._player._prepareWalkPos = Common::Point(111, 129);
			_game._player._prepareWalkFacing = FACING_NORTHEAST;
			_game._player._needToWalk = true;
			_game._player._readyToWalk = true;
		}
	}
}

void Scene209::actions() {
	if (_action._lookFlag) {
		_vm->_dialogs->show(0x51B0);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_WALK_TOWARDS, 0x1A2)) {
		_scene->_nextSceneId = 203;
		_action._inProgress = false;
		return;
	}

	if ((_action.isAction(VERB_TALKTO, NOUN_MONKEY)) && !_pitchFl && !_playingDialogFl) {
		_scene->_sequences.addTimer(1, _dialogAbortVal);
		_playingDialogFl = true;
		_game._player._stepEnabled = false;
		_action._inProgress = false;
		return;
	}

	switch (_game._trigger) {
	case 130:
		_game._player._stepEnabled = true;
		_playingDialogFl = false;
		_action._inProgress = false;
		return;

	case 5:
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 6, 180, _game.getQuote(139));
		_action._inProgress = false;
		return;

	case 6:
		_scene->_kernelMessages.add(Common::Point(180, 21), 0xFDFC, 0, 0, 60, _game.getQuote(151));
		_scene->_sequences.addTimer(60, 130);
		_dialogAbortVal = 7;
		_action._inProgress = false;
		return;

	case 7:
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 8, 180, _game.getQuote(140));
		_action._inProgress = false;
		return;

	case 8:
		_scene->_kernelMessages.add(Common::Point(180, 21), 0xFDFC, 0, 0, 60, _game.getQuote(149));
		_scene->_sequences.addTimer(60, 130);
		_dialogAbortVal = 9;
		_action._inProgress = false;
		return;

	case 9:
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 180, _game.getQuote(141));
		_scene->_sequences.addTimer(200, 10);
		_action._inProgress = false;
		return;

	case 10:
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 11, 180, _game.getQuote(142));
		_action._inProgress = false;
		return;

	case 11:
		_scene->_kernelMessages.add(Common::Point(180, 21), 0xFDFC, 0, 0, 60, _game.getQuote(152));
		_scene->_sequences.addTimer(60, 130);
		_dialogAbortVal = 12;
		_action._inProgress = false;
		return;

	case 12:
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 130, _game.getQuote(143));
		_scene->_sequences.addTimer(150, 13);
		_action._inProgress = false;
		return;

	case 13:
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 14, 180, _game.getQuote(145));
		_action._inProgress = false;
		return;

	case 14:
		_scene->_kernelMessages.add(Common::Point(180, 21), 0xFDFC, 0, 0, 60, _game.getQuote(151));
		_scene->_sequences.addTimer(60, 130);
		_dialogAbortVal = 15;
		_action._inProgress = false;
		return;

	case 15:
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 16, 180, _game.getQuote(146));
		_action._inProgress = false;
		return;

	case 16:
		_scene->_kernelMessages.add(Common::Point(180, 21), 0xFDFC, 0, 17, 60, _game.getQuote(154));
		_action._inProgress = false;
		return;

	case 17:
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 130, 60, _game.getQuote(147));
		_dialogAbortVal = 18;
		_action._inProgress = false;
		return;

	case 18:
		_scene->_kernelMessages.reset();
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 180, _game.getQuote(148));
		_pitchFl = true;
		_playingDialogFl = false;
		_dialogAbortVal = 5;
		_action._inProgress = false;
		return;
	}

	if (_globals[kMonkeyStatus] == MONKEY_HAS_BINOCULARS) {
		if ((_action.isAction(VERB_SHOOT) || _action.isAction(VERB_HOSE_DOWN)) && _action.isAction(NOUN_MONKEY)
			&& _action.isAction(NOUN_BLOWGUN) && _game._objects.isInInventory(OBJ_BLOWGUN) && _game._objects.isInInventory(OBJ_POISON_DARTS)) {
			if (_action.isAction(VERB_SHOOT, NOUN_BLOWGUN, NOUN_MONKEY) && !_startShootingInTimerFl) {
				_game._triggerSetupMode = SEQUENCE_TRIGGER_DAEMON;
				_scene->_sequences.addTimer(1, 231);
				_startShootingInTimerFl = true;
				_game._player._stepEnabled = false;
				_dodgeFl = true;
				_action._inProgress = false;
				return;
			}

			if (_action.isAction(VERB_HOSE_DOWN, NOUN_BLOWGUN, NOUN_MONKEY) && !_startShootingInTimerFl) {
				_game._triggerSetupMode = SEQUENCE_TRIGGER_DAEMON;
				_scene->_sequences.addTimer(1, 228);
				_game._player._stepEnabled = false;
				_fallFl = true;
				_startShootingInTimerFl = true;
				_action._inProgress = false;
				return;
			}
		}

		if (_action.isAction(VERB_LOOK, NOUN_MONKEY)) {
			_pitchFl = true;
			_game._player._stepEnabled = false;
			_vm->_dialogs->show(0x51B2);
			_action._inProgress = false;
			return;
		}
	}

	if (_action.isAction(VERB_TAKE, NOUN_PLANT_STALK) && (_game._trigger || _game._objects.isInRoom(OBJ_PLANT_STALK))) {
		switch (_game._trigger) {
		case 0:
			_globals._spriteIndexes[11] = _scene->_sprites.addSprites("*RXMBD_2");
			_game._player._stepEnabled = false;
			_game._player._visible = false;
			_globals._sequenceIndexes[11] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[11], false, 3, 2, 0, 0);
			_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[11]);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[11], SEQUENCE_TRIGGER_SPRITE, 4, 1);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[11], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
			break;

		case 1:
			_scene->_sequences.remove(_globals._sequenceIndexes[1]);
			_game._objects.addToInventory(OBJ_PLANT_STALK);
			break;

		case 2:
			_game._player._visible = true;
			_game._player._stepEnabled = true;
			_scene->_sequences.addTimer(4, 3);
			_vm->_dialogs->showItem(OBJ_PLANT_STALK, 0x328);
			break;

		case 3:
			_scene->_sprites.remove(_globals._spriteIndexes[11]);
			break;
		}
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_TAKE, 0x27) && (_game._trigger || _game._objects.isInRoom(OBJ_BINOCULARS))) {
		switch (_game._trigger) {
		case 0:
			_globals._spriteIndexes[10] = _scene->_sprites.addSprites("*RXMBD_8");
			_game._player._stepEnabled = false;
			_game._player._visible = false;
			_globals._sequenceIndexes[10] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[10], false, 3, 2, 0, 0);
			_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[10]);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[10], SEQUENCE_TRIGGER_SPRITE, 4, 1);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[10], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
			break;

		case 1:
			_scene->_sequences.remove(_globals._sequenceIndexes[9]);
			_game._objects.addToInventory(OBJ_BINOCULARS);
			break;

		case 2:
			_game._player._visible = true;
			_game._player._stepEnabled = true;
			_binocularsDroppedFl = false;
			_scene->_sequences.addTimer(4, 3);
			break;

		case 3:
			_vm->_dialogs->showItem (OBJ_BINOCULARS, 0x51AF);
			_scene->_sprites.remove(_globals._spriteIndexes[10]);
			break;
		}
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x142)) {
		_vm->_dialogs->show(0x51A5);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x1A3)) {
		_vm->_dialogs->show(0x51A6);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x1A4)) {
		_vm->_dialogs->show(0x51A7);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x1A6)) {
		_vm->_dialogs->show(0x51A8);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x84)) {
		_vm->_dialogs->show(0x51A9);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x1A2)) {
		_vm->_dialogs->show(0x51AA);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x10F) && (_action._savedFields._mainObjectSource == 4)) {
		_vm->_dialogs->show(0x51AB);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_GIVE, 0x17A, 0xE3) || _action.isAction(VERB_THROW, 0x17A, 0xE3)) {
		_vm->_dialogs->show(0x51AD);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x175)) {
		_vm->_dialogs->show(0x51B1);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_THROW, 0xE3) && _game._objects.isInInventory(_game._objects.getIdFromDesc(_action._activeAction._objectNameId))) {
		if (!_action.isAction(0x114)) {
			_vm->_dialogs->show(0x51B3);
		}
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_THROW, 0x114, 0xE3)) {
		_vm->_dialogs->show(0x51B4);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x100)) {
		if (_globals[kMonkeyStatus] == MONKEY_HAS_BINOCULARS) {
			if (_monkeyPosition == 1)
				_vm->_dialogs->show(0x51B5);
			else
				_vm->_dialogs->show(0x51B6);
		} else {
			if (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY)
				_vm->_dialogs->show(0x51B5);
			else
				_vm->_dialogs->show(0x51B7);
		}
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x3A4)) {
		_vm->_dialogs->show(0x51B8);
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_TAKE, 0x3A4)) {
		_vm->_dialogs->show(0x51B9);
		_action._inProgress = false;
		return;
	}
}

void Scene209::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_dodgeFl);
	s.syncAsByte(_forceDodgeFl);
	s.syncAsByte(_shouldDodgeFl);
	s.syncAsByte(_pitchFl);
	s.syncAsByte(_fallFl);
	s.syncAsByte(_forceFallFl);
	s.syncAsByte(_shouldFallFl);
	s.syncAsByte(_playingAnimFl);
	s.syncAsByte(_playingDialogFl);

	s.syncAsSint32LE(_pauseMode);
	s.syncAsSint32LE(_pauseCounterThreshold);
	s.syncAsSint32LE(_pauseCounter);

	s.syncAsByte(_removeMonkeyFl);

	s.syncAsSint32LE(_monkeyPosition);

	s.syncAsByte(_shootReadyFl);
	s.syncAsByte(_startShootingInTimerFl);
	s.syncAsByte(_shootMissedLastFl);
	s.syncAsByte(_binocularsDroppedFl);

	s.syncAsSint32LE(_dialogAbortVal);
	s.syncAsSint32LE(_counter);
}

/*****************************************************************************/

void Scene210::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(0x70);
	_scene->addActiveVocab(VERB_WALK_THROUGH);
}

void Scene210::handleConversations() {
	if (_game._trigger == 0) {
		_scene->_kernelMessages.reset();
		_game._player._stepEnabled = false;
		Common::String curQuote = _game.getQuote(_action._activeAction._verbId);
		if (_vm->_font->getWidth(curQuote, _scene->_textSpacing) > 200) {
			Common::String subQuote1;
			_game.splitQuote(curQuote, subQuote1, _subQuote2);
			_scene->_kernelMessages.add(Common::Point(0, -14), 0x1110, 34, 0, 240, subQuote1);
			_scene->_sequences.addTimer(60, 50);
		} else {
			_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 1, 120, curQuote);
		}
	} else if (_game._trigger == 50) {
		_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 240, _subQuote2);
		_scene->_sequences.addTimer(180, 1);
	} else {
		if (_game._trigger == 1)
			_scene->_kernelMessages.reset();

		switch (_curDialogNode) {
		case 1:
			handleConversation1();
			break;

		case 2:
			handleConversation2();
			break;

		case 3:
			handleConversation3();
			break;

		case 5:
			handleConversation5();
			break;

		case 6:
			handleConversation6();
			break;

		case 7:
			handleConversation7();
			break;

		case 8:
			handleConversation8();
			break;
		}
	}
}

void Scene210::handleConversation1() {
	switch (_action._activeAction._verbId) {
	case 180:
		setDialogNode(2);
		break;

	case 181:
		setDialogNode(6);
		break;

	case 182:
		setDialogNode(4);
		break;

	case 183:
		setDialogNode(9);
		break;

	case 184:
		setDialogNode(0);
		break;
	}
}

void Scene210::handleConversation2() {
	switch (_action._activeAction._verbId) {
	case 187:
		setDialogNode(3);
		break;

	case 188:
		setDialogNode(4);
		break;

	case 189:
		setDialogNode(0);
		break;
	}
}

void Scene210::handleConversation3() {
	switch (_action._activeAction._verbId) {
	case 193:
		setDialogNode(6);
		break;

	case 194:
		setDialogNode(5);
		break;

	case 195:
		setDialogNode(4);
		break;

	case 196:
		setDialogNode(0);
		break;
	}
}

void Scene210::handleConversation5() {
	switch (_action._activeAction._verbId) {
	case 204:
		setDialogNode(6);
		break;

	case 205:
	case 206:
		setDialogNode(4);
		break;

	case 207:
		setDialogNode(0);
		break;
	}
}

void Scene210::handleConversation6() {
	switch (_action._activeAction._verbId) {
	case 211:
		setDialogNode(7);
		break;

	case 212:
		setDialogNode(4);
		break;

	case 213:
		setDialogNode(0);
		break;
	}
}

void Scene210::handleConversation7() {
	switch (_action._activeAction._verbId) {
	case 216:
	case 217:
	case 219:
		setDialogNode(4);
		break;

	case 218:
		setDialogNode(8);
		break;

	case 220:
		setDialogNode(0);
		break;
	}
}

void Scene210::handleConversation8() {
	switch (_action._activeAction._verbId) {
	case 223:
	case 224:
		setDialogNode(4);
		break;

	case 225:
	case 226:
		setDialogNode(9);
		break;

	case 227:
		setDialogNode(0);
		break;
	}
}

void Scene210::setDialogNode(int node) {
	switch (node) {
	case 0:
		_scene->_userInterface.setup(kInputBuildingSentences);
		_shouldFaceRex = false;
		_shouldTalk = false;
		_game._player._stepEnabled = true;
		_curDialogNode = 0;
		break;

	case 2:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 1;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				handleTwinklesSpeech(0xB9, -1, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;

		case 2:
			_nextHandsPlace = 0;
			handleTwinklesSpeech(186, 0, 0);
			_scene->_sequences.addTimer(180, 3);
			break;

		default:
			_nextHandsPlace = 0;
			_shouldTalk = false;
			_game._player._stepEnabled = true;
			newNode(2);
			break;
		}
		break;

	case 3:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 0;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				handleTwinklesSpeech(0xBE, -2, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;
		case 2:
			_nextHandsPlace = 2;
			handleTwinklesSpeech(191, -1, 0);
			_scene->_sequences.addTimer(180, 3);
			break;
		case 3:
			_nextHandsPlace = 0;
			handleTwinklesSpeech(192, 0, 0);
			_scene->_sequences.addTimer(180, 4);
			break;
		default:
			_shouldTalk = false;
			_game._player._stepEnabled = true;
			newNode(3);
			break;
		}
		break;

	case 4:
		if (_game._trigger == 1) {
			_nextHandsPlace = 1;
			_shouldTalk = true;
			_game._player._stepEnabled = false;

			int quote;
			if (_game._storyMode == STORYMODE_NAUGHTY)
				quote = _vm->getRandomNumber(199, 201);
			else
				quote = _vm->getRandomNumber(197, 198);

			if (_twinklesTalking) {
				handleTwinklesSpeech(quote, 0, 360);
				_scene->_sequences.addTimer(120, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
		} else {
			_scene->_userInterface.setup(kInputBuildingSentences);
			_shouldFaceRex = false;
			_shouldTalk = false;
			_game._player._stepEnabled = true;
		}
		break;

	case 5:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 2;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				handleTwinklesSpeech(0xCA, -1, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;

		case 2:
			_nextHandsPlace = 1;
			handleTwinklesSpeech(0xCB, 0, 0);
			_scene->_sequences.addTimer(180, 3);
			break;

		default:
			_nextHandsPlace = 2;
			_shouldTalk = false;
			_game._player._stepEnabled = true;
			newNode(5);
			break;
		}
		break;

	case 6:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 1;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				handleTwinklesSpeech(0xD0, -2, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;

		case 2:
			handleTwinklesSpeech(0xD1, -1, 0);
			_scene->_sequences.addTimer(180, 3);
			break;

		case 3:
			_nextHandsPlace = 1;
			handleTwinklesSpeech(0xD2, 0, 0);
			_scene->_sequences.addTimer(180, 4);
			break;

		default:
			_nextHandsPlace = 0;
			_shouldTalk = false;
			_game._player._stepEnabled = true;
			newNode(6);
			break;
		}
		break;

	case 7:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 2;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				handleTwinklesSpeech(0xD6, -1, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;

		case 2:
			handleTwinklesSpeech(0xD7, 0, 0);
			_scene->_sequences.addTimer(180, 3);
			break;

		default:
			_shouldTalk = false;
			_game._player._stepEnabled = true;
			newNode(7);
			break;
		}
		break;

	case 8:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 2;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				handleTwinklesSpeech(0xDD, -1, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;

		case 2:
			handleTwinklesSpeech(0xDE, 0, 0);
			_scene->_sequences.addTimer(180, 3);
			break;

		default:
			_shouldTalk = false;
			_game._player._stepEnabled = true;
			newNode(8);
			break;
		}
		break;


	case 9:
		switch (_game._trigger) {
		case 1:
			_nextHandsPlace = 0;
			_shouldTalk = true;
			_game._player._stepEnabled = false;
			if (_twinklesTalking) {
				_scene->_userInterface.emptyConversationList();
				_scene->_userInterface.setup(kInputConversation);
				handleTwinklesSpeech(0xE4, -1, 0);
				_scene->_sequences.addTimer(180, 2);
			} else {
				_scene->_sequences.addTimer(6, 1);
			}
			break;

		case 2:
			handleTwinklesSpeech(0xE5, 0, 0);
			_scene->_sequences.addTimer(180, 3);
			break;

		case 3:
			_twinkleAnimationType = 2;
			_globals[kCurtainOpen] = true;
			_game._player._visible = false;
			_vm->_palette->lock();
			_scene->_kernelMessages.reset();
			_scene->freeAnimation();
			_scene->_activeAnimation = nullptr;
			_scene->resetScene();

			_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('c', -1));
			_game.loadQuoteSet(0xE6, 0xE9, 0xEA, 0xE7, 0xE8, 0);
			_scene->loadAnimation(formAnimName('B', -1), 4);
			break;

		case 4: {
			_globals._spriteIndexes[8] = _scene->_sequences.startCycle(_globals._spriteIndexes[1], false, 5);
			_scene->_sequences.setDepth(_globals._spriteIndexes[8], 1);

			int msgIndex = _scene->_kernelMessages.add(Common::Point(160, 20), 0x1110, 32, 5, 180, _game.getQuote(231));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			}
			break;

		case 5: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(160, 40), 0xFDFC, 32, 6, 180, _game.getQuote(233));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			}
			break;

		case 6: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(160, 60), 0x1110, 32, 7, 180, _game.getQuote(232));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			}
			break;

		case 7: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(160, 80), 0xFDFC, 32, 8, 180, _game.getQuote(234));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			}
			break;

		case 8:
			_globals[kTwinklesStatus] = TWINKLES_GONE;
			_scene->_nextSceneId = 216;
			break;
		}
		break;
	}
}

void Scene210::handleTwinklesSpeech(int quoteId, int shiftX, uint32 delay) {
	_scene->_kernelMessages.add(Common::Point(10, 70 + (shiftX * 14)), 0xFDFC, 0, 0, (delay == 0) ? 9999999 : delay, _game.getQuote(quoteId));
}

void Scene210::newNode(int node) {
	_curDialogNode = node;

	switch (_curDialogNode) {
	case 1:
		_conv1.start();
		break;

	case 2:
		_conv2.start();
		break;

	case 3:
		_conv3.start();
		break;

	case 5:
		_conv5.start();
		break;

	case 6:
		_conv6.start();
		break;

	case 7:
		_conv7.start();
		break;

	case 8:
		_conv8.start();
		break;

	default:
		break;
	}
}

void Scene210::restoreDialogNode(int node, int msgId, int posY) {
	int curQuoteId = msgId;
	int curY = 1 - posY;
	for (int count = 0; count < posY; count++) {
		handleTwinklesSpeech(curQuoteId, curY, 0);
		curY++;
		curQuoteId++;
	}

	newNode(node);
}

void Scene210::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('c', -1));

	if (!_game._visitedScenes._sceneRevisited)
		_globals[kCurtainOpen] = 0;

	if (_scene->_priorSceneId == 205)
		_game._player._playerPos = Common::Point(277, 56);
	else if (_scene->_priorSceneId == 215) {
		_game._player._playerPos = Common::Point(168, 128);
		_game._player._facing = FACING_SOUTH;
		_globals[kCurtainOpen] = true;
	} else if (_scene->_priorSceneId != -2)
		_game._player._playerPos = Common::Point(308, 132);

	if (!_globals[kCurtainOpen]) {
		_globals._sequenceIndexes[1] = _scene->_sequences.startCycle(_globals._spriteIndexes[1], false, 5);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 5);
	} else {
		int idx = _scene->_dynamicHotspots.add(112, 395, -1, Common::Rect(163, 87, 163 + 19, 87 + 36));
		_doorway = _scene->_dynamicHotspots.setPosition(idx, Common::Point(168, 127), FACING_NORTH);
		_scene->_dynamicHotspots.setCursor(_doorway, CURSOR_GO_UP);
	}

	_game.loadQuoteSet(0x5A, 0x73, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB8, 0xB7,
		0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA,
		0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC,
		0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0);

	_conv1.setup(0x2E, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0);

	if (!_game._visitedScenes._sceneRevisited) {
		_conv1.set(0x2E, 0xB4, 0xB5, 0xB6, 0xB8, 0);

		if (_game._widepipeCtr >= 2)
			_conv1.write(0xB7, true);
	}

	bool sceneRevisited = _game._visitedScenes._sceneRevisited;
	_conv2.setup(0x2F, 0xBC, 0xBB, 0xBD, sceneRevisited ? 0 : -1);
	_conv3.setup(0x30, 0xC3, 0xC2, 0xC1, 0xC4, sceneRevisited ? 0 : -1);
	_conv5.setup(0x31, 0xCD, 0xCC, 0xCE, 0xCF, sceneRevisited ? 0 : -1);
	_conv6.setup(0x32, 0xD3, 0xD4, 0xD5, sceneRevisited ? 0 : -1);
	_conv7.setup(0x33, 0xD8, 0xDA, 0xD9, 0xDB, 0xDC, sceneRevisited ? 0 : -1);
	_conv8.setup(0x34, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, sceneRevisited ? 0 : -1);

	_twinkleAnimationType = 0;
	_twinklesCurrentFrame = 0;

	if (_scene->_priorSceneId != -2) {
		_shouldMoveHead = false;
		_shouldFaceRex = false;
		_shouldTalk = false;
		_nextHandsPlace = 0;
		_twinklesTalking = false;
		_curDialogNode = 0;
		_stopWalking = false;
		_twinklesTalk2 = (_globals[kTwinklesApproached] > 0);
	}

	if (_globals[kTwinklesStatus] == 0) {
		_scene->loadAnimation(formAnimName('A', -1), 0);
		_twinkleAnimationType = 1;
	} else
		_scene->_hotspots.activate(476, false);

	if (_curDialogNode) {
		int quote = 0;
		int number = 0;

		switch (_curDialogNode) {
		case 1:
			quote = 0xB3;
			number = 1;
			break;
		case 2:
			quote = 0xB9;
			number = 2;
			break;
		case 3:
			quote = 0xBE;
			number = 3;
			break;
		case 5:
			quote = 0xCA;
			number = 2;
			break;
		case 6:
			quote = 0xD0;
			number = 3;
			break;
		case 7:
			quote = 0xD6;
			number = 2;
			break;
		case 8:
			quote = 0xDD;
			number = 2;
			break;
		}

		restoreDialogNode(_curDialogNode, quote, number);
		_scene->_activeAnimation->setCurrentFrame(131);
	}

	_vm->_palette->setEntry(252, 63, 63, 10);
	_vm->_palette->setEntry(253, 45, 45, 5);

	sceneEntrySound();
}

void Scene210::step() {
	if ((_twinkleAnimationType == 1) && _scene->_activeAnimation) {
		if (_twinklesCurrentFrame != _scene->_activeAnimation->getCurrentFrame()) {
			_twinklesCurrentFrame = _scene->_activeAnimation->getCurrentFrame();
			int reset_frame = -1;
			int random = _vm->getRandomNumber(1, 1000);

			switch (_twinklesCurrentFrame) {
			case 31:
			case 58:
			case 74:
			case 108:
			case 190:
				if (_shouldFaceRex)
					reset_frame = 108;
				else if ((random <= 100) || _shouldMoveHead)
					reset_frame = 74;
				else if (random <= 300)
					reset_frame = 58;
				else if (random <= 500)
					reset_frame = 31;
				else
					reset_frame = 0;
				break;

			case 80:
			case 90:
				_twinklesTalking = false;
				if (_shouldMoveHead) {
					reset_frame = 90;
				} else if (_twinklesCurrentFrame == 90) {
					if ((random <= 400) || _shouldFaceRex)
						reset_frame = 99;
					else
						reset_frame = 79;
				}
				break;

			case 98:
				if (_shouldMoveHead)
					reset_frame = 91;
				break;

			case 99:
				if ((random <= 400) && !_shouldFaceRex)
					reset_frame = 79;
				break;

			case 124:
			case 136:
			case 174:
			case 143:
			case 152:
				if (_nextHandsPlace == 3)
					reset_frame = 174;
				else if (!_shouldFaceRex)
					reset_frame = 174;
				else if (_nextHandsPlace == 1)
					reset_frame = 136;
				else if (_nextHandsPlace == 2)
					reset_frame = 152;
				else if (_shouldTalk)
					reset_frame = 124;
				else
					reset_frame = (random <= 200) ? 131 : 143;
				break;

			case 131:
				if (_shouldTalk) {
					switch (_nextHandsPlace) {
					case 1:
						reset_frame = 136;
						break;
					case 2:
						reset_frame = 152;
						break;
					default:
						reset_frame = 124;
						break;
					}
				}
				break;

			case 138:
			case 141:
				if ((_nextHandsPlace == 0) || !_shouldFaceRex)
					reset_frame = 141;
				else if (_nextHandsPlace == 2)
					reset_frame = 152;
				else if (!_shouldTalk || (_twinklesCurrentFrame == 141))
					reset_frame = 137;
				break;

			case 153:
			case 169:
				if ((_nextHandsPlace == 0) || !_shouldFaceRex)
					reset_frame = 169;
				else if (_nextHandsPlace == 1)
					reset_frame = 136;
				else if (_shouldTalk)
					reset_frame = 153;
				else
					reset_frame = 162;
				break;

			case 162:
				if (_shouldTalk) {
					switch (_nextHandsPlace) {
					case 0:
						reset_frame = 124;
						break;
					case 1:
						reset_frame = 136;
						break;
					default:
						reset_frame = 153;
						break;
					}
				}
				break;
			}

			if (reset_frame >= 0) {
				if (reset_frame != _scene->_activeAnimation->getCurrentFrame()) {
					_scene->_activeAnimation->setCurrentFrame(reset_frame);
					_twinklesCurrentFrame = reset_frame;
				}

				if ((reset_frame == 90) || (reset_frame == 91) || (reset_frame == 124) || (reset_frame == 153)
					|| ((reset_frame == 137) && _shouldTalk)) {
					_twinklesTalking = true;
				} else {
					_twinklesTalking = false;
				}
			}
		}
	}

	if ((_twinkleAnimationType == 2) && _scene->_activeAnimation) {
		if (_twinklesCurrentFrame != _scene->_activeAnimation->getCurrentFrame()) {
			_twinklesCurrentFrame = _scene->_activeAnimation->getCurrentFrame();
			int reset_frame = -1;

			if (_twinklesCurrentFrame == 53) {
				_scene->_kernelMessages.add(Common::Point(151, 61), 0xFDFC, 32, 70, 180, _game.getQuote(230));
				_shouldTalk = true;
			} else if ((_twinklesCurrentFrame == 75) && _shouldTalk)
				reset_frame = 60;

			if ((reset_frame >= 0) && (reset_frame != _scene->_activeAnimation->getCurrentFrame())) {
				_scene->_activeAnimation->setCurrentFrame(reset_frame);
				_twinklesCurrentFrame = reset_frame;
			}
		}

		if (_game._trigger == 70)
			_shouldTalk = false;
	}

	if ((_twinkleAnimationType == 1) && (_scene->_rails.getNext() > 0)) {
		_game._player.walk(Common::Point(214, 150), FACING_NORTHWEST);
		_scene->_rails.resetNext();
		_stopWalking = true;
	}
}

void Scene210::preActions() {
	_stopWalking = false;

	if (_action.isAction(VERB_WALK_DOWN, 0x1C1))
		_game._player._walkOffScreenSceneId = 211;
}

void Scene210::actions() {
	if (_action.isAction(VERB_LOOK, 0x27, 0x1C0)) {
		_vm->_dialogs->show(0x5219);
	} else if (_game._screenObjects._inputMode == 1) {
		handleConversations();
	} else if (_action.isAction(VERB_TALKTO, 0x1DC) ||
		((_game._player._playerPos == Common::Point(214, 150)) && (_game._player._facing == FACING_NORTHWEST) && (_twinkleAnimationType == 1) && _stopWalking)) {
		switch (_game._trigger) {
		case 0: {
			_game._player._stepEnabled = false;
			int quote;
			if (_globals[kTwinklesApproached] == 0)
				quote = 90;
			else if (_globals[kTwinklesApproached] == 1)
				quote = 115;
			else
				quote = 171;

			_shouldFaceRex = true;
			_nextHandsPlace = 0;
			_scene->_kernelMessages.reset();
			_scene->_kernelMessages.addQuote(quote, 1, 120);
			}
			break;

		case 1:
			_shouldTalk = true;
			if (!_twinklesTalking) {
				_scene->_sequences.addTimer(6, 1);
			} else {
				if (_globals[kTwinklesApproached] == 0) {
					handleTwinklesSpeech(0xAF, -1, 0);
					handleTwinklesSpeech(0xB0, 0, 0);
				} else if (_globals[kTwinklesApproached] == 1) {
					handleTwinklesSpeech(0xB1, 0, 0);
				} else {
					int quote = _twinklesTalk2 ? 0xB3 : 0xB2;
					_twinklesTalk2 = true;
					handleTwinklesSpeech(quote, 0, 0);
				}
				_scene->_sequences.addTimer(60, 3);
			}
			break;

		case 3:
			_game._player._stepEnabled = true;
			_shouldMoveHead = false;
			_shouldTalk = false;

			if (_globals[kTwinklesApproached] < 2)
				_globals[kTwinklesApproached]++;

			_conv1.start();
			_curDialogNode = 1;
			break;
		}
	} else if (_action.isAction(VERB_GIVE, 0x1DC) && _game._objects.isInInventory(_game._objects.getIdFromDesc(_action._activeAction._objectNameId))) {
		switch (_game._trigger) {
		case 0: {
			int quote = _vm->getRandomNumber(172, 174);
			_shouldMoveHead = true;
			_game._player._stepEnabled = false;
			handleTwinklesSpeech(quote, 0, 120);
			_scene->_sequences.addTimer(120, 1);
			}
			break;

		case 1:
			_game._player._stepEnabled = true;
			_shouldMoveHead = false;
			break;
		}
	} else if (_action.isAction(VERB_WALK_DOWN, 0x1BF) || _action.isAction(VERB_WALK_TOWARDS, 0x1C0)) {
		_scene->_nextSceneId = 205;
	} else if (_action.isAction(VERB_WALK_THROUGH, 0x70)) {
		_scene->_nextSceneId = 215;
	} else if ((_action.isAction(VERB_PULL, 0x5F) || _action.isAction(VERB_OPEN, 0x5F)) && !_globals[kCurtainOpen]) {
		switch (_game._trigger) {
		case 0:
			_game._player._stepEnabled = false;
			_scene->_sequences.remove(_globals._sequenceIndexes[1]);
			_globals._sequenceIndexes[1] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[1], false, 12, 1, 0, 0);
			_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 5);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[1], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
			break;

		case 1:
			_game._player._stepEnabled = true;
			_globals[kCurtainOpen] = true;
			_doorway = _scene->_dynamicHotspots.add(112, 395, -1, Common::Rect(163, 87, 163 + 19, 87 + 36));
			_scene->_dynamicHotspots.setPosition(_doorway, Common::Point(168, 127), FACING_NORTH);
			_scene->_dynamicHotspots.setCursor(_doorway, CURSOR_GO_UP);
			break;
		}
	} else if ((_action.isAction(VERB_PULL, 0x5F) || _action.isAction(VERB_CLOSE, 0x5F)) && _globals[kCurtainOpen]) {
		switch (_game._trigger) {
		case 0:
			_scene->_sequences.remove(_globals._sequenceIndexes[1]);
			_game._player._stepEnabled = false;
			_game._player._facing = FACING_NORTH;
			_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 12, 0, 0, 1);
			_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 5);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[1], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
			_game._player._stepEnabled = false;
			break;
		case 1:
			_globals._sequenceIndexes[1] = _scene->_sequences.startCycle(_globals._spriteIndexes[1], false, 5);
			_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 5);
			_scene->_sequences.addTimer(48, 2);
			break;
		case 2:
			_scene->_dynamicHotspots.remove(_doorway);
			_game._player._stepEnabled = true;
			_globals[kCurtainOpen] = false;
			break;
		}
	} else if (_action.isAction(VERB_LOOK, 0xAA)) {
		if (_globals[kTwinklesStatus] == TWINKLES_GONE) {
			if (_game._storyMode == STORYMODE_NAUGHTY)
				_vm->_dialogs->show(0x520B);
			else
				_vm->_dialogs->show(0x520A);
		} else {
			_vm->_dialogs->show(0x5209);
		}
	} else if (_action.isAction(VERB_LOOK, 0x31)) {
		_vm->_dialogs->show(0x520C);
	} else if (_action.isAction(VERB_LOOK, 0xA7)) {
		_vm->_dialogs->show(0x520D);
	} else if (_action.isAction(VERB_TAKE, 0xA7) || _action.isAction(VERB_TAKE, 0x31)) {
		_vm->_dialogs->show(0x520E);
	} else if (_action.isAction(VERB_LOOK, 0x1C5)) {
		_vm->_dialogs->show(0x520F);
	} else if (_action.isAction(VERB_LOOK, 0x3A)) {
		_vm->_dialogs->show(0x5210);
	} else if (_action.isAction(VERB_LOOK, 0x1B0)) {
		_vm->_dialogs->show(0x5211);
	} else if (_action.isAction(VERB_LOOK, 0x1DC)) {
		_vm->_dialogs->show(0x5212);
	} else if (_action.isAction(0x13A, 0x1DC) || _action.isAction(0xA6, 0x1DC)) {
		_vm->_dialogs->show(0x5213);
	} else if (_action.isAction(VERB_LOOK, 0x1BF)) {
		_vm->_dialogs->show(0x5214);
	} else if (_action.isAction(VERB_LOOK, 0x5F)) {
		_vm->_dialogs->show(0x5215);
	} else if (_action.isAction(VERB_LOOK, 0x53)) {
		_vm->_dialogs->show(0x5216);
	} else if (_action.isAction(VERB_TAKE, 0x53)) {
		_vm->_dialogs->show(0x5217);
	} else if (_action.isAction(VERB_LOOK, 0x1C0)) {
		_vm->_dialogs->show(0x5218);
	} else {
		// Not handled
		return;
	}

	_action._inProgress = false;
}

void Scene210::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsSint32LE(_curDialogNode);
	s.syncAsSint32LE(_nextHandsPlace);
	s.syncAsSint32LE(_twinkleAnimationType);
	s.syncAsSint32LE(_twinklesCurrentFrame);

	s.syncAsByte(_shouldTalk);
	s.syncAsByte(_shouldFaceRex);
	s.syncAsByte(_shouldMoveHead);
	s.syncAsByte(_stopWalking);
	s.syncAsByte(_twinklesTalking);
	s.syncAsByte(_twinklesTalk2);

	s.syncAsSint32LE(_doorway);

	s.syncString(_subQuote2);

	_conv1.synchronize(s);
	_conv2.synchronize(s);
	_conv3.synchronize(s);
	_conv5.synchronize(s);
	_conv6.synchronize(s);
	_conv7.synchronize(s);
	_conv8.synchronize(s);
}

/*------------------------------------------------------------------------*/

void Scene211::setup() {
	setPlayerSpritesPrefix();
	setAAName();

	_scene->addActiveVocab(0x144);
}

void Scene211::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites("*SC002Z2");
	_wakeFl = false;

	if (_scene->_priorSceneId == 210)
		_game._player._playerPos = Common::Point(25, 148);
	else if (_scene->_priorSceneId == 205) {
		_game._player._playerPos = Common::Point(49, 133);
		_game._player._facing = FACING_WEST;
		_wakeFl = true;
		_game._player._stepEnabled = false;
		_game._player._visible = false;
		_scene->loadAnimation(formAnimName('A', -1), 100);
		_scene->_activeAnimation->setCurrentFrame(169);
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(310, 31);
		_game._player._facing = FACING_SOUTHWEST;
	}

	if (_vm->getRandomNumber(1, 8) == 1) {
		_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 6, 0, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(202, 126));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 8);
		_scene->_sequences.setMotion(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_SPRITE, -200, 0);
		_scene->_dynamicHotspots.add(324, 13, _globals._sequenceIndexes[2], Common::Rect(1, 1, 1 + 41, 1 + 10));
	}

	if (_scene->_roomChanged)
		_game._objects.addToInventory(OBJ_BINOCULARS);

	_vm->_palette->setEntry(252, 63, 44, 30);
	_vm->_palette->setEntry(253, 63, 20, 22);
	_game.loadQuoteSet(0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 1, 0);

	if (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY)
		warning("sub71704(0x2, 0x0, 0x36, 0x0, 0x1E, 0xD, 2, 0xFDFC, 0x3C, 0x97, 0x98, 0x99, 0x9A, 0);");

	_monkeyTime = _vm->_game->_scene._frameStartTime;
	_scrollY = 30;

	_ambushFl = false;
	_monkeyFrame = 0;

	sceneEntrySound();
}

void Scene211::step() {
	if (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY) {
		warning("TODO: sub7178C()");

		if (!_ambushFl && !_wakeFl && (_vm->_game->_scene._frameStartTime >= _monkeyTime)) {
			warning("if (sub717B2(80, 1 + sub7176C())) {");
				_vm->_sound->command(18);
			// }
			_monkeyTime = _vm->_game->_scene._frameStartTime + 2;
		}

		if ((_game._player._playerPos == Common::Point(52, 132)) && (_game._player._facing == FACING_WEST) && !_game._player._moving &&
			(_game._trigger || !_ambushFl)) {
			switch (_game._trigger) {
			case 0:
				if (_game._objects.isInInventory(OBJ_BINOCULARS)) {
					_ambushFl = true;
					_monkeyFrame = 0;
					_game._player._stepEnabled = false;
					_game._player._visible = false;
					_scene->_kernelMessages.reset();
					_scene->loadAnimation(formAnimName('A', -1), 90);
					_vm->_sound->command(19);
					int count = (int)_game._objects._inventoryList.size();
					for (int idx = 0; idx < count; idx++) {
						if ((_game._objects._inventoryList[idx] == OBJ_BINOCULARS) && (_scene->_userInterface._selectedInvIndex != idx))
							_scene->_userInterface.selectObject(idx);
					}
				}
				break;

			case 90:
				_vm->_sound->command(10);
				_game._player._stepEnabled = true;
				_game._player._visible = true;
				_game._player._playerPos = Common::Point(49, 133);
				_ambushFl = false;
				_globals[kMonkeyStatus] = MONKEY_HAS_BINOCULARS;
				break;
			}
		}
	}

	if (_ambushFl && (_scene->_activeAnimation->getCurrentFrame() > _monkeyFrame)) {
		_monkeyFrame = _scene->_activeAnimation->getCurrentFrame();
		switch (_monkeyFrame) {
		case 2: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(12, 4), 0xFDFC, 0, 0, 60, _game.getQuote(157));
			_scene->_kernelMessages.setQuoted(msgIndex, 2, true);
			}
			break;

		case 12: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(35, 20), 0xFDFC, 0, 0, 60, _game.getQuote(155));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			}
			break;

		case 42: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(60, 45), 0xFDFC, 0, 0, 60, _game.getQuote(156));
			_scene->_kernelMessages.setQuoted(msgIndex, 6, true);
			}
			break;

		case 73:
			_scene->_kernelMessages.add(Common::Point(102, 95), 0xFDFC, 32, 0, 75, _game.getQuote(157));
			break;

		case 90: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(102, 95), 0xFDFC, 32, 0, 60, _game.getQuote(158));
			_scene->_kernelMessages.setQuoted(msgIndex, 6, true);
			}
			break;

		case 97:
			_scene->_userInterface.selectObject(-1);
			_game._objects.removeFromInventory(OBJ_BINOCULARS, 1);
			break;

		case 177: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(161));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			_scrollY += 14;
			}
			break;

		case 181: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(162));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			_scrollY += 14;
			}
			break;

		case 188: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(163));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			_scrollY += 14;
			}
			break;

		case 200: {
			int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(164));
			_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
			_scrollY += 14;
			}
			break;
		}
	}

	if (_wakeFl) {
		if (_game._trigger == 100) {
			_game._player._visible = true;
			_game._player._stepEnabled = true;
			_wakeFl = false;
		}

		if (_scene->_activeAnimation->getCurrentFrame() > _monkeyFrame) {
			_monkeyFrame = _scene->_activeAnimation->getCurrentFrame();
			switch (_scene->_activeAnimation->getCurrentFrame()) {
			case 177: {
				int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(165));
				_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
				_scrollY += 14;
				}
				break;

			case 181: {
				int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(166));
				_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
				_scrollY += 14;
				}
				break;

			case 188: {
				int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(167));
				_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
				_scrollY += 14;
				}
				break;

			case 200: {
				int msgIndex = _scene->_kernelMessages.add(Common::Point(63, _scrollY), 0x1110, 0, 0, 180, _game.getQuote(168));
				_scene->_kernelMessages.setQuoted(msgIndex, 4, true);
				_scrollY += 14;
				}
				break;
			}
		}
	}
}

void Scene211::preActions() {
	if (_action.isAction(VERB_WALK_DOWN, 0x1B2) && _game._objects.isInInventory(OBJ_BINOCULARS) && (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY)
	&& (_scene->_customDest.x <= 52) && (_scene->_customDest.y >= 132))
		_game._player.walk(Common::Point(52, 132), FACING_WEST);

	if (_action.isAction(VERB_WALK_DOWN, 0x1AE)) {
		if (_game._objects.isInInventory(OBJ_BINOCULARS) && (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY))
			_game._player.walk(Common::Point(52, 132), FACING_WEST);
		else
			_game._player._walkOffScreenSceneId = 210;
	}

	if (_action.isAction(VERB_WALK_DOWN, 0x1B1))
		_game._player._walkOffScreenSceneId = 207;
}

void Scene211::actions() {
	if (_action._lookFlag && (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY))
		_vm->_dialogs->show(0x5277);
	else if (_action.isAction(VERB_LOOK, 0x27, 0x100))
		_vm->_dialogs->show(0x527C);
	else if (_action.isAction(VERB_LOOK, 0x3A))
		_vm->_dialogs->show(0x526D);
	else if (_action.isAction(VERB_LOOK, 0x1B2))
		_vm->_dialogs->show(0x526E);
	else if (_action.isAction(VERB_LOOK, 0x100)) {
		if (_globals[kMonkeyStatus] == MONKEY_AMBUSH_READY) {
			if (_game._storyMode == STORYMODE_NAUGHTY)
				_vm->_dialogs->show(0x526F);
			else
				_vm->_dialogs->show(0x5270);
		} else {
			_vm->_dialogs->show(0x5271);
		}
	} else if (_action.isAction(VERB_LOOK, 0x1B3)) {
		if (_game._storyMode == STORYMODE_NAUGHTY)
			_vm->_dialogs->show(0x5272);
		else
			_vm->_dialogs->show(0x5273);
	} else if (_action.isAction(VERB_LOOK, 0xB8))
		_vm->_dialogs->show(0x5274);
	else if (_action.isAction(VERB_LOOK, 0x1B1))
		_vm->_dialogs->show(0x5275);
	else if (_action.isAction(VERB_LOOK, 0x1AE))
		_vm->_dialogs->show(0x5276);
	else if (_action.isAction(VERB_LOOK, 0x144))
		_vm->_dialogs->show(0x5279);
	else if (_action.isAction(VERB_TAKE, 0x144))
		_vm->_dialogs->show(0x527A);
	else if (_action.isAction(VERB_LOOK, 0x129))
		_vm->_dialogs->show(0x527B);
	else
		return;

	_action._inProgress = false;
}

void Scene211::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsByte(_ambushFl);
	s.syncAsByte(_wakeFl);

	s.syncAsSint32LE(_monkeyFrame);
	s.syncAsSint32LE(_scrollY);
	s.syncAsUint32LE(_monkeyTime);
}

/*------------------------------------------------------------------------*/

void Scene212::setup() {
	setPlayerSpritesPrefix();
	setAAName();

	_scene->addActiveVocab(0x19D);
}

void Scene212::enter() {
	// CHECKME: Some useless variables have been remove here

	if (_scene->_priorSceneId == 208) {
		_game._player._playerPos = Common::Point(195, 85);
		_game._player._facing = FACING_SOUTH;
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(67, 117);
		_game._player._facing = FACING_NORTHEAST;
	}

	sceneEntrySound();
}

void Scene212::step() {
// CHECKME: Could we move the dino?
}

void Scene212::preActions() {
	if (_action.isAction(VERB_WALK_THROUGH, 0x41))
		_game._player._walkOffScreenSceneId = 111;
}

void Scene212::actions() {
	if (_action._lookFlag)
		_vm->_dialogs->show(0x52D9);
	else if (_action.isAction(VERB_WALK_TOWARDS) && (_action.isObject(0x82) || _action.isObject(0xE8)))
		_scene->_nextSceneId = 208;
	else if (_action.isAction(VERB_WALK_TOWARDS, 0x3F))
		_scene->_nextSceneId = 111;
	else if (_action.isAction(VERB_LOOK, 0x19C))
		_vm->_dialogs->show(0x52D1);
	else if (_action.isAction(VERB_LOOK, 0x129))
		_vm->_dialogs->show(0x52D2);
	else if (_action.isAction(VERB_LOOK, 0x41))
		_vm->_dialogs->show(0x52D3);
	else if (_action.isAction(VERB_LOOK, 0x142))
		_vm->_dialogs->show(0x52D4);
	else if (_action.isAction(VERB_LOOK, 0x82))
		_vm->_dialogs->show(0x52D5);
	else if (_action.isAction(VERB_LOOK, 0x175))
		_vm->_dialogs->show(0x52D6);
	else if (_action.isAction(VERB_LOOK, 0x110))
		_vm->_dialogs->show(0x52D7);
	else if (_action.isAction(VERB_LOOK, 0xE8))
		_vm->_dialogs->show(0x52D8);
	else
		return;

	_action._inProgress = false;
}

/*------------------------------------------------------------------------*/

void Scene213::setup() {
	_game._player._spritesPrefix = "";

	// The original is calling Scene2xx::setAAName()
	_game._aaName = Resources::formatAAName(2);
}

void Scene213::enter() {
	if (_globals[kMeteorologistWatch] != 0)
		_handSpriteId = _scene->_sprites.addSprites("*METHAND");
	else if (_globals[kSexOfRex] == REX_MALE)
		_handSpriteId = _scene->_sprites.addSprites("*REXHAND");
	else
		_handSpriteId = _scene->_sprites.addSprites("*ROXHAND");

	teleporterEnter();

	// The original is calling Scene2xx::sceneEntrySound()
		if (_vm->_musicFlag) {
			if (_globals[kMeteorologistWatch] == 0)
				_vm->_sound->command(1);
			else
				_vm->_sound->command(9);
		} else
			_vm->_sound->command(2);
}

void Scene213::step() {
	teleporterStep();
}

void Scene213::actions() {
	if (teleporterActions()) {
		_action._inProgress = false;
		return;
	}

	if (_action.isAction(VERB_LOOK, 0x59))
		_vm->_dialogs->show(21301);
	else if (_action.isAction(VERB_LOOK, 0xC4) || _action.isAction (0xB7, 0xC4))
		_vm->_dialogs->show(21302);
	else if (_action.isAction(VERB_LOOK, 0x1CC))
		_vm->_dialogs->show(21303);
	else if (_action.isAction(VERB_LOOK, 0x181) || _action.isAction(0x103, 0x181))
		_vm->_dialogs->show(21304);
	else if (_action.isAction(VERB_LOOK, 0x1CF))
		_vm->_dialogs->show(21305);
	else if (_action.isAction(VERB_LOOK, 0x1D0) || _action.isAction(VERB_LOOK, 0x1D1)
	 || _action.isAction(VERB_LOOK, 0x1D2) || _action.isAction(VERB_LOOK, 0x1D3)
	 || _action.isAction(VERB_LOOK, 0x1D4) || _action.isAction(VERB_LOOK, 0x1D5)
	 || _action.isAction(VERB_LOOK, 0x1D6) || _action.isAction(VERB_LOOK, 0x1D7)
	 || _action.isAction(VERB_LOOK, 0x1D8) || _action.isAction(VERB_LOOK, 0x1D9)
	 || _action.isAction(VERB_LOOK, 0x1DB) || _action.isAction(VERB_LOOK, 0x7A)
	 || _action.isAction(VERB_LOOK, 0x1DA))
		_vm->_dialogs->show(21306);
	else
		return;

	_action._inProgress = false;
}

/*------------------------------------------------------------------------*/

void Scene214::setup() {
	setPlayerSpritesPrefix();
	setAAName();
	_scene->addActiveVocab(0x1C3);
	_scene->addActiveVocab(0xD);
}

void Scene214::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('e', 0));
	_globals._spriteIndexes[2] = _scene->_sprites.addSprites(formAnimName('e', 1));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('t', -1));
	_globals._spriteIndexes[4] = _scene->_sprites.addSprites("*RXMRD_7");

	_devilTime = _game._player._priorTimer;
	_devilRunningFl = false;

	if (_game._objects.isInRoom(OBJ_POISON_DARTS)) {
		_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[1], false, 6, 0, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[1], Common::Point(103, 86));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 11);
	} else {
		_scene->_hotspots.activate(0x114, false);
	}

	if (_game._objects.isInRoom(OBJ_BLOWGUN)) {
		_globals._sequenceIndexes[2] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[2], false, 6, 0, 0, 0);
		_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[2], Common::Point(90, 87));
		_scene->_sequences.setDepth(_globals._sequenceIndexes[2], 13);
	} else {
		_scene->_hotspots.activate(0x29, false);
	}

	if (_scene->_priorSceneId != -2)
		_game._player._playerPos = Common::Point(191, 152);

	sceneEntrySound();
}

void Scene214::step() {
	if ((_game._player._priorTimer - _devilTime > 800) && !_devilRunningFl) {
		_devilRunningFl = true;
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 9, 1, 6, 0);
		_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 1, 4);
		_scene->_sequences.setDepth(_globals._sequenceIndexes[3], 2);
		_scene->_dynamicHotspots.add(451, 13, _globals._sequenceIndexes[3], Common::Rect(0, 0, 0, 0));
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 71);
	}

	if (_devilRunningFl) {
		switch (_game._trigger) {
		case 71: {
			int oldIdx = _globals._sequenceIndexes[3];
			_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 9, 5, 0, 0);
			_scene->_sequences.updateTimeout(oldIdx, _globals._sequenceIndexes[3]);
			_scene->_dynamicHotspots.add(451, VERB_WALKTO, _globals._sequenceIndexes[3], Common::Rect(0, 0, 0, 0));
			_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 5, 8);
			_scene->_sequences.setDepth(_globals._sequenceIndexes[3], 2);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 72);
			}
			break;

		case 72: {
			int oldIdx = _globals._sequenceIndexes[3];
			_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 9, 1, 0, 0);
			_scene->_sequences.updateTimeout(oldIdx, _globals._sequenceIndexes[3]);
			_scene->_dynamicHotspots.add(451, VERB_WALKTO, _globals._sequenceIndexes[3], Common::Rect(0, 0, 0, 0));
			_scene->_sequences.setAnimRange(_globals._sequenceIndexes[3], 9, -2);
			_scene->_sequences.setDepth(_globals._sequenceIndexes[3], 2);
			_devilTime = _game._player._priorTimer;
			_devilRunningFl = false;
			}
			break;
		}
	}
}

void Scene214::actions() {
	if (_action._lookFlag)
		_vm->_dialogs->show(0x53B3);
	else if (_action.isAction(0x18A, 0xAA))
		_scene->_nextSceneId = 207;
	else if (_action.isAction(VERB_TAKE, 0x114) && (_game._trigger || _game._objects.isInRoom(OBJ_POISON_DARTS))) {
		switch (_game._trigger) {
		case 0:
			_game._player._stepEnabled = false;
			_game._player._visible = false;
			_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], true, 6, 1, 0, 0);
			_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[4]);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
			break;

		case 1:
			_globals._sequenceIndexes[4] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[4], true, 6, 1, 0, 0);
			_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[4]);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
			_scene->_sequences.remove(_globals._sequenceIndexes[1]);
			_game._objects.addToInventory(OBJ_POISON_DARTS);
			_scene->_hotspots.activate(0x114, false);
			break;

		case 2:
			_game._player._visible = true;
			_scene->_sequences.addTimer(48, 3);
			break;

		case 3:
			_game._player._stepEnabled = true;
			_vm->_dialogs->showItem(OBJ_POISON_DARTS, 0x53A5);
			break;
		}
	} else if (_action.isAction(VERB_TAKE, 0x29) && (_game._trigger || _game._objects.isInRoom(OBJ_BLOWGUN))) {
		switch (_game._trigger) {
		case 0:
			_game._player._stepEnabled = false;
			_game._player._visible = false;
			_globals._sequenceIndexes[4] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[4], false, 6, 1, 0, 0);
			_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[4]);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 1);
			break;

		case 1:
			_globals._sequenceIndexes[4] = _scene->_sequences.addReverseSpriteCycle(_globals._spriteIndexes[4], false, 6, 1, 0, 0);
			_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[4]);
			_scene->_sequences.addSubEntry(_globals._sequenceIndexes[4], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
			_scene->_sequences.remove(_globals._sequenceIndexes[2]);
			_game._objects.addToInventory(OBJ_BLOWGUN);
			_scene->_hotspots.activate(0x29, false);
			break;

		case 2:
			_game._player._visible = true;
			_scene->_sequences.addTimer(48, 3);
			break;

		case 3:
			_game._player._stepEnabled = true;
			_vm->_dialogs->showItem(OBJ_BLOWGUN, 0x329);
			break;
		}
	} else if (_action.isAction(VERB_LOOK, 0x197))
		_vm->_dialogs->show(0x5399);
	else if (_action.isAction(VERB_LOOK, 0x7E))
		_vm->_dialogs->show(0x539A);
	else if (_action.isAction(VERB_LOOK, 0x1C3))
		_vm->_dialogs->show(0x539B);
	else if (_action.isAction(VERB_LOOK, 0x21))
		_vm->_dialogs->show(0x539C);
	else if (_action.isAction(VERB_LOOK, 0x1BB))
		_vm->_dialogs->show(0x539D);
	else if (_action.isAction(VERB_LOOK, 0x1BE)) {
		if (_game._storyMode == STORYMODE_NAUGHTY) {
			_vm->_dialogs->show(0x539E);
		} else {
			_vm->_dialogs->show(0x539F);
		}
	} else if (_action.isAction(VERB_LOOK, 0x1BC))
		_vm->_dialogs->show(0x53A0);
	else if (_action.isAction(VERB_TAKE, 0x1BE) || _action.isAction(VERB_TAKE, 0x1BC))
		_vm->_dialogs->show(0x53A1);
	else if (_action.isAction(VERB_LOOK, 0x13D))
		_vm->_dialogs->show(0x53A2);
	else if (_action.isAction(VERB_TAKE, 0x13D) || _action.isAction(VERB_TAKE, 0x48A))
		_vm->_dialogs->show(0x53A3);
	else if (_action.isAction(VERB_LOOK, 0x48A))
		_vm->_dialogs->show(0x53B4);
	else if (_action.isAction(VERB_LOOK, 0x114) && (_action._savedFields._mainObjectSource == 4))
		_vm->_dialogs->show(0x53A4);
	else if (_action.isAction(VERB_OPEN, 0x7E))
		_vm->_dialogs->show(0x53A6);
	else if (_action.isAction(VERB_TALKTO, 0x1C3))
		_vm->_dialogs->show(0x53A7);
	else if (_action.isAction(VERB_GIVE, 0x17A, 0x1C3))
		_vm->_dialogs->show(0x53A8);
	else if (_action.isAction(0x13A, 0x29, 0x1C3) || _action.isAction(0xA6, 0x29, 0x1C3))
		_vm->_dialogs->show(0x53A9);
	else if (_action.isAction(VERB_LOOK, 0x473))
		_vm->_dialogs->show(0x53AA);
	else if (_action.isAction(VERB_TAKE, 0x473))
		_vm->_dialogs->show(0x53AB);
	else if (_action.isAction(VERB_TAKE, 0x21))
		_vm->_dialogs->show(0x53AC);
	else if (_action.isAction(VERB_LOOK, 0x8A))
		_vm->_dialogs->show(0x53AD);
	else if (_action.isAction(VERB_LOOK, 0x29))
		_vm->_dialogs->show(0x53AE);
	else if (_action.isAction(VERB_LOOK, 0x160)) {
		if (_game._objects.isInRoom(OBJ_POISON_DARTS) && _game._objects.isInRoom(OBJ_BLOWGUN)) {
			_vm->_dialogs->show(0x53AF);
		} else if (_game._objects.isInRoom(OBJ_POISON_DARTS) && !_game._objects.isInRoom(OBJ_BLOWGUN)) {
			_vm->_dialogs->show(0x53B0);
		} else if (!_game._objects.isInRoom(OBJ_POISON_DARTS) && _game._objects.isInRoom(OBJ_BLOWGUN)) {
			_vm->_dialogs->show(0x53B1);
		} else {
			_vm->_dialogs->show(0x53B2);
		}
	} else
		return;

	_action._inProgress = false;
}

void Scene214::synchronize(Common::Serializer &s) {
	Scene2xx::synchronize(s);
	s.syncAsUint32LE(_devilTime);

	s.syncAsByte(_devilRunningFl);
}

/*------------------------------------------------------------------------*/

void Scene215::setup() {
	setPlayerSpritesPrefix();
	setAAName();
}

void Scene215::enter() {
	_globals._spriteIndexes[1] = _scene->_sprites.addSprites(formAnimName('e', 0));
	_globals._spriteIndexes[3] = _scene->_sprites.addSprites(formAnimName('a', 0));

	_globals._sequenceIndexes[1] = _scene->_sequences.addSpriteCycle (_globals._spriteIndexes[1], false, 7, 0, 0, 0);
	_scene->_sequences.setMsgPosition(_globals._sequenceIndexes[1], Common::Point(235, 83));
	_scene->_sequences.setDepth(_globals._sequenceIndexes[1], 15);

	if (_globals[kSexOfRex] == REX_MALE)
		_globals._spriteIndexes[2] = _scene->_sprites.addSprites("*RXMRC_9");
	else
		_globals._spriteIndexes[2] = _scene->_sprites.addSprites("*ROXRC_9");

	if (_scene->_priorSceneId == 216) {
		_game._player._playerPos = Common::Point(140, 119);
		_game._player._facing = FACING_SOUTHWEST;
		_game._player._visible = false;
		_game._player._stepEnabled = false;
		_globals._sequenceIndexes[3] = _scene->_sequences.startCycle(_globals._spriteIndexes[3], false, 1);
		_scene->_sequences.addTimer(120, 70);
	} else if (_scene->_priorSceneId != -2) {
		_game._player._playerPos = Common::Point(204, 152);
		_game._player._facing = FACING_NORTH;
	}

	_game.loadQuoteSet(0xA9, 0xAA, 0);
	sceneEntrySound();
}

void Scene215::step() {
	if (_game._trigger == 70) {
		_scene->_sequences.remove (_globals._sequenceIndexes[3]);
		_globals._sequenceIndexes[3] = _scene->_sequences.addSpriteCycle(_globals._spriteIndexes[3], false, 6, 1, 0, 0);
		_scene->_sequences.addSubEntry(_globals._sequenceIndexes[3], SEQUENCE_TRIGGER_EXPIRE, 0, 71);
	}

	if (_game._trigger == 71) {
		_scene->_sequences.updateTimeout(-1, _globals._sequenceIndexes[3]);
		_game._player._visible = true;
		_game._player._stepEnabled = true;
	}
}

void Scene215::actions() {
	if (_action._lookFlag)
		_vm->_dialogs->show(0x5405);
	else if (_action.isAction(VERB_TAKE, 0x17A)) {
		if (!_game._objects.isInInventory(OBJ_TWINKIFRUIT) || _game._trigger) {
			switch (_game._trigger) {
			case 0:
				if (_globals[kSexOfRex] == REX_MALE) {
					_game._player._visible = false;
					_game._player._stepEnabled = false;
					_globals._sequenceIndexes[2] = _scene->_sequences.startReverseCycle(_globals._spriteIndexes[2], false, 6, 2, 0, 0);
					_scene->_sequences.setAnimRange(_globals._sequenceIndexes[2], 1, 4);
					_scene->_sequences.setMsgLayout(_globals._sequenceIndexes[2]);
					_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_LOOP, 0, 1);
					_scene->_sequences.addSubEntry(_globals._sequenceIndexes[2], SEQUENCE_TRIGGER_EXPIRE, 0, 2);
				} else {
					_game._objects.addToInventory(OBJ_TWINKIFRUIT);
					_vm->_dialogs->showItem(OBJ_TWINKIFRUIT, 0x5404);
				}
				break;

			case 1:
				if (!_game._objects.isInInventory(OBJ_TWINKIFRUIT)) {
					_game._objects.addToInventory(OBJ_TWINKIFRUIT);
					_vm->_dialogs->showItem(OBJ_TWINKIFRUIT, 0x5404);
				}
				break;

			case 2:
				_game._player._visible = true;
				_game._player._stepEnabled = true;
				_scene->_sequences.updateTimeout(-1, _globals._sequenceIndexes[2]);
				break;
			}
		} else {
			int idx = _vm->getRandomNumber(169, 170);
			_scene->_kernelMessages.reset();
			_scene->_kernelMessages.add(Common::Point(0, 0), 0x1110, 34, 0, 120, _game.getQuote(idx));
		}
	} else if (_action.isAction(0x18A, 0xAA))
		_scene->_nextSceneId = 210;
	else if (_action.isAction(VERB_LOOK, 0x21))
		_vm->_dialogs->show(0x53FD);
	else if (_action.isAction(VERB_LOOK, 0x1CB))
		_vm->_dialogs->show(0x53FE);
	else if (_action.isAction(VERB_LOOK, 0x3A3))
		_vm->_dialogs->show(0x53FF);
	else if (_action.isAction(VERB_LOOK, 0xD5))
		_vm->_dialogs->show(0x5400);
	else if (_action.isAction(VERB_LOOK, 0x197))
		_vm->_dialogs->show(0x5401);
	else if (_action.isAction(VERB_LOOK, 0x289))
		_vm->_dialogs->show(0x5402);
	else if (_action.isAction(VERB_LOOK, 0x17A) && (_action._savedFields._mainObjectSource == 4))
		_vm->_dialogs->show(0x5403);
	else if (_action.isAction(VERB_TAKE, 0x21))
		_vm->_dialogs->show(0x5406);
	else if (_action.isAction(VERB_TAKE, 0xD5))
		_vm->_dialogs->show(0x5407);
	else if (_action.isAction(VERB_LOOK, 0x1CA))
		_vm->_dialogs->show(0x5408);
	else if (_action.isAction(VERB_TAKE, 0x1CA))
		_vm->_dialogs->show(0x5409);
	else if (_action.isAction(VERB_TAKE, 0x3A3))
		_vm->_dialogs->show(0x540A);
	else
		return;

	_action._inProgress = false;
}

/*------------------------------------------------------------------------*/

void Scene216::setup() {
	setPlayerSpritesPrefix();
	setAAName();
}

void Scene216::enter() {
	_game._player._stepEnabled = false;
	_game._player._visible = false;

	_scene->_userInterface.emptyConversationList();
	_scene->_userInterface.setup(kInputConversation);
	_scene->loadAnimation(formAnimName('A', -1), 60);

	sceneEntrySound();
}

void Scene216::step() {
	if (_game._trigger == 60)
		_scene->_nextSceneId = 215;
}

/*------------------------------------------------------------------------*/

} // End of namespace Nebular
} // End of namespace MADS
