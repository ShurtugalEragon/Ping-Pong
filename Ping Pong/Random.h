#pragma once
#include <random>

/// <summary>
/// 
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns>Random integer within [min,max]</returns>
int random_int(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

/// <summary>
/// 
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns>Return random double within [min,max)</returns>
double random_double(double min, double max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distrib(min, max);
	return distrib(gen);
}