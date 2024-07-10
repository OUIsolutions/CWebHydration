
#include "CWebStudio.h"
#include "src/one.c"
CwebNamespace cweb;
CTextStackModule stack;
CWebHydrationNamespace hy;

CwebHttpResponse *main_sever(CwebHttpRequest *request) {

    CWebHyDration *hydration = hy.newHyDration(request);
    CWebHyDrationBridge *increment = hy.create_bridge(hydration,"/increment",NULL);
    hy.request_number_text_content_by_id(increment, "num");

    if(hy.is_the_route(increment)) {
        long num = hy.read_long(increment,"num");

        if(hy.error(increment)) {
            CwebHttpResponse *response = hy.generate_error_response(increment);
            hy.free(hydration);
            return response;
        }

        CTextStack * text = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.format(text,"%d",num + 1);
        }

        hy.replace_element_by_id_with_ctext_stack_cleaning_memory(increment,"num",text);
        hy.alert(increment, "O crlh que eu quiser");
        CwebHttpResponse *response = hy.generate_response(increment);
        return response;
    }


    CTextStack * text = stack.newStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    CTextScope(text,CTEXT_BODY){
        CTextScope(text,CTEXT_SCRIPT) {
           stack.format(text,hy.create_script(hydration));
        }
        CText$Scope(text,CTEXT_H3,"id='num'"){
            stack.text(text,"0");
        }
        CText$Scope(text,CTEXT_BUTTON,"onclick='%s'",hy.call(increment,NULL)){
             stack.text(text,"increment");
        }
    }
    hy.free(hydration);
    return  cweb.response.send_rendered_CTextStack_cleaning_memory(text,200);
}


int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    stack = newCTextStackModule();
    hy = newCWebHydrationNamespace();
    struct CwebServer server = newCwebSever(5001, main_sever);
    cweb.server.start(&server);
    return 0;

}