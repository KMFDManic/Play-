#pragma once

#include <map>
#include <mutex>
#include "PadHandler.h"
// #include "InputBindingManager.h"
#include "libretro.h"

class CPH_Libretro_Input : public CPadHandler
{
public:
	CPH_Libretro_Input() = default;
	virtual ~CPH_Libretro_Input() = default;

	void Update(uint8*) override;

	static FactoryFunction GetFactoryFunction();

	void UpdateInputState();

private:
	std::map<int, uint8> m_btn_state = {};
};