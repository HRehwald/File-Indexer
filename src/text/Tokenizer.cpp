#include "text/Tokenizer.hpp"
    using namespace std;


    explicit Tokenizer::Tokenizer(const TokenizerOptions& options = {}) {

    }
    std::vector<Word> Tokenizer::tokenizeLine(std::string_view line) const {
        std::vector<Word> words;
        
        size_t i = 0;

        while (i < line.size()) {
            // 1) skip whitespace
            while (i < line.size() && isspace(line[i])) {
                ++i;
            }

            if (i >= line.size()) break;

            // 2) mark token start
            size_t start = i;

            // 3) advance until whitespace
            while (i < line.size() && !isspace(line[i])) {
                ++i;
            }

            size_t length = i - start;

            // 4) extract token
            string_view tokenView = line.substr(start, length);

            // 5) normalize + store
            words.push_back(normalize(tokenView));
        }
        return words;
    }

    WordCounts Tokenizer::countTokensInLine(std::string_view line) const {
        std::vector<Word> words = Tokenizer::tokenizeLine(line);
        WordCounts counts;
        for (const Word& word : words) {
            counts[word]++;
        }
        return counts;
    }

    // Convenience: read entire file and count tokens
    WordCounts Tokenizer::countTokensInFile(const FilePath& file) const {

    }
