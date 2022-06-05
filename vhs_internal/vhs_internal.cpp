#include <includes.h>
#include "hooks/hooks.h"

bool DllMain(const HMODULE module, const std::uint32_t call_reason, void* reserved [[maybe_unused]] ) {
	LI_FN(DisableThreadLibraryCalls)(module);

	if (call_reason != DLL_PROCESS_ATTACH) {
		return false;
	}

	std::future<void> thread = std::async(std::launch::async, [&module]{
		try {
			// utils::console::initialize(_("vhs_internal"));
			ue4::sdk::initialize();
		}

		catch (const std::runtime_error& error) {
			LI_FN(MessageBoxA)(nullptr, error.what(), _("vhs_internal"), MB_OK | MB_ICONERROR);
			LI_FN(FreeLibraryAndExitThread)(module, 0);
		}
	});

	return true;
}