class Solution {
public:
    string reorderSpaces(string s) {
        int scount = 0, wcount = 0;
        int n = s.size();
        vector<string> words;

        // Count spaces and collect words
        string current_word;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                scount++;
                if(!current_word.empty()) {
                    words.push_back(current_word);
                    current_word.clear();
                }
            } else {
                current_word += s[i];
            }
        }
        
        // Add the last word if exists
        if(!current_word.empty()) {
            words.push_back(current_word);
        }
        
        wcount = words.size();
        
        // Handle edge cases
        if(wcount == 0) return s; // No words, return as is
        if(wcount == 1) { // Only one word, all spaces at end
            return words[0] + string(scount, ' ');
        }

        // Calculate spaces between words and extra spaces
        int spaces_between = scount / (wcount - 1);
        int extra_spaces = scount % (wcount - 1);

        string result;
        for(int i = 0; i < words.size(); i++) {
            result += words[i];
            if(i < words.size() - 1) { // Not the last word
                result += string(spaces_between, ' ');
            }
        }

        // Add remaining spaces at the end
        if(extra_spaces > 0) {
            result += string(extra_spaces, ' ');
        }

        return result;
    }
};