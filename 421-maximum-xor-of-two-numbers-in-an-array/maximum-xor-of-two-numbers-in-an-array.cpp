struct TrieNode {
    TrieNode* children[2];
    TrieNode() { children[0] = children[1] = nullptr; }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int L = 31; // assume 32-bit integers (0..31)
        int maxXor = 0;

        for (int num : nums) {
            TrieNode* node = root;
            TrieNode* xorNode = root;
            int currXor = 0;

            for (int i = L; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int toggledBit = bit ^ 1;

                // Insert into Trie
                if (!node->children[bit]) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];

                // Check for best XOR path
                if (xorNode->children[toggledBit]) {
                    currXor |= (1 << i);
                    xorNode = xorNode->children[toggledBit];
                } else {
                    xorNode = xorNode->children[bit];
                }
            }
            maxXor = max(maxXor, currXor);
        }

        return maxXor;
    }
};