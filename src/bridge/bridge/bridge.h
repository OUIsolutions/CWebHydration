

typedef struct  CWebHyDrationBridge {
    char *route;
    char *name;
    char *error;
    char *error_key;
    int error_type;
    CwebStringArray *callbacks;
    CwebHttpRequest *request;
    cJSON *response;
    int max_body_size;
    cJSON *body;
}CWebHyDrationBridge;


