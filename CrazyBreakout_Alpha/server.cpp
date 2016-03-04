#include "server.h"

server* server::_Server = 0;
int server::_angle = 0;
int server::_power = 0;

server::server(){
    isconnect = false;
}

bool server::createSocket(){
    this->_fd = socket(AF_INET,SOCK_STREAM,0);
    if (this->_fd < 0)
        return false;
    this->_socketInformation.sin_family = AF_INET;
    this->_socketInformation.sin_addr.s_addr = INADDR_ANY;
    this->_socketInformation.sin_port = htons(5001);
    memset(&_socketInformation.sin_zero,0,sizeof(_socketInformation.sin_zero));
    return true;
}

bool server::setKernel(){
    if((bind(this->_fd,(sockaddr*)&_socketInformation,(socklen_t)sizeof(_socketInformation))) < 0)
        return false;

    listen(this->_fd,5);
    return true;
}

void server::run(){
    if(!this->createSocket())
        throw string("Error al crear socket");
    if(!this->setKernel())
        throw string("Error al crear kernel");
    while(true){
        cout << "Wait for client" << endl;
        dataSocket data;
        socklen_t tam = sizeof(data.info);
        data.descriptor = accept(this->_fd,(sockaddr*)&data.info,&tam);
        if(data.descriptor < 0){
            throw string("Error en aceptar el client");
        }else{
            cout << "Found a client" << endl;
            isconnect = true;
            pthread_t hilo;
            args.data = data;
            args.Server = this;
            pthread_create(&hilo,0,SocketThread,(void*)&data);
            pthread_detach(hilo);
        }
    }
}

void* server::SocketThread(void* obj){
    arguments *args = (arguments*) obj;
    dataSocket data = args->data;
    _Server = (server*)args->Server;
    while(true){
        string mensaje;
        while(true){
            char buffer [10] = {0};
            int bytes = recv(data.descriptor,buffer,10,0);
            mensaje.append(buffer,bytes);
            if(mensaje.length() < 10)
                break;
        }
        cout << "mensaje" << _Server->parcerAngulo(mensaje) << " " << _Server->parcerFuerza(mensaje) << endl;
    }
    close(data.descriptor);
    pthread_exit(NULL);
}

int server::parcerFuerza(string pParcer){
    string fuerza = pParcer.substr(pParcer.find(" "),pParcer.length());
    server::_power = atoi(fuerza.c_str());
    return server::_power;
}

bool server::getIsconnect() const
{
    return isconnect;
}

int server::parcerAngulo(string pParcer){
    string angulo = pParcer.substr(0,pParcer.find(" "));
    server::_angle = atoi(angulo.c_str());
    return server::_angle;
}

server::~server(){
}
