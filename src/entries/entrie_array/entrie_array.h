
typedef struct privateCWebEntrieArray {
    privateCWebHyDrationEntrie **elements;
    int size;
}privateCWebEntrieArray;

privateCWebEntrieArray *private_new_privateCWebEntrieArray();

void privateCWebEntrieArray_free(privateCWebEntrieArray *self);