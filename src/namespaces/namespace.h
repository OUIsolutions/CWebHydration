
typedef struct CWebHydrationNamespace{

    CWebHyDration * (*newHyDration)(CwebHttpRequest *request);
    CWebHyDrationBridge * (*create_bridge)(CWebHyDration *self,const char *route,char *name);
    char *(*create_script)(CWebHyDration *self);
    void (*free)(CWebHyDration *self);

}CWebHydrationNamespace;

CWebHydrationNamespace newCWebHydrationNamespace();