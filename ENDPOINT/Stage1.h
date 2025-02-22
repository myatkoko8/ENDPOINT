﻿#pragma once
#include"Base.h"
#include"PlayerClass.h"
#include"EnemyClass.h"
#include "MapClass.h"

class Stage1 : public App::Scene
{
private:

	
	Texture BackScreen[3] = { Texture{ U"Material/3.MAP/7._background.png" },  Texture{ U"Material/3.MAP/7.1_background.png" } , Texture{ U"Material/3.MAP/7.2_background.png" } };

	Texture UnderGround     { U"Material/3.MAP/使うやつ.png" };

	Texture fistWaitingMotionPNG	{ U"Material/1.img/プレイヤー/1.拳/1.待機モーション.png" };
	Texture fistWalkMotionPNG		{ U"Material/1.img/プレイヤー/1.拳/2.歩きモーション.png" };
	Texture fistRunMotionPNG		{ U"Material/1.img/プレイヤー/1.拳/3.ダッシュモーション.png" };
	Texture fistJumpMotionPNG		{ U"Material/1.img/プレイヤー/1.拳/4.ジャンプモーション.png" };
	Texture fistFallingMotionPNG	{ U"Material/1.img/プレイヤー/1.拳/5.空中モーション.png" };
	Texture fistLandingMotionPNG	{ U"Material/1.img/プレイヤー/1.拳/6.着地モーション.png" };
	Texture fistReceiveMotionPNG	{ U"Material/1.img/プレイヤー/1.拳/10.受けモーション.png" };
	Texture fistAttackMotionPNG		{ U"Material/1.img/プレイヤー/1.拳/7.拳モーション.png" };
	Texture fistMagicMotionPNG		{ U"Material/1.img/プレイヤー/1.拳/8.攻撃魔法モーション.png" };
	Texture swordWaitingMotionPNG	{ U"Material/1.img/プレイヤー/2.剣/1.待機モーション.png" };
	Texture swordWalkMotionPNG		{ U"Material/1.img/プレイヤー/2.剣/2.歩きモーション.png" };
	Texture swordRunMotionPNG		{ U"Material/1.img/プレイヤー/2.剣/3.ダッシュモーション.png" };
	Texture swordJumpMotionPNG		{ U"Material/1.img/プレイヤー/2.剣/4.ジャンプモーション.png" };
	Texture swordFallingMotionPNG	{ U"Material/1.img/プレイヤー/2.剣/5.空中モーション .png" };
	Texture swordLandingMotionPNG	{ U"Material/1.img/プレイヤー/2.剣/6.着地モーション.png" };
	Texture swordReceiveMotionPNG	{ U"Material/1.img/プレイヤー/2.剣/10.受けモーション.png" };
	Texture swordAttackMotionPNG	{ U"Material/1.img/プレイヤー/2.剣/7.剣モーション.png" };
	Texture swordMagicMotionPNG		{ U"Material/1.img/プレイヤー/2.剣/8.攻撃魔法モーション.png" };
	//Texture guardMotionPNG		{ U"Material/1.img/プレイヤー/1.拳/11.防御モーション.png" };
	//Texture notstaminaMotionPNG	{ U"Material/1.img/プレイヤー/1.拳/14.スタミナ切れ(待機).png" };

