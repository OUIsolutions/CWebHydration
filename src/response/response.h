typedef struct  CWebHyDrationResponse {
    cJSON *responses;
}CWebHyDrationResponse;

CWebHyDrationResponse * private_new_CWebHyDrationResponse();


CwebHttpResponse *CWebHyDrationResponse_create_respose(CWebHyDrationResponse *self);

void private_CWebHyDrationResponse_free(CWebHyDrationResponse *self);
