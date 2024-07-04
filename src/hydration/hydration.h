

typedef struct CWebHyDration {

}CWebHyDration;

CWebHyDration * newCWebHyDration(CwebHttpRequest *request);

char *CWebHyDration_create_script(CWebHyDration *self);

void CWebHyDration_free(CWebHyDration *self);
