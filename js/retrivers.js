



function private_cweb_hydration_get_text_content_by_id (body,id){
    let element = document.getElementById(id);
    if(element){
        body[id] = element;
    }
}
