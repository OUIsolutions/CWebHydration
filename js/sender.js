



/**
 *@typedef {Object} ServerResponse
 *@property {string} callback
 *@property {Object} args
 */


/**
 *@param {string} route
 *@param {object} body
 **/
async function private_cweb_send_to_server(route,body){

    let result = await fetch(route,{
     method:'POST',
     body:JSON.stringify(body)
 });
 if(!result.ok){
     console.log(result.text());
    return;
 }
 /**@type {Array<ServerResponse>}**/
 let parsed =await result.json();
 parsed.forEach(function (callback){
     try{
         private_cweb_callbacks[callback.callback](callback.args)
     }
     catch (error){
         console.log(error);
     }
 })
}