#pragma once

#include <nlohmann/json.hpp>

class UINameTable
{
public:
	UINameTable() = delete;

	static void loadNameTable(const std::string& filepath);
	static const nlohmann::json& getNameTable();

private:
	static nlohmann::json nameTable;
};
