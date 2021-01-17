
function altera_exibicao(item_id){
    let item = document.getElementById(item_id)
    let lista_item_visivel = document.getElementsByClassName("visivel")
    let item_visivel
    let i
    if(item.classList.contains("invisivel")){
        item.classList.remove("invisivel")
        item.classList.add("visivel")
    }
    else{
        item.classList.remove("visivel")
        item.classList.add("invisivel")
    }
    for(i = 0; i < lista_item_visivel.length; i++){
        item_visivel = document.getElementById(lista_item_visivel[i].id)
        if(item_visivel != item){
            item_visivel.classList.remove("visivel")
            item_visivel.classList.add("invisivel")
        } 
    }
}