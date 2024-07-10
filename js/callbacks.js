

let private_cweb_callbacks = {}

/**
 *@typedef {Object} AlertArgs
 *@property {string} menssage
 */

/**
 *@param {AlertArgs} args
 **/
private_cweb_callbacks.private_cweb_alert = function (args){
    alert(args.menssage);
}

/**
 *@typedef {Object} DestroyArgs
 *@property {string} id
 */

/**
 *@param {DestroyArgs} args
 * **/
private_cweb_callbacks.private_cweb_destroy_by_id = function (args){
    let element = document.getElementById(args.id);
    if(element){
        element.remove();
    }
}

/**
 *@typedef {Object} ReplaceIdArg
 *@property {string} id
 *@property {string} html
 */

/**
 * @param {ReplaceId} args
 * **/
private_cweb_callbacks.private_cweb_hydration_replace_by_id = function (args){
    let element = document.getElementById(args.id);
    if(!element){
        return ;
    }
    let father = element.parentNode;
    let new_node = document.createElement("template");
    new_node.innerHTML= args.html;
    father.replaceChild(new_node,element);
}
