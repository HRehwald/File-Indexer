#pragma once

#include <string>
#include <vector>
#include <string_view>

#include "util/Types.hpp"

struct TokenizerOptions {
    bool toLower = true;
    bool keepDigits = true;
    std::size_t minTokenLength = 2;
};

class Tokenizer {
public:
    explicit Tokenizer(const TokenizerOptions& options = {});

    std::vector<Word> tokenizeLine(std::string_view line) const;

    // Convenience: read entire file and count tokens
    WordCounts countTokensInFile(const FilePath& file) const;

private:
    TokenizerOptions options;
    WordCounts countTokensInLine(std::string_view line) const;
    Word normalize(Word word) const;
};  
