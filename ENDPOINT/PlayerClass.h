﻿#include"GameObject.h"
#include"Menu.h"

#pragma once

class PlayerClass
{
public:
	PlayerClass() {};
	PlayerClass(Texture _animation[4][20], EffectClass effect[3], Audio _audio[19], CSV AnimationData, CSV TextureShiftData, CSV statusData, CSV skillPointStatData, CSV experienceBorder, CSV magicSkillPointData, CSV magicOther)
	{
		gameObject.Reload(_animation, effect, _audio, AnimationData,TextureShiftData,statusData,skillPointStatData,experienceBorder,magicSkillPointData,magicOther);
	};

	enum class MenuUpdateProcess
	{
		FirstScene, Item, Status, SkillPoint, SkillPointNomalAllocation, SkillPointMagicAllocation, MagicSelect, FinalConfirmation
	};

	MenuUpdateProcess selectScene = MenuUpdateProcess::FirstScene;;

	GameObject gameObject;

	MagicType ChangeMagicType = MagicType::FIREBALL;

	StatusType currentStatus = StatusType::HP;

	//バーの定義
	Bar hitpointBar{};
	Bar magicpointBar{ Palette::Blue};
	Bar mentalpointBar{ Palette::Purple};
	Bar staminapointBar{ Palette::Yellow};

	Array<String> firstMenuChara;
	Menu firstMenu;

	Array<String> itemMenuChara;
	Menu itemMenu;

	Array<String> statusMenuChara;
	Array<String> magicMenuChara;
	Menu statusMenu;
	Menu magicMenu;

	Array<String> skillPointMenuChara;
	Menu skillPointMenu;

	Array<String> skillPointNomalAllocationChara;
	Menu skillPointNomalAllocationMenu;

	Array<int> skillPointChar;
	Menu skillPointStateMenu;

	Array<int> remainingPointChara;
	Menu remainingPointMenu;

	Array<String> skillAllocationIncreaseAmountChara;
	Menu skillAllocationIncreaseAmountMenu{Palette::Lightgrey,Palette::White};

	Array<String>magicSelectChara;
	Menu magicSelectMenu;

	Array<String>skillPointMagicAllocationChara;
	Menu skillPointMagicAllocationMenu;

	Array<int> skillPointMagicStateChar;
	Menu skillPointMagicStateMenu;

	Array<String> skillMagicAllocationIncreaseAmountChara;
	Menu skillMagicAllocationIncreaseAmountMenu{ Palette::Lightgrey,Palette::White };

	Array<String>finalConfirmationChara;
	Menu finalConfirmationMenu;

	Array<double> statusChar;
	Array<double> magicChar;


	
	Font font30{ 30 ,U"Material/6.font/jfdotfont-20150527/JF-Dot-ShinonomeMin12.ttf" };//フォント

	bool isOnline = false;

	StatusClass status;

	Audio selectAudio{ U"Material/4.SE/16.ゲームを一時停止した時1.mp3" };


	void Initialize();

	void BarInitialize();

	void Update();

	void PlayAudio();

	void skillPointAdd();

	void MagicSkillPointAdd(int changeNumber);

	void ChangeMagic(MagicType currentMagic);

	void ConfigOnlineProcess();

	void ConfigOnlineDraw()const;

	void CharSet();

	void StatusDraw()const;

	void Draw()const;

	void DebugDraw()const;
};




