
//status 0 para display none e 1 para display block

var status = 0

function altera_exibicao(item_id){
    let item = document.getElementById(item_id)
    if(status == 0){
        item.setAttribute("style", "display: block;")
        status = 1
    }
    else{
        item.setAttribute("style", "display: none;")
        status = 0
    }
}