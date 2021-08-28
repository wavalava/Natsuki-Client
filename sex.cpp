#include "SexCommand.h"

SexCommand::SexCommand() : IMCCommand("sex", "balls", "funny") {
}

SexCommand::~SexCommand() {
}

bool SexCommand::execute(std::vector<std::string>* args) {
    assertTrue(g_Data.getLocalPlayer() != nullptr);

    clientMessageF("sex");
    return true;
}
