

typedef struct CWebHyDration {
    privateCWebHyDrationBridgeArray *all_bridges;

}CWebHyDration;

CWebHyDration * newCWebHyDration(CwebHttpRequest *request);

CWebHyDrationBridge * CWebHyDration_create_bridge(CWebHyDration *self,const char *route);

char *CWebHyDration_create_script(CWebHyDration *self);

void CWebHyDration_free(CWebHyDration *self);
