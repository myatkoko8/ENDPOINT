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

	BarInitialize();
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

	for (int i = 0; i < 11; i++)
	{
		Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus][i]);
	}

	skillAllocationIncreaseAmountChara =
	{
		{U"1            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][1]) + U"up" } ,
		{U"2            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][2]) + U"up" } ,
		{U"3            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][3]) + U"up" } ,
		{U"4            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][4]) + U"up" } ,
		{U"5            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][5]) + U"up" } ,
		{U"6            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][6]) + U"up" } ,
		{U"7            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][7]) + U"up" } ,
		{U"8            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][8]) + U"up" } ,
		{U"9            " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][9]) + U"up" } ,
		{U"10           " + (String)Parse<String>(gameObject.status.copySkillPointStatData[(int)currentStatus+1][10]) + U"up" } ,
	};

	skillMagicAllocationIncreaseAmountChara =
	{
		{U"1           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[skillPointMagicAllocationMenu.IsCurrent()+1][1+2]) + U"up"},
		{U"2           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[skillPointMagicAllocationMenu.IsCurrent()+1][2+2]) + U"up"},
		{U"3           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[skillPointMagicAllocationMenu.IsCurrent()+1][3+2]) + U"up"},
		{U"4           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[skillPointMagicAllocationMenu.IsCurrent()+1][4+2]) + U"up"},
		{U"5           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[skillPointMagicAllocationMenu.IsCurrent()+1][5+2]) + U"up"}
	};

	//{ U"1           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[(int)gameObject.status.magicType + 2][1]) + U"up"},
	//{ U"2           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[(int)gameObject.status.magicType + 2][2]) + U"up" },
	//{ U"3           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[(int)gameObject.status.magicType + 2][3]) + U"up" },
	//{ U"4           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[(int)gameObject.status.magicType + 2][4]) + U"up" },
	//{ U"5           " + (String)Parse<String>(gameObject.status.copyMagicSkillPointData[(int)gameObject.status.magicType + 2][5]) + U"up" }

	

	magicSelectChara =
	{
		U"火球",
		U"サンダー",
		U"ヒール",
		U"ステータスアップ",
		U"タイム",
		U"戻る"
	};

	skillPointMagicAllocationChara =
	{
		U"威力",
		U"速度",
		U"クールタイム",
		U"大きさ",
		U"戻る"
	};

	skillPointMagicStateChar =
	{
		gameObject.status.magicSkillPointAllocation[0],
		gameObject.status.magicSkillPointAllocation[1],
		gameObject.status.magicSkillPointAllocation[2],
		gameObject.status.magicSkillPointAllocation[3]
	};

	finalConfirmationChara =
	{
		U"はい",
		U"いいえ"
	};


	//String
	firstMenu.StringSet(firstMenuChara, { 20,20 });
	itemMenu.StringSet(itemMenuChara, { 100,10 });
	statusMenu.StringSet(statusMenuChara, { 350,20 });
	magicMenu.StringSet(magicMenuChara, { 380,((statusMenuChara.size()) * 45) + 15 });
	skillPointMenu.StringSet(skillPointMenuChara, { 340,20 });
	skillPointNomalAllocationMenu.StringSet(skillPointNomalAllocationChara, { 520,20 });
	skillAllocationIncreaseAmountMenu.StringSet(skillAllocationIncreaseAmountChara, {820,20});
	magicSelectMenu.StringSet(magicSelectChara, { 820,20 });
	skillPointMagicAllocationMenu.StringSet(skillPointMagicAllocationChara, { 580,60 });
	skillMagicAllocationIncreaseAmountMenu.StringSet(skillMagicAllocationIncreaseAmountChara, { 870,20 });
	finalConfirmationMenu.StringSet(finalConfirmationChara, { 620,300 });

	//int
	skillPointStateMenu.intSet(skillPointChar, { 750,20 });
	remainingPointMenu.intSet(remainingPointChara, { 760,495 });
	skillPointMagicStateMenu.intSet(skillPointMagicStateChar, { 815,60 });
}

void PlayerClass::MagicSkillPointAdd(int changeNumber)
{
	//スキルポイント加算
	if ((KeyZ.down() || KeyEnter.down()) && gameObject.status.IsEnoughMagicSkillPoint(changeNumber) == 0 && gameObject.status.IsAllocateMagicSkillPoint(changeNumber))
	{
		gameObject.status.MagicSkillPointAdd(changeNumber);

		CharSet();
	}
}

void PlayerClass::skillPointAdd()
{
	//スキルポイント加算
	if ((KeyZ.down() || KeyEnter.down()) && gameObject.status.IsEnoughSkillPoint(currentStatus) == 0 && gameObject.status.IsAllocateSkillPoint(currentStatus))
	{
		gameObject.status.SkillPointAdd(currentStatus, MagicType::FIREBALL);

		CharSet();

		BarInitialize();
	}
}


void PlayerClass::PlayAudio()
{
	//選択音流す
	selectAudio.playOneShot(GameData::MainVolume * GameData::SEVolume);
}

void PlayerClass::BarInitialize()
{
	//初期化、初期定義
//バーの情報を定義
	hitpointBar.Initialize(gameObject.status.hitPoint);
	magicpointBar.Initialize(gameObject.status.magicPoint);
	mentalpointBar.Initialize(gameObject.status.mental);
	staminapointBar.Initialize(gameObject.status.stamina);
}


void PlayerClass::Draw()const
{
	//バーなどの描画
	StatusDraw();


	//GameobjectのDrawを実行
	gameObject.Draw();

	//キャラコンフィグ描画
	ConfigOnlineDraw();
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

void PlayerClass::DebugDraw() const
{
	//当たり判定を表示
	gameObject.GetHitRect().drawFrame(2, Palette::Green);

	//現在の状態を表示
	gameObject.StatusDraw();

	//画像の時間系を表示
	gameObject.TimeDebuggDraw();
}

void PlayerClass::ConfigOnlineProcess()
{

	//キャラコンフィグがオンラインになったら処理を実行(Eキーが押されたら)
	if (isOnline)
	{

		switch (selectScene)
		{
		case PlayerClass::MenuUpdateProcess::FirstScene://最初の選択画面{ U"アイテム",U"ステータス",U"スキルポイント",U"閉じる" }

			//最初の選択画面を選択できる処理
			firstMenu.Update();

			//遷移処理
			switch (firstMenu.IsCurrent())
			{
			case 0://アイテム
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//アイテムに遷移
					selectScene = MenuUpdateProcess::Item;
					//選択音再生
					PlayAudio();
				}
				break;
			case 1://ステータス
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//ステータスに遷移
					selectScene = MenuUpdateProcess::Status;
					//選択音再生
					PlayAudio();
				}
				break;
			case 2://スキルポイント
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//スキルポイントに遷移
					selectScene = MenuUpdateProcess::SkillPoint;
					//選択音再生
					PlayAudio();
				}
				break;
			case 3://閉じる
				if (KeyZ.down() || KeyEnter.down() || firstMenu.IsMouseOver() && MouseL.down())
				{
					//キャラコンフィグ画面を閉じる
					isOnline = false;

					//選択音再生
					PlayAudio();

					//初期化
					firstMenu.Initialize();
				}
				break;
			default:
				break;
			}
			break;

		case PlayerClass::MenuUpdateProcess::Item:

			//戻る用
			if (KeyZ.down() || KeyEnter.down() || MouseL.down())
			{
				selectScene = MenuUpdateProcess::FirstScene;
			}
			break;

		case PlayerClass::MenuUpdateProcess::Status:

			//戻る用
			if (KeyZ.down() || KeyEnter.down() || MouseL.down())
			{
				selectScene = MenuUpdateProcess::FirstScene;
			}
			break;

		case PlayerClass::MenuUpdateProcess::SkillPoint:

			//スキルポイントの最初の選択画面を選択できる処理
			skillPointMenu.Update();

			//遷移処理
			switch (skillPointMenu.IsCurrent())
			{
			case 0://通常
				if (KeyZ.down() || KeyEnter.down() || skillPointMenu.IsMouseOver() && MouseL.down())
				{
					//通常スキルポイント分配画面に遷移
					selectScene = MenuUpdateProcess::SkillPointNomalAllocation;
					//選択音再生
					PlayAudio();
				}
				break;
			case 1://魔法
				if (KeyZ.down() || KeyEnter.down() || skillPointMenu.IsMouseOver() && MouseL.down())
				{
					//魔法スキルポイント分配画面に遷移
					selectScene = MenuUpdateProcess::SkillPointMagicAllocation;
					//選択音再生
					PlayAudio();
				}
				break;
			case 2://戻る
				if (KeyZ.down() || KeyEnter.down() || skillPointMenu.IsMouseOver() && MouseL.down())
				{
					//一つ前の画面に戻る
					selectScene = MenuUpdateProcess::FirstScene;

					//選択音再生
					PlayAudio();

					//初期化
					skillPointMenu.Initialize();
				}
				break;
			default:
				break;
			}
			break;

		case PlayerClass::MenuUpdateProcess::SkillPointNomalAllocation:

			//通常スキルポイント分配画面を選択できる処理
			skillPointNomalAllocationMenu.Update();

			//右の変数が連動
			skillPointStateMenu.InterlockingUpdate(skillPointNomalAllocationMenu);

			//遷移処理
			switch (skillPointNomalAllocationMenu.IsCurrent())
			{
			case 0:
				//ステータスの状態遷移
				currentStatus = StatusType::HP;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.hitPointAllotted;
				break;
			case 1:
				//ステータスの状態遷移
				currentStatus = StatusType::STAMINA;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.staminaAllotted;
				break;
			case 2:
				//ステータスの状態遷移
				currentStatus = StatusType::MENTAL;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.mentalAllotted;
				break;
			case 3:
				//ステータスの状態遷移
				currentStatus = StatusType::POWER;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.powerAllotted;
				break;
			case 4:
				//ステータスの状態遷移
				currentStatus = StatusType::PROTECTION;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.protectionAllotted;
				break;
			case 5:
				//ステータスの状態遷移
				currentStatus = StatusType::WEIGHT;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.weightAllotted;
				break;
			case 6:
				//ステータスの状態遷移
				currentStatus = StatusType::MAGICTYPE;

				if (KeyZ.down() || KeyEnter.down() || skillPointNomalAllocationMenu.IsMouseOver() && MouseL.down())
				{
					//魔法変更画面に遷移
					selectScene = MenuUpdateProcess::MagicSelect;
					//選択音再生
					PlayAudio();
				}

				break;
			case 7:
				//ステータスの状態遷移
				currentStatus = StatusType::MP;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.magicPointAllotted;
				break;
			case 8:
				//ステータスの状態遷移
				currentStatus = StatusType::MAGICPOWER;

				//ステータスの状態に応じてステータス加算
				skillPointAdd();

				//右の表のグレーアウト
				skillAllocationIncreaseAmountMenu.menuID = gameObject.status.magicPowerAllotted;
				break;
			case 9://戻る
				if (KeyZ.down() || KeyEnter.down() || skillPointNomalAllocationMenu.IsMouseOver() && MouseL.down())
				{
					//一つ前の画面に戻る
					selectScene = MenuUpdateProcess::SkillPoint;

					//選択音再生
					PlayAudio();

					//初期化
					skillPointNomalAllocationMenu.Initialize();
				}
				break;
			default:
				break;
			}
			break;

		case PlayerClass::MenuUpdateProcess::SkillPointMagicAllocation:
			skillPointMagicAllocationMenu.Update();

			skillPointMagicStateMenu.InterlockingUpdate(skillPointMagicAllocationMenu);

			switch (skillPointMagicAllocationMenu.IsCurrent())
			{
			case 0:
				//ステータスの状態に応じてステータス加算
				MagicSkillPointAdd(0);

				//右の表のグレーアウト
				skillMagicAllocationIncreaseAmountMenu.menuID = gameObject.status.magicSkillPointAllocation[0];
				break;
			case 1:
				//ステータスの状態に応じてステータス加算
				MagicSkillPointAdd(1);

				//右の表のグレーアウト
				skillMagicAllocationIncreaseAmountMenu.menuID = gameObject.status.magicSkillPointAllocation[1];
				break;
			case 2:
				//ステータスの状態に応じてステータス加算
				MagicSkillPointAdd(2);

				//右の表のグレーアウト
				skillMagicAllocationIncreaseAmountMenu.menuID = gameObject.status.magicSkillPointAllocation[2];
				break;
			case 3:
				//ステータスの状態に応じてステータス加算
				MagicSkillPointAdd(3);

				//右の表のグレーアウト
				skillMagicAllocationIncreaseAmountMenu.menuID = gameObject.status.magicSkillPointAllocation[3];
				break;
			case 4:
				if (KeyZ.down() || KeyEnter.down() || skillPointMagicAllocationMenu.IsMouseOver() && MouseL.down())
				{
					//一つ前の画面に戻る
					selectScene = MenuUpdateProcess::SkillPoint;

					//選択音再生
					PlayAudio();

					//初期化
					skillPointMagicAllocationMenu.Initialize();
				}
				break;
			default:
				break;
			}
			break;

		case PlayerClass::MenuUpdateProcess::MagicSelect:

			magicSelectMenu.Update();

			switch (magicSelectMenu.IsCurrent())
			{
			case 0:
				if (KeyZ.down() || KeyEnter.down() || magicSelectMenu.IsMouseOver() && MouseL.down())
				{
					ChangeMagicType = MagicType::FIREBALL;
					selectScene = MenuUpdateProcess::FinalConfirmation;
				}
				break;
			case 1:
				if (KeyZ.down() || KeyEnter.down() || magicSelectMenu.IsMouseOver() && MouseL.down())
				{
					ChangeMagicType = MagicType::THUNDER;

					selectScene = MenuUpdateProcess::FinalConfirmation;
				}
				break;
			case 2:
				if (KeyZ.down() || KeyEnter.down() || magicSelectMenu.IsMouseOver() && MouseL.down())
				{
					ChangeMagicType = MagicType::HEAL;

					selectScene = MenuUpdateProcess::FinalConfirmation;
				}
				break;
			case 3:
				if (KeyZ.down() || KeyEnter.down() || magicSelectMenu.IsMouseOver() && MouseL.down())
				{
					ChangeMagicType = MagicType::STATUSUP;

					selectScene = MenuUpdateProcess::FinalConfirmation;
				}
				break;
			case 4:
				if (KeyZ.down() || KeyEnter.down() || magicSelectMenu.IsMouseOver() && MouseL.down())
				{
					ChangeMagicType = MagicType::TIME;

					selectScene = MenuUpdateProcess::FinalConfirmation;
				}
				break;
			case 5:
				if (KeyZ.down() || KeyEnter.down() || magicSelectMenu.IsMouseOver() && MouseL.down())
				{
					//一つ前の画面に戻る
					selectScene = MenuUpdateProcess::SkillPointNomalAllocation;

					//選択音再生
					PlayAudio();

					//初期化
					magicSelectMenu.Initialize();
				}
				break;
			default:
				break;
			}
			break;

		case PlayerClass::MenuUpdateProcess::FinalConfirmation:

			//スキルポイントが足りていれば処理,足りていなければ戻る
			if (gameObject.status.IsEnoughSkillPoint(currentStatus) == 0)
			{
				finalConfirmationMenu.Update();

				switch (finalConfirmationMenu.IsCurrent())
				{
				case 0:
					if (KeyZ.down() || KeyEnter.down() || finalConfirmationMenu.IsMouseOver() && MouseL.down())
					{
						gameObject.status.SkillPointAdd(currentStatus, ChangeMagicType);

						CharSet();

						//二つ前の画面に戻る
						selectScene = MenuUpdateProcess::SkillPointNomalAllocation;

						//選択音再生
						PlayAudio();

						//初期化
						finalConfirmationMenu.Initialize();
					}
					break;
				case 1:
					if (KeyZ.down() || KeyEnter.down() || finalConfirmationMenu.IsMouseOver() && MouseL.down())
					{
						//一つ前の画面に戻る
						selectScene = MenuUpdateProcess::MagicSelect;

						//選択音再生
						PlayAudio();

						//初期化
						finalConfirmationMenu.Initialize();
					}
					break;
				default:
					break;
				}	
			}
			else
			{
				if (KeyZ.down() || KeyEnter.down() || MouseL.down())
				{
					selectScene = MenuUpdateProcess::MagicSelect;
				}
			}
			break;
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
		Rect{ 10,10,300,190 }.drawFrame(10, Palette::White).draw(Palette::Black);
		Rect{ 10,230,200,40 }.drawFrame(10, Palette::White).draw(Palette::Black);

		//メニュー描画
		firstMenu.InRectDraw(true);

		//所持金を描画
		font30(U"1000＄").draw(20, 235, Palette::White);

		switch (selectScene)
		{
		case PlayerClass::MenuUpdateProcess::Item:
			break;
		case PlayerClass::MenuUpdateProcess::Status:
			//後ろの四角い枠
			Rect{ 330,10,400,690 }.drawFrame(10, Palette::White).draw(Palette::Black);

			//ステータスの項目を表示
			statusMenu.InRectDraw(false);
			magicMenu.InRectDraw(false);

			//ステータスの数値を表示
			for (int i = 0; i < statusChar.size(); i++)
			{
				//描画
				font30(statusChar[i]).draw(715 - (font30(statusChar[i]).region().w), statusMenu.startPos.y + ((statusMenu.fontSize * 1.5) * i));
			}

			//魔法の種類を描画
			font30(gameObject.status.magicTypeMame).draw(715 - gameObject.status.magicTypeMame.length() * (gameObject.status.magicType == MagicType::NONE ? 15 : 30), (statusChar.size() * 45) + 15);


			//ステータスの数値を表示
			for (int i = 0; i < magicMenuChara.size(); i++)
			{
				//描画
				font30(magicChar[i]).draw(715 - (font30(magicChar[i]).region().w), magicMenu.startPos.y + ((magicMenu.fontSize * 1.5) * i));
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
		case PlayerClass::MenuUpdateProcess::SkillPoint:
			//後ろの四角い枠
			Rect{ 330,10,150,140 }.drawFrame(10, Palette::White).draw(Palette::Black);

			//メニュー描画
			skillPointMenu.InRectDraw(true);
			break;
		case PlayerClass::MenuUpdateProcess::SkillPointNomalAllocation:
			//後ろの四角い枠
			Rect{ 330,10,150,140 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 500,10,280,460 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 610,490,170,40 }.drawFrame(10, Palette::White).draw(Palette::Black);

			//メニュー描画
			skillPointMenu.InRectDraw(true);//スキル最初の画面

			skillPointNomalAllocationMenu.InRectDraw(true);//ステータスポイント分配画面

			skillPointStateMenu.NumberDraw_int(true);//右の変数

			font30(U"ポイント").draw(620, 495);
			remainingPointMenu.NumberDraw_int(false);//残りスキルポイント数

			if (skillPointNomalAllocationMenu.IsCurrent() != 9)
			{
				//魔法タイプ選択の時以外右のステータス増加量描画
				if (skillPointNomalAllocationMenu.IsCurrent() == 6)
				{
					Rect{ 800,10,290,280 }.drawFrame(10, Palette::White).draw(Palette::Black);

					magicSelectMenu.InRectDraw(false);
				}

				else
				{
					Rect{ 800,10,290,380 }.drawFrame(10, Palette::White).draw(Palette::Black);

					skillAllocationIncreaseAmountMenu.TwoWayDraw();
				}
			}

			break;
		case PlayerClass::MenuUpdateProcess::SkillPointMagicAllocation:
			//後ろの四角い枠
			Rect{ 330,10,150,140 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 500,10,340,275 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 650,300,190,40 }.drawFrame(10, Palette::White).draw(Palette::Black);

			//メニュー描画
			skillPointMenu.InRectDraw(true);
			skillPointMagicAllocationMenu.InRectDraw(true);
			skillPointMagicStateMenu.NumberDraw_int(true);
			if (skillPointMagicAllocationMenu.IsCurrent() != 4)
			{
				Rect{ 860,10,290,190 }.drawFrame(10, Palette::White).draw(Palette::Black);

				skillMagicAllocationIncreaseAmountMenu.TwoWayDraw();
			}

			//魔法の種類を描画
			font30(gameObject.status.magicTypeMame).draw(520, 20);

			font30(U"ポイント").draw(655, 305);

			font30(gameObject.status.magicSkillPoint).draw(835 - (int)(font30(gameObject.status.magicSkillPoint)).region().w, 305);

			break;
		case PlayerClass::MenuUpdateProcess::MagicSelect:
			//後ろの四角い枠
			Rect{ 330,10,150,140 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 500,10,280,460 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 610,490,170,40 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 800,10,290,280 }.drawFrame(10, Palette::White).draw(Palette::Black);

			//メニュー描画
			skillPointMenu.InRectDraw(true);//スキル最初の画面

			skillPointNomalAllocationMenu.InRectDraw(true);//ステータスポイント分配画面

			skillPointStateMenu.NumberDraw_int(true);//右の変数

			magicSelectMenu.InRectDraw(true);

			remainingPointMenu.NumberDraw_int(false);//残りスキルポイント数

			font30(U"ポイント").draw(620, 495);

			break;
		case PlayerClass::MenuUpdateProcess::FinalConfirmation:
			//後ろの四角い枠
			Rect{ 330,10,150,140 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 500,10,280,460 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 610,490,170,40 }.drawFrame(10, Palette::White).draw(Palette::Black);
			Rect{ 800,10,290,280 }.drawFrame(10, Palette::White).draw(Palette::Black);


			//メニュー描画
			skillPointMenu.InRectDraw(true);//スキル最初の画面

			skillPointNomalAllocationMenu.InRectDraw(true);//ステータスポイント分配画面

			skillPointStateMenu.NumberDraw_int(true);//右の変数

			magicSelectMenu.InRectDraw(true);

			remainingPointMenu.NumberDraw_int(false);//残りスキルポイント数

			font30(U"ポイント").draw(620, 495);


			if (gameObject.status.IsEnoughSkillPoint(currentStatus) == 0)
			{
				Rect{ 225,150,900,300 }.drawFrame(10, Palette::White).draw(Palette::Black);
				finalConfirmationMenu.InRectDraw(true);

				String magicName;
				switch (ChangeMagicType)
				{
				case MagicType::FIREBALL:
					magicName = { U"火球" };
					break;
				case MagicType::THUNDER:
					magicName = { U"サンダー" };
					break;
				case MagicType::STATUSUP:
					magicName = { U"ステータスアップ" };
					break;
				case MagicType::HEAL:
					magicName = { U"ヒール" };
					break;
				case MagicType::TIME:
					magicName = { U"タイム" };
					break;
				default:
					break;
				}

				font30(U"5ポイントを消費して", magicName, U"を習得しますか？").draw(400, 170);
				font30(U"※一度習得すると変更がとても難しくなります。").draw(370, 210);
			}
			else
			{
				Rect{ 800,400,470,40 }.drawFrame(10, Palette::White).draw(Palette::Black);
				font30(U"魔法の習得には5ポイント必要です").draw(805, 405, Palette::Red);
			}

			break;
		default:
			break;
		}
	}
}



