﻿

export module actFuncSet;

import std;
import util;
import globalVar;
import World;
import ItemStack;
import ItemPocket;
import log;
import Lst;
import Player;
import Prop;

//액트가 실행되는 환경은 3가지 경우가 가능
// 0:기본 HUD, 1:Loot, 2:Equip 

export enum class actEnv 
{
	HUD,
	Loot,
	Equip,
	Inventory
};

export namespace actFunc
{
	//장전 : 총이나 탄창에 사용, 자기 자신의 탄환을 채워넣음
	export Corouter reloadSelf(actEnv envType, ItemPocket* reloadItemPocket, int reloadItemCursor)
	{
		prt(L"executeReloadSelf이 실행되었다.\n");
		int targetLootCursor = reloadItemCursor;
		std::vector<std::wstring> bulletList;
		ItemPocket* equipPtr = (ItemPocket*)Player::ins()->getEquipPtr();
		std::vector<ItemPocket*> targetSearchPtr;

		//탐사할 타일 추가 (장비, 주변타일 9칸)
		{
			targetSearchPtr.push_back(equipPtr);

			//바닥타일
			ItemStack* stack = World::ins()->getItemPos(lootTile[axis::x], lootTile[axis::y], lootTile[axis::z]);
			ItemPocket* lootPtr = stack->getPocket();
			targetSearchPtr.push_back(lootPtr);
		}

		for (int j = 0; j < targetSearchPtr.size(); j++)
		{
			//장비 중인 아이템에서 bulletList(또는 magazine) 추가
			for (int i = 0; i < targetSearchPtr[j]->itemInfo.size(); i++)
			{
				//만약 이 아이템에 넣을 수 있는 아이템코드가 equip에 있는 아이템과 같으면
				if (std::find(reloadItemPocket->itemInfo[targetLootCursor].pocketOnlyItem.begin(), reloadItemPocket->itemInfo[targetLootCursor].pocketOnlyItem.end(), targetSearchPtr[j]->itemInfo[i].itemCode) != reloadItemPocket->itemInfo[targetLootCursor].pocketOnlyItem.end())
				{
					bulletList.push_back(targetSearchPtr[j]->itemInfo[i].name);
				}
			}
		}

		if (bulletList.size() == 0) //넣을만한 포켓을 찾지 못했을 경우
		{
			//이 아이템을 넣을만한 포켓이 없다.
			updateLog(col2Str(col::white) + sysStr[96]);
			co_return;
		}

		////////////////////////////////////////////////////////////////////

		new Lst(sysStr[95], sysStr[94], bulletList);//넣기, 넣을 포켓을 선택해주세요.
		co_await std::suspend_always();

		////////////////////////////////////////////////////////////////////

		int counter = 0;
		for (int j = 0; j < targetSearchPtr.size(); j++)
		{
			for (int i = 0; i < targetSearchPtr[j]->itemInfo.size(); i++)
			{
				//만약 이 아이템에 넣을 수 있는 아이템코드가 equip에 있는 아이템과 같으면
				if (std::find(reloadItemPocket->itemInfo[targetLootCursor].pocketOnlyItem.begin(), reloadItemPocket->itemInfo[targetLootCursor].pocketOnlyItem.end(), targetSearchPtr[j]->itemInfo[i].itemCode) != reloadItemPocket->itemInfo[targetLootCursor].pocketOnlyItem.end())
				{
					if (counter == wtoi(coAnswer.c_str()))
					{
						//넣을 수 있는만큼 가득 넣음
						targetSearchPtr[j]->transferItem
						(
							(ItemPocket*)reloadItemPocket->itemInfo[targetLootCursor].pocketPtr,
							i,
							1//일단은 전부 넣는걸로
						);

						co_return;
					}
					counter++;
				}
			}
		}
	}



