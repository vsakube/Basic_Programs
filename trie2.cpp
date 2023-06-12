#include <iostream>
#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

void printWords(TrieNode* root, std::string& currentPrefix) {
    if (root == nullptr)
        return;

    if (root->isEndOfWord) {
        std::cout << currentPrefix << std::endl;
    }

    for (auto& entry : root->children) {
        char c = entry.first;
        TrieNode* child = entry.second;

        currentPrefix += c;
        printWords(child, currentPrefix);
        currentPrefix.pop_back();
    }
}


void insert(TrieNode* root, const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->isEndOfWord = true;
}

bool deleteWord(TrieNode* root, const std::string& word) {

    int level=0;
    if (root == nullptr)
        return false;

    // Base case: all characters of the word have been processed
    if (level == word.length()) {
        if (root->isEndOfWord) {
            // Mark the node as no longer the end of a word
            root->isEndOfWord = false;

            // If the node has no other children, it can be deleted
            if (root->children.empty()) {
                delete root;
                root = nullptr;
                return true;
            }
        }
        return false;
    }

    char currentChar = word[level];
    TrieNode* nextNode = root->children[currentChar];

    // Recursive call to delete the next character in the word
    bool shouldDeleteCurrentNode = deleteWord(nextNode, word, level + 1);

    // If the next node was deleted and this node has no other children, it can be deleted as well
    if (shouldDeleteCurrentNode && !root->isEndOfWord && root->children.empty()) {
        delete root;
        root = nullptr;
        return true;
    }

    return false;
}

int main() {
    TrieNode* root = new TrieNode();
    std::string str = "Hello World";

    insert(root, str);
    std::string currentPrefix;
    printWords(root, currentPrefix);

    std::cout << std::endl;

    deleteWord(root, "Hello", 1);

    printWords(root, currentPrefix);


    return 0;
}

