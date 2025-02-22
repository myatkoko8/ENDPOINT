﻿#include "Title.h"
#undef System

Title::~Title()
{

}

void Title::Initialize()
{
	//Scene::SetBackground(ColorF(0.3, 0.3, 0.3));//シーンの色を灰色に設定

}

void Title::update()
{
	/*ClearPrint();
	Print << bgcolorChangeTimer;*/


	if (bgcolorChangeTimer > 5s)
	{
		i++;
		if (i > 2) { i = 0; }
		bgcolorChangeTimer.restart();
	}

	Scene::SetBackground(BackgroupColor[i]);//シーンの色を灰色に設定



	if (titleNameFont_NewRect.leftClicked()) { changeScene(SceneName::Stage1); }
	if (titleNameFont_EndRect.leftClicked()) { System::Exit(); }

	if (KeyEnter.down() || KeyZ.down())
	{
		switch (menuID)
		{
		case MENU::New:
			changeScene(SceneName::Stage1);
			break;
		case MENU::End:
			System::Exit();
			break;
		default:
			break;
		}
	}

	if (KeyDown.down() || KeyS.down())
	{
		menuID += 1;
		if (menuID > MENU::End)
		{
			menuID = MENU::New;
		}
	
	}

	if (KeyUp.down()|| KeyW.down())
	{
		menuID -= 1;
		if (menuID < MENU::New)
		{
			menuID = MENU::End;
		}
	}

}


void Title::draw() const
{

	//ClearPrint();
	//Print << bgcolorChangeTimer;


	Color FontColor;
	bool ColorFlag = false;


	titleNameFont_NewRect.draw			(ColorF(1.0, 0.0, 0.0, 0.0));
	titleNameFont_ContinueRect.draw		(ColorF(1.0, 0.0, 0.0, 0.0));
	titleNameFont_SettingRect.draw		(ColorF(1.0, 0.0, 0.0, 0.0));
	titleNameFont_EndRect.draw			(ColorF(1.0, 0.0, 0.0, 0.0));

	titleNameFont_GameTitle(U"E N D POINT").drawAt(Scene::Center().x,100, Palette::Orange);

	titleNameFont_NewRect.x = Scene::Center().x - (int)(titleNameFont_New(Menu_New).region().w / 2);
	titleNameFont_ContinueRect.x = Scene::Center().x - (int)(titleNameFont_Continue(Menu_Continue).region().w / 2);
	titleNameFont_SettingRect.x = Scene::Center().x - (int)(titleNameFont_Setting(Menu_Setting).region().w / 2);
	titleNameFont_EndRect.x = Scene::Center().x - (int)(titleNameFont_End(Menu_End).region().w / 2);

	FontColor = titleNameFont_NewRect.mouseOver() ? Palette::Orange : Palette::White;
	if (FontColor == Palette::Orange) { ColorFlag = true; }
	titleNameFont_New(Menu_New).
		draw(titleNameFont_NewRect.x, titleNameFont_NewRect.y, FontColor);

	FontColor = titleNameFont_ContinueRect.mouseOver() ? Palette::Orange : Palette::White;
	if (FontColor == Palette::Orange) { ColorFlag = true; }
	titleNameFont_Continue(Menu_Continue).
		draw(titleNameFont_ContinueRect.x, titleNameFont_ContinueRect.y, FontColor);

	FontColor = titleNameFont_SettingRect.mouseOver() ? Palette::Orange : Palette::White;
	if (FontColor == Palette::Orange) { ColorFlag = true; }
	titleNameFont_Setting(Menu_Setting).
		draw(titleNameFont_SettingRect.x, titleNameFont_SettingRect.y, FontColor);

	FontColor = titleNameFont_EndRect.mouseOver() ? Palette::Orange : Palette::White;
	if (FontColor == Palette::Orange) { ColorFlag = true; }
	titleNameFont_End(Menu_End).
		draw(titleNameFont_EndRect.x, titleNameFont_EndRect.y, FontColor);
	



	if (ColorFlag == false)
	{
		switch (menuID)
		{
		case MENU::Null:
			break;
		case MENU::New:
			titleNameFont_New(U"始めから").
				draw(titleNameFont_NewRect.x, titleNameFont_NewRect.y, Palette::Orange);
			break;
		case MENU::Continue:
			titleNameFont_Continue(U"つづきから").
				draw(titleNameFont_ContinueRect.x, titleNameFont_ContinueRect.y, Palette::Orange);
			break;
		case MENU::Setting:
			titleNameFont_Setting(U"設定").
				draw(titleNameFont_SettingRect.x, titleNameFont_SettingRect.y, Palette::Orange);
			break;
		case MENU::End:
			titleNameFont_End(U"終わる").
				draw(titleNameFont_EndRect.x, titleNameFont_EndRect.y, Palette::Orange);
			break;
		default:
			break;
		}
	}





}



