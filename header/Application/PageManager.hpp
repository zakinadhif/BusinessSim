#pragma once

#include <TGUI/TGUI.hpp>

#include <string>

class PageManager
{
public:
	PageManager(tgui::Container::Ptr pageContainer);

	void addPage(const std::string& filepath, const std::string& name);
	void removePage(const std::string& name);
	void clearPages();

	void reloadPages();

	void setActivePage(const std::string& name);
	void clearActivePage();

	~PageManager();

private:
	std::vector<tgui::Group::Ptr> pages;
	std::vector<std::string> pageFilepaths;
	tgui::Container::Ptr pageContainer;
};
