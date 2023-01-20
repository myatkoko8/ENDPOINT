﻿#pragma once
class GameObject
{
public:



	CSV AnimationData{ U"ConfigData/アニメーションデータ.csv" };

	AnimationClass waitMotion;
	AnimationClass walkMotion;
	AnimationClass runMotion;
	AnimationClass jumpMotion;
	AnimationClass receiveMotion;
	AnimationClass attackMotion;
	AnimationClass magicMotion;
	AnimationClass guardMotion;
	AnimationClass notstaminaMotion;

	AnimationClass animation[9];

	StatusClass status;//ステータス

	StateType state = StateType::WAIT;

	Stopwatch animationTime;

	Rect waitPosDifference = { 62,30,35,130 };

	Vec2 position = { 0,0 };
	Vec2 velocity = { 0,0 };
	Rect hitBox = { 0,0,0,0 };

	double gravity = 0.5;
	bool isJump = false;
	bool isMotionLock = false;
	bool isHit = false;
	bool isMirror = false;

	int jumpPower = 10;
	int charaSpeed = 5;


	GameObject(Texture _wait,CSV AnimationData, CSV statusData)
	{
		waitMotion.Reload(_wait, AnimationData,1);/*@*/
		status.Reload(statusData);
	};

	//機能

	/// @brief 毎フレーム更新する情報
	void Update();

	void MotionStart();

	void MotionStop();

	/// @brief ジャンプの処理
	void Jump();

	/// @brief 歩きの処理
	void Walk();

	/// @brief 移動の処理
	void Move();

	/// @brief 状態に応じた処理を行う
	void StateManagement();

	/// @brief 状態に応じたテクスチャを描画する
	void StateManagementDraw()const;

	/// @brief 状態を変化させる処理
	void ChangeState();

	//デバック用

	void Initialize();




	//ここから下はGameObjectInternal.cppに

	/*内部データ用*/


	//使ってないの
    //CSV AnimationData{ U"ConfigData/アニメーションデータ.csv" };
    //Texture waitingMotionPNG{ U"Material/1.img/1.待機モーション.png" };
    //Texture waikMotionPNG{ U"Material/1.img/1.待機モーション.png" };
    //void AnimationProcess(AnimationClass animation);
    //void AnimationDraw(AnimationClass animation,Vec2 position)const;
    //void AnimationHitBox(AnimationClass animation,CSV hitBoxData);
	//Rect GetHitRect(AnimationClass animation);
	//int GetTop(AnimationClass animation);
	//int GetBottom(AnimationClass animation);
	//int GetLeft(AnimationClass animation);
	//int GetRight(AnimationClass animation);
	//void PlayerDraw()const;これいる？

};

