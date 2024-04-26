#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

// Change membership card
bool card_class_change(struct User* current, int c)
{
	switch (c)
	{
	case 1:
		current->c = SILVER;
		break;
	case 2:
		current->c = GOLD;
		break;
	case 3:
		current->c = PLATINUM;
		break;
	default:
		return false;
		break;
	}
	return true;
}