	Texture enemeyFistWaitingMotionPNG		{ U"Material/1.img/敵/1.拳/1.待機モーション-enemey.png" };
	Texture enemeyFistWalkMotionPNG			{ U"Material/1.img/敵/1.拳/2.歩きモーション-enemey.png" };
	Texture enemeyFistRunMotionPNG			{ U"Material/1.img/敵/1.拳/3.ダッシュモーション-enemey.png" };
	Texture enemeyFistJumpMotionPNG			{ U"Material/1.img/敵/1.拳/4.ジャンプモーション-enemey.png" };
	Texture enemeyFistFallingMotionPNG		{ U"Material/1.img/敵/1.拳/5.空中モーション-enemey.png" };
	Texture enemeyFistLandingMotionPNG		{ U"Material/1.img/敵/1.拳/6.着地モーション-enemey.png" };
	Texture enemeyFistReceiveMotionPNG		{ U"Material/1.img/敵/1.拳/10.受けモーション-enemey.png" };
	Texture enemeyFistAttackMotionPNG		{ U"Material/1.img/敵/1.拳/7.拳モーション-enemey.png" };
	Texture enemeyFistMagicMotionPNG		{ U"Material/1.img/敵/1.拳/8.攻撃魔法モーション-enemey.png" };
	Texture enemeySwordWaitingMotionPNG		{ U"Material/1.img/敵/2.剣/1.待機モーション-enemey.png" };
	Texture enemeySwordWalkMotionPNG		{ U"Material/1.img/敵/2.剣/2.歩きモーション-enemey.png" };
	Texture enemeySwordRunMotionPNG			{ U"Material/1.img/敵/2.剣/3.ダッシュモーション-enemey.png" };
	Texture enemeySwordJumpMotionPNG		{ U"Material/1.img/敵/2.剣/4.ジャンプモーション-enemey.png" };
	Texture enemeySwordFallingMotionPNG		{ U"Material/1.img/敵/2.剣/5.空中モーション-enemey.png" };
	Texture enemeySwordLandingMotionPNG		{ U"Material/1.img/敵/2.剣/6.着地モーション-enemey.png" };
	Texture enemeySwordReceiveMotionPNG		{ U"Material/1.img/敵/2.剣/10.受けモーション-enemey.png" };
	Texture enemeySwordAttackMotionPNG		{ U"Material/1.img/敵/2.剣/7.剣モーション-enemey.png" };
	Texture enemeySwordMagicMotionPNG		{ U"Material/1.img/敵/2.剣/8.攻撃魔法モーション-enemey.png" };
	//Texture enemeyGuardMotionPNG		{ U"Material/1.img/敵/1.拳/11.防御モーション-enemey.png" };
	//Texture enemeyNotstaminaMotionPNG	{ U"Material/1.img/敵/1.拳/14.スタミナ切れ(待機)-enemey.png" };

	Texture BlowPNG{ U"Material/2.EF/1.拳と杖.png" };
	Texture SlashingPNG{ U"Material/2.EF/2.剣と鈍器.png" };
	Texture FireBallPNG{ U"Material/2.EF/３.火球.png" };

	Audio WalkAudio			{ U"Material/4.SE/1.歩き.mp3" , Loop::Yes };
	Audio RunAudio			{ U"Material/4.SE/2.走り.mp3" , Loop::Yes };
	Audio JumpAudio			{ U"Material/4.SE/3.ジャンプ.mp3" };
	Audio FistAudio			{ U"Material/4.SE/4.拳.mp3" };
	Audio SwordAudio		{ U"Material/4.SE/5.剣.mp3" };
	Audio HammerAudio		{ U"Material/4.SE/6.鈍器.mp3" };
	Audio FireBallAudio		{ U"Material/4.SE/7.火球.mp3" };
	Audio ThunderAudio		{ U"Material/4.SE/8.サンダー.mp3" };
	Audio HealAudio			{ U"Material/4.SE/9.回復.mp3" };
	Audio StatusUpAudio		{ U"Material/4.SE/10.ステータスアップ.mp3" };
	Audio TimeAudio			{ U"Material/4.SE/11.タイム.mp3" };
	Audio DamageAudio		{ U"Material/4.SE/12.ダメージ.mp3" };
	Audio GuardAudio		{ U"Material/4.SE/13.防御した時.mp3" };
	Audio GuardDamageAudio	{ U"Material/4.SE/14.防御中攻撃を受けた時.mp3" };
	Audio GuardBreakAudio	{ U"Material/4.SE/15.防御割れ.mp3" };
	Audio Pause1Audio		{ U"Material/4.SE/16.ゲームを一時停止した時1.mp3" };
	Audio Pause2Audio		{ U"Material/4.SE/17.ゲームを一時停止した時.mp3" };
	Audio DropAudio			{ U"Material/4.SE/18.ドロップアイテムを落とした時.mp3" };
	Audio PickUpAudio		{ U"Material/4.SE/19.ドロップアイテムを拾った時.mp3" };

	
	CSV AnimationData{ U"ConfigData/アニメーションデータ.csv" };
	CSV EffectData{ U"ConfigData/エフェクトデータ.csv" };
	CSV TextureShiftData{ U"ConfigData/画像補正位置.csv" };
	CSV BasicStatusData{ U"ConfigData/基礎ステータスデータ.csv" };
	CSV SkillPointStatusData{ U"ConfigData/スキルポイントステータスデータ.csv" };
	CSV ExperienceBorder{ U"ConfigData/経験値ボーダー.csv" };
	CSV MagicSkillPointData{ U"ConfigData/魔法スキルポイントステータスデータ.csv" };
	CSV MagicOther{ U"ConfigData/魔法その他.csv" };

