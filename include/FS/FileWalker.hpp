#pragma once

#include <vector>
#include <string>
#include <filesystem>

#include "util/Types.hpp"

namespace fs = std::filesystem;

struct WalkOptions {
    std::vector<std::string> allowedExtensions;
    std::uintmax_t maxFileSizeBytes = 0; // 0 = no limit
    bool skipHidden = true;
    bool skipCommonJunkDirs = true;
};

class FileWalker {
public:
    static std::vector<FilePath>
    collectFiles(const FilePath& root, const WalkOptions& options);
};
