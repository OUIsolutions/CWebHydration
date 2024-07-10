
#include "CWebStudio.h"
#include "src/one.c"
CwebNamespace cweb;
CTextNamespace stack;
/*
CwebHttpResponse *server(CwebHttpRequest *request) {

    CWebHyDration *hy = newCWebHyDration(request);

    CWebHyDrationBridge *increment = CWebHyDration_create_bridge(hy,"/increment",NULL);


    if(CWebHyDrationBridge_is_the_route(increment)) {
        long num = CWebHyDration_get_num(increment,"num");

        if(CWebHyDration_error(hy)) {
            char *error = CWebHydration_get_error(increment);
            return  cweb.response.send_text(error,404);
        }

        CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
        CTextScope(text,CTEXT_H3,{
            CTextFormat(text,"%d",num + num);
        })
        CWebHyDration_replace_id_with_ctext_cleaning_memory(increment,"h3",text);
        CwebHttpResponse *response = CWebHyDration_create_response(increment);
        CWebHyDration_free(hy);
        return response;
    }


    CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY,{

        CTextScope(text,CTEXT_H3,{
            CTextFormat(text,"id='%d'",0);
        })
        CTextScope(text,CTEXT_BUTTON,{
            CTextFormat(text,"increment");
        })
    })

    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}
*/
int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    stack = newCTextNamespace();
    CWebHyDration *hy = newCWebHyDration(NULL);
    CWebHyDrationBridge *increment = CWebHyDration_create_bridge(hy,"/increment",NULL);
    CWebHyDration_add_input_by_id(increment,"num");
    char* script  = CWebHyDration_create_script(hy);
    printf("%s\n",script);
    return 0;
}