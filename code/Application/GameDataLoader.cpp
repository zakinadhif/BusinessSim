#include "Application/GameDataLoader.hpp"

#include <yaml-cpp/yaml.h>

#include <filesystem>

static const char* commoditiesFilepath = "assets/game_data/commodities.yaml";
static const char* gameDataPath = "assets/game_data/";

static std::vector<MarketEvent> loadEvents(const std::string& filepath)
{
	// Determines relative path from exe's directory
	namespace fs = std::filesystem;
	fs::path gameDataPath(::gameDataPath);

	fs::path eventsFilepath = gameDataPath / filepath;

	std::vector<MarketEvent> events;

	YAML::Node root = YAML::LoadFile(eventsFilepath);

	for (const auto& node : root)
	{
		MarketEvent event {
			.id = node[0].as<int>(),
			.headline = node[1].as<std::string>(),
			.marketVolatility = node[2].as<float>(),
			.marketDrive = node[3].as<float>(),
			.maxPriceChange = node[4].as<float>(),
			.chance = node[5].as<int>(),
			.onlyOnce = node[6].as<bool>()
		};
		
		events.push_back(event);
	}

	return std::move(events);
}

static Commodity loadCommodity(YAML::Node node)
{
	Commodity commodity {
		.shortName = node.as<std::string>(),
		.fullName = node["name"].as<std::string>(),
		.description = node["description"].as<std::string>(),
		.logoPath = node["logo"].as<std::string>(),
		.events = loadEvents(node["events"].as<std::string>())
	};

	return std::move(commodity);
}

std::vector<Commodity> loadCommodities()
{
	std::vector<Commodity> commodities;

	YAML::Node root = YAML::LoadFile(commoditiesFilepath);

	for (const auto& node : root)
	{
		commodities.push_back(loadCommodity(node));
	}

	return std::move(commodities);
}
