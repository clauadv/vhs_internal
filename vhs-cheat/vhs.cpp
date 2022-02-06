#include <thread>
#include "hooks/hooks.h"

unsigned long WINAPI initialize(void* instance) {
	try {
		// utils::console::initialize("vhs-cheat");
		sdk::initialize();
	}

	catch (const std::runtime_error& error) {
		MessageBoxA(nullptr, error.what(), ("vhs-cheat"), MB_OK | MB_ICONERROR);
		FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
	}

	while (!GetAsyncKeyState(VK_END))
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
}

bool DllMain(const HMODULE module, const std::uint32_t call_reason, void* reserved [[maybe_unused]] ) {
	DisableThreadLibraryCalls(module);

	switch (call_reason) {
		case DLL_PROCESS_ATTACH:
		if (const auto handle = CreateThread(nullptr, NULL, initialize, module, NULL, nullptr))
			CloseHandle(handle);
		break;
		case DLL_PROCESS_DETACH:
		hooks::release();
		break;
		default:
		break;
	}

	return true;
}