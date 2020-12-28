#pragma once

#include <TGUI/TGUI.hpp>

#include <string>

class PageManager
{
public:
	PageManager(tgui::Container::Ptr pageContainer);

	void addPage(const std::string& filepath, const std::string& name, bool setAsActive = false);
	void removePage(const std::string& name);
	void clearPages();

	tgui::Group::Ptr getPage(const std::string& name);

	void reloadPages();

	void setActivePage(const std::string& name);
	void clearActivePage();

	~PageManager();

private:
	std::vector<tgui::Group::Ptr> pages;
	std::vector<std::string> pageFilepaths;
	tgui::Container::Ptr pageContainer;
};
