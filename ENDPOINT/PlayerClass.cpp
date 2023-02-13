﻿#include"PlayerClass.h"
#pragma once

void PlayerClass::Initialize()
{
	//初期座標
	gameObject.screenPosition = { 250,125 };

	//初期移動量
	gameObject.velocity = { 0,0 };

	//ストップウォッチスタート
	gameObject.MotionStart();


	//初期化、初期定義
	//バーの情報を定義
	hitpointBar.Initialize(gameObject.status.hitPoint);
	magicpointBar.Initialize(gameObject.status.magicPoint);
	mentalpointBar.Initialize(gameObject.status.mental);
	staminapointBar.Initialize(gameObject.status.stamina);
}

void PlayerClass::Update()
{
	//GameObjectのUpdateを実行
	gameObject.Update();

	gameObject.MapPosition = gameObject.screenPosition + GameData::cameraPos;

	//バーの見た目を現在の数値に更新
	hitpointBar.Update(gameObject.status.currentHitPoint);
	magicpointBar.Update(gameObject.status.currentMagicPoint);
	mentalpointBar.Update(gameObject.status.currentMental);
	staminapointBar.Update(gameObject.status.currentStamina);

	//スタミナと魔力が自然回復
	if (gameObject.status.currentStamina <= gameObject.status.stamina)gameObject.status.currentStamina += 1.0 / 60.0;
	if (gameObject.status.currentMagicPoint <= gameObject.status.magicPoint)gameObject.status.currentMagicPoint += 1.0 / 60.0;

	//毎フレーム更新
	CharSet();
}

void PlayerClass::CharSet()
{
	firstMenuChara = { U"アイテム",U"ステータス",U"スキルポイント",U"閉じる" };
	itemMenuChara = {  };
	statusMenuChara = { U"レベル",U"HP",U"MP",U"スタミナ",U"精神力",U"攻撃力",U"魔力",U"防御力",U"重量", U"魔法" };
	magicMenuChara = { U"威力",U"速度",U"クールタイム",U"大きさ" };
	skillPointMenuChara = { U"通常",U"魔法",U"戻る" };
	skillPointNomalAllocationChara = { U"HP",U"スタミナ",U"精神力",U"攻撃力",U"防御力",U"重量",U"魔法",U"MP",U"基礎魔力",U"戻る" };

	//UIの情報を代入
	statusChar =
	{
						(double)gameObject.status.level	,
						gameObject.status.hitPoint		,
						gameObject.status.magicPoint	,
						gameObject.status.stamina		,
						gameObject.status.mental		,
						gameObject.status.power			,
						gameObject.status.magicPower	,
						gameObject.status.protection	,
						gameObject.status.weight
	};

	magicChar =
	{
					   gameObject.status.magicProficiencyPower	,
					   gameObject.status.subSkill				,
					   gameObject.status.coolTime				,
					   gameObject.status.specialFunctioVernValue
	};

	skillPointChar =
	{
					   gameObject.status.hitPointAllotted	,
					   gameObject.status.staminaAllotted	,
					   gameObject.status.mentalAllotted		,
					   gameObject.status.powerAllotted		,
					   gameObject.status.protectionAllotted	,
					   gameObject.status.weightAllotted		,
					   0									,
					   gameObject.status.magicPointAllotted	,
					   gameObject.status.magicPowerAllotted
	};

	remainingPointChara =
	{
		gameObject.status.skillPoint
	};

	skillAllocationIncreaseAmountChara =
	{
		U"1            10up",
		U"2            10up",
		U"3            10up",
		U"4            10up",
		U"5            10up",
		U"6            10up",
		U"7            10up",
		U"8            10up",
		U"9            10up",
		U"10           10up"
	};

	magicSelectChara =
	{
		U"火球",
		U"サンダー",
		U"回復",
		U"ステータスアップ",
		U"タイム",
		U"戻る"
	};

	//String
	firstMenu.StringSet(firstMenuChara, { 20,20 });
	itemMenu.StringSet(itemMenuChara, { 100,10 });
	statusMenu.StringSet(statusMenuChara, { 350,20 });
	magicMenu.StringSet(magicMenuChara, { 380,((statusMenuChara.size()) * 45) + 15 });
	skillPointMenu.StringSet(skillPointMenuChara, { 340,20 });
	skillPointNomalAllocationMenu.StringSet(skillPointNomalAllocationChara, { 520,20 });
	skillAllocationIncreaseAmountMenu.StringSet(skillAllocationIncreaseAmountChara, { 820,20 });
	magicSelectMenu.StringSet(magicSelectChara, { 820,20 });

	//int
	skillPointStateMenu.intSet(skillPointChar, { 750,20 });
	remainingPointMenu.intSet(remainingPointChara, { 760,495 });
}

