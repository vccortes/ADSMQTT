# ADSMQTT
## Breve descrição do funcionamento e uso para quem quiser reproduzir:
O código apresentado é destinado a controlar um dispositivo IoT utilizando o ESP32 como plataforma de desenvolvimento. O dispositivo possui um sensor de movimento (PIR) conectado ao pino 13 e se comunica com um servidor MQTT hospedado em "test.mosquitto.org" na porta 1883. O ESP32 se conecta a uma rede Wi-Fi fornecendo as credenciais do SSID e senha. Após estabelecer a conexão Wi-Fi e a conexão MQTT, o ESP32 monitora o estado do sensor de movimento. Se o sensor detectar movimento, o ESP32 publica a mensagem "Movimento" no tópico "movimento" do servidor MQTT. Caso contrário, ele publica a mensagem "Sem Movimento". O dispositivo também recebe comandos MQTT do servidor, mas essa funcionalidade não está presente no código fornecido.

## Software desenvolvido e documentação do código:
O código fornecido é escrito em linguagem C++ usando a biblioteca Arduino. Ele utiliza a biblioteca "WiFi.h" para a conexão Wi-Fi e a biblioteca "PubSubClient.h" para a comunicação MQTT. O código é executado em um loop infinito, onde a função loop() verifica se o cliente MQTT está conectado e lida com as detecções do sensor de movimento. A função reconnect() é chamada para reconectar ao servidor MQTT, caso a conexão seja perdida.

## Descrição do hardware utilizado:
O hardware utilizado consiste no módulo ESP32 como plataforma de desenvolvimento. O sensor de movimento (PIR) está conectado ao pino 13 do ESP32. Além disso, é necessário um acesso à rede Wi-Fi para estabelecer a conexão com o servidor MQTT hospedado em "test.mosquitto.org" na porta 1883. Detalhes adicionais sobre a plataforma física e a montagem não são fornecidos no código.

## Documentação das interfaces, protocolos e módulos de comunicação:
O código utiliza a interface Wi-Fi para se conectar a uma rede sem fio fornecendo as credenciais do SSID e senha. A comunicação com o servidor MQTT é estabelecida usando o protocolo MQTT (Message Queuing Telemetry Transport). A biblioteca "WiFi.h" é responsável pela comunicação Wi-Fi, enquanto a biblioteca "PubSubClient.h" lida com a comunicação MQTT.

## Comunicação/controle via internet (TCP/IP) e uso do Protocolo MQTT:
O projeto utiliza a comunicação via internet por meio do protocolo TCP/IP. O ESP32 se conecta à rede Wi-Fi para estabelecer uma conexão TCP/IP com o servidor MQTT hospedado em "test.mosquitto.org" na porta 1883. O protocolo MQTT é utilizado para enviar mensagens e receber comandos do servidor MQTT. O ESP32 publica mensagens no tópico "movimento" quando detecta ou não movimento, permitindo que outros dispositivos inscritos no mesmo tópico recebam essas informações.
