

typedef struct privateCWebHyDrationEntrie {
    char *key;
    int type;
    bool required;
    char * script;
}privateCWebHyDrationEntrie;

privateCWebHyDrationEntrie *private_privateCWebHyDrationEntrie();

void privateCWebHyDrationEntrie_free(privateCWebHyDrationEntrie*self);