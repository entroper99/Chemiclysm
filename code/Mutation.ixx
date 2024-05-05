﻿#include <SDL.h>

export module Mutation;

import std;
import util;
import GUI;
import textureVar;
import drawText;
import drawSprite;
import drawStadium;
import globalVar;
import checkCursor;
import drawWindow;
import drawRect;

export class Mutation : public GUI
{
private:
	inline static Mutation* ptr = nullptr;
	SDL_Rect mutationBase;
	std::array<SDL_Rect, 12> bionicRect;
	int bionicCursor = -1;
public:
	Mutation() : GUI(false)
	{
		//1개 이상의 메시지 객체 생성 시의 예외 처리
		errorBox(ptr != nullptr, "More than one message instance was generated.");
		ptr = this;

		//메세지 박스 렌더링
		changeXY(cameraW / 2, cameraH / 2, true);

		tabType = tabFlag::closeWin;

		deactInput();
		deactDraw();
		setAniType(aniFlag::winUnfoldOpen);
		aniUSet.insert(this);
		turnCycle = turn::playerAnime;
	}
	~Mutation()
	{
		tabType = tabFlag::autoAtk;
		ptr = nullptr;
	}
	static Mutation* ins() { return ptr; }
	void changeXY(int inputX, int inputY, bool center)
	{


		mutationBase = { 0, 0, 650, 376 };

		if (center == false)
		{
			mutationBase.x += inputX;
			mutationBase.y += inputY;
		}
		else
		{
			mutationBase.x += inputX - mutationBase.w / 2;
			mutationBase.y += inputY - mutationBase.h / 2;
		}


		if (center == false)
		{
			x = inputX;
			y = inputY;
		}
		else
		{
			x = inputX - mutationBase.w / 2;
			y = inputY - mutationBase.h / 2;
		}

		for (int i = 0; i < bionicRect.size(); i++)
		{
			bionicRect[i] = { mutationBase.x + 25, mutationBase.y + 34 + 29 + 24 * i, 569, 22 };
		}
	}
	void drawGUI()
	{
		if (getStateDraw() == false) { return; }

		if (getFoldRatio() == 1.0)
		{
			drawWindow(&mutationBase, sysStr[54], 11);

			setFontSize(10);
			drawText(col2Str(lowCol::white) + L"32/45", mutationBase.x + mutationBase.w - 46, mutationBase.y + 36 + 30 + 1 + +22 * -1);

			//for (int i = 0; i < bionicRect.size(); i++)
			for(int i=0; i<1; i++)
			{
				SDL_Rect pivotRect = bionicRect[i];

				SDL_Color btnColor = { 0x00, 0x00, 0x00 };
				if (checkCursor(&pivotRect))
				{
					if (click == false) { btnColor = lowCol::blue; }
					else { btnColor = lowCol::deepBlue; }
				}
				else if(bionicCursor == i)
				{
					btnColor = lowCol::blue;
				}
				
				drawFillRect(pivotRect.x, pivotRect.y, pivotRect.w, pivotRect.h, btnColor);
				drawRect(pivotRect.x + 4, pivotRect.y + 2, 18, 18, col::white); //아이콘 테두리
				drawSprite(spr::mutationIcon, 17, pivotRect.x + 5, pivotRect.y + 3);
				setFontSize(10);
				drawText(col2Str(lowCol::red) + L"[유당불내증] 당신은 유제품을 소화할 수 없습니다.", pivotRect.x + 29, pivotRect.y + 4);
				setFontSize(8);
				drawText(L"#FFFF00TOGGLE#FFFFFF : 360 kcal/act", pivotRect.x + pivotRect.w - 90, pivotRect.y + 11);
			}

			// 액티브 바이오닉 스크롤 그리기
			{
				SDL_Rect activeScrollBox = { mutationBase.x + mutationBase.w - 20,mutationBase.y + 36 + 24, 2, 282 };
				SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
				SDL_RenderFillRect(renderer, &activeScrollBox);
			}
		}
		else
		{
			SDL_Rect vRect = mutationBase;
			int type = 1;
			switch (type)
			{
				case 0:
					vRect.w = vRect.w * getFoldRatio();
					vRect.h = vRect.h * getFoldRatio();
					break;
				case 1:
					vRect.x = vRect.x + vRect.w * (1 - getFoldRatio()) / 2;
					vRect.w = vRect.w * getFoldRatio();
					break;
			}
			drawWindow(&vRect);
		}
	}
	void clickUpGUI()
	{
		if (getStateInput() == false) { return; }

		if (checkCursor(&tab))
		{
			close(aniFlag::winUnfoldClose);
		}
		else
		{
			for (int i = 0; i < bionicRect.size(); i++)
			{
				if (checkCursor(&bionicRect[i]))
				{
					bionicCursor = i;
					break;
				}

				if (i == bionicRect.size() - 1) bionicCursor = -1;
			}
		}
	}
	void clickMotionGUI(int dx, int dy) { }
	void clickDownGUI() { }
	void step() { }
};