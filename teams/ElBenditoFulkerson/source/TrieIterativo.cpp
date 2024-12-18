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

void insert(node* root, string word) {
  node* cur = root;

  for(int i = 0; i < word.size(); i++) {
    int pos = word[i] - A;

    if(cur->child[pos] == NULL) {
      cur->child[pos] = new node(word[i]);
    }
    cur = cur->child[pos];
  }

  cur->isEndOfWord = 1;
}

void remove(node* root, string word) {
  stack<node*> S;

  node* cur = root;

  for(int i = 0; i < word.size(); i++) {
    int pos = word[i] - A;

    if(cur->child[pos] == NULL) return;

    S.push(cur->child[pos]);
    cur = cur->child[pos];
  }

  int i = word.size() - 1;

  while(!S.empty()) {
    cur = S.top();
    S.pop();

    int pos = word[i] - A;
    if(cur->isEndOfWord) cur->isEndOfWord = 0;
    if(!cur->hasChild()) cur = NULL;

    i--;
  }
}

bool search(node* root, string word) {
  node* cur = root;

  for(int i = 0; i < word.size(); i++) {
    int pos = word[i] - A;

    if(cur->child[pos] == NULL) return 0;
    cur = cur->child[pos];
  }

  return cur->isEndOfWord;
}

node* searchPrefix(node* root, string prefix) {
  node* cur = root;

  for(int i = 0; i < prefix.size(); i++) {
    int pos = prefix[i] - A;

    if(cur->child[pos] == NULL) return NULL;
    cur = cur->child[pos];
  }

  return cur;
}

bool startWith(node* root, string prefix) {
  node* cur = root;

  for(int i = 0; i < prefix.size(); i++) {
    int pos = prefix[i] - A;

    if(cur->child[pos] == NULL) return 0;
    cur = cur->child[pos];
  }

  return 1;
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

    insert(root, "car");
    insert(root, "clear");
    insert(root, "bar");
    insert(root, "claw");


    node* prefix = searchPrefix(root, "cl");
    for(int i = 0; i < MAX; i++) {
    }


    dfs(root, "");

    prefix = searchPrefix(root, "cl");
    dfs(prefix, "cl");

    remove(root, "clear");
    remove(root, "car");

    return 0;
}