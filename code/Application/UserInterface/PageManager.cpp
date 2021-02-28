#include "Application/UserInterface/PageManager.hpp"

#include <spdlog/spdlog.h>
#include <memory>
#include <string_view>
#include <tuple>

PageManager::PageManager(tgui::Container::Ptr pageContainer)
	: m_pageContainer(pageContainer)
{

}

tgui::Group::Ptr PageManager::getPage(const std::string &name)
{
	auto& [formpath, pagePtr] = m_pages.at(name);
	return pagePtr;
}

void PageManager::addPage(const std::string& filepath, const std::string& name, bool setAsActive)
{
	assert(filepath != "");

	auto page = tgui::Group::create();

	// load widgets from file, and save the filepath for later use
	page->loadWidgetsFromFile(filepath);
	m_pageContainer->add(page, name);
	
	m_pages.emplace(name, std::make_tuple(filepath, page));

	if (setAsActive)
	{
		setActivePage(name);
	}
	else
	{
		page->setVisible(false);
	}

	spdlog::info("PageManager: Page \"{}\" was added from \"{}\", setAsActive? {}.", name, filepath, setAsActive);
}

void PageManager::removePage(const std::string& name)
{
	auto& [formpath, pagePtr] = m_pages.at(name);

	m_pageContainer->remove(pagePtr);
	m_pages.erase(name);

	spdlog::info("PageManager: Page \"{}\" was removed.", name);
}

void PageManager::clearPages()
{
	m_pageContainer->removeAllWidgets();
	m_pages.clear();

	spdlog::info("PageManager: Pages cleared.");
}

void PageManager::setActivePage(const std::string &name)
{
	auto& [formpath, pagePtr] = m_pages.at(name);

	{
		auto currentActivePage = getActivePage();
		if (currentActivePage.get())
			currentActivePage->setVisible(false);
	}

	pagePtr->setVisible(true);
	m_activePage = pagePtr;

	spdlog::info("PageManager: Page \"{}\" is activated", name);
}

tgui::Group::Ptr PageManager::getActivePage()
{
	return m_activePage;
}

void PageManager::clearActivePage()
{
	auto currentActivePage = getActivePage();
	currentActivePage->setVisible(false);

	m_activePage = nullptr;

	spdlog::info("PageManager: Active page is set to none.");
}

void PageManager::reloadPages()
{
	for (auto& [pageName, formpathPagePair] : m_pages)
	{
		auto& [formpath, pagePtr] = formpathPagePair;

		spdlog::info("PageManager: Reloading page \"{}\" ...", formpath);

		pagePtr->removeAllWidgets();
		pagePtr->loadWidgetsFromFile(formpath);
	}

	spdlog::info("PageManager: All pages has been reloaded.");
}

PageManager::~PageManager()
{
	clearPages();
	spdlog::info("PageManager: Leaving with page cleared");
}


