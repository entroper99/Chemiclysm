export module Gas;

import util;
import Coord;
import TileData;
import constVar;
import globalVar;
import World;

export struct Gas
{
    int gridX, gridY, gridZ;
    gasFlag gasType = gasFlag::NONE;
    unsigned __int8 sprInfimum = 0;
    unsigned __int8 sprRandomStart = 0;

    Gas(int inputGridX, int inputGridY, int inputGridZ, gasFlag inputGas)
    {
        TileData* thisTile = &World::ins()->getTile(inputGridX, inputGridY, inputGridZ);
        if (thisTile->gasPtr != nullptr)
        {
            prt(L"[makeFlag] 이미 (%d,%d,%d)에는 가스가 존재한다.\n", inputGridX, inputGridY, inputGridZ);
            errorBox(L"중복된 위치에 Gas이 생성되었다.\n");
        }
        else
        {
            sprRandomStart = randomRange(0, 4);
            gridX = inputGridX;
            gridY = inputGridY;
            gridZ = inputGridZ;

            thisTile->gasPtr = this;
            switch (inputGas)
            {
            default:
            case gasFlag::SMALL:
                sprInfimum = 15;
                break;
            case gasFlag::NORMAL:
                sprInfimum = 10;
                break;
            case gasFlag::BIG:
                sprInfimum = 5;
                break;
            }
        }
    }

    ~Gas()
    {
        TileData* thisTile = &World::ins()->getTile(gridX, gridY, gridZ);
        thisTile->gasPtr = nullptr;
    }
};
