#include "../headerFile/Troll.h"

Item* Troll::GetItem()
{
	if (item == nullptr)
	{
		item = new potion50;
	}

	delete item;

	switch (GetRandom(1, 3))
	{
	case 1:
		item = new potion50;
		break;
	case 2:
		item = new potion100;
		break;
	case 3:
		item = new potion300;
		break;
	default:
		break;
	}

	return item;
}
