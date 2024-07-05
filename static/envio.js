
async  function envia_pro_back(){
    let name = document.getElementById("name").value;
    let json = {
        name:name
    }
    let resposta = await  fetch("/valida_name",{
        method:'POST',
        body:JSON.stringify(json)
    })
    let resposta_texto =  await  resposta.text();
    alert(resposta_texto)

}