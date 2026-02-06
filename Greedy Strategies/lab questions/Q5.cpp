#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        this->left = this->right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void storeCodes(struct MinHeapNode* root, string str, map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (root->data != '$')
        huffmanCode[root->data] = str;

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

void HuffmanCodes(vector<char>& data, vector<int>& freq, int size) {
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    map<char, string> huffmanCode;
    storeCodes(minHeap.top(), "", huffmanCode);

    cout << "Character Huffman Code" << endl;
    for (int i = 0; i < size; i++) {
        cout << data[i] << " " << huffmanCode[data[i]] << endl;
    }
}

int main() {
    vector<char> characters = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> frequencies = { 5, 9, 12, 13, 16, 45 };
    int size = characters.size();

    HuffmanCodes(characters, frequencies, size);

    return 0;
}