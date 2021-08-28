#include "FardCommand.h"

FardCommand::FardCommand() : IMCCommand("farded", "Fard", "fards") {
}

SexCommand::~SexCommand() {
}

bool SexCommand::execute(std::vector<std::string>* args) {
    assertTrue(g_Data.getLocalPlayer() != nullptr);

    clientMessageF("Fard");
    return true;
}
