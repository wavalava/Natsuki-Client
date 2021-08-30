#pragma once
#include "ICommand.h"
class SexCommand : public IMCCommand {
public:
	SexCommand();
	~SexCommand();

	// Inherited via IMCCommand
	virtual bool execute(std::vector<std::string>* args) override;
};
