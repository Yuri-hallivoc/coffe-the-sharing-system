# Coffee the sharing system

## O que é?


Trata-se de um sistema que visa permitir a transferência de arquivos pela web, permitindo que os usuários enviem
e baixem arquivos já enviados ao servidor.


## O que  motivou a criação deste sistema?


Após verificar as diversas opções de transfência de arquivo disponíveis, é possível verificar que,
para aqueles que já tem um servidor web e o php instalados em uma máquina conectada a rede, um sistema 
desse tipo é uma alternativa mais simples, pois basta clonar o projeto e configurá-lo no servidor para poder
tranferir facilmente arquivos via web.


## como instalar o sistema? (instruções para o servidor web apache no sistema operacional ubuntu)


1. abra um terminal e clone o repositório com o comando

~~~shell

git clone https://github.com/Yuri-hallivoc/coffee-the-sharing-system

~~~

2. Envie os arquivos clonados do repositório para dentro da pasta definida pelo apache como Document Roots
através do comando

~~~shell

sudo cp -r ./coffee-the-sharing-system /var/www

~~~

3. Acesse a pasta /etc/apache2/sites-available e crie um arquivo chamado coffee-the-sharing-system.conf.

4. Abra o arquivo criado e cole o seguinte texto e salve-o

~~~

<VirtualHost *:3000>

               ServerAdmin                    webmaster@localhost

               DocumentRoot                /var/www/coffee-the-sharing-system

</VirtualHost>

~~~

**obs.:** A porta 3000 pode ser substituída por outra qualquer.

5. Abra o arquivo /etc/apache2/ports.conf e localize a linha onde está escrito **Listen 80**
e cole abaixo desta linha o texto **Listen 3000** (ou com outro número, caso escolha usar outra
porta) e salve o arquivo.

6. Usando o terminal, ative o site através do seguinte comando

~~~shell

a2ensite coffee-the-sharing-system

~~~

7. Digite o seguinte comando no terminal para reiniciar o apache

~~~shell

service apache2 reload

~~~

Após seguir estes passos o sistema já deve estar no ar. Para acessá-lo, digite o endereço
de ip do servidor no navegador, seguido de dois pontos e o número da porta(ex.: 192.168.0.14:3000).

É possível que a transferência fique limitada a arquivos de até 2MB por conta das configurações padrão
do apache. Nesse caso, você pode precisar aumentar os limites de transferência. Para obter mais informações
acesse [https://pt.stackoverflow.com/questions/256460/upload-de-imagens-maior-que-2mb](https://pt.stackoverflow.com/questions/256460/upload-de-imagens-maior-que-2mb).