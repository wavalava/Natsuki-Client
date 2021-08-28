#pragma once
#include <map>

#include "ICommand.h"

class BindCommand : public IMCCommand {
public:
	BindCommand();
	~BindCommand();

	// Skidded from horion!
	virtual bool execute(std::vector<std::string>* args) override;
};