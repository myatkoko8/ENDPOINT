﻿#include "stdafx.h"
#include "StatusClass.h"

/*内部データ*/

int StatusClass::IsEnoughSkillPoint(StatusType statusType)
{

	if (statusType == StatusType::MAGICTYPE)
	{
		if (SkillPointForMagic <= skillPoint)
		{
			return 0;
		}
		else
		{
			return SkillPointForMagic - skillPoint;

		}
	}
	else
	{
		if (skillPoint > 0)
		{
			return 0;
		}
		else
		{
			return 1;

		}
	}

}

bool StatusClass::IsAllocateSkillPoint(StatusType statusType)
{

	switch (statusType)
	{
	case StatusType::HP:
		if (hitPointAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::STAMINA:
		if (staminaAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::MENTAL:
		if (mentalAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::POWER:
		if (mentalAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::PROTECTION:
		if (protectionAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::WEIGHT:
		if (weightAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::MAGICTYPE:
		if (magicType == MagicType::NONE)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case StatusType::MP:
		if (magicPointAllotted < MaxSkillPoint)
		{
			return true;
		}
		break;
	case StatusType::MAGICPOWER:
		if (magicPowerAllotted < MaxSkillPoint)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		break;
	}
}