void PlayerClass::skillPointAdd()
{
	//スキルポイント加算
	if ((KeyZ.down() || KeyEnter.down()) && gameObject.status.IsEnoughSkillPoint(currentStatus) == 0 && gameObject.status.IsAllocateSkillPoint(currentStatus))
	{
		gameObject.status.SkillPointAdd(currentStatus, MagicType::FIREBALL);

		Initialize();
	}
}

void PlayerClass::ChangeMagic()
{
	//スキルポイント加算
	if ((KeyZ.down() || KeyEnter.down()) && gameObject.status.IsEnoughSkillPoint(currentStatus) == 0 && gameObject.status.IsAllocateSkillPoint(currentStatus))
	{
		gameObject.status.SkillPointAdd(currentStatus, gameObject.status.magicType);

		Initialize();
	}
}

void PlayerClass::Draw()const
{
	//GameobjectのDrawを実行
	gameObject.Draw();

	//バーなどの描画
	StatusDraw();
}

void PlayerClass::StatusDraw() const
{
	//バーを描画する座標
	RectF hitpointBarRect = {10,10,500,50};
	RectF magicpointBarRect = {10,65,500,20};
	RectF mentalpointBarRect = {10,90,500,20};
	RectF staminapointBarRect = {gameObject.GetHitRect().x + gameObject.GetHitRect().w + 10,gameObject.GetHitRect().y,20,100};

	//常に描画
	hitpointBar.DrawSideways(hitpointBarRect);
	magicpointBar.DrawSideways(magicpointBarRect);
	mentalpointBar.DrawSideways(mentalpointBarRect);

	//スタミナが最大でないなら描画
	if (gameObject.status.currentStamina < gameObject.status.stamina)
	{
		staminapointBar.DrawPortrait(staminapointBarRect);
	}
}

