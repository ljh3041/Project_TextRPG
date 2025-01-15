#include "../headerFile/MyMath.h"

int GetRandom(int _min, int _max)
{
	// 난수 엔진 초기화
	std::random_device rd;  // 하드웨어 기반 난수 생성기 (시드용)
	std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화

	// 범위 내 난수 생성기 (최소, 최대)
	std::uniform_int_distribution<> dist(_min, _max);

	return dist(gen);
}

float GetRandomf(float _min, float _max)
{
	// 난수 엔진 초기화
	std::random_device rd;  // 하드웨어 기반 난수 생성기 (시드용)
	std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화

	// 범위 내 난수 생성기 (최소, 최대)
	std::uniform_real_distribution<> dist(_min, _max);


	return static_cast<float>(dist(gen));
}

void PressAnyKey()
{
	int i = 0;
	std::cout << "\n▶ 아무 키나 입력해주세요.";
	i = _getch();
}
