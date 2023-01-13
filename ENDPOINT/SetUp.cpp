﻿#include "SetUp.h"
#undef System


void SetUp::Initialize()
{
	//最初の情報定義
	mainVolumeGauge.Set(mainVolumeGaugeRect, GameData::selectMainVolume, U"マスター");
	BGMVolumeGauge.Set(BGMVolumeGaugeRect, GameData::selectEffectVolume, U"BGM");
	SEVolumeGauge.Set(SEVolumeGaugeRect, GameData::selectBGMVolume, U"SE");

	//音量定義
	mainVolumeGauge.AudioSet(selectAudio, GameData::MainVolume * GameData::EffectVolume);
	BGMVolumeGauge.AudioSet(selectAudio, GameData::MainVolume * GameData::EffectVolume);
	SEVolumeGauge.AudioSet(selectAudio, GameData::MainVolume * GameData::EffectVolume);

	isEnable = true;
	isFirst = false;
}

void SetUp::SetUpEnable()
{
	//最初のループでは読まない,ESCAPEが押されたら設定画面を閉じて初期化フラグを立てる
	if (KeyEscape.down() && not isFirst)
	{
		isEnable = false;
		isFirst = true;
	}

	if (isEnable)
	{
		if (isFirst)
		{
			Initialize();
		}
		update();
		draw();
	}
}

void SetUp::update()
{
	///todoList:
	// 選択音に音量調整のボリュームが適応されてない
	// キャラのサイズ感確認
	// タイトルから飛んだ時違うやつ表示、二重で表示されないようにするべし
	// フォントの書体を変える,UIデザイン煮詰める
	// マウスの消去
	// マウスだけでなくキーにも対応
	// 
	
	//シーン管理
	switch (selectScene)
	{
	case SetUp::NowScene::MenuSelect:

		for (int i = 0; i < MenuNumber; i++)
		{
			//当たり判定とマウスが交差していたらフラグを立てる
			if (MenuHitBox[i].mouseOver())
			{
				isSelectMenu[i] = true;
			}
			else
			{
				isSelectMenu[i] = false;
			}

			//シーン遷移
			switch (i)
			{
			case 0:
				if (MenuHitBox[i].mouseOver() && MouseL.down())
				{
					selectScene = NowScene::AudioConfig;
					selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
				}
				break;
			case 1:
				if (MenuHitBox[i].mouseOver() && MouseL.down())
				{
					selectScene = NowScene::KeyConfig;
					selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
				}
				break;
			case 2:
				if (MenuHitBox[i].mouseOver() && MouseL.down())
				{
					selectScene = NowScene::Save;
					selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
				}
				break;
			case 3:
				if (MenuHitBox[i].mouseOver() && MouseL.down())
				{
					selectScene = NowScene::Load;
					selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
				}
				break;
			case 4:
				if (MenuHitBox[i].mouseOver() && MouseL.down())
				{
					selectScene = NowScene::Explanation;
					selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
				}
				break;
			case 5:
				if (MenuHitBox[i].mouseOver() && MouseL.down())
				{
					selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
					System::Exit();
				}
				break;
			}
		}
		break;
	case SetUp::NowScene::AudioConfig:
		//戻る
		if (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)))
		{
			selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
			selectScene = NowScene::MenuSelect;
		}

		mainVolumeGauge.CreateGauge();
		BGMVolumeGauge.CreateGauge();
		SEVolumeGauge.CreateGauge();

		GameData::selectMainVolume = mainVolumeGauge.selectVolume;
		GameData::selectEffectVolume = BGMVolumeGauge.selectVolume;
		GameData::selectBGMVolume = SEVolumeGauge.selectVolume;
		break;
	case SetUp::NowScene::KeyConfig:
		//戻る
		if (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)))
		{
			selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
			selectScene = NowScene::MenuSelect;
		}
		break;
	case SetUp::NowScene::Save:
		//戻る
		if (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)))
		{
			selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
			selectScene = NowScene::MenuSelect;
		}
		break;
	case SetUp::NowScene::Load:
		//戻る
		if (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)))
		{
			selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
			selectScene = NowScene::MenuSelect;
		}
		break;
	case SetUp::NowScene::Explanation:
		//戻る
		if (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)))
		{
			selectAudio.playOneShot(GameData::MainVolume * GameData::EffectVolume);
			selectScene = NowScene::MenuSelect;
		}
		break;
	default:
		break;
	}
}


void SetUp::draw()
{
	//※要検証
	//Scene::SetBackground(Color(85, 85, 85,1));//シーンの色を半透明な灰色に設定
	Rect BackGround{ 0,0,Scene::Width(),Scene::Height() }; 
	BackGround.draw(ColorF(0.3,0.7));

	bool dmy;

	switch (selectScene)
	{
	case SetUp::NowScene::MenuSelect:
		//メニュー描画
		for (int i = 0; i < MenuNumber; i++)
		{
			if (isSelectMenu[i])
			{
				//選択されていれば黄色
				font30(SetUpMenuName[i]).draw(10, 10 + i * 45, Palette::Yellow);
			}
			else
			{
				//選択されていなければ白色
				font30(SetUpMenuName[i]).draw(10, 10 + i * 45, Palette::White);
			}
		}
		break;
	case SetUp::NowScene::AudioConfig:

		gaugeBackRect.draw().drawFrame(2,Palette::Black);
		//ゲージ描画,デバッグモードなら当たり判定も描画
		mainVolumeGauge.GaugeDraw();
		BGMVolumeGauge.GaugeDraw();
		SEVolumeGauge.GaugeDraw();

		dmy = (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)));

		font30(SetUpMenuName[0]).draw(10,10,Palette::White);
		break;
	case SetUp::NowScene::KeyConfig:
		dmy = (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)));
		break;
	case SetUp::NowScene::Save:
		dmy = (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)));
		break;
	case SetUp::NowScene::Load:
		dmy = (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)));
		break;
	case SetUp::NowScene::Explanation:
		dmy = (SimpleGUI::ButtonAt(U"戻る", Vec2(Scene::Width() - 70, Scene::Height() - 30)));
		break;
	default:
		break;
	}

	
}
