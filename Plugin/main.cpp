#include "../ServerAPI/AsaApi/Core/Public/IApiUtils.h"



void Load() {
    Log::Get().Init("ASAApi_example");
    Log::GetLog()->error("Hello World!");
}

void Unload() {

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            Load();
            break;
        case DLL_PROCESS_DETACH:
            Unload();
            break;
    }
    return TRUE;
}