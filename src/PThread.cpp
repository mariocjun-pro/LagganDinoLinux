#include "PThread.h"

using namespace GerenciadoresEntidades;
pthread_mutex_t PThread::mutex;

using namespace GerenciadoresEntidades;

PThread::PThread() {
    pthread_mutex_init(&PThread::mutex, NULL);
}

PThread::~PThread() {
    
}

void PThread::iniciarThread() {
    int status = pthread_attr_init(&tAtributo);
    status = pthread_attr_setscope(&tAtributo, PTHREAD_SCOPE_SYSTEM);
    
    if(status) {
        cerr << "Erro ao iniciar atributo thread" << endl;
    }
    
   
    status = pthread_create(&threadId, &tAtributo, PThread::executarThread, (void*)this);
    
    if(status) {
       cerr << "Falha ao iniciar a Thread" << endl; 
    }
    
    status = pthread_attr_destroy(&tAtributo);
    if(status) {
        cerr << "Falha ao destruir a Thread" << endl;
    }
}

void PThread::juntarThread() {
    int status = pthread_join(threadId, NULL);
    if(status) {
        cerr << "Comando join falhou" << endl;
    }
}

void PThread::liberarThread() {
    sched_yield();
}

void* PThread::executarThread(void* pThread) {
    PThread* sThread = static_cast<PThread*>(pThread);
    
    if(not sThread) {
        cerr << "Thread falhou" << endl;
    } 
    else {
        sThread->funcaoThread();
    }
}

void PThread::fecharThread() {
    pthread_mutex_lock(&PThread::mutex);
}

void PThread::abrirThread() {
    pthread_mutex_unlock(&PThread::mutex);
}