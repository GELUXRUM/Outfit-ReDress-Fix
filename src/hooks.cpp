#include "hooks.h"

namespace HookLineAndSinker
{
	typedef int64_t(Set3DUpdateFlagSig)(RE::AIProcess*, RE::RESET_3D_FLAGS);
	REL::Relocation<Set3DUpdateFlagSig> OriginalFunction;

	int64_t HookedSet3DUpdateFlag(RE::AIProcess* a_process, RE::RESET_3D_FLAGS a_flags) {
		a_flags = RE::RESET_3D_FLAGS::kModel;
		return OriginalFunction(a_process, a_flags);
	}

	void RegisterHook(F4SE::Trampoline& trampoline) {
		REL::Relocation<Set3DUpdateFlagSig> callLocation{ REL::ID(323782), 0x29 };
		OriginalFunction = trampoline.write_call<5>(callLocation.address(), &HookedSet3DUpdateFlag);
	}
}