void PlayerClass::ConfigOnlineProcess()
{

	//キャラコンフィグがオンラインになったら処理を実行(Eキーが押されたら)
	if (isOnline)
	{
		//現在操作できるシーン
		//選択するメニュー数に応じた数が必要
		switch (selectMenu)
		{
			//------------------------------------------------------------------------------
		case PlayerClass::MenuTransition::FirstScene://最初の選択画面{ U"アイテム",U"ステータス",U"スキルポイント",U"閉じる" }

			//最初の選択画面を選択できる処理
			firstMenu.Update();

			//最初の選択画面で選んでいるメニューを選択したときの処理
			switch (firstMenu.IsCurrent())
			{
			case 0://アイテム
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//アイテムに遷移
					selectMenu = MenuTransition::Item;
					selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
				}
				break;
			case 1://ステータス
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//ステータスに遷移
					selectMenu = MenuTransition::Status;
					selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
				}
				break;
			case 2://スキルポイント
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//スキルポイントに遷移
					selectMenu = MenuTransition::SkillPoint;
					selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
				}
				break;
			case 3://閉じる
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//キャラコンフィグ画面を閉じる
					isOnline = false;
					selectMenu = MenuTransition::FirstScene;

					//初期化
					firstMenu.Initialize();

					selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
				}
				break;
			default:
				break;
			}
			break;
			//------------------------------------------------------------------------------


			//------------------------------------------------------------------------------

		case PlayerClass::MenuTransition::Item:
			if (KeyZ.down() || KeyEnter.down())
			{
				selectMenu = MenuTransition::FirstScene;
			}
			break;

			//------------------------------------------------------------------------------



			//------------------------------------------------------------------------------

		case PlayerClass::MenuTransition::Status://ステータス確認画面,ここでは上下選択はない{ U"レベル",U"HP",U"MP",U"スタミナ",U"精神力",U"攻撃力",U"魔力",U"防御力",U"重量", U"魔法"}
			if (KeyZ.down() || KeyEnter.down())
			{
				selectMenu = MenuTransition::FirstScene;
			}
			break;

			//------------------------------------------------------------------------------



			//------------------------------------------------------------------------------

		case PlayerClass::MenuTransition::SkillPoint://スキルポイントの最初の画面{ U"通常",U"魔法",U"戻る" }

			switch (selectSkillPointMenu)
			{
			case PlayerClass::SkillPointMenuTransition::SkillPointFirstMenu:
				//スキルポイントの最初の選択画面を選択できる処理
				skillPointMenu.Update();
				//スキルポイントの最初の選択画面で選んでいるメニューを選択したときの処理
				switch (skillPointMenu.IsCurrent())
				{
				case 0://通常
					if (KeyZ.down() || KeyEnter.down() || skillPointMenu.IsMouseOver() && MouseL.down())
					{
						//通常スキルポイント分配画面に遷移
						selectSkillPointMenu = SkillPointMenuTransition::SkillPointNomalAllocation;
						selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
					}
					break;
				case 1://魔法
					if (KeyZ.down() || KeyEnter.down() || skillPointMenu.IsMouseOver() && MouseL.down())
					{
						//魔法スキルポイント分配画面に遷移
						selectSkillPointMenu = SkillPointMenuTransition::SkillPointMagicAllocation;
						selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
					}
					break;
				case 2://戻る
					if (KeyZ.down() || KeyEnter.down() || skillPointMenu.IsMouseOver() && MouseL.down())
					{
						//初期化
						skillPointMenu.Initialize();

						//一つ前の画面に戻る
						selectMenu = MenuTransition::FirstScene;
						selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
					}
					break;
				default:
					break;
				}
				break;
			case PlayerClass::SkillPointMenuTransition::SkillPointNomalAllocation:

				//通常スキルポイント分配画面を選択できる処理
				skillPointNomalAllocationMenu.Update();
			
				skillPointStateMenu.InterlockingUpdate(skillPointNomalAllocationMenu);

				switch (skillPointNomalAllocationMenu.IsCurrent())
				{
				case 0:
					currentStatus = StatusType::HP;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.hitPointAllotted;
					break;
				case 1:
					currentStatus = StatusType::STAMINA;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.staminaAllotted;
					break;
				case 2:
					currentStatus = StatusType::MENTAL;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.mentalAllotted;
					break;
				case 3:
					currentStatus = StatusType::POWER;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.powerAllotted;
					break;
				case 4:
					currentStatus = StatusType::PROTECTION;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.protectionAllotted;
					break;
				case 5:
					currentStatus = StatusType::WEIGHT;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.weightAllotted;
					break;
				case 6:
					currentStatus = StatusType::MAGICTYPE;
					if (KeyZ.down() || KeyEnter.down() || skillPointNomalAllocationMenu.IsMouseOver() && MouseL.down())
					{
						selectSkillPointMenu = SkillPointMenuTransition::SkillPointMagicSelect;
					}
					break;
				case 7:
					currentStatus = StatusType::MP;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.magicPointAllotted;
					break;
				case 8:
					currentStatus = StatusType::MAGICPOWER;
					skillPointAdd();
					skillAllocationIncreaseAmountMenu.menuID = gameObject.status.magicPowerAllotted;
					break;
				case 9:
					if (KeyZ.down() || KeyEnter.down() || skillPointNomalAllocationMenu.IsMouseOver() && MouseL.down())
					{
						selectSkillPointMenu = SkillPointMenuTransition::SkillPointFirstMenu;
					}
					break;
				default:
					break;
				}
				break;
			case PlayerClass::SkillPointMenuTransition::SkillPointMagicAllocation:
				break;
			case PlayerClass::SkillPointMenuTransition::SkillPointMagicSelect:
				magicSelectMenu.Update();
				ChangeMagic();
				break;
			default:
				break;
			}
			break;

			//------------------------------------------------------------------------------

		default:
			break;
		}
	}
}