	EffectClass Effect[3]{
							{ BlowPNG ,EffectData ,1 } ,
							{ SlashingPNG ,EffectData ,2 } ,
							{FireBallPNG ,EffectData ,5 } ,
	};


	Texture playerPNG[4][20] =
	{
		/*0が拳*/{{fistWaitingMotionPNG} ,{fistWalkMotionPNG} ,{fistRunMotionPNG},{fistJumpMotionPNG},{fistFallingMotionPNG},{fistReceiveMotionPNG},{fistAttackMotionPNG},{fistMagicMotionPNG}},
		/*1が剣*/{{swordWaitingMotionPNG} ,{swordWalkMotionPNG} ,{swordRunMotionPNG},{swordJumpMotionPNG},{swordFallingMotionPNG},{swordReceiveMotionPNG},{swordAttackMotionPNG},{swordMagicMotionPNG}},
		/*2が鈍器*/{},
		/*3が杖*/{},
		//各20種
	};

	Texture enemeyPNG[4][20] =
	{
		/*0が拳*/{{enemeyFistWaitingMotionPNG} ,{enemeyFistWalkMotionPNG} ,{enemeyFistRunMotionPNG},{enemeyFistJumpMotionPNG},{enemeyFistFallingMotionPNG},{enemeyFistLandingMotionPNG},{enemeyFistReceiveMotionPNG},{enemeyFistAttackMotionPNG},{enemeyFistMagicMotionPNG}},
		/*1が剣*/{{enemeySwordWaitingMotionPNG} ,{enemeySwordWalkMotionPNG} ,{enemeySwordRunMotionPNG},{enemeySwordJumpMotionPNG},{enemeySwordFallingMotionPNG},{enemeySwordLandingMotionPNG},{enemeySwordReceiveMotionPNG},{enemeySwordAttackMotionPNG},{enemeySwordMagicMotionPNG}},
		/*2が鈍器*/{},
		/*3が杖*/{},
		//各20種
	};

	Audio SEAudio[19] =
	{
		WalkAudio,
		RunAudio,
		JumpAudio,
		DamageAudio,
		FistAudio,
		SwordAudio,
		FireBallAudio,//ここまで使ってます。
		HammerAudio,
		ThunderAudio,
		HealAudio,
		StatusUpAudio,
		TimeAudio,
		GuardAudio,
		GuardDamageAudio,
		GuardBreakAudio,
		Pause1Audio,
		Pause2Audio,
		DropAudio,
		PickUpAudio
	};


	PlayerClass Player = { playerPNG ,Effect,SEAudio,AnimationData ,TextureShiftData,BasicStatusData ,SkillPointStatusData,ExperienceBorder ,MagicSkillPointData ,MagicOther };

	EnemyClass Enemey = { enemeyPNG,Effect ,SEAudio,AnimationData ,TextureShiftData,BasicStatusData, SkillPointStatusData ,ExperienceBorder  ,MagicSkillPointData ,MagicOther };

	CSV mapData{ U"ConfigData/map.csv" };

	MapClass Map{ UnderGround, mapData };


	Array<EnemyClass> Enemeys;

	// プレイヤーインデックス (0 - 3)
	size_t playerIndex = 0;
	const Array<String> options = Range(1, 4).map([](int32 i) {return U"{}P"_fmt(i); });

	// デッドゾーンを有効にするか
	bool enableDeadZone = true;

	// 振動 (0.0 ～ 1.0)
	XInputVibration vibration;

	//デバック用
	Font font{ 30 };

	//経験値関連使い方講座
	int S = 0;
	StatusType tentative = StatusType::HP;
	String statusTypeName = U"HP";;	//状態
	int Missing;
	String isMissing = U"";		//足りてないか
	String isMax = U"";			//

	bool a = false;

public:

    Stage1(const InitData& init)
        : IScene(init)
    {
        Initialize();
    }
    ~Stage1();

    void update() override;

    void draw() const override;

    void Initialize();//初期化


	/// @brief 体同士が衝突した際の当たり判定で使う移動量を計算
	/// @param velox1 一キャラ目の移動値X
	/// @param velox2 二キャラ目の移動値X
	/// @return 結果の移動値
	double HitBodyVelocity(double velox1, double velox2);

	/// @brief 二つの移動地のうち、どちらが押しているかを判定
	/// @param velox1 1P
	/// @param velox2 2P
	/// @return 1Pが押しているならtrue,それ以外ならfalse,同値でもfalse
	bool Is1PPush(double velox1, double velox2);

	/// @brief 敵生成
	void EnemeyAdd();
	
};
