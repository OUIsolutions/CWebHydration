

void CWebHyDrationBridge_add_function(CWebHyDrationBridge *self,const char *function,const char *format, ...) {

    if(format == NULL) {
        CTextStack *code = newCTextStack_string_format("%s(body);",function);
        CwebStringArray_add(self->callbacks,code->rendered_text);
        CTextStack_free(code);
        return;
    }
    va_list  args;
    va_start(args,format);
    char *result = private_CWebHydration_format_vaarg(format,args);
    va_end(args);
    CTextStack *code = newCTextStack_string_format("%s(body,%s);",function,result);
    CwebStringArray_add(self->callbacks,code->rendered_text);
    CTextStack_free(code);
    free(result);
}
