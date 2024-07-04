

typedef struct  CWebHyDrationBridge {
    char *route;
    char *error;
    char *error_key;
    int error_code;
    CwebHttpRequest *request;
}CWebHyDrationBridge;

CWebHyDrationBridge *private_newCWebHyDrationBridge(const char *route,CwebHttpRequest *request);

bool   CWebHyDrationBridge_is_the_route(CWebHyDrationBridge *self);

int    CWebHyDrationBridge_validate_entries(CWebHyDrationBridge *self);

char * CWebHyDrationBridge_get_error_menssage(CWebHyDrationBridge *self);

char * CWebHyDrationBridge_get_error_key(CWebHyDrationBridge *self);

int  CWebHyDrationBridge_get_error_code(CWebHyDrationBridge *self);


char *CWebHyDrationBridge_get_string_arg(CWebHyDrationBridge *self);

bool CWebHyDrationBridge_get_bool_arg(CWebHyDrationBridge *self);

int CWebHyDrationBridge_get_int_arg(CWebHyDrationBridge *self);

double CWebHyDrationBridge_get_double_arg(CWebHyDrationBridge *self);


void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self);
