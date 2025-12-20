#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>
#include <atomic>


#include "util/Types.hpp"

struct IndexStats {
    std::uint64_t filesIndexed = 0;
    std::uint64_t totalTokens  = 0;
    std::uint64_t uniqueWords  = 0;
};

class InvertedIndex {
public:
    explicit InvertedIndex(std::size_t numStripes = 64);

    void mergeFileCounts(const FilePath& file,
                         const WordCounts& localCounts);

    std::vector<std::pair<FilePath, Count>>
    lookup(const Word& word) const;

    IndexStats stats() const;

private:
    std::size_t stripeFor(const Word& word) const;

private:
    using FileMap = std::unordered_map<std::string, Count>;
    using IndexMap = std::unordered_map<Word, FileMap>;

    IndexMap index;

    std::vector<std::mutex> stripedMutexes;
    
    std::atomic<std::uint64_t> filesIndexed{0};
    std::atomic<std::uint64_t> totalTokens{0};
};
