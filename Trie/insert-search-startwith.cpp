// Implementation of TRIE
// Insert , Search , StartsWith function
// TC - O(length of word)  for all

// Now on : its only implementation code not working one

struct Node
{
    Node *links[26];  // first member to hold reference
    bool flag = true; // this generally represents word ends or not

    // here we have some member functions according to our need

    // check if the key(i.e, character in word already exists or not in trie)
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    // add a key with new reference node attach to it
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node; // adding reference node to it
    }

    // getting reference node of particular key
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // set the flag of last reference node of word's key to true to mark  the word's end
    void setEnd()
    {
        flag = true;
    }

    // to check if word's last char as key , their reference node's flag value is true or not
    bool isEnd()
    {
        return flag;
    }
};

// creating root
Node *root = new Node();

// insert a new word in trie data structure
void insert(string word)
{
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (!node->containsKey(word[i])) // if that key is not in the trie particular position then add it to it
        {
            node->put(word[i], new Node()); // adding key with reference new node
        }
        // moves to the reference track
        node = node->get(word[i]);
    }
    // after inserting every letter in trie mark the end of word by setting last reference node flag to true
    node->setEnd();
}

// returns if the word is in the Trie
bool search(string word)
{
    Node *node = root;
    for (int i = 0; i < n; i++)
    {
        if (!node->containsKey(word[i])) // if it doesnot contain word's character as a key then return false
        {
            return false;
        }
        node = node->get(word[i]);
    }
    return node->isEnd();
}

// return if there is any word that starts with prefix given
bool startsWith(string prefix)
{
    Node *node = root;
    for (int i = 0; i < prefix.size(); i++)
    {
        if (!node->containsKey(prefix[i]))
        {
            return false;
        }
        node = node->get(prefix[i]);
    }
    return true;
}

int main()
{
    return 0;
}