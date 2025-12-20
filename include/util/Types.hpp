#pragma once

#include <string>
#include <unordered_map>
#include <filesystem>
#include <cstdint>

using FilePath = std::filesystem::path;
using Word     = std::string;
using Count    = std::uint32_t;

using WordCounts = std::unordered_map<Word, Count>;
