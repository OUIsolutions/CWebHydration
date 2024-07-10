

CWebHyDrationBridge *private_newCWebHyDrationBridge(
    const char *name,
    const char *route,
    CwebHttpRequest *request) {
    CWebHyDrationBridge *self = (CWebHyDrationBridge*)malloc(sizeof(CWebHyDrationBridge));
    *self = (CWebHyDrationBridge){0};
    if(name) {
        self->name = strdup(name);
    }
    self->route = strdup(route);
    self->request = request;
	self->callbacks = newCwebStringArray();
    return  self;
}

bool   CWebHyDrationBridge_is_the_route(CWebHyDrationBridge *self) {
    return strcmp(self->route,self->request->route) == 0;
}

CTextStack *private_CWebHyDrationBridge_create_script(CWebHyDrationBridge *self) {
    CTextStack *function = newCTextStack_string_empty();
    CTextStack_format(function,"async function ");
    if(self->name) {
        CTextStack_format(function,"%s",self->name);
    }
    else {
        CTextStack *formatted_name = newCTextStack_string(self->route);
        CTextStack_self_replace(formatted_name,"/","");
        CTextStack_format(function,"%tc",formatted_name);
    }
    CTextStack_format(function,"{\n");
    CTextStack_format(function,"\tlet body = {}\n");
    for(int i= 0; i < self->callbacks->size;i++) {
        CTextStack_format(function,"\t%s\n",self->callbacks->strings[i]);
    }

    CTextStack_format(function,"\tawait send_to_server('%s',body)\n",self->route);
    CTextStack_format(function,"}\n");
    return function;
}

void private_CWebHyDrationBridge_free(CWebHyDrationBridge *self) {
    free(self->route);
    if(self->name) {
        free(self->name);
    }
    free(self);
}