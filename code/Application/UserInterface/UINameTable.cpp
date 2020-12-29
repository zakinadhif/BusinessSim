#include "Application/UserInterface/UINameTable.hpp"

#include <fstream>
#include <sstream>

nlohmann::json UINameTable::nameTable;

void UINameTable::loadNameTable(const std::string& filepath)
{
	std::ifstream nameTableFile(filepath);
	nameTableFile >> nameTable;
}

const nlohmann::json& UINameTable::getNameTable()
{
	return nameTable;
}
