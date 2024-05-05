export module Mapmaker;

import std;
import util;
import constVar;

// Mapmaker
// 앞으로 생성될 청크들을 기록하는 객체 (큰 절차적 생성으로 만들어진 값들)
// 플레이어 주변에 없는 계시는 따로 파일로 저장함
// 저장 기능이 존재

export class Mapmaker
{
private:
	std::unordered_map<std::array<int, 3>, chunkFlag, decltype(arrayHasher3)> prophecy;
public:
	static Mapmaker* ins()//싱글톤 함수
	{
		static Mapmaker* ptr = new Mapmaker();
		return ptr;
	}
	void addProphecy(int chunkX, int chunkY, int chunkZ, chunkFlag input)
	{
		//errorBox(prophecy.find({ chunkX,chunkY,chunkZ }) == prophecy.end(), L"이미 계시된 청크가 Mapmaker에 입력됨");
		prophecy[{ chunkX, chunkY, chunkZ }] = input;
	}
	chunkFlag getProphecy(int chunkX, int chunkY, int chunkZ)
	{
		errorBox(prophecy.find({ chunkX,chunkY,chunkZ }) == prophecy.end(), L"얻어낼 청크가 Mapmaker에 존재하지 않음");
		return prophecy[{ chunkX, chunkY, chunkZ }];
	}
	bool isEmptyProphecy(int chunkX, int chunkY, int chunkZ)
	{
		if (prophecy.find({ chunkX,chunkY,chunkZ }) == prophecy.end()) return true;
		else return false;
	}
};