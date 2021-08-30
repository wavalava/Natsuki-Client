#include "Sex.h"

SexCommand::SexCommand() : IMCCommand("balls", "funi", "a") {
}

SexCommand::~SexCommand() {
}

bool SexCommand::execute(std::vector<std::string>* args) {
	assertTrue(g_Data.getLocalPlayer() != nullptr);

	clientMessageF("sex");
	return true;
}
