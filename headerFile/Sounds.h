#pragma once
#include <iostream>
#include <windows.h>
#include <atomic>
#include <thread>
#pragma comment(lib,"winmm.lib")
using namespace std;

void PlayWavFile(const char* fileName);