#include "Application/PageManager.hpp"

#include <spdlog/spdlog.h>
#include <memory>
#include <string_view>

PageManager::PageManager(tgui::Container::Ptr pageContainer)
	: pageContainer(pageContainer)
{
	spdlog::info("PageManager: created with {} as page container", static_cast<void*>(pageContainer.get()));
}

void PageManager::addPage(const std::string& filepath, const std::string& name, bool setAsActive)
{
	if (name == "")
	{
		throw "Page name can't be empty";
	}

	auto page = tgui::Group::create();

	// load widgets from file, and save the filepath for later use
	page->loadWidgetsFromFile(filepath);
	pageFilepaths.push_back(filepath);

	// adding it to page container and saving the pointer
	pageContainer->add(page, name);
	pages.push_back(page);

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
	bool found = false;
	for (std::size_t i = 0; i < pages.size(); ++i)
	{
		auto& page = pages[i];

		sf::String pageName = std::static_pointer_cast<tgui::Widget>(page)->getWidgetName();

		// remove page with the same name as @parameter name
		if (pageName == name)
		{
			// remove the removed page from pages and pageFilepaths index, then remove the page
			pages.erase(pages.begin() + i);
			pageFilepaths.erase(pageFilepaths.begin() + i);
			pageContainer->remove(page);

			found = true;
		}
	}
	
	if (!found)
	{
		throw "Page \"" + name + "\" can't be removed: No such page exist.";
	}

	spdlog::info("PageManager: Page \"{}\" was removed.", name);
}

void PageManager::clearPages()
{
	pageContainer->removeAllWidgets();
	pages.clear();
	pageFilepaths.clear();

	spdlog::info("PageManager: Pages cleared.");
}

void PageManager::setActivePage(const std::string &name)
{
	bool found = false;
	for (auto& page : pages)
	{
		sf::String pageName = std::static_pointer_cast<tgui::Widget>(page)->getWidgetName();

		if (pageName == name)
		{
			page->setVisible(true);
			found = true;
		}
		else
		{
			page->setVisible(false);
		}
	}

	if (!found)
	{
		throw "Page \"" + name + "\" can't be activated: No such page exist.";
	}

	spdlog::info("PageManager: Page \"{}\" is setted active", name);
}

void PageManager::clearActivePage()
{
	for (auto& page : pages)
	{
		page->setVisible(false);
	}
	
	spdlog::info("PageManager: Active page is set to none.");
}

void PageManager::reloadPages()
{
	for (std::size_t i = 0; i < pages.size(); ++i)
	{
		auto& page = pages[i];

		page->removeAllWidgets();
		page->loadWidgetsFromFile(pageFilepaths[i]);
	}

	spdlog::info("PageManager: All pages has been reloaded.");
}

PageManager::~PageManager()
{
	clearPages();
	spdlog::info("PageManager: Leaving with page cleared");
}