void PlayerClass::ConfigOnlineDraw() const
{
	//キャラコンフィグがオンラインになったら描画を実行(Eキーが押されたら)
	//描画は処理が動いてなくても描画し続ける場合がある
	if (isOnline)
	{
		//後ろの四角い枠
		Rect window1 = { 10,10,300,190 };
		Rect window2 = { 10,230,200,40 };

		window1.drawFrame(10, Palette::White).draw(Palette::Black);
		window2.drawFrame(10, Palette::White).draw(Palette::Black);

		//メニュー描画
		firstMenu.InRectDraw(true);

		//所持金を描画
		font30(U"1000＄").draw(20, 235, Palette::White);

		//シーンごとの描画処理,階層別にする必要がある(裏で描画し続けるため)
		switch (selectMenu)
		{
		case PlayerClass::MenuTransition::Item:
			break;
		case PlayerClass::MenuTransition::Status:
			//後ろの四角い枠
			Rect window3 = { 330,10,400,690 };

			window3.drawFrame(10, Palette::White).draw(Palette::Black);

			//ステータスの項目を表示
			statusMenu.InRectDraw(false);
			magicMenu.InRectDraw(false);

			//ステータスの数値を表示
			for (int i = 0; i < statusChar.size(); i++)
			{
				//桁数計算
				int number = statusChar[i];
				int digit = 0;
				while (number != 0)
				{
					number = number / 10;
					digit++;
				}
				//数値が0だと桁数が0になるので加算
				if (digit == 0)digit = 1;

				//描画
				font30(statusChar[i]).draw(715 - digit * (statusMenu.fontSize / 2), statusMenu.startPos.y + ((statusMenu.fontSize * 1.5) * i));
			}

			//魔法の種類を描画
			font30(gameObject.status.magicTypeMame).draw(715 - gameObject.status.magicTypeMame.length() * (gameObject.status.magicType == MagicType::NONE ? 15 : 30), (statusChar.size() * 45) + 15);


			//ステータスの数値を表示
			for (int i = 0; i < magicMenuChara.size(); i++)
			{
				//桁数計算
				int number = (int)magicChar[i];
				int digit = 0;
				while (number != 0)
				{
					number = number / 10;
					digit++;
				}
				//数値が0だと桁数が0になるので加算
				if (digit == 0)digit = 1;
				//描画
				font30(magicChar[i]).draw(715 - digit * (magicMenu.fontSize / 2), magicMenu.startPos.y + ((magicMenu.fontSize * 1.5) * i));
			}

			font30(U"次のレベルまで").draw(statusMenu.startPos.x, magicMenu.startPos.y + ((magicMenu.fontSize * 1.5) * 4));

			for (int i = 0; i < 1; i++)
			{
				//桁数計算
				int number = gameObject.status.NextLevel();
				int digit = 0;
				while (number != 0)
				{
					number = number / 10;
					digit++;
				}
				//数値が0だと桁数が0になるので加算
				if (digit == 0)digit = 1;
				font30(gameObject.status.NextLevel(), U"EXP").draw((715 - (15 * 3)) - digit * 15, magicMenu.startPos.y + ((magicMenu.fontSize * 1.5) * 4));
			}
			break;

		case PlayerClass::MenuTransition::SkillPoint:
			//後ろの四角い枠
			Rect window4 = { 330,10,150,140 };

			window4.drawFrame(10, Palette::White).draw(Palette::Black);

			//メニュー描画
			skillPointMenu.InRectDraw(true);

			switch (selectSkillPointMenu)
			{
			case PlayerClass::SkillPointMenuTransition::SkillPointNomalAllocation:
				//後ろの四角い枠
				Rect window5 = { 500,10,280,460 };
				Rect window6 = { 610,490,170,40 };
				

				window5.drawFrame(10, Palette::White).draw(Palette::Black);
				window6.drawFrame(10, Palette::White).draw(Palette::Black);

				/*font30(U"体力").draw(520,15);
				font30(U"筋力").draw(520,155);
				font30(U"魔力").draw(520,290);*/

				//メニュー描画
				skillPointNomalAllocationMenu.InRectDraw(true);

				skillPointStateMenu.NumberDraw_int(true);

				remainingPointMenu.NumberDraw_int(false);

				if (skillPointNomalAllocationMenu.IsCurrent() != 6)
				{
					Rect window7 = { 800,10,290,380 };
					window7.drawFrame(10, Palette::White).draw(Palette::Black);

					skillAllocationIncreaseAmountMenu.TwoWayDraw();
				}
				else
				{
					Rect window7 = { 800,10,290,280 };
					window7.drawFrame(10, Palette::White).draw(Palette::Black);

					magicSelectMenu.InRectDraw(false);
				}
				

				font30(U"ポイント").draw(620,495);

				break;
			case PlayerClass::SkillPointMenuTransition::SkillPointMagicAllocation:
				break;
			case PlayerClass::SkillPointMenuTransition::SkillPointMagicSelect:
				break;
			default:
				break;
			}
			
			break;
		}
	}
}



