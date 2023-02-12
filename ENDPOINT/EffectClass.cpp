﻿#include "stdafx.h"
#include "EffectClass.h"

void EffectClass::Update()
{
	if (isMirror == false)
	{
		creationPos += vector;
	}
	else
	{
		creationPos -= vector;

	}


	if (effectType == EffectType::FISTEFFECT)
	{
		Animation();

	}
	else if (effectType == EffectType::FIREBALLEFFECT)
	{
		FireBallAnimation();
	}

	HitBoxUpdate();
}

void EffectClass::HitBoxUpdate()
{
	hitBox = RectF(creationPos, (effectBase.texture.width() / effectBase.totalPatterns * effectBase.size), effectBase.texture.height() * effectBase.size);
}

void EffectClass::Animation(double _motionEndMagnification)
{
	if (currentTime.isRunning() == false)
	{
		currentTime.start();
	}

	if (effectBase.totalPatterns > effectBase.cutPos.x)
	{
		//タイル遷移
		if (currentTime.ms() > (effectBase.OnePatternMotionTime() * _motionEndMagnification))
		{
			effectBase.cutPos.x++;
			currentTime.restart();
		}
	}

}

void EffectClass::FireBallAnimation()
{
	if (currentTime.isRunning() == false)
	{
		currentTime.start();
	}

	//タイル遷移
	if ((switchingTime * conut) < currentTime.ms())
	{
		conut++;

		if (effectBase.cutPos.x < effectBase.totalPatterns - 1)
		{
			effectBase.cutPos.x++;
		}
		else
		{
			effectBase.ResetImage();

		}

	}
}

void EffectClass::CreationPosChange(Vec2 changePos)
{
	creationPos = changePos - (effectBase.cutPos.size / 2 * effectBase.size);
}

void EffectClass::EffectTypeChange(EffectType changeType, double changeSpeed)
{
	effectType = changeType;

	if (effectType == EffectType::FIREBALLEFFECT)
	{
		vector.x = changeSpeed;
	}
}



void EffectClass::MirrorChange(bool changeMirror)
{
	isMirror = changeMirror;
}



void EffectClass::Draw()const
{
	effectBase.texture(effectBase.cutPos.x * effectBase.cutPos.w, effectBase.cutPos.y * effectBase.cutPos.h, effectBase.cutPos.w, effectBase.cutPos.h).scaled(effectBase.size).mirrored(isMirror).draw(creationPos);
}



