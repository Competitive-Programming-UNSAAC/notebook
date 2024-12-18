#define A 'a'
#define MAX 26

struct node {
  char alphabet;
  bool isEndOfWord;
  vector<node*> child;

  node() {
    isEndOfWord = 0;
    child.assign(MAX, NULL);
  }

  node(char letter) {
    alphabet = letter;
    isEndOfWord = 0;
    child.assign(MAX, NULL);
  }

  bool hasChild() {
    if(child.size() == 0) return 0;

    for(int i = 0; i < MAX; i++) {
      if(child[i] != NULL) return 1;
    }

    return 0;
  }
};

void insert(node* root, string word, int index) {
  if(index == word.size()) {
    root->isEndOfWord = 1;
    return;
  }

  int pos = word[index] - A;
  if(root->child[pos] == NULL) {
    root->child[pos] = new node(word[index]);
  }

  insert(root->child[pos], word, index + 1);
}

bool remove(node* root, string word, int index) {
  if(index == word.size()) {
    if(root->isEndOfWord) {
      root->isEndOfWord = 0;
      return !root->hasChild();
    }
    return 0;
  }

  int pos = word[index] - A;
  if(root->child[pos] == NULL) return 0;

  bool shouldDeleteNode = remove(root->child[pos], word, index + 1);

  if(shouldDeleteNode) {
    root->child[pos] = NULL;
    return !root->hasChild();
  }
  return 0;
}

bool search(node* root, string word, int index) {
  if(index == word.size()) return root->isEndOfWord;

  int pos = word[index] - A;
  if(root->child[pos] == NULL) return 0;

  return search(root->child[pos], word, index + 1);
}

node* searchPrefix(node* root, string prefix, int index) {
  if(index == prefix.size()) return root;

  int pos = prefix[index] - A;
  if(root->child[pos] == NULL) return NULL;

  return searchPrefix(root->child[pos], prefix, index + 1);
}

bool startWith(node* root, string prefix, int index) {
  if(index == prefix.size()) return 1;

  int pos = prefix[index] - A;
  if(root->child[pos] == NULL) return 0;

  return startWith(root->child[pos], prefix, index + 1);
}

// Print all words from a node
void dfs(node* root, string word) {
  for(int i = 0; i < MAX; i++) {
    if(root->child[i] != NULL) {
      char letter = root->child[i]->alphabet;
      node* next = root->child[i];

      dfs(next, word + letter);
    }
  }

  if(root->isEndOfWord) cout<<word<<endl;
}

int main() {
    // do not remove this code if you use cin or cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    node* root = new node();

    insert(root, "car", 0);
    insert(root, "clear", 0);
    insert(root, "bar", 0);
    insert(root, "claw", 0);

    node* prefix = searchPrefix(root, "cl", 0);
    for(int i = 0; i < MAX; i++) {
    }


    dfs(root, "");

    prefix = searchPrefix(root, "cl", 0);
    dfs(prefix, "cl");

    remove(root, "clear", 0);
    remove(root, "car", 0);


    return 0;
}