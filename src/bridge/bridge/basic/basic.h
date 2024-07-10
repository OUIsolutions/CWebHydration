

CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    const char *route,
    CwebHttpRequest *request
    );


bool CWebHyDrationBridge_is_the_route(CWebHyDrationBridge *self);


CTextStack *private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self);

void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self);