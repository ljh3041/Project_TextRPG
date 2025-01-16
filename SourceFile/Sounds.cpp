#include "../headerFile/Sounds.h"

void PlayWavFile(const char* fileName)
{
	wchar_t wFilePath[MAX_PATH];
	MultiByteToWideChar(CP_ACP, 0, fileName, -1, wFilePath, MAX_PATH);
	PlaySound(wFilePath, NULL, SND_FILENAME | SND_ASYNC);
}

void playMusicLoop(const wchar_t* filePath) {
    while (1) {
        PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

