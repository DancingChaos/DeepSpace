#pragma once
#include <random>
#include <iomanip>

float FloatRand(const float FLOAT_MIN, const float FLOAT_MAX) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
	return distr(eng);
}
