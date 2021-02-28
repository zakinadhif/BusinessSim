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
	tgui::Group::Ptr getActivePage();
	void clearActivePage();

	~PageManager();

private:
	typedef std::tuple<std::string, tgui::Group::Ptr> FormpathPagePair;

	tgui::Group::Ptr m_activePage;
	std::unordered_map<std::string, FormpathPagePair> m_pages;
	tgui::Container::Ptr m_pageContainer;
};
