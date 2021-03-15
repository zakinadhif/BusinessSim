#include "Application/GameDataLoader.hpp"

#include <yaml-cpp/yaml.h>

static const char* commoditiesFilepath = "assets/game_data/commodities.yaml";

static std::vector<MarketEvent> loadEvents(const std::string& filepath)
{
	std::vector<MarketEvent> events;

	YAML::Node root = YAML::LoadFile(filepath);

	for (const auto& node : root)
	{
		MarketEvent event {
			.id = node[0].as<int>(),
			.headline = node[1].as<std::string>(),
			.marketVolatility = node[2].as<float>(),
			.marketDrive = node[3].as<float>(),
			.onlyOnce = node[4].as<bool>(),
			.chance = node[5].as<int>()
		};
		
		events.push_back(event);
	}

	return std::move(events);
}

static CommodityData loadCommodity(YAML::Node node)
{
	CommodityData commodity {
		.shortName = node.as<std::string>(),
		.name = node["name"].as<std::string>(),
		.description = node["description"].as<std::string>(),
		.logoPath = node["logo"].as<std::string>(),
		.events = loadEvents(node["events"].as<std::string>())
	};

	return std::move(commodity);
}

std::vector<CommodityData> loadCommodities()
{
	std::vector<CommodityData> commodities;

	YAML::Node root = YAML::LoadFile(commoditiesFilepath);

	for (const auto& node : root)
	{
		commodities.push_back(loadCommodity(node));
	}

	return std::move(commodities);
}
