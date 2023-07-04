#pragma once

namespace HookLineAndSinker
{
	std::int64_t HookedSet3DUpdateFlag(RE::AIProcess* a_process, RE::RESET_3D_FLAGS a_flags);

	void RegisterHook(F4SE::Trampoline& trampoline);
}
