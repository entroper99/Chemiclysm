﻿export module randomRange;

import std;

std::random_device rd;
std::mt19937 gen(rd());

export int randomRange(int a, int b)
{
	std::uniform_int_distribution<int> dis(a, b);
	return dis(gen);
}