	export Corouter reloadOther(actEnv envType, ItemPocket* reloadItemPocket, int reloadItemCursor)//삽탄 : 총알에 사용, 이 탄환을 넣을 수 있는 탄창 리스트를 표시하고 거기에 넣음
	{
		//탄창이 장착한 총에 바로 넣는 기능 추가? -> 탄창을 안 빼고 총알을 넣는게 현실적으로 가능할리가 없다

		prt(L"executeReloadOther이 실행되었다.\n");
		int targetLootCursor = reloadItemCursor;
		std::vector<std::wstring> pocketList;
		ItemPocket* equipPtr = (ItemPocket*)Player::ins()->getEquipPtr();
		std::vector<ItemPocket*> targetSearchPtr;
		
		//탐사할 타일 추가 (장비, 주변타일 9칸)
		{
			targetSearchPtr.push_back(equipPtr);

			//바닥타일
			ItemStack* stack = World::ins()->getItemPos(lootTile[axis::x], lootTile[axis::y], lootTile[axis::z]);
			ItemPocket* lootPtr = stack->getPocket();
			targetSearchPtr.push_back(lootPtr);
		}

		//장비 중인 아이템에서 pocketList 추가
		for (int j = 0; j < targetSearchPtr.size(); j++)
		{
			for (int i = 0; i < targetSearchPtr[j]->itemInfo.size(); i++)
			{
				if (targetSearchPtr[j]->itemInfo[i].pocketMaxNumber > 0 && countPocketItemNumber((ItemPocket*)targetSearchPtr[j]->itemInfo[i].pocketPtr) < targetSearchPtr[j]->itemInfo[i].pocketMaxNumber)
				{
					if (std::find(targetSearchPtr[j]->itemInfo[i].pocketOnlyItem.begin(), targetSearchPtr[j]->itemInfo[i].pocketOnlyItem.end(), reloadItemPocket->itemInfo[targetLootCursor].itemCode) != targetSearchPtr[j]->itemInfo[i].pocketOnlyItem.end())
					{
						pocketList.push_back(targetSearchPtr[j]->itemInfo[i].name);
					}
				}
			}
		}

		if (pocketList.size() == 0) //넣을만한 포켓을 찾지 못했을 경우
		{
			//이 아이템을 넣을만한 포켓이 없다.
			updateLog(col2Str(col::white) + sysStr[96]);
			co_return;
		}

		////////////////////////////////////////////////////////////////////

		new Lst(sysStr[95], sysStr[94], pocketList);//넣기, 넣을 포켓을 선택해주세요.
		co_await std::suspend_always();

		////////////////////////////////////////////////////////////////////

		int counter = 0;
		for (int j = 0; j < targetSearchPtr.size(); j++)
		{
			for (int i = 0; i < targetSearchPtr[j]->itemInfo.size(); i++)
			{
				if (targetSearchPtr[j]->itemInfo[i].pocketMaxNumber > 0 && countPocketItemNumber((ItemPocket*)targetSearchPtr[j]->itemInfo[i].pocketPtr) < targetSearchPtr[j]->itemInfo[i].pocketMaxNumber)
				{
					if (std::find(targetSearchPtr[j]->itemInfo[i].pocketOnlyItem.begin(), targetSearchPtr[j]->itemInfo[i].pocketOnlyItem.end(), reloadItemPocket->itemInfo[targetLootCursor].itemCode) != targetSearchPtr[j]->itemInfo[i].pocketOnlyItem.end())
					{
						if (counter == wtoi(coAnswer.c_str()))
						{
							reloadItemPocket->transferItem
							(
								(ItemPocket*)targetSearchPtr[j]->itemInfo[i].pocketPtr,
								targetLootCursor,
								1
							);

							co_return;
						}

						counter++;
					}
				}
			}
		}
	}


	export void unload(ItemPocket* unloadItemPocket, int unloadItemCursor)//장전해제 : 타겟아이템에 들어있는 아이템을 드랍하거나 인벤토리에 넣는다.
	{
		int targetLootCursor = unloadItemCursor;
		ItemPocket* targetPocket = (ItemPocket*)unloadItemPocket->itemInfo[targetLootCursor].pocketPtr;
		ItemPocket* drop = new ItemPocket(storageType::null);
		for (int i = 0; i < targetPocket->itemInfo.size(); i++) { targetPocket->transferItem(drop, i, targetPocket->itemInfo[i].number); }
		Player::ins()->drop(drop);
	}

	export void closeDoor(int tgtX, int tgtY, int tgtZ)
	{
		Prop* tgtProp = (Prop*)World::ins()->getTile(tgtX, tgtY, tgtZ).PropPtr;
		tgtProp->leadItem.eraseFlag(itemFlag::DOOR_OPEN);
		tgtProp->leadItem.addFlag(itemFlag::DOOR_CLOSE);

		if (tgtProp->leadItem.checkFlag(itemFlag::PROP_GAS_OBSTACLE_OFF))
		{
			tgtProp->leadItem.eraseFlag(itemFlag::PROP_GAS_OBSTACLE_OFF);
			tgtProp->leadItem.addFlag(itemFlag::PROP_GAS_OBSTACLE_ON);
		}

		tgtProp->leadItem.eraseFlag(itemFlag::PROP_WALKABLE);
		tgtProp->leadItem.addFlag(itemFlag::PROP_BLOCKER);
		tgtProp->leadItem.extraSprIndexSingle--;
		tgtProp->updateTile();
		Player::ins()->updateVision(Player::ins()->entityInfo.eyeSight);
	}
};