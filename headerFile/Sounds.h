#pragma once
#include <iostream>
#include <windows.h>
#include <atomic>
#include <thread>
#pragma comment(lib,"winmm.lib")

void PlayWavFile(const char* fileName);

void playMusicLoop(const wchar_t* filePath);