
#include "CWebStudio.h"

CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    if(strcmp(request->route,"/valida_name")== 0) {
        cJSON *body = cweb.request.read_cJSON(request,1000);
        if(body== NULL) {
            return  cweb.response.send_text("vnocê não passou um json",404);
        }
        cJSON *name = cJSON_GetObjectItem(body,"name");
        if(name == NULL) {
            return  cweb.response.send_text("vnocê não passou o name",404);
        }
        if(!cJSON_IsString(name)) {
            return  cweb.response.send_text("nome não é uma string",404);
        }
        char *name_convertido = cJSON_GetStringValue(name);
        char menssagem[20] = {0};
        sprintf(menssagem,"nome %s salvo",name_convertido);
        return cweb.response.send_text(menssagem,200);
    }

    return cweb.response.send_text("Hello World", 200);

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();

    struct CwebServer server = newCwebSever(5001, main_sever);
    server.single_process = true;
    cweb.server.start(&server);
    return 0;
